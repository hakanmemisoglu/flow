#include "graph/aggregate_node.hpp"

namespace flow {

AggregateNode::AggregateNode(const std::string &name,
                             NodePtr input,
                             const AggregateType agg_type)
  : UnaryNode(name, input),
    m_agg_type(agg_type) {
}

AggregateNode::~AggregateNode() {
}

void AggregateNode::codegen(gcc_jit_context *context,
                            QueryScope *scope) {
  gcc_jit_block *eval_block = scope->getCurrentEvalBlock();

  gcc_jit_rvalue *val = scope->getCurrentValue();

  gcc_jit_type *int64_type =
      gcc_jit_context_get_type(context, GCC_JIT_TYPE_LONG_LONG);


  gcc_jit_lvalue *aggregate_val = gcc_jit_function_new_local(
      scope->getQueryFunction(),
      nullptr,
      int64_type,
      "aggregate1");

  gcc_jit_block_add_assignment(scope->getQueryInitBlock(),
                               nullptr,
                               aggregate_val,
                               gcc_jit_context_zero(context, int64_type));

  gcc_jit_block_add_assignment_op(eval_block, nullptr, aggregate_val, GCC_JIT_BINARY_OP_PLUS, val);

  gcc_jit_block_end_with_jump(eval_block, nullptr, scope->getCurrentExitBlock());

  scope->setCurrentValue(gcc_jit_lvalue_as_rvalue(aggregate_val));

  scope->setCurrentEvalBlock(scope->getQueryExitBlock());
  scope->setCurrentExitBlock(scope->getQueryExitBlock());

  getParent()->codegen(context, scope);
}

void AggregateNode::open() {
  m_agg_value = 0;
  m_has_next = true;
  getChild()->open();
}

int64_t* AggregateNode::next() {
  while (getChild()->hasNext()) {
    m_agg_value += *(getChild()->next());
  }
  m_has_next = false;
  return &m_agg_value;
};

bool AggregateNode::hasNext() {
  return m_has_next;
}

}
