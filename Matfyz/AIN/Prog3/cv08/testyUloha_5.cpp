// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "3_Subtitles.h"

using namespace ::testing;

//Uloha 5.
TEST(TestFifthTask, CorrectNumberOrder) {
  const std::string mojTitulok {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
                                "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
  const std::string mojTitulok1 {"125\n00:02:19,488 --> 00:02:21,949\nTo je riadokTitulku 3."
                                 "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
  const std::string mojTitulok2 {"126\n00:03:56,211 --> 00:04:06,123\nTo je riadokTitulku 2."
                                 "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
  const std::string mojTitulok3 {"245\n00:04:16,488 --> 00:04:18,949\nTo je riadokTitulku 3."
                                 "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
  const std::string mojTitulok4 {"512\n06:05:16,488 --> 06:05:18,637\nTo je riadokTitulku 4."
                                 "\nTo je riadokTitulku 41.\nTo je riadokTitulku 42."};

  Subtitles vsetkyTitulky;
  vsetkyTitulky.putSubtitle(mojTitulok);
  vsetkyTitulky.putSubtitle(mojTitulok1);
  vsetkyTitulky.putSubtitle(mojTitulok2);
  vsetkyTitulky.putSubtitle(mojTitulok3);
  vsetkyTitulky.putSubtitle(mojTitulok4);
  ASSERT_EQ("", vsetkyTitulky.wrongSubtitlesOrder());
}

TEST(TestFifthTask, WrongTitleNumberOrder) {
  const std::string mojTitulok {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
                                "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
  const std::string mojTitulok1 {"125\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 3."
                                 "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
  const std::string mojTitulok2 {"124\n00:03:56,211 --> 00:04:06,123\nTo je riadokTitulku 2."
                                 "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
  const std::string mojTitulok3 {"125\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 3."
                                 "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
  const std::string mojTitulok4 {"121\n06:02:16,488 --> 06:02:18,637\nTo je riadokTitulku 4."
                                 "\nTo je riadokTitulku 41.\nTo je riadokTitulku 42."};
  Subtitles vsetkyTitulky;
  vsetkyTitulky.putSubtitle(mojTitulok);
  vsetkyTitulky.putSubtitle(mojTitulok1);
  vsetkyTitulky.putSubtitle(mojTitulok2);
  vsetkyTitulky.putSubtitle(mojTitulok3);
  vsetkyTitulky.putSubtitle(mojTitulok4);
  ASSERT_EQ("2: 125 is not less than next 124\n4: 125 is not less than next 121"
  , vsetkyTitulky.wrongSubtitlesOrder());
}

TEST(TestFifthTask, WrongOrder) {
  const std::string mojTitulok {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
                                "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
  const std::string mojTitulok1 {"125\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 3."
                                 "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
  const std::string mojTitulok2 {"124\n00:03:56,211 --> 00:04:06,123\nTo je riadokTitulku 2."
                                 "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
  const std::string mojTitulok3 {"125\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 3."
                                 "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
  const std::string mojTitulok4 {"126\n06:02:16,488 --> 06:02:18,637\nTo je riadokTitulku 4."
                                 "\nTo je riadokTitulku 41.\nTo je riadokTitulku 42."};
  Subtitles vsetkyTitulky;
  vsetkyTitulky.putSubtitle(mojTitulok);
  vsetkyTitulky.putSubtitle(mojTitulok1);
  vsetkyTitulky.putSubtitle(mojTitulok2);
  vsetkyTitulky.putSubtitle(mojTitulok3);
  vsetkyTitulky.putSubtitle(mojTitulok4);
  ASSERT_EQ("1: 00:02:18,949 is not less than next 00:02:16,488"
               "\n3: 00:04:06,123 is not less than next 00:02:16,488"
               , vsetkyTitulky.wrongSubtitlesTimeOrder());
}

TEST(TestFifthTask, WrongOrder1) {
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
	ASSERT_EQ("2: 00:04:06,123 is not less than next 00:02:16,488"
            , vsetkyTitulky.wrongSubtitlesTimeOrder());
}

TEST(TestFifthTask, CorrectOrder) {
  const std::string mojTitulok {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
                                "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
  const std::string mojTitulok1 {"125\n00:02:19,488 --> 00:02:21,949\nTo je riadokTitulku 3."
                                 "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
  const std::string mojTitulok2 {"124\n00:03:56,211 --> 00:04:06,123\nTo je riadokTitulku 2."
                                 "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
  const std::string mojTitulok3 {"125\n00:04:16,488 --> 00:04:18,949\nTo je riadokTitulku 3."
                                 "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
  const std::string mojTitulok4 {"126\n06:05:16,488 --> 06:05:18,637\nTo je riadokTitulku 4."
                                 "\nTo je riadokTitulku 41.\nTo je riadokTitulku 42."};
  Subtitles vsetkyTitulky;
  vsetkyTitulky.putSubtitle(mojTitulok);
  vsetkyTitulky.putSubtitle(mojTitulok1);
  vsetkyTitulky.putSubtitle(mojTitulok2);
  vsetkyTitulky.putSubtitle(mojTitulok3);
  vsetkyTitulky.putSubtitle(mojTitulok4);
  ASSERT_EQ("", vsetkyTitulky.wrongSubtitlesTimeOrder());
}

