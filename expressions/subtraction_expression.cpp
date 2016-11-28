#include "expressions/subtraction_expression.hpp"

#include "expressions/expression.hpp"
#include "expressions/binary_expression.hpp"
#include "expressions/operator.hpp"
#include "expressions/scope.hpp"

namespace flow {

SubtractionExpression::SubtractionExpression(ExpressionPtr left,
                                             ExpressionPtr right)
  : BinaryExpression(OperatorID::E_SUB, left, right) {
}

gcc_jit_rvalue* SubtractionExpression::jit(gcc_jit_context *context,
                                           Scope &scope) {
  gcc_jit_rvalue *left_rval = m_left_child->jit(context, scope);
  gcc_jit_rvalue *right_rval = m_right_child->jit(context, scope);
  gcc_jit_type *result_type = gcc_jit_context_get_type(context,
                                                       GCC_JIT_TYPE_LONG_LONG);
  gcc_jit_location *location = nullptr;
  gcc_jit_rvalue *result = gcc_jit_context_new_binary_op(context,
                                                         location,
                                                         GCC_JIT_BINARY_OP_MINUS,
                                                         result_type,
                                                         left_rval,
                                                         right_rval);
  return result;
}

Result SubtractionExpression::eval(std::int64_t opt_arg) {
  Result left_result = m_left_child->eval(opt_arg);
  Result right_result = m_right_child->eval(opt_arg);
  Result r;
  r.type = ResultType::INT64;
  r.value.int64_value = left_result.value.int64_value - right_result.value.int64_value;
  return r;
}

}
