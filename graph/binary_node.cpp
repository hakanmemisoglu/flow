#include "graph/binary_node.hpp"

#include <string>
#include <vector>

#include "graph/node.hpp"

namespace flow {

BinaryNode::BinaryNode(const std::string &name)
  : Node(name) {
}

std::vector<NodePtr> BinaryNode::getChildren() const {
  std::vector<NodePtr> children;
  children.emplace_back(m_left_child);
  children.emplace_back(m_right_child);
  return children;
}

NodePtr BinaryNode::getLeftChild() const {
  return m_left_child;
}

void BinaryNode::setLeftChild(NodePtr node) {
  m_left_child = node;
}

NodePtr BinaryNode::getRightChild() const {
  return m_right_child;
}

}
