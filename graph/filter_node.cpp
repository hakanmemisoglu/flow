#include "graph/filter_node.hpp"

#include "graph/unary_node.hpp"

namespace flow {

FilterNode::FilterNode(const std::string &name,
                       NodePtr input,
                       FilterExpressionPtr filter_expression)
  : UnaryNode(name, input),
    m_filter_expression(filter_expression) {
}

void FilterNode::codegen(gcc_jit_context *context, flow::QueryScope *scope) {

  Scope expression_scope;
  gcc_jit_function *filter_func =
      (gcc_jit_function *)m_filter_expression->jit(context, expression_scope);

  gcc_jit_block *eval_block = scope->getCurrentEvalBlock();
  gcc_jit_block *exit_block = scope->getCurrentExitBlock();
  gcc_jit_rvalue *val = scope->getCurrentValue();

  gcc_jit_type *bool_type = gcc_jit_context_get_type(context, GCC_JIT_TYPE_BOOL);
  gcc_jit_lvalue *filter_result = gcc_jit_function_new_local(
      scope->getQueryFunction(),
      nullptr,
      bool_type,
      "filter_result");

  gcc_jit_rvalue *arguments[1] = { val };
  gcc_jit_block_add_assignment(eval_block,
                               nullptr,
                               filter_result,
                               gcc_jit_context_new_call(context,
                                                        nullptr,
                                                        filter_func,
                                                        1,
                                                        arguments));

  gcc_jit_block *next_eval_block = gcc_jit_function_new_block(scope->getQueryFunction(), "FilterNextEval");

  gcc_jit_block_end_with_conditional(eval_block,
                                     nullptr,
                                     gcc_jit_lvalue_as_rvalue(filter_result),
                                     next_eval_block,
                                     exit_block);


  scope->setCurrentEvalBlock(next_eval_block);
  getParent()->codegen(context, scope);
}

}
