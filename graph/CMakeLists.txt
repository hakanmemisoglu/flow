add_library(flow_graph_node
  node.cpp
  node.hpp)

add_library(flow_graph_nullarynode
  nullary_node.cpp
  nullary_node.hpp)

add_library(flow_graph_unarynode
  unary_node.cpp
  unary_node.hpp)

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
  flow_expressions_expression)
