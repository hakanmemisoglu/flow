#ifndef FLOW_EXPRESSIONS_FILTEREXPRESSION_HPP
#define FLOW_EXPRESSIONS_FILTEREXPRESSION_HPP

#include <memory>
#include <string>

#include <libgccjit.h>

#include "expressions/expression.hpp"
#include "expressions/parameter_expression.hpp"
#include "expressions/scope.hpp"

namespace flow {

class FilterExpression;

using FilterExpressionPtr = std::shared_ptr<FilterExpression>;

class FilterExpression : public Expression {
public:
  FilterExpression(const std::string &name,
                   ParameterExpressionPtr var,
                   ExpressionPtr body);

  gcc_jit_rvalue* jit(gcc_jit_context *context, Scope &scope) override;

private:
  const std::string m_name;
  ParameterExpressionPtr m_var;
  ExpressionPtr m_body;
};

}
#endif
