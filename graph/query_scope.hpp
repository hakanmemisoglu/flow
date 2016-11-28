#ifndef FLOW_GRAPH_QUERYSCOPE_HPP
#define FLOW_GRAPH_QUERYSCOPE_HPP

#include <vector>

#include <libgccjit.h>

namespace flow {

class QueryScope {
public:
  QueryScope() = default;

  QueryScope(const QueryScope &other) = delete;
  QueryScope& operator=(const QueryScope &other) = delete;

  gcc_jit_function* getQueryFunction();
  void setQueryFunction(gcc_jit_function *query_function);

  void setCurrentExitBlock(gcc_jit_block *exit_block);
  gcc_jit_block* getCurrentExitBlock();

  void setCurrentEvalBlock(gcc_jit_block *block);
  gcc_jit_block* getCurrentEvalBlock();

  void setCurrentValue(gcc_jit_rvalue *value);
  gcc_jit_rvalue* getCurrentValue();

  void setQueryInitBlock(gcc_jit_block *init_block);
  gcc_jit_block* getQueryInitBlock();

  void setQueryExitBlock(gcc_jit_block *exit_block);
  gcc_jit_block* getQueryExitBlock();

private:
  gcc_jit_function *m_query_function;

  gcc_jit_block *m_exit_block;

  gcc_jit_rvalue *m_current_value;

  gcc_jit_block *m_eval_block;

  gcc_jit_block *m_query_init_block;

  gcc_jit_block *m_query_exit_block;
};

}

#endif
