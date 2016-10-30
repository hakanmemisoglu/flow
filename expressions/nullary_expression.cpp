#include "expressions/nullary_expression.hpp"

#include "expressions/expression.hpp"
#include "expressions/operator.hpp"

namespace flow {

NullaryExpression::NullaryExpression(Operator op)
  : Expression(op) {
}

}
