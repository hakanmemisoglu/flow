#ifndef FLOW_EXPRESSIONS_VARIABLEEXPRESSION_HPP
#define FLOW_EXPRESSIONS_VARIABLEEXPRESSION_HPP

#include <memory>
#include <string>

#include "expressions/expression.hpp"
#include "expressions/scope.hpp"

namespace flow {

class VariableExpression;

using VariableExpressionPtr = std::shared_ptr<VariableExpression>;

class VariableExpression : public Expression {
public:
  VariableExpression(const std::string &var_name);

  gcc_jit_rvalue* jit(gcc_jit_context *context, Scope &scope) override;

  Result eval(std::int64_t opt_arg = 0) final override;
private:
  const std::string m_var_name;
};

}

#endif
