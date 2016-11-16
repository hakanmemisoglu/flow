#include "graph/query_scope.hpp"

#include <libgccjit.h>

namespace flow {

gcc_jit_function* QueryScope::getQueryFunction() {
  return m_query_function;
}

void QueryScope::setQueryFunction(gcc_jit_function *query_function) {
  m_query_function = query_function;
}

}
