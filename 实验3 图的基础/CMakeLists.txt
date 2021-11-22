cmake_minimum_required(VERSION 3.20)
project(DL1116)

set(CMAKE_CXX_STANDARD 20)

add_executable(DL1116 User/main.cpp User/AdjacencyList.cpp Header/AdjacencyList.h User/AdjacencyMat.cpp Header/AdjacencyMat.h Header/test.h)
