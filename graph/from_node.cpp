#include "graph/from_node.hpp"

#include <string>

#include "graph/node.hpp"
#include "graph/unary_node.hpp"

namespace flow {

FromNode::FromNode(const std::string &name,
                   NodePtr input)
  : UnaryNode(name),
    m_input(input) {
}

}
