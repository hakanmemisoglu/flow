#ifndef FLOW_GRAPH_AGGREGATENODE_HPP
#define FLOW_GRAPH_AGGREGATENODE_HPP

#include <memory>

#include "graph/unary_node.hpp"

namespace flow {

class AggregateNode;

using AggregateNodePtr = std::shared_ptr<AggregateNode>;

enum class AggregateType {
  SUM,
  MIN,
  MAX,
};

class AggregateNode : public UnaryNode {
public:
  AggregateNode(const std::string &name,
                NodePtr input,
                const AggregateType agg_type);

  ~AggregateNode();

  void codegen(gcc_jit_context *context, QueryScope *scope) final override;

  void open() final override;
  int64_t* next() final override;
  bool hasNext() final override;

private:
  AggregateType m_agg_type;

  std::int64_t m_agg_value;
  std::int64_t m_has_next;
};

}

#endif
