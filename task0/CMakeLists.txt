cmake_minimum_required(VERSION 3.26)
project(task0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -mavx2")

add_executable(task0 main.cpp
        FileReader.cpp
        FileReader.h
        CSVFileWriter.cpp
        CSVFileWriter.h
        Parser.cpp
        Parser.h
        DataStorage.cpp
        DataStorage.h)
