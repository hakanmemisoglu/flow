#include <memory>
#include <string>

#include <libgccjit.h>

#include "graph/table_node.hpp"

int main(int argc, char *argv[]) {
  flow::TableNodePtr table_node = std::make_shared<flow::TableNode>("TableNode1", "Lineorder");

  gcc_jit_context *context = gcc_jit_context_acquire();
  gcc_jit_context_set_int_option(context, GCC_JIT_INT_OPTION_OPTIMIZATION_LEVEL, 3);
  gcc_jit_context_set_bool_option(context, GCC_JIT_BOOL_OPTION_DUMP_GENERATED_CODE, 1);
  gcc_jit_context_add_command_line_option(context, "-flto");

  flow::QueryScope query_scope;
  gcc_jit_type *void_type = gcc_jit_context_get_type(context, GCC_JIT_TYPE_VOID);
  gcc_jit_function *query_function = gcc_jit_context_new_function(context,
                                                                  nullptr,
                                                                  GCC_JIT_FUNCTION_EXPORTED,
                                                                  void_type,
                                                                  "query_func",
                                                                  0,
                                                                  nullptr,
                                                                  0);
  query_scope.setQueryFunction(query_function);
  table_node->setNumTuples(10);
  table_node->codegen(context, &query_scope);

  gcc_jit_result *result = gcc_jit_context_compile(context);
  void (*query_func)() = (void(*)()) gcc_jit_result_get_code(result, "query_func");

  query_func();

  gcc_jit_context_release(context);
  gcc_jit_result_release(result);
}
