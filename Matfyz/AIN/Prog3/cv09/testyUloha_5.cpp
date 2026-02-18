// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "4_Operators.h"

using namespace ::testing;

//Uloha 5
TEST(TestFifthTask, SubtractAllOneSecond) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitles.srt");
  ASSERT_EQ("01:07:56,409", allSubtitles.getSubtitle(4).getBeginTime());
  ASSERT_EQ("4\n01:07:56,409 --> 01:08:02,709\nImmortal maiden elven-wise", allSubtitles.getSubtitleText(4));
  ASSERT_EQ("22\n01:24:05,443 --> 01:24:09,443\nHear my voice...come back to the light.", allSubtitles.getSubtitleText(22));
  Time shift;
  std::istringstream is("0:0:1,000");
  is >> shift;
  allSubtitles.shitfSubtitlesTimeDown(shift);
  ASSERT_EQ("4\n01:07:55,409 --> 01:08:01,709\nImmortal maiden elven-wise", allSubtitles.getSubtitleText(4));
  ASSERT_EQ("22\n01:24:04,443 --> 01:24:08,443\nHear my voice...come back to the light.", allSubtitles.getSubtitleText(22));
}

TEST(TestFifthTask, ZapisDoSuboru) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitles.srt");
  Time shift;
  std::istringstream is("0:0:0,100");
  is >> shift;
  allSubtitles.shitfSubtitlesTimeDown(shift);
  ASSERT_TRUE(allSubtitles.saveToFile("titulkyDown01.srt"));
  Subtitles allSubtitles1;
  allSubtitles1.readFromFile("titulkyDown01.srt");
  ASSERT_EQ(22, allSubtitles1.getNumberOfSubtitles());
}

TEST(TestFifthTask, AddOneMinute) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitles.srt");
  ASSERT_EQ("01:07:56,409", allSubtitles.getSubtitle(4).getBeginTime());
  ASSERT_EQ("01:24:05,443", allSubtitles.getSubtitle(22).getBeginTime());
  Time shift;
  std::istringstream is("0:1:11,111");
  is >> shift;
  allSubtitles.shitfSubtitlesTimeUp(shift);
  ASSERT_EQ("01:09:07,520", allSubtitles.getSubtitle(4).getBeginTime());
  ASSERT_EQ("01:25:20,554", allSubtitles.getSubtitle(22).getEndTime());
}

TEST(TestFifthTask, AddTooMuch) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitles.srt");
  Time shift;
  std::istringstream is("22:45:13,500");
  is >> shift;
  allSubtitles.shitfSubtitlesTimeUp(shift);
  ASSERT_EQ(6, allSubtitles.getNumberOfSubtitles());
}

TEST(TestFifthTask, AddZapisDoSuboru) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitles.srt");
  Time shift;
  std::istringstream is("1:1:1,100");
  is >> shift;
  allSubtitles.shitfSubtitlesTimeUp(shift);
  ASSERT_TRUE(allSubtitles.saveToFile("titulkyUp1.srt"));
  Subtitles allSubtitles1;
  allSubtitles1.readFromFile("titulkyUp1.srt");
  ASSERT_EQ(22, allSubtitles1.getNumberOfSubtitles());
}

TEST(TestFifthTask, ShiftDown15) {
    Subtitles allSubtitles;
    allSubtitles.readFromFile("subtitles.srt");
    Time shift;
    std::istringstream is("1:22:01,100");
    is >> shift;
    allSubtitles.shitfSubtitlesTimeDown(shift);
    ASSERT_EQ(7, allSubtitles.getNumberOfSubtitles());
    ASSERT_EQ("Waters of the Misty Mountains...", allSubtitles.getSubtitle(1).getTextRow(0));
    ASSERT_TRUE(allSubtitles.saveToFile("subtitlesLess.srt"));
    Subtitles allSubtitles1;
    allSubtitles1.readFromFile("subtitlesLess.srt");
    ASSERT_EQ(7, allSubtitles1.getNumberOfSubtitles());
    ASSERT_EQ("Hear my voice...come back to the light.", allSubtitles.getSubtitle(7).getTextRow(0));
}

TEST(TestFifthTask, ShiftDown8) {
    Subtitles allSubtitles;
    allSubtitles.readFromFile("subtitles.srt");
    Time shift;
    std::istringstream is("1:19:52,100");
    is >> shift;
    allSubtitles.shitfSubtitlesTimeDown(shift);
    ASSERT_EQ(14, allSubtitles.getNumberOfSubtitles());
    ASSERT_EQ("00:00:02,861", allSubtitles.getSubtitle(1).getBeginTime());
    ASSERT_EQ("Stay with the Hobbits, l-ll send horses for you.", allSubtitles.getSubtitle(1).getTextRow(0));
}

TEST(TestFifthTask, ShiftDown) {
    Subtitles allSubtitles;
    allSubtitles.readFromFile("subtitles.srt");
    ASSERT_EQ(22, allSubtitles.getNumberOfSubtitles());
    Time shift;
    std::istringstream is("1:23:1,100");
    is >> shift;
    allSubtitles.shitfSubtitlesTimeDown(shift);
    ASSERT_EQ(1, allSubtitles.getNumberOfSubtitles());
}

TEST(TestFifthTask, ShiftUnderZero) {
    Subtitles allSubtitles;
    allSubtitles.readFromFile("subtitles.srt");
    ASSERT_EQ(22, allSubtitles.getNumberOfSubtitles());
    Time shift;
    std::istringstream is("1:1:1,100");
    is >> shift;
    allSubtitles.shitfSubtitlesTimeDown(shift);
    ASSERT_EQ(20, allSubtitles.getNumberOfSubtitles());
    ASSERT_TRUE(allSubtitles.saveToFile("subtitles1.srt"));
    Subtitles allSubtitles1;
    allSubtitles1.readFromFile("subtitles1.srt");
    ASSERT_EQ(20, allSubtitles1.getNumberOfSubtitles());
}
