cmake_minimum_required(VERSION 3.17)
project(Graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graph main.cpp DenseGraph.h SparseGraph.h ReadGraph.h Components.h Path.h ShortestPath.h)