#ifndef FLOW_EXPRESSIONS_BINARYEXPRESSION_HPP
#define FLOW_EXPRESSIONS_BINARYEXPRESSION_HPP

#include "expressions/expression.hpp"

namespace flow {

class BinaryExpression : public Expression {
public:
  BinaryExpression() = delete;

  virtual ~BinaryExpression() = default;

protected:
  BinaryExpression(Operator op,
                   ExpressionPtr left_child,
                   ExpressionPtr right_child);

  ExpressionPtr m_left_child;
  ExpressionPtr m_right_child;
};

}

#endif
