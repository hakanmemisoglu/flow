#ifndef FLOW_GRAPH_FILTERNODE_HPP
#define FLOW_GRAPH_FILTERNODE_HPP

#include "graph/unary_node.hpp"
#include "graph/expression.hpp"

namespace flow {

class FilterNode : public UnaryNode {
public:
  FilterNode(const std::string &name,
             NodePtr input,
             ExpressionPtr filter_expression);
private:
};

}

#endif
