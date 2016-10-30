#ifndef FLOW_EXPRESSIONS_PARAMETEREXPRESSION_HPP
#define FLOW_EXPRESSIONS_PARAMETEREXPRESSION_HPP

#include <memory>
#include <string>

#include "expressions/expression.hpp"
#include "expressions/scope.hpp"

namespace flow {

class ParameterExpression;

using ParameterExpressionPtr = std::shared_ptr<ParameterExpression>;

class ParameterExpression : public Expression {
public:
  ParameterExpression(const std::string &name);

  gcc_jit_rvalue* jit(gcc_jit_context *context, Scope &scope) override;

private:
  const std::string m_parameter_name;

};

}

#endif
