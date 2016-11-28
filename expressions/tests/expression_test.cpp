#include <iostream>

#include <libgccjit.h>

#include "expressions/value.hpp"
#include "expressions/constant_expression.hpp"
#include "expressions/expression.hpp"
#include "expressions/addition_expression.hpp"
#include "expressions/subtraction_expression.hpp"
#include "expressions/parameter_expression.hpp"
#include "expressions/filter_expression.hpp"
#include "expressions/lessthan_expression.hpp"
#include "expressions/variable_expression.hpp"
#include "expressions/scope.hpp"

int main() {
  flow::ExpressionPtr const_e1 = std::make_shared<flow::ConstantExpression>(123);
  flow::ExpressionPtr const_e2 = std::make_shared<flow::ConstantExpression>(256);

  flow::ExpressionPtr e3 = std::make_shared<flow::AdditionExpression>(const_e1, const_e2);
  flow::VariableExpressionPtr e4 =
      std::make_shared<flow::VariableExpression>("param1");
  flow::ExpressionPtr const_e5 = std::make_shared<flow::ConstantExpression>(54);
  flow::ExpressionPtr e6 = std::make_shared<flow::SubtractionExpression>(e4, const_e5);
  flow::ExpressionPtr e7 = std::make_shared<flow::LessThanExpression>(e6, e3);

  flow::ParameterExpressionPtr param
    = std::make_shared<flow::ParameterExpression>("param1");

  flow::ExpressionPtr f1 = std::make_shared<flow::FilterExpression>("filter",
                                                                    param,
                                                                    e7);
  /*
  flow::Scope scope;
  gcc_jit_context *context = gcc_jit_context_acquire();
  gcc_jit_context_set_int_option(context, GCC_JIT_INT_OPTION_OPTIMIZATION_LEVEL, 3);
  gcc_jit_context_set_bool_option(context,
                                  GCC_JIT_BOOL_OPTION_DUMP_GENERATED_CODE, 1);
  f1->jit(context, scope);

  gcc_jit_result *res = gcc_jit_context_compile(context);
  bool(*filter_func)(std::int64_t) = (bool(*)(std::int64_t))gcc_jit_result_get_code(res, "filter");

  std::cout << filter_func(100) << std::endl;
  std::cout << filter_func(200) << std::endl;
  std::cout << filter_func(600) << std::endl;

  //  gcc_jit_context_dump_to_file(context, "source.txt", 1);

  gcc_jit_context_release(context);
  gcc_jit_result_release(res);
  */

  std::cout << "INTERPRETER" << std::endl;
  std::cout << f1->eval(100).value.bool_value << std::endl;
  std::cout << f1->eval(200).value.bool_value << std::endl;
  std::cout << f1->eval(600).value.bool_value << std::endl;

}
