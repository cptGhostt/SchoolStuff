cmake_minimum_required(VERSION 3.6.2)

set(TARGET_NAME exercise9)
project(${TARGET_NAME})

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        1_Time.cpp
        2_Subtitle.cpp
        2_Subtitles.cpp
        3_ReadFile.cpp
        4_Operators.cpp
        5_Shift.cpp
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

add_custom_command(TARGET exercise9 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/subtitles.srt
        ${CMAKE_SOURCE_DIR}/subtitlesWithWrong.srt
        ${CMAKE_SOURCE_DIR}/The_Matrix.srt
        $<TARGET_FILE_DIR:exercise9>
        VERBATIM)
