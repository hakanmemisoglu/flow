#include "graph/node.hpp"

#include <string>

namespace flow {

Node::Node(const std::string name)
  : m_name(name) {
}

Node::~Node() {
}

std::string Node::getName() const {
  return m_name;
}

void Node::setParent(Node *node) {
  m_parent = node;
}

Node* Node::getParent() {
  return m_parent;
}

}
