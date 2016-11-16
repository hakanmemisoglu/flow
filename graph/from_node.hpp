#ifndef FLOW_GRAPH_FROMNODE_HPP
#define FLOW_GRAPH_FROMNODE_HPP

#include "graph/node.hpp"
#include "graph/unary_node.hpp"

namespace flow {

class FromNode : public UnaryNode {
public:
  FromNode(const std::string &name,
           NodePtr input);

protected:
  NodePtr m_input;
};

}

#endif
