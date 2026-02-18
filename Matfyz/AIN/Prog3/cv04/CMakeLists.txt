cmake_minimum_required(VERSION 3.6.2)
project(cvicenie4)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads)

set(SOURCE_FILES
        1_Elements.cpp
        2_GetNthWord.cpp
        3_GetItemsFromList.cpp
        4_SortWords.cpp
        5_SortByFunction.cpp

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
add_executable(cvicenie4 ${SOURCE_FILES})
target_link_libraries(cvicenie4 ${CMAKE_THREAD_LIBS_INIT})