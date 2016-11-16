#ifndef FLOW_GRAPH_NODE_HPP
#define FLOW_GRAPH_NODE_HPP

#include <memory>
#include <string>
#include <vector>

#include <libgccjit.h>

#include "graph/query_scope.hpp"

namespace flow {

class Node;

using NodePtr = std::shared_ptr<Node>;

class Node {
public:
  Node() = delete;
  Node(const std::string name);

  virtual ~Node();

  Node(const Node &other) = delete;
  Node& operator=(const Node &other) = delete;

  Node(Node &&other) = default;
  Node& operator=(Node &&other) = default;

  std::string getName() const;

  virtual std::vector<NodePtr> getChildren() const = 0;

  virtual void codegen(gcc_jit_context *context, QueryScope *scope) = 0;

private:
  const std::string m_name;
};

}

#endif
