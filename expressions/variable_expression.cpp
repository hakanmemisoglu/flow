#include "expressions/variable_expression.hpp"

#include <string>

#include "expressions/expression.hpp"

namespace flow {

VariableExpression::VariableExpression(const std::string &var_name)
  : Expression(OperatorID::E_VAR),
    m_var_name(var_name) {
}

gcc_jit_rvalue* VariableExpression::jit(gcc_jit_context *context,
                                        Scope &scope) {
  gcc_jit_param* param = scope.get_parameter(m_var_name);
  gcc_jit_rvalue* rval = gcc_jit_param_as_rvalue(param);
  return rval;
}

Result VariableExpression::eval(std::int64_t opt_arg) {
  Result r;
  r.type = ResultType::INT64;
  r.value.int64_value = opt_arg;
  return r;
}

}
