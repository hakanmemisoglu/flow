#ifndef FLOW_EXPRESSIONS_EQUALEXPRESSION_HPP
#define FLOW_EXPRESSIONS_EQUALEXPRESSION_HPP

#include "expressions/binary_expression.hpp"
#include "expressions/expression.hpp"
#include "expressions/scope.hpp"

namespace flow {

class EqualExpression : public BinaryExpression {
public:
  EqualExpression(ExpressionPtr left,
                  ExpressionPtr right);

  gcc_jit_rvalue* jit(gcc_jit_context *context, Scope &scope) override;
};

}

#endif
