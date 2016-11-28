#include <chrono>
#include <iostream>
#include <memory>
#include <random>
#include <string>

#include <libgccjit.h>

#include "graph/aggregate_node.hpp"
#include "graph/table_node.hpp"
#include "graph/filter_node.hpp"
#include "graph/print_node.hpp"

#include "expressions/filter_expression.hpp"
#include "expressions/variable_expression.hpp"
#include "expressions/equal_expression.hpp"
#include "expressions/addition_expression.hpp"
#include "expressions/constant_expression.hpp"
#include "expressions/lessthan_expression.hpp"

int main(int argc, char *argv[]) {
  flow::TableNodePtr table_node =
      std::make_shared<flow::TableNode>("TableNode1", "Lineorder");

  flow::ExpressionPtr const_e1 = std::make_shared<flow::ConstantExpression>(10);
  flow::VariableExpressionPtr var_e1 =
      std::make_shared<flow::VariableExpression>("x");
  flow::ExpressionPtr addition_e1 =
      std::make_shared<flow::AdditionExpression>(var_e1, const_e1);
  flow::ExpressionPtr const_e2 = std::make_shared<flow::ConstantExpression>(55);

  flow::ExpressionPtr cond_e1 =
      std::make_shared<flow::LessThanExpression>(const_e2, addition_e1);

  flow::ParameterExpressionPtr param =
      std::make_shared<flow::ParameterExpression>("x");
  flow::FilterExpressionPtr filter_e =
      std::make_shared<flow::FilterExpression>("filter", param, cond_e1);

  flow::FilterNodePtr filter_node =
      std::make_shared<flow::FilterNode>("FilterNode1", table_node, filter_e);

  flow::AggregateNodePtr agg_node = std::make_shared<flow::AggregateNode>(
      "AggNode1", filter_node, flow::AggregateType::SUM);

  flow::PrintNodePtr print_node =
      std::make_shared<flow::PrintNode>("PrintNode1", agg_node);

  gcc_jit_context *context = gcc_jit_context_acquire();
  gcc_jit_context_set_int_option(context, GCC_JIT_INT_OPTION_OPTIMIZATION_LEVEL, 2);
  //gcc_jit_context_set_bool_option(context, GCC_JIT_BOOL_OPTION_DUMP_GENERATED_CODE, 1);
  //gcc_jit_context_set_bool_option(context, GCC_JIT_BOOL_OPTION_DUMP_INITIAL_GIMPLE, 1);

  //gcc_jit_context_add_command_line_option(context, "-march=haswell");
  //gcc_jit_context_add_command_line_option(context, "-fverbose-asm");
  //gcc_jit_context_add_command_line_option(context, "-ffast-math");
  //gcc_jit_context_add_command_line_option(context, "-faggressive-loop-optimizations");
  //gcc_jit_context_add_command_line_option(context, "-funroll-loops");
  //gcc_jit_context_add_command_line_option(context, "-flto");

  flow::QueryScope query_scope;
  gcc_jit_type *void_type =
      gcc_jit_context_get_type(context, GCC_JIT_TYPE_VOID);
  gcc_jit_function *query_function =
      gcc_jit_context_new_function(context,
                                   nullptr,
                                   GCC_JIT_FUNCTION_EXPORTED,
                                   void_type,
                                   "query_func",
                                   0,
                                   nullptr,
                                   0);

  query_scope.setQueryFunction(query_function);

  std::mt19937 rand_gen;
  rand_gen.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> uni_dist(0,100);
  for (std::int64_t i = 0; i < 100000000; ++i) {
    table_node->insert(uni_dist(rand_gen));
  }

  auto compilation_begin = std::chrono::high_resolution_clock::now();
  table_node->codegen(context, &query_scope);
  //gcc_jit_function_dump_to_dot(query_scope.getQueryFunction(), "query.dot");

  gcc_jit_result *result = gcc_jit_context_compile(context);
  void (*query_func)() = (void(*)()) gcc_jit_result_get_code(result, "query_func");
  auto compilation_end = std::chrono::high_resolution_clock::now();

  query_func();

  auto query_end = std::chrono::high_resolution_clock::now();

  gcc_jit_context_release(context);
  gcc_jit_result_release(result);

  std::cout << "Compilation: "
            << std::chrono::duration_cast<std::chrono::microseconds>(
                   compilation_end - compilation_begin)
                   .count()
            << " microseconds." << std::endl;

  std::cout << "Query      : "
            << std::chrono::duration_cast<std::chrono::microseconds>(
                   query_end - compilation_end)
                   .count()
            << " microseconds." << std::endl;
}
