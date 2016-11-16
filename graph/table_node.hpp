#ifndef FLOW_GRAPH_TABLENODE_HPP
#define FLOW_GRAPH_TABLENODE_HPP

#include <string>

#include "graph/nullary_node.hpp"

namespace flow {

class TableNode : public NullaryNode {
public:
  TableNode() = delete;

  TableNode(const std::string &name,
            const std::string &table_name);

  void codegen() final override;

protected:
  const std::string m_table_name;
};

}

#endif
