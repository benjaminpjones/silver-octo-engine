cmake_minimum_required(VERSION 3.10)

project(MicrosoftQuestions)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(../include)

add_executable(LinkNodesTest link_nodes_test.cpp)
