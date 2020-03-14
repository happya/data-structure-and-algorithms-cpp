cmake_minimum_required(VERSION 3.13)
project(SortAlgo)

set(CMAKE_CXX_STANDARD 14)

add_executable(SortAlgo main.cpp Sort.h AlgoData.h SelectionSort.h InsertionSort.h MergeSort.h QuickSort.h HeapSort.h SortAlgorithms.h)