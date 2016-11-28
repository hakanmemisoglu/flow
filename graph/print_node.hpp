#ifndef FLOW_GRAPH_PRINTNODE_HPP
#define FLOW_GRAPH_PRINTNODE_HPP

#include <memory>

#include "graph/unary_node.hpp"
#include "graph/node.hpp"

namespace flow {

class PrintNode;

using PrintNodePtr = std::shared_ptr<PrintNode>;

class PrintNode : public UnaryNode {
public:
  PrintNode(const std::string &name,
            NodePtr input);

  void codegen(gcc_jit_context *context, QueryScope *scope) final override;

  void open() final override;
  int64_t* next() final override;
  bool hasNext() final override;
};

}

#endif
