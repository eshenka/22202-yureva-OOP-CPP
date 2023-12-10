cmake_minimum_required(VERSION 3.26)
project(task1)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Google_tests)
add_executable(task1
        main.cpp
        BitArray.h
        BitArray.cpp
        BitArrayException.h)
