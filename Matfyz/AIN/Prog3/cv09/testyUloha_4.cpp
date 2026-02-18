// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "2_Subtitles.h"
#include "4_Operators.h"

using namespace ::testing;

//Uloha 4.
TEST(TestFourthTask, NumberOfSubtitles) {
    Subtitles allSubtitles;
    allSubtitles.readFromFile("subtitles.srt");
    ASSERT_EQ("2\n00:02:51,468 --> 00:02:55,068\nFire the arrows!\nNow!", allSubtitles.getSubtitleText(2));
    ASSERT_EQ("5\n01:08:04,107 --> 01:08:10,007\nAbout him cast her night-dark hair", allSubtitles.getSubtitleText(5));
    ASSERT_EQ("22\n01:24:05,443 --> 01:24:09,443\nHear my voice...come back to the light.", allSubtitles.getSubtitleText(22));
    ASSERT_EQ("", allSubtitles.getSubtitleText(-7));
    ASSERT_EQ("", allSubtitles.getSubtitleText(23));
}

TEST(TestFourthTask, GoodSum) {
    Time time1;
    std::istringstream is("05:33:21,510");
    is >> time1;
    Time time2;
    std::istringstream is2("05:33:21,510");
    is2 >> time2;
    Time cas3;
    cas3 = time1 + time2;
    ASSERT_EQ("11:06:43,020", cas3.getTime());
}
TEST(TestFourthTask, SameAdd) {
    Time time1;
    std::istringstream is("05:33:21,510");
    is >> time1;
    time1 = time1 + time1;
    ASSERT_EQ("11:06:43,020", time1.getTime());
}
TEST(TestFourthTask, ZeroSum) {
    Time time1;
    std::istringstream is("05:33:21,510");
    is >> time1;
    Time time2;
    std::istringstream is2("0:0:0,0");
    is2 >> time2;
    time2 = time1 + time2;
    ASSERT_EQ("05:33:21,510", time2.getTime());
}
TEST(TestFourthTask, SumTooHigh) {
    std::string vynimka;
    try {
        Time time1;
        std::istringstream is("15:33:21,510");
        is >> time1;
        Time time2;
        std::istringstream is2("08:33:54,510");
        is2 >> time2;
        time2 = time1 + time2;
    }
    catch (WrongTimeMove e) {
        vynimka = e.message();
    }
    ASSERT_EQ("Hour out of limits", vynimka);
}
TEST(TestFourthTask, Zeros) {
    Time time1;
    std::istringstream is("0:0:0,0");
    is >> time1;
    Time time2;
    std::istringstream is2("0:0:0,0");
    is2 >> time2;
    time1 = time2 + time1;
    ASSERT_EQ("00:00:00,000", time1.getTime());
}
TEST(TestFourthTask, Sum24) {
    std::string vynimka;
    try {
        Time time1;
        std::istringstream is("15:33:21,500");
        is >> time1;
        Time time2;
        std::istringstream is2("08:26:38,500");
        is2 >> time2;
        time1 = time2 + time1;
    }
    catch (WrongTimeMove e) {
        vynimka = e.message();
    }
    ASSERT_EQ("Hour out of limits", vynimka);
}
TEST(TestFourthTask, WrongTime) {
    std::string vynimka;
    try {
        Time time1;
        std::istringstream is("15:33:21,500");
        is >> time1;
        Time time2;
        std::istringstream is2("08:-26:38,500");
        is2 >> time2;
        time1 = time2 + time1;
    }
    catch (WrongTime e) {
        vynimka = e.message();
    }
    ASSERT_EQ("Minute out of limits", vynimka);
}

TEST(TestFourthTask, SubtractionNormal) {
    Time time1;
    std::istringstream is("15:33:21,500");
    is >> time1;
    Time time2;
    std::istringstream is2("5:35:44,721");
    is2 >> time2;
    time1 = time1 - time2;
    ASSERT_EQ("09:57:36,779", time1.getTime());
    time1 = time1 + time2;
    ASSERT_EQ("15:33:21,500", time1.getTime());
}
TEST(TestFourthTask, SubtractionSame) {
    Time time1;
    std::istringstream is("15:33:21,500");
    is >> time1;
    Time time2;
    std::istringstream is2("15:33:21,500");
    is2 >> time2;
    time1 = time1 - time2;
    ASSERT_EQ("00:00:00,000", time1.getTime());
}
TEST(TestFourthTask, SubtractionMore) {
    std::string vynimka;
    try {
        Time time1;
        std::istringstream is("15:33:21,500");
        is >> time1;
        Time time2;
        std::istringstream is2("15:33:21,501");
        is2 >> time2;
        time1 = time1 - time2;
    }
    catch (WrongTimeMove e) {
        vynimka = e.message();
    }
    ASSERT_EQ("Result of time subtraction is less than zero", vynimka);
}
TEST(TestFourthTask, SubtractionOfSame) {
    Time time1;
    std::istringstream is("15:33:21,500");
    is >> time1;
    time1 = time1 - time1;
    ASSERT_EQ("00:00:00,000", time1.getTime());
}
TEST(TestFourthTask, SubtractionFromZero) {
    std::string vynimka;
    try {
        Time time1;
        std::istringstream is("0:0:0,000");
        is >> time1;
        Time time2;
        std::istringstream is2("15:33:21,501");
        is2 >> time2;
        time1 = time1 - time2;
    }
    catch (WrongTimeMove e) {
        vynimka = e.message();
    }
    ASSERT_EQ("Result of time subtraction is less than zero", vynimka);
}

