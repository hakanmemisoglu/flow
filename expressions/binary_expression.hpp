#ifndef FLOW_GRAPH_BINARYEXPRESSION_HPP
#define FLOW_GRAPH_BINARYEXPRESSION_HPP

#include "expressions/expression.hpp"

namespace flow {

class BinaryExpression : public Expression {
public:
  BinaryExpression() = delete;

  virtual ~BinaryExpression() = default;

protected:
  BinaryExpression(ExpressionPtr left_child,
                   ExpressionPtr right_child);

  ExpressionPtr m_left_child;
  ExpressionPtr m_right_child;
};

}

#endif
