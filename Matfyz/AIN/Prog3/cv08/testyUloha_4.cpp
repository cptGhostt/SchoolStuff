// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "3_Subtitles.h"

using namespace ::testing;

TEST(TestFourthTask, VsetkyTitulky) {
    const std::string mojTitulok {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
        "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
    const std::string mojTitulok2 {"124\n00:03:56,211 --> 00:04:06,123\nTo je riadokTitulku 2."
        "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
    const std::string mojTitulok3 {"125\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 3."
        "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
    const std::string mojTitulok4 {"126\n06:02:16,488 --> 06:02:18,637\nTo je riadokTitulku 4."
        "\nTo je riadokTitulku 41.\nTo je riadokTitulku 42."};

    Subtitles vsetkyTitulky;
    vsetkyTitulky.putSubtitle(mojTitulok);
    vsetkyTitulky.putSubtitle(mojTitulok2);
    vsetkyTitulky.putSubtitle(mojTitulok3);
    vsetkyTitulky.putSubtitle(mojTitulok4);
    ASSERT_EQ(4, vsetkyTitulky.getNumberOfSubtitles());
    vsetkyTitulky.nextSubtitle(1);
    ASSERT_EQ(124, vsetkyTitulky.currentSubtitle().getSubtitleNumber());
    vsetkyTitulky.nextSubtitle(2);
    ASSERT_EQ("06:02:18,637", vsetkyTitulky.currentSubtitle().getEndTime());
}

TEST(TestFourthTask, NastavNaZaciatokCas) {
    const std::string mojTitulok {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
        "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
    const std::string mojTitulok2 {"124\n00:03:56,211 --> 00:04:06,123\nTo je riadokTitulku 2."
        "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
    const std::string mojTitulok3 {"125\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 3."
        "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
    const std::string mojTitulok4 {"126\n06:02:16,488 --> 06:02:18,637\nTo je riadokTitulku 4."
        "\nTo je riadokTitulku 41.\nTo je riadokTitulku 42."};
    Subtitles allSubtitles;
    allSubtitles.putSubtitle(mojTitulok);
    allSubtitles.putSubtitle(mojTitulok2);
    allSubtitles.putSubtitle(mojTitulok3);
    allSubtitles.putSubtitle(mojTitulok4);
    ASSERT_EQ("00:02:16,488", allSubtitles.currentSubtitle().getBeginTime());
    ASSERT_EQ("To je riadokTitulku 1.", allSubtitles.currentSubtitle().getTextRow(1));
    ASSERT_EQ("To je riadokTitulku 12.", allSubtitles.currentSubtitle().getTextRow(3));
    allSubtitles.nextSubtitle(3);
    ASSERT_EQ("06:02:16,488", allSubtitles.currentSubtitle().getBeginTime());
    ASSERT_EQ("To je riadokTitulku 42.", allSubtitles.currentSubtitle().getTextRow(3));
    allSubtitles.eraseAll();
    ASSERT_EQ(0, allSubtitles.getNumberOfSubtitles());
    allSubtitles.putSubtitle(mojTitulok2);
    allSubtitles.putSubtitle(mojTitulok3);
    ASSERT_EQ(2, allSubtitles.getNumberOfSubtitles());
}

TEST(TestFourthTask, NastavNaKoniec) {
    const std::string mojTitulok {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
        "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
    const std::string mojTitulok2 {"124\n00:03:56,211 --> 00:04:06,123\nTo je riadokTitulku 2."
        "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
    const std::string mojTitulok3 {"125\n00:05:21,333 --> 00:05:58,437\nTo je riadokTitulku 3."
        "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
    Subtitles vsetkyTitulky;
    vsetkyTitulky.putSubtitle(mojTitulok);
    vsetkyTitulky.putSubtitle(mojTitulok3);
    vsetkyTitulky.putSubtitle(mojTitulok2);
    int pocetTitulkov = vsetkyTitulky.getNumberOfSubtitles();
    ASSERT_EQ(3, vsetkyTitulky.getNumberOfSubtitles());

    vsetkyTitulky.nextSubtitle(pocetTitulkov - 1);
    ASSERT_EQ("To je riadokTitulku 21.", vsetkyTitulky.currentSubtitle().getTextRow(2));
    ASSERT_EQ("00:03:56,211", vsetkyTitulky.currentSubtitle().getBeginTime());
}

TEST(TestFourthTask, NastavNaDruhy) {
    const std::string mojTitulok {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
        "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
    const std::string mojTitulok2 {"124\n00:03:56,211 --> 00:04:06,123\nTo je riadokTitulku 2."
        "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
    const std::string mojTitulok3 {"125\n00:05:21,333 --> 00:05:58,437\nTo je riadokTitulku 3."
        "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
    Subtitles vsetkyTitulky;
    vsetkyTitulky.putSubtitle(mojTitulok);
    vsetkyTitulky.putSubtitle(mojTitulok2);
    vsetkyTitulky.putSubtitle(mojTitulok3);

    vsetkyTitulky.nextSubtitle(2);
    ASSERT_EQ("00:05:58,437", vsetkyTitulky.currentSubtitle().getEndTime());
    ASSERT_EQ("To je riadokTitulku 31.", vsetkyTitulky.currentSubtitle().getTextRow(2));
}

TEST(TestFourthTask, deleteSubtitle) {
  const std::string mojTitulok {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
                                "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
  const std::string mojTitulok2 {"124\n00:03:56,211 --> 00:04:06,123\nTo je riadokTitulku 2."
                                 "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
  const std::string mojTitulok3 {"125\n00:05:21,333 --> 00:05:58,437\nTo je riadokTitulku 3."
                                 "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
  Subtitles vsetkyTitulky;
  vsetkyTitulky.putSubtitle(mojTitulok);
  vsetkyTitulky.putSubtitle(mojTitulok3);
  vsetkyTitulky.putSubtitle(mojTitulok2);
  ASSERT_EQ(3, vsetkyTitulky.getNumberOfSubtitles());
  vsetkyTitulky.deleteCurrentSubtitle();
  ASSERT_EQ(2, vsetkyTitulky.getNumberOfSubtitles());
  ASSERT_EQ("To je riadokTitulku 3.", vsetkyTitulky.currentSubtitle().getTextRow(1));
  vsetkyTitulky.nextSubtitle(1);
  vsetkyTitulky.deleteCurrentSubtitle();
  ASSERT_EQ(1, vsetkyTitulky.getNumberOfSubtitles());
  ASSERT_EQ("To je riadokTitulku 31.", vsetkyTitulky.currentSubtitle().getTextRow(2));
}

TEST(TestFourthTask, BackToFirst) {
    const std::string mojTitulok {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
                                  "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
    const std::string mojTitulok2 {"124\n00:03:56,211 --> 00:04:06,123\nTo je riadokTitulku 2."
                                   "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
    const std::string mojTitulok3 {"125\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 3."
                                   "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
    const std::string mojTitulok4 {"126\n06:02:16,488 --> 06:02:18,637\nTo je riadokTitulku 4."
                                   "\nTo je riadokTitulku 41.\nTo je riadokTitulku 42."};
    Subtitles vsetkyTitulky;
    vsetkyTitulky.putSubtitle(mojTitulok);
    vsetkyTitulky.putSubtitle(mojTitulok2);
    vsetkyTitulky.putSubtitle(mojTitulok3);
    vsetkyTitulky.putSubtitle(mojTitulok4);
    ASSERT_EQ(4, vsetkyTitulky.getNumberOfSubtitles());
    vsetkyTitulky.nextSubtitle(1);
    ASSERT_EQ(124, vsetkyTitulky.currentSubtitle().getSubtitleNumber());
    vsetkyTitulky.nextSubtitle(2);
    ASSERT_EQ("06:02:18,637", vsetkyTitulky.currentSubtitle().getEndTime());
    vsetkyTitulky.setFirstSubtitle();
    ASSERT_EQ(123, vsetkyTitulky.currentSubtitle().getSubtitleNumber());
    vsetkyTitulky.nextSubtitle(2);
    ASSERT_EQ("00:02:18,949", vsetkyTitulky.currentSubtitle().getEndTime());
}

