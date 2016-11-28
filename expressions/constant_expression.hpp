#ifndef FLOW_EXPRESSIONS_CONSTANTEXPRESSION_HPP
#define FLOW_EXPRESSIONS_CONSTANTEXPRESSION_HPP

#include "expressions/nullary_expression.hpp"
#include "expressions/value.hpp"
#include "expressions/scope.hpp"

namespace flow {

class ConstantExpression : public NullaryExpression {
public:
  ConstantExpression(Value val);

  gcc_jit_rvalue* jit(gcc_jit_context *context, Scope &scope) override;

  Result eval(std::int64_t opt_arg = 0) final override;

private:
  Value m_value;
};

}

#endif
