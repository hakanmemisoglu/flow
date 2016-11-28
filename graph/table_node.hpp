#ifndef FLOW_GRAPH_TABLENODE_HPP
#define FLOW_GRAPH_TABLENODE_HPP

#include <cstdint>
#include <memory>
#include <string>

#include <libgccjit.h>

#include "graph/nullary_node.hpp"
#include "graph/query_scope.hpp"

namespace flow {

class TableNode;

using TableNodePtr = std::shared_ptr<TableNode>;

class TableNode : public NullaryNode {
public:
  TableNode() = delete;

  TableNode(const std::string &name,
            const std::string &table_name);

  ~TableNode();

  void codegen(gcc_jit_context *context, QueryScope *query_scope) final override;

  std::int64_t getNumTuples() const;

  void insert(const std::int64_t value);

  void open() final override;
  int64_t* next() final override;
  bool hasNext() final override;

protected:
  const std::string m_table_name;
  std::int64_t m_num_tuples;

  std::int64_t m_capacity;
  std::int64_t *m_data;

  std::int64_t m_iterator_index;
};

}

#endif
