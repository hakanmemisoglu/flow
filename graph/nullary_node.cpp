#include "graph/nullary_node.hpp"

#include <vector>

#include "graph/node.hpp"

namespace flow {

NullaryNode::NullaryNode(const std::string &name)
  : Node(name) {
}

NullaryNode::~NullaryNode() {
}

std::vector<NodePtr> NullaryNode::getChildren() const {
  return std::vector<NodePtr>();
}

}
