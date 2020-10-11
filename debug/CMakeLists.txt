cmake_minimum_required(VERSION 3.13)
project(debug)

set(CMAKE_CXX_STANDARD 11)

add_executable(debug main.cpp DebugNew.h TraceNew.cpp TraceNew.h)