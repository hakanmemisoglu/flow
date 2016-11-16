#ifndef FLOW_GRAPH_FILTERNODE_HPP
#define FLOW_GRAPH_FILTERNODE_HPP

#include "graph/unary_node.hpp"
#include "expressions/filter_expression.hpp"

namespace flow {

class FilterNode : public UnaryNode {
public:
  FilterNode(const std::string &name,
             NodePtr input,
             FilterExpressionPtr filter_expression);
protected:
  FilterExpressionPtr m_filter_expression;
};

}

#endif
