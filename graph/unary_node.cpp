#include "graph/unary_node.hpp"

#include <vector>
#include <string>

#include "graph/node.hpp"

namespace flow {

UnaryNode::UnaryNode(const std::string &name,
                     NodePtr child)
  : Node(name),
    m_child(child) {
  m_child->setParent(this);
}

UnaryNode::~UnaryNode() {
}

std::vector<NodePtr> UnaryNode::getChildren() const {
  std::vector<NodePtr> children;
  children.emplace_back(m_child);
  return children;
}

NodePtr UnaryNode::getChild() const {
  return m_child;
}

void UnaryNode::setChild(NodePtr node) {
  m_child = node;
}

}
