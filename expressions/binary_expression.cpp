#include "expressions/binary_expression.hpp"

#include "expressions/expression.hpp"

namespace flow {

BinaryExpression::BinaryExpression(Operator op,
                                   ExpressionPtr left_child,
                                   ExpressionPtr right_child)
  : Expression(op),
    m_left_child(left_child),
    m_right_child(right_child) {
}

}
