// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "2_Subtitles.h"

using namespace ::testing;

TEST(TestThirdTask, NoFile) {
  Subtitles allSubtitles;
  ASSERT_FALSE(allSubtitles.readFromFile("no.srt"));
}

TEST(TestThirdTask, NumberOfSubtitles) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitles.srt");
  ASSERT_EQ(22, allSubtitles.getNumberOfSubtitles());
  allSubtitles.clearAllSubtitles();
  ASSERT_EQ(0, allSubtitles.getNumberOfSubtitles());
}

TEST(TestThirdTask, PrvyTitulok) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitles.srt");
  ASSERT_EQ("00:02:51,370", allSubtitles.getSubtitle(1).getEndTime());
}
TEST(TestThirdTask, PrvyTitulokPoradie) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitles.srt");
  ASSERT_EQ(1, allSubtitles.getSubtitle(1).getSubtitleNumber());
}
TEST(TestThirdTask, riadok21) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitles.srt");
  ASSERT_EQ("01:22:56,449", allSubtitles.getSubtitle(21).getBeginTime());
}
TEST(TestThirdTask, zapornyTitulok) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitles.srt");
  ASSERT_EQ("00:00:00,000", allSubtitles.getSubtitle(-4).getBeginTime());
}
TEST(TestThirdTask, neexistujuciRiadok) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitles.srt");
  ASSERT_EQ("00:00:00,000", allSubtitles.getSubtitle(201).getBeginTime());
}
TEST(TestThirdTask, PoslednyRiadokKoniec) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitles.srt");
  ASSERT_EQ("01:24:09,443", allSubtitles.getSubtitle(22).getEndTime());
}
TEST(TestThirdTask, PoslednyRiadokText) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitles.srt");
  ASSERT_EQ("Hear my voice...come back to the light.", allSubtitles.getSubtitle(22).getTextRow(0));
  ASSERT_EQ("Ride fast Asfaloth!", allSubtitles.getSubtitle(15).getTextRow(0));
}
TEST(TestThirdTask, PoslednyRiadokText2) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitles.srt");
  ASSERT_EQ("", allSubtitles.getSubtitle(22).getTextRow(2));
}
TEST(TestThirdTask, PoslednyRiadokText5) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitles.srt");
  ASSERT_EQ("", allSubtitles.getSubtitle(22).getTextRow(5));
}
TEST(TestThirdTask, PocetTitulkovMatrix) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("The_Matrix.srt");
  ASSERT_EQ(1343, allSubtitles.getNumberOfSubtitles());
}
TEST(TestThirdTask, PrvyTitulokMatrix) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("The_Matrix.srt");
  ASSERT_EQ("00:00:52,595", allSubtitles.getSubtitle(1).getEndTime());
  ASSERT_EQ("- You're not to relieve me.</i>", allSubtitles.getSubtitle(1).getTextRow(1));
  ASSERT_EQ(2, allSubtitles.getSubtitle(1).getSubtitleNumber());
}
TEST(TestThirdTask, LastLine) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("The_Matrix.srt");
  ASSERT_EQ("<i>...is a choice I leave to you.</i>", allSubtitles.getSubtitle(1343).getTextRow(0));
}

TEST(TestThirdTask, MatrixText317) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("The_Matrix.srt");
  ASSERT_EQ("You take the blue pill...", allSubtitles.getSubtitle(316).getTextRow(0));
  ASSERT_EQ(317, allSubtitles.getSubtitle(316).getSubtitleNumber());
}
TEST(TestThirdTask, NacitajZleTitulky) {
  Subtitles allSubtitles;
  allSubtitles.readFromFile("subtitlesWithWrong.srt");
  ASSERT_EQ(16, allSubtitles.getNumberOfSubtitles());
}

TEST(TestThirdTask, NacitajTitulky) {
  Subtitles allSubtitles;
  ASSERT_TRUE(allSubtitles.readFromFile("subtitlesWithWrong.srt"));
}

TEST(TestThirdTask, ZapisDoSuboru) {
    Subtitles allSubtitles;
    allSubtitles.readFromFile("subtitles.srt");
    ASSERT_EQ(22, allSubtitles.getNumberOfSubtitles());
    ASSERT_TRUE(allSubtitles.saveToFile("subtitles1.srt"));
    Subtitles allSubtitles1;
    allSubtitles1.readFromFile("subtitles1.srt");
    ASSERT_EQ(22, allSubtitles1.getNumberOfSubtitles());
}

TEST(TestThirdTask, ZapisDoSuboruDvakrat) {
    Subtitles allSubtitles;
    allSubtitles.readFromFile("subtitlesWithWrong.srt");
    ASSERT_EQ(16, allSubtitles.getNumberOfSubtitles());
    ASSERT_TRUE(allSubtitles.saveToFile("subtitlesWithWrong1.srt"));
    Subtitles allSubtitles1;
    allSubtitles1.readFromFile("subtitlesWithWrong1.srt");
    ASSERT_EQ(16, allSubtitles1.getNumberOfSubtitles());
}
