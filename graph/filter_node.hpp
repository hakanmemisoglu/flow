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

protected:
  FilterExpressionPtr m_filter_expression;
};

}

#endif
