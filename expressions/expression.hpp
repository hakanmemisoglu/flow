#ifndef FLOW_GRAPH_EXPRESSION_HPP
#define FLOW_GRAPH_EXPRESSION_HPP

#include <memory>

#include "graph/value.hpp"

namespace flow {

class Expression;

using ExpressionPtr = std::shared_ptr<Expression>;

class Expression {
public:
  virtual ~Expression() = default;

  virtual Value eval() const = 0;

protected:
  Expression() = default;
};

}

#endif
