cmake_minimum_required(VERSION 3.6.2)
set(PROJECT_NAME skuska_2025_01_09)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

find_package(Threads)

set(SOURCE_FILES
        1_Project.cpp
        2_Employee.cpp
        3_Company.cpp
        4_StartupList.cpp
        5_LoadFromFile.cpp

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
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/startuplist.txt
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM)
