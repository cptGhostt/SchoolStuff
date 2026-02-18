cmake_minimum_required(VERSION 3.6.2)

set(TARGET_NAME exercise7)
project(${TARGET_NAME})

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        1_VeryLargeInteger.cpp
        2_Constructors.cpp
        3_OperatorMethods.cpp
        4_OperatorFunctions.cpp
        5_MinMax.cpp
)

set(TEST_FILES
        testyUloha_1.cpp
        testyUloha_2.cpp
        testyUloha_3.cpp
        testyUloha_4.cpp
        testyUloha_5.cpp
)

set(GTEST_SOURCE_FILES
        GoogleTest/gtest-death-test.cc
        GoogleTest/gtest-filepath.cc
        GoogleTest/gtest-port.cc
        GoogleTest/gtest-printers.cc
        GoogleTest/gtest-test-part.cc
        GoogleTest/gtest-typed-test.cc
        GoogleTest/gtest.cc
        GoogleTest/gtest_main.cc)

add_library(tests OBJECT ${TEST_FILES})
add_library(gtest OBJECT ${GTEST_SOURCE_FILES})

find_package(Threads REQUIRED)

include_directories(GoogleTest)
add_executable(${TARGET_NAME} ${SOURCE_FILES} ${TEST_FILES} ${GTEST_SOURCE_FILES})
target_link_libraries(${TARGET_NAME} ${CMAKE_THREAD_LIBS_INIT})
