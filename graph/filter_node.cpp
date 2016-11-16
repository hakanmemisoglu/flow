#include "graph/filter_node.hpp"

#include "graph/unary_node.hpp"

namespace flow {

FilterNode::FilterNode(const std::string &name,
                       NodePtr input,
                       FilterExpressionPtr filter_expression)
  : UnaryNode(name, input),
    m_filter_expression(filter_expression) {
}

}
