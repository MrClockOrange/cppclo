cmake_minimum_required(VERSION 3.11)
project(cppclo)

set(CMAKE_CXX_STANDARD 17)

add_executable(cppclo main.cpp ClojExp.cpp ClojExp.h ClojFunc.cpp ClojFunc.h)
add_executable(cppcotest test.cpp ClojExp.cpp ClojExp.h ClojFunc.cpp ClojFunc.h)