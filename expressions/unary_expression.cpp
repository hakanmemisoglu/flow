#include "expressions/unary_expression.hpp"

#include "expressions/expression.hpp"
#include "expressions/operator.hpp"

namespace flow {

UnaryExpression::UnaryExpression(Operator op,
                                 ExpressionPtr child)
  : Expression(op),
    m_child(child) {
}

}
