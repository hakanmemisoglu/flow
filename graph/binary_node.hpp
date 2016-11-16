#ifndef FLOW_GRAPH_BINARYNODE_HPP
#define FLOW_GRAPH_BINARYNODE_HPP

#include <string>

#include "graph/node.hpp"
#include "graph/query_scope.hpp"

namespace flow {

class BinaryNode : public Node {
public:
  BinaryNode() = delete;

  BinaryNode(const std::string &name);

  virtual ~BinaryNode();

  std::vector<NodePtr> getChildren() const final override;

  NodePtr getLeftChild() const;

  void setLeftChild(NodePtr node);

  NodePtr getRightChild() const;

  void setRightChild(NodePtr node);

protected:
  NodePtr m_left_child;
  NodePtr m_right_child;
};

}

#endif
