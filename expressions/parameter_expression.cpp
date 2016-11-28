#include "expressions/parameter_expression.hpp"

#include <string>

#include <libgccjit.h>

#include "expressions/expression.hpp"
#include "expressions/operator.hpp"
#include "expressions/scope.hpp"

namespace flow {

ParameterExpression::ParameterExpression(const std::string &name)
  : Expression(OperatorID::E_PARAM),
    m_parameter_name(name) {
}

gcc_jit_rvalue* ParameterExpression::jit(gcc_jit_context *context,
                                         Scope &scope) {
  gcc_jit_type *param_type = gcc_jit_context_get_type(context,
                                                      GCC_JIT_TYPE_LONG_LONG);
  gcc_jit_location *location = nullptr;
  gcc_jit_param *param = gcc_jit_context_new_param(context,
                                                   location,
                                                   param_type,
                                                   m_parameter_name.c_str());
  scope.set_parameter(m_parameter_name, param);

  // Check sanity!!;
  return (gcc_jit_rvalue*) param;
}

Result ParameterExpression::eval(std::int64_t opt_arg) {
  Result r;
  return r;
}

}
