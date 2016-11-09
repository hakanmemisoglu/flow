set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgccjit")

add_library(flow_expressions_scope
  scope.cpp
  scope.hpp)

add_library(flow_expressions_operator
  operator.cpp
  operator.hpp)

add_library(flow_expressions_expression
  expression.cpp
  expression.hpp)
target_link_libraries(flow_expressions_expression
  flow_expressions_scope
  flow_expressions_operator)

add_library(flow_expressions_binaryexpression
  binary_expression.cpp
  binary_expression.hpp)
target_link_libraries(flow_expressions_binaryexpression
  flow_expressions_expression)

add_library(flow_expressions_unaryexpression
  unary_expression.cpp
  unary_expression.hpp)
target_link_libraries(flow_expressions_unaryexpression
  flow_expressions_expression)

add_library(flow_expressions_nullaryexpression
  nullary_expression.cpp
  nullary_expression.hpp)
target_link_libraries(flow_expressions_unaryexpression
  flow_expressions_expression)

add_library(flow_expressions_additionexpression
  addition_expression.cpp
  addition_expression.hpp)
target_link_libraries(flow_expressions_additionexpression
  flow_expressions_binaryexpression
  flow_expressions_expression
  flow_expressions_operator)

add_library(flow_expressions_subtractionexpression
  subtraction_expression.cpp
  subtraction_expression.hpp)
target_link_libraries(flow_expressions_subtractionexpression
  flow_expressions_binaryexpression
  flow_expressions_expression
  flow_expressions_operator)

add_library(flow_expressions_multiplicationexpression
  multiplication_expression.cpp
  multiplication_expression.hpp)
target_link_libraries(flow_expressions_multiplicationexpression
  flow_expressions_binaryexpression
  flow_expressions_expression
  flow_expressions_operator)

add_library(flow_expressions_equalexpression
  equal_expression.cpp
  equal_expression.hpp)
target_link_libraries(flow_expressions_equalexpression
  flow_expressions_binaryexpression
  flow_expressions_expression
  flow_expressions_operator)

add_library(flow_expressions_greaterthanexpression
  greaterthan_expression.cpp
  greaterthan_expression.hpp)
target_link_libraries(flow_expressions_greaterthanexpression
  flow_expressions_binaryexpression
  flow_expressions_expression
  flow_expressions_operator)

add_library(flow_expressions_lessthanexpression
  lessthan_expression.cpp
  lessthan_expression.hpp)
target_link_libraries(flow_expressions_lessthanexpression
  flow_expressions_binaryexpression
  flow_expressions_expression
  flow_expressions_operator)

add_library(flow_expressions_value
  value.cpp
  value.hpp)

add_library(flow_expressions_constantexpression
  constant_expression.cpp
  constant_expression.hpp)
target_link_libraries(flow_expressions_constantexpression
  flow_expressions_value
  flow_expressions_nullaryexpression)

add_library(flow_expressions_parameterexpression
  parameter_expression.cpp
  parameter_expression.hpp)
target_link_libraries(flow_expressions_parameterexpression
  flow_expressions_expression
  flow_expressions_operator)

add_library(flow_expressions_filterexpression
  filter_expression.cpp
  filter_expression.hpp)
target_link_libraries(flow_expressions_filterexpression
  flow_expressions_expression
  flow_expressions_parameterexpression)

add_library(flow_expressions_variableexpression
  variable_expression.cpp
  variable_expression.hpp)

add_executable(expression_test
  tests/expression_test.cpp)
target_link_libraries(expression_test
  flow_expressions_value
  flow_expressions_constantexpression
  flow_expressions_expression
  flow_expressions_additionexpression
  flow_expressions_subtractionexpression
  flow_expressions_parameterexpression
  flow_expressions_filterexpression
  flow_expressions_lessthanexpression
  flow_expressions_variableexpression)
