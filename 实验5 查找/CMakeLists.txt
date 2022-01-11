cmake_minimum_required(VERSION 3.21)
project(DL1216)

set(CMAKE_CXX_STANDARD 20)

add_executable(DL1216 User/main.cpp Header/Binary_search.h User/BinarySortTree.cpp Header/BinarySortTree.h Header/Hash.h)
