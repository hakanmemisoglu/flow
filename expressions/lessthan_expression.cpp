#include "expressions/lessthan_expression.hpp"

#include "expressions/expression.hpp"
#include "expressions/binary_expression.hpp"
#include "expressions/operator.hpp"
#include "expressions/scope.hpp"

namespace flow {

LessThanExpression::LessThanExpression(ExpressionPtr left,
                                       ExpressionPtr right)
  : BinaryExpression(OperatorID::E_LT, left, right) {
}

gcc_jit_rvalue* LessThanExpression::jit(gcc_jit_context *context,
                                        Scope &scope) {
  gcc_jit_rvalue *left_rval = m_left_child->jit(context, scope);
  gcc_jit_rvalue *right_rval = m_right_child->jit(context, scope);


  gcc_jit_location *location = nullptr;
  gcc_jit_rvalue *result = gcc_jit_context_new_comparison(context,
                                                          location,
                                                          GCC_JIT_COMPARISON_LT,
                                                          left_rval,
                                                          right_rval);
  return result;
}

};
