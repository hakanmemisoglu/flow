#include "graph/node.hpp"

#include <string>

namespace flow {

Node::Node(const std::string name)
  : m_name(name) {
}

std::string Node::getName() const {
  return m_name;
}

}
