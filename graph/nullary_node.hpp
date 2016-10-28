#ifndef FLOW_GRAPH_NULLARYNODE_HPP
#define FLOW_GRAPH_NULLARYNODE_HPP

#include "graph/node.hpp"

namespace flow {

class NullaryNode : public Node {
public:
  NullaryNode() = delete;

  NullaryNode(const std::string &name);

  virtual ~NullaryNode();

  std::vector<NodePtr> getChildren() const final override;

private:
};

}

#endif
