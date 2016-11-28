#ifndef FLOW_EXPRESSIONS_EXPRESSION_HPP
#define FLOW_EXPRESSIONS_EXPRESSION_HPP

#include <memory>

#include <libgccjit.h>

#include "expressions/operator.hpp"
#include "expressions/scope.hpp"
#include "expressions/result.hpp"

namespace flow {

class Expression;

using ExpressionPtr = std::shared_ptr<Expression>;

class Expression {
public:
  Expression() = delete;

  virtual ~Expression() = default;

  virtual gcc_jit_rvalue* jit(gcc_jit_context *context, Scope &scope) = 0;

  Operator getOperator() const;

  virtual Result eval(std::int64_t opt_arg = 0) = 0;

protected:
  Expression(Operator op);

  Operator m_op;
};

}

#endif
