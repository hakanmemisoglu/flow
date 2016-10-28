#include "graph/source_node.hpp"

namespace flow {

SourceNode::SourceNode(const std::string &name,
                       const std::string &source)
  : NullaryNode(name),
    m_source_name(source) {
}

}
