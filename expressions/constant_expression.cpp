#include "constant_expression.hpp"

#include <libgccjit.h>

#include "expressions/nullary_expression.hpp"
#include "expressions/operator.hpp"
#include "expressions/value.hpp"
#include "expressions/scope.hpp"

namespace flow {

ConstantExpression::ConstantExpression(Value val)
  : NullaryExpression(OperatorID::E_CONST), m_value(val) {
}

gcc_jit_rvalue* ConstantExpression::jit(gcc_jit_context *context,
                                        Scope &scope) {
  std::int64_t val = m_value.getVal();
  gcc_jit_type *type = gcc_jit_context_get_type(context, GCC_JIT_TYPE_LONG_LONG);
  gcc_jit_rvalue *rval = gcc_jit_context_new_rvalue_from_long(context, type, val);
  return rval;
}

Result ConstantExpression::eval(std::int64_t opt_arg) {
  Result res;
  res.type = ResultType::INT64;
  res.value.int64_value = m_value.getVal();
  return res;
}

}
