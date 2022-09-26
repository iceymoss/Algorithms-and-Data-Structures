cmake_minimum_required(VERSION 3.17)
project(Minimum_Span_Trees)

set(CMAKE_CXX_STANDARD 14)

add_executable(Minimum_Span_Trees main.cpp Edge.h DenseGraph.h ReadGraph.h SparseGraph.h MinHeap.h LazyPrimMST.h IndexMinHeap.h)