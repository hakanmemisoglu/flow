#ifndef FLOW_GRAPH_QUERYSCOPE_HPP
#define FLOW_GRAPH_QUERYSCOPE_HPP

#include <libgccjit.h>

namespace flow {

class QueryScope {
public:
  QueryScope() = default;

  QueryScope(const QueryScope &other) = delete;
  QueryScope& operator=(const QueryScope &other) = delete;

  gcc_jit_function* getQueryFunction();
  void setQueryFunction(gcc_jit_function *query_function);

private:
  gcc_jit_function *m_query_function;
};

}

#endif
