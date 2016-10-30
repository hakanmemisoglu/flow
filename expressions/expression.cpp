#include "expressions/expression.hpp"

namespace flow {

Expression::Expression(Operator op)
  : m_op(op) {
}

Operator Expression::getOperator() const {
  return m_op;
}

}
