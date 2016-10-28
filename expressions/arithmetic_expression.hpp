#ifndef FLOW_GRAPH_ARITHMETICEXPRESSION_HPP
#define FLOW_GRAPH_ARITHMETICEXPRESSION_HPP

#include "expressions/expression.hpp"
#include "expressions/binary_expression.hpp"
#include "expressions/operator.hpp"

namespace flow {

class ArithmeticExpression : public BinaryExpression {
public:
  ArithmeticExpression(Operator op);
private:
};

}


#endif
