cmake_minimum_required(VERSION 3.20)
project(Cpp1103)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cpp1103 User/main.cpp User/Huffman_Tree.cpp Header/Huffman_Tree.h)
