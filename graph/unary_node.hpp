#ifndef FLOW_GRAPH_UNARYNODE_HPP
#define FLOW_GRAPH_UNARYNODE_HPP

#include <memory>
#include <vector>

#include "graph/node.hpp"

namespace flow {

class UnaryNode : public Node {
public:
  UnaryNode() = delete;

  virtual ~UnaryNode();

  std::vector<NodePtr> getChildren() const final override;

  NodePtr getChild() const;

  void setChild(NodePtr node);

protected:
  UnaryNode(const std::string &name,
            NodePtr child);

  NodePtr m_child;
};

}

#endif
