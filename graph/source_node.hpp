#ifndef FLOW_GRAPH_SOURCENODE_HPP
#define FLOW_GRAPH_SOURCENODE_HPP

#include "graph/node.hpp"
#include "graph/nullary_node.hpp"

namespace flow {

class SourceNode : public NullaryNode {
public:
  SourceNode(const std::string &name,
             const std::string &source);

private:
  const std::string m_source_name;
};

}
#endif
