#include "graph/table_node.hpp"

#include <libgccjit.h>

#include "graph/nullary_node.hpp"

namespace flow {

TableNode::TableNode(const std::string &name,
                     const std::string &table_name)
  : NullaryNode(name),
    m_table_name(table_name) {
}

void TableNode::codegen() {
  // Initial block.
  gcc_jit_block *table_node_initial = gcc_jit_function_new_block(query_function,
                                                                 "TableNodeInitial");

  gcc_jit_type *int64_type =  gcc_jit_context_get_type(jit_context,
                                                       GCC_JIT_TYPE_LONG_LONG);
  gcc_jit_block_add_assignment(table_node_initial,
                               nullptr,
                               tuple_id,
                               gcc_jit_context_zero(jit_context, int64_type));

  // Loop condition.
  gcc_jit_block *table_node_loop_cond =
      gcc_jit_function_new_block(query_function, "TableNodeLoopCond");


}

}
