cmake_minimum_required(VERSION 3.20)
project(DL1203)

set(CMAKE_CXX_STANDARD 14)

add_executable(DL1203 User/main.cpp User/AdjacencyMat.cpp Header/AdjacencyMat.h User/AdjacencyList.cpp Header/AdjacencyList.h)
