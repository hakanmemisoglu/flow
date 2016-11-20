#include "graph/query_scope.hpp"

#include <libgccjit.h>

namespace flow {

gcc_jit_function* QueryScope::getQueryFunction() {
  return m_query_function;
}

void QueryScope::setQueryFunction(gcc_jit_function *query_function) {
  m_query_function = query_function;
}

void QueryScope::setCurrentExitBlock(gcc_jit_block *exit_block) {
  m_exit_block = exit_block;
}

gcc_jit_block* QueryScope::getCurrentExitBlock() {
  return m_exit_block;
}

void QueryScope::setCurrentEvalBlock(gcc_jit_block *block) {
  m_eval_block = block;
}

gcc_jit_block* QueryScope::getCurrentEvalBlock() {
  return m_eval_block;
}

void QueryScope::setCurrentValue(gcc_jit_rvalue *value) {
  m_current_value = value;
}

gcc_jit_rvalue* QueryScope::getCurrentValue() {
  return m_current_value;
}


}
