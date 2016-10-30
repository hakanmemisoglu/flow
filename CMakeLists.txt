cmake_minimum_required(VERSION 2.8)
project(flow)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(graph)
add_subdirectory(expressions)
