#ifndef FLOW_EXPRESSION_ADDITIONEXPRESSION
#define FLOW_EXPRESSION_ADDITIONEXPRESSION

#include <libgccjit.h>

#include "expressions/binary_expression.hpp"
#include "expressions/expression.hpp"
#include "expressions/scope.hpp"

namespace flow {

class AdditionExpression : public BinaryExpression {
public:
  AdditionExpression(ExpressionPtr left,
                     ExpressionPtr right);

  gcc_jit_rvalue* jit(gcc_jit_context *context, Scope &scope) override;
};

}

#endif
