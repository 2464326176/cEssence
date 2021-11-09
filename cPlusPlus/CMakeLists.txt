cmake_minimum_required(VERSION 3.13)
project(cplus)

set(CMAKE_CXX_STANDARD 11)

add_executable(cplus main.cpp typeunit/type.h test/test.cpp stl/vectornew/vector.cpp stl/stl.cpp stl/knowledge.h)