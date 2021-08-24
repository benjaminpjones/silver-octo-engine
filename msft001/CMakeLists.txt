cmake_minimum_required(VERSION 3.10)

project(LinkNodes)

# specify the C++ standard. 17 necessary because of use of std::optional
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(../include)

add_executable(LinkNodesTest link_nodes_test.cpp)
