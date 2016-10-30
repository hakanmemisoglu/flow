#ifndef FLOW_EXPRESSIONS_ARITHMETICEXPRESSION_HPP
#define FLOW_EXPRESSIONS_ARITHMETICEXPRESSION_HPP

#include "expressions/expression.hpp"
#include "expressions/binary_expression.hpp"
#include "expressions/operator.hpp"

namespace flow {

class ArithmeticExpression {
public:
  ArithmeticExpression() = delete;

  ArithmeticExpression(const ArithmeticExpression &other) = delete;
  ArithmeticExpression& operator=(const ArithmeticExpression &other) = delete;

protected:
  ArithmeticExpression(Operator op);

  Operator m_operator;
};

}


#endif
