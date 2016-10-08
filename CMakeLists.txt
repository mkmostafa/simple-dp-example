cmake_minimum_required(VERSION 2.8)

project(recursion LANGUAGES CXX)

add_executable(recursion recursion.cpp)
target_compile_options(recursion PRIVATE -std=c++11 -g)
set_target_properties(recursion PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../)

