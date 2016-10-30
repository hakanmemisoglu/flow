#ifndef FLOW_EXPRESSIONS_LESSTHAN_HPP
#define FLOW_EXPRESSIONS_LESSTHAN_HPP

#include "expressions/binary_expression.hpp"
#include "expressions/expression.hpp"
#include "expressions/scope.hpp"

namespace flow {

class LessThanExpression : public BinaryExpression {
public:
  LessThanExpression(ExpressionPtr left, ExpressionPtr right);

  gcc_jit_rvalue* jit(gcc_jit_context *context, Scope &scope) override;
};

}

#endif
