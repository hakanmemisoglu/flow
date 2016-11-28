#include "graph/print_node.hpp"

namespace flow {

PrintNode::PrintNode(const std::string &name,
                     NodePtr input)
  : UnaryNode(name, input) {
}

void PrintNode::codegen(gcc_jit_context *context, flow::QueryScope *scope) {
  gcc_jit_param *parameters = gcc_jit_context_new_param(
      context,
      nullptr,
      gcc_jit_context_get_type(context, GCC_JIT_TYPE_CONST_CHAR_PTR),
      "format");

  gcc_jit_function *printf_func = gcc_jit_context_new_function(
      context,
      nullptr,
      GCC_JIT_FUNCTION_IMPORTED,
      gcc_jit_context_get_type(context, GCC_JIT_TYPE_INT),
      "printf",
      1,
      &parameters,
      1);

  gcc_jit_rvalue *printf_args[2];
  printf_args[0] = gcc_jit_context_new_string_literal(context, "%d\n");
  printf_args[1] = scope->getCurrentValue();

  gcc_jit_block *current_eval_block = scope->getCurrentEvalBlock();
  gcc_jit_block *current_exit_block = scope->getCurrentExitBlock();

  gcc_jit_block_add_eval(scope->getCurrentEvalBlock(),
                         nullptr,
                         gcc_jit_context_new_call(context,
                                                  nullptr,
                                                  printf_func,
                                                  2,
                                                  printf_args));

  if (current_eval_block != current_exit_block) {
    // Means it is pipelining. Put print operation.
    gcc_jit_block_end_with_jump(current_eval_block,
                                nullptr,
                                current_exit_block);
  }
}

void PrintNode::open() {
  getChild()->open();
}

int64_t* PrintNode::next() {
  int64_t* value = getChild()->next();
  printf("%ld\n", *value);
  return nullptr;
}

bool PrintNode::hasNext() {
  return getChild()->hasNext();
}

}
