cmake_minimum_required(VERSION 3.6.2)
set(TARGET_NAME exercise11)
project(${TARGET_NAME})

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        0_Phrase.cpp
        0_Line.cpp
        0_Song.cpp
        1_Chords.cpp
        2_SongBook.cpp
        3_GetSong.cpp
        4_AddSongBook.cpp
        5_Musician.cpp
        )

set(TEST_FILES
        testyUloha_0.cpp
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

add_custom_command(TARGET exercise11 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/Where_the_wild_roses_grow.txt
        ${CMAKE_SOURCE_DIR}/Suzanne.txt
        ${CMAKE_SOURCE_DIR}/We_No_Who_U_R.txt
        ${CMAKE_SOURCE_DIR}/Hello.txt
        $<TARGET_FILE_DIR:exercise11>
        VERBATIM)
