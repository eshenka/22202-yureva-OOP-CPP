project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_tests_run
        Parser_test.cpp
        ../Parser.h
        ../Parser.cpp
        FileReader_test.cpp
        ../FileReader.h
        ../FileReader.cpp
        DataStorage_test.cpp
        ../DataStorage.h
        ../DataStorage.cpp
        CSVFileWriter_test.cpp
        ../CSVFileWriter.h
        ../CSVFileWriter.cpp)

target_link_libraries(Google_tests_run gtest gtest_main)