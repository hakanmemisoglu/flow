#ifndef FLOW_EXPRESSIONS_SUBTRACTIONEXPRESSION_HPP
#define FLOW_EXPRESSIONS_SUBTRACTIONEXPRESSION_HPP

#include "expressions/expression.hpp"
#include "expressions/binary_expression.hpp"
#include "expressions/scope.hpp"

namespace flow {

class SubtractionExpression : public BinaryExpression {
public:
  SubtractionExpression(ExpressionPtr left,
                        ExpressionPtr right);

  gcc_jit_rvalue* jit(gcc_jit_context *context, Scope &scope) override;
};

}

#endif
