#ifndef FLOW_EXPRESSIONS_NULLARYEXPRESSION_HPP
#define FLOW_EXPRESSIONS_NULLARYEXPRESSION_HPP

#include "expressions/expression.hpp"
#include "expressions/operator.hpp"

namespace flow {

class NullaryExpression : public Expression {
public:
  NullaryExpression() = delete;

  virtual ~NullaryExpression() = default;

protected:
  NullaryExpression(Operator op);
};

}

#endif
