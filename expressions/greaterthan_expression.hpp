#ifndef FLOW_EXPRESSIONS_GREATERTHAN_HPP
#define FLOW_EXPRESSIONS_GREATERTHAN_HPP

#include "expressions/binary_expression.hpp"
#include "expressions/expression.hpp"
#include "expressions/scope.hpp"

namespace flow {

class GreaterThanExpression : public BinaryExpression {
public:
  GreaterThanExpression(ExpressionPtr left, ExpressionPtr right);

  gcc_jit_rvalue* jit(gcc_jit_context *context, Scope &scope) override;
};

}

#endif
