cmake_minimum_required(VERSION 3.17)
project(Implementation_of_Dijkstra)

set(CMAKE_CXX_STANDARD 14)

add_executable(Implementation_of_Dijkstra main.cpp Edge.h SparseGraph.h DenseGraph.h IndexMinHeap.h ReadGraph.h Dijkstra.h)