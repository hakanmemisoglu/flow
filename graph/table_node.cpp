#include "graph/table_node.hpp"

#include <cstdlib>
#include <string>

#include <libgccjit.h>

#include "graph/nullary_node.hpp"
#include "graph/query_scope.hpp"

extern "C" {
void my_internal_function(std::int64_t input_arg) {
  std::printf("%ld\n", input_arg * 2);
}
}

namespace flow {

TableNode::TableNode(const std::string &name,
                     const std::string &table_name)
  : NullaryNode(name),
    m_table_name(table_name),
    m_capacity(128),
    m_data(reinterpret_cast<std::int64_t*>(std::malloc(128 * sizeof(std::int64_t)))) {
}

std::int64_t TableNode::getNumTuples() const {
  return m_num_tuples;
}

TableNode::~TableNode() {
  std::free(m_data);
}

void TableNode::insert(const std::int64_t value) {
  if (m_num_tuples >= m_capacity) {
    m_data = reinterpret_cast<std::int64_t *>(
        std::realloc(m_data, (m_capacity * 2) * sizeof(std::int64_t)));
    m_capacity = 2 * m_capacity;
  }
  m_data[m_num_tuples] = value;
  ++m_num_tuples;
}

void TableNode::codegen(gcc_jit_context *context, QueryScope *scope) {
  gcc_jit_function *query_function = scope->getQueryFunction();

  // Initial block.
  gcc_jit_block *table_node_initial = gcc_jit_function_new_block(query_function,
                                                                 "TableNodeInitial");

  // Loop condition.
  gcc_jit_block *table_node_loop_cond =
      gcc_jit_function_new_block(query_function, "TableNodeLoopCond");

  // Loop body
  gcc_jit_block *table_node_loop_body = gcc_jit_function_new_block(query_function, "TableNodeLoopBody");

  // Loop body-end
  gcc_jit_block *table_node_loop_body_end = gcc_jit_function_new_block(query_function, "TableNodeLoopBodyEnd");

  // Loop exit
  gcc_jit_block *table_node_loop_exit = gcc_jit_function_new_block(query_function, "TableNodeLoopExit");

  gcc_jit_type *int64_type =  gcc_jit_context_get_type(context,
                                                       GCC_JIT_TYPE_LONG_LONG);

  // Intial block actions.
  gcc_jit_lvalue *tuple_id = gcc_jit_function_new_local(query_function, nullptr, int64_type, "tuple_id");
  gcc_jit_block_add_assignment(table_node_initial,
                               nullptr,
                               tuple_id,
                               gcc_jit_context_zero(context, int64_type));

  gcc_jit_lvalue *total_num_tuples = gcc_jit_function_new_local(query_function,
                                                                nullptr,
                                                                int64_type,
                                                                "total_num_tuples");
  gcc_jit_block_add_assignment(table_node_initial,
                               nullptr,
                               total_num_tuples,
                               gcc_jit_context_new_rvalue_from_long(context,
                                                                    int64_type,
                                                                    getNumTuples()));

  gcc_jit_type *int64_pointer_type = gcc_jit_type_get_pointer(int64_type);
  gcc_jit_rvalue *column_begin = gcc_jit_context_new_rvalue_from_ptr(context, int64_pointer_type, m_data);
  gcc_jit_lvalue *value = gcc_jit_context_new_array_access(context,
                                                           nullptr,
                                                           column_begin,
                                                           gcc_jit_lvalue_as_rvalue(tuple_id));

  // Loop condition actions.
  gcc_jit_rvalue *loop_guard = gcc_jit_context_new_comparison(
      context,
      nullptr,
      GCC_JIT_COMPARISON_GE,
      gcc_jit_lvalue_as_rvalue(tuple_id),
      gcc_jit_lvalue_as_rvalue(total_num_tuples));

  gcc_jit_block_end_with_conditional(table_node_loop_cond,
                                     nullptr,
                                     loop_guard,
                                     table_node_loop_exit,
                                     table_node_loop_body);

  // Loop body actions.
  gcc_jit_block *table_node_parent_begin =
      gcc_jit_function_new_block(query_function, "Parent1Begin");

  gcc_jit_block_end_with_jump(table_node_loop_body, nullptr,
                              table_node_parent_begin);

  gcc_jit_block *table_node_parent_end =
      gcc_jit_function_new_block(query_function, "ParentEnd1");

  gcc_jit_block_end_with_jump(table_node_parent_end, nullptr,
                              table_node_loop_body_end);

  gcc_jit_block_add_assignment_op(table_node_loop_body_end,
                                  nullptr,
                                  tuple_id,
                                  GCC_JIT_BINARY_OP_PLUS,
                                  gcc_jit_context_one(context, int64_type));

  // Goto loop condition.
  gcc_jit_block_end_with_jump(table_node_loop_body_end,
                              nullptr,
                              table_node_loop_cond);



  // Modify the scope.
  scope->setCurrentValue(gcc_jit_lvalue_as_rvalue(value));
  scope->setCurrentEvalBlock(table_node_parent_begin);
  scope->setCurrentExitBlock(table_node_parent_end);
  scope->setQueryInitBlock(table_node_initial);
  scope->setQueryExitBlock(table_node_loop_exit);

  // Call parent.
  getParent()->codegen(context, scope);


  gcc_jit_block_end_with_jump(table_node_initial, nullptr, table_node_loop_cond);

  // Loop end actions.
  gcc_jit_block_end_with_void_return(table_node_loop_exit, nullptr);

}

void TableNode::open() {
  m_iterator_index = 0;
}

int64_t* TableNode::next() {
  return &m_data[m_iterator_index++];
}

bool TableNode::hasNext() {
  return m_iterator_index < m_num_tuples;
}

}
