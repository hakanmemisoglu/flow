add_library(flow_graph_queryscope
  query_scope.cpp
  query_scope.hpp)

add_library(flow_graph_node
  node.cpp
  node.hpp)

add_library(flow_graph_aggregatenode
  aggregate_node.cpp
  aggregate_node.hpp)

add_library(flow_graph_nullarynode
  nullary_node.cpp
  nullary_node.hpp)
target_link_libraries(flow_graph_nullarynode
  flow_graph_node)

add_library(flow_graph_unarynode
  unary_node.cpp
  unary_node.hpp)
target_link_libraries(flow_graph_unarynode
  flow_graph_node)

add_library(flow_graph_binarynode
  binary_node.cpp
  binary_node.hpp)

add_library(flow_graph_sourcenode
  source_node.cpp
  source_node.hpp)

add_library(flow_graph_filternode
  filter_node.cpp
  filter_node.hpp)
target_link_libraries(flow_graph_filternode
  flow_graph_unarynode
  flow_expressions_expression
  flow_expressions_filterexpression)

add_library(flow_graph_tablenode
  table_node.cpp
  table_node.hpp)
target_link_libraries(flow_graph_tablenode
  flow_graph_nullarynode
  flow_graph_queryscope
  gccjit)

add_library(flow_graph_printnode
  print_node.cpp
  print_node.hpp)
target_link_libraries(flow_graph_printnode
  flow_graph_unarynode
  flow_graph_node)

add_executable(nodes_test
  tests/nodes_test.cpp)
target_link_libraries(nodes_test
  flow_graph_aggregatenode
  flow_graph_tablenode
  flow_graph_filternode
  flow_graph_printnode
  flow_expressions_filterexpression
  flow_expressions_constantexpression
  flow_expressions_variableexpression
  flow_expressions_lessthanexpression
  flow_expressions_additionexpression
  gccjit)

add_executable(interpreter_test
  tests/interpreter_test.cpp)
target_link_libraries(interpreter_test
  flow_graph_aggregatenode
  flow_graph_tablenode
  flow_graph_filternode
  flow_graph_printnode
  flow_expressions_filterexpression
  flow_expressions_constantexpression
  flow_expressions_variableexpression
  flow_expressions_lessthanexpression
  flow_expressions_additionexpression)
