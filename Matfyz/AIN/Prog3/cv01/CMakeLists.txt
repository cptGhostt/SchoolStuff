cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 17)
project(cvicenie1)

find_package(Threads)

set(SOURCE_FILES
        getText.cpp
        isDecimalNumber.cpp
        numberOfOccurrences.cpp

        testyUloha_1.cpp
        testyUloha_2.cpp
        testyUloha_3.cpp
        testyUloha_4.cpp
        testyUloha_5.cpp

        GoogleTest/gtest-death-test.cc
        GoogleTest/gtest-filepath.cc
        GoogleTest/gtest-port.cc
        GoogleTest/gtest-printers.cc
        GoogleTest/gtest-test-part.cc
        GoogleTest/gtest-typed-test.cc
        GoogleTest/gtest.cc
        GoogleTest/gtest_main.cc)

include_directories(GoogleTest)
add_executable(cvicenie1 ${SOURCE_FILES})
target_link_libraries(cvicenie1 ${CMAKE_LIBS_INIT} ${CMAKE_THREAD_LIBS_INIT})