#ifndef FLOW_EXPRESSIONS_UNARYEXPRESSION_HPP
#define FLOW_EXPRESSIONS_UNARYEXPRESSION_HPP

#include "expressions/expression.hpp"
#include "expressions/operator.hpp"

namespace flow {

class UnaryExpression : public Expression {
public:
  UnaryExpression() = delete;

  virtual ~UnaryExpression() = default;

protected:
  UnaryExpression(Operator op, ExpressionPtr child);

  ExpressionPtr m_child;
};

}

#endif
