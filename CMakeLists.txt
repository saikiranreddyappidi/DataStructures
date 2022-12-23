cmake_minimum_required(VERSION 3.23)
project(DataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructures Pratice/main.c Pratice/BinarySearch.c)

add_executable(LinearSearch Pratice/LinearSearch.c)
add_executable(BinarySearch Pratice/BinarySearch.c)