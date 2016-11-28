#ifndef FLOW_GRAPH_FILTERNODE_HPP
#define FLOW_GRAPH_FILTERNODE_HPP

#include <memory>

#include "graph/unary_node.hpp"
#include "expressions/filter_expression.hpp"

namespace flow {

class FilterNode;

using FilterNodePtr = std::shared_ptr<FilterNode>;

class FilterNode : public UnaryNode {
public:
  FilterNode(const std::string &name,
             NodePtr input,
             FilterExpressionPtr filter_expression);

  void codegen(gcc_jit_context *context, QueryScope *scope) final override;

  void open() final override;
  int64_t* next() final override;
  bool hasNext() final override;

protected:
  FilterExpressionPtr m_filter_expression;

private:
  int64_t *m_next_to_push;
  bool m_has_next;
};

}

#endif
