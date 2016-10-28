#ifndef FLOW_GRAPH_UNARYNODE_HPP
#define FLOW_GRAPH_UNARYNODE_HPP

#include "graph/node.hpp"

namespace flow {

class UnaryNode : public Node {
public:
  UnaryNode() = delete;

  UnaryNode(const std::string &name);

  virtual ~UnaryNode();

  std::vector<NodePtr> getChildren() const final override;

  NodePtr getChild() const;

  void setChild(NodePtr node);

protected:
  NodePtr m_child;
};

}

#endif
