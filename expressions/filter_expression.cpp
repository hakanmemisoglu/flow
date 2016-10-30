#include "expressions/filter_expression.hpp"

#include "expressions/expression.hpp"
#include "expressions/operator.hpp"
#include "expressions/parameter_expression.hpp"
#include "expressions/scope.hpp"

namespace flow {

FilterExpression::FilterExpression(const std::string &name,
                                   ParameterExpressionPtr var,
                                   ExpressionPtr body)
  : Expression(OperatorID::E_FILTER),
    m_name(name),
    m_var(var),
    m_body(body) {
};

gcc_jit_rvalue* FilterExpression::jit(gcc_jit_context *context,
                                      Scope &scope) {
  gcc_jit_param *param = (gcc_jit_param*) m_var->jit(context, scope);
  gcc_jit_location *location = nullptr;
  gcc_jit_type *result_type = gcc_jit_context_get_type(context,
                                                       GCC_JIT_TYPE_BOOL);
  std::size_t num_parameters = 1;
  gcc_jit_function *func = gcc_jit_context_new_function(context,
                                                        location,
                                                        GCC_JIT_FUNCTION_EXPORTED,
                                                        result_type,
                                                        m_name.c_str(),
                                                        num_parameters,
                                                        &param,
                                                        0);
  gcc_jit_block *block = gcc_jit_function_new_block(func, nullptr);
  gcc_jit_rvalue *body_rval = m_body->jit(context, scope);
  gcc_jit_block_end_with_return(block, nullptr, body_rval);
  return nullptr;
}

}
