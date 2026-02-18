// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "2_Subtitle.h"
#include "2_Subtitles.h"

using namespace ::testing;

//Uloha 2.
TEST(TestSecondTask, WrongSeconds) {
  std::string myException;
  try {
    const std::string timeRow {"00:02:16,488 --> 00:02:418,949"};
    Subtitle title;
    title.putTimeRow(timeRow);
  }
  catch (WrongTime e) {
    myException = e.message();
  }
  catch (WrongInput e) {
    myException = e.message();
  }
  ASSERT_EQ("Second out of limits", myException);
}
TEST(TestSecondTask, WrongMilliSeconds) {
  std::string myException;
  try {
    const std::string timeRow {"00:02:16,488 --> 00:02:18,1949"};
    Subtitle title;
    title.putTimeRow(timeRow);
  }
  catch (WrongTime e) {
    myException = e.message();
  }
  ASSERT_EQ("Millisecond out of limits", myException);
}
TEST(TestSecondTask, correctTime) {
  const std::string timeRow {"00:02:16,488 --> 00:02:18,549"};
  Subtitle title;
  title.putTimeRow(timeRow);
  ASSERT_EQ("00:02:18,549", title.getEndTime());
}
TEST(TestSecondTask, ZleSekundy) {
  std::string myException;
  try {
    const std::string myTitle{"1\n00:02:16,488 --> 00:02:418,949\nAhoj"};
    Subtitle title;
      title.putSubtitle(myTitle);
  }
  catch (WrongTime e) {
    myException = e.message();
  }
  ASSERT_EQ("Second out of limits", myException);
}
TEST(TestSecondTask, ZlytimeRow) {
  std::string myException;
  try {
    const std::string myTitle{"1\n00:02:16,488 --> 00:02:418,949\nAhoj"};
    Subtitle title;
      title.putSubtitle(myTitle);
  }
  catch (WrongTime e) {
    myException = e.message();
  }
  ASSERT_EQ("Second out of limits", myException);
}
TEST(TestSecondTask, ZlyFormatCasuTitulku) {
  std::string myException;
  try {
    const std::string myTitle{"44\n00:02:16,488 -> 00:02:18,949\nPrepac"};
    Subtitle title;
      title.putSubtitle(myTitle);
  }
  catch (WrongInput e) {
    myException = e.message();
  }
  ASSERT_EQ("Subtitle time row has wrong format", myException);
}
TEST(TestSecondTask, ZlePoradieCasovTitulku) {
  std::string myException;
  try {
    const std::string myTitle{"13\n1:05:55,555 --> 1:05:55,555\nPrepac"};
    Subtitle title;
      title.putSubtitle(myTitle);
  }
  catch (WrongInput e) {
    myException = e.message();
  }
  ASSERT_EQ("Subtitle begin time is not less than end time", myException);
}
TEST(TestSecondTask, ZlePoradieAjZlyFormatCasuTitulku) {
  std::string myException;
  try {
    const std::string myTitle{"xyz\n00:02:16,488 -> 00:02:18,949\nPrepac"};
    Subtitle title;
      title.putSubtitle(myTitle);
  }
  catch (WrongInput e) {
    myException = e.message();
  }
  ASSERT_EQ("Subtitle has wrong format", myException);
}
TEST(TestSecondTask, JednoduchytitleText) {
  std::string riadok;
  const std::string myTitle{"32\n00:02:16,488 --> 00:02:18,949\nCo to za veselie."};
  Subtitle title;
    title.putSubtitle(myTitle);
  riadok = title.getTextRow(0);
  ASSERT_EQ("Co to za veselie.", riadok);
}
TEST(TestSecondTask, ChybajuciTextTitulku) {
  std::string myException;
  try {
    const std::string myTitle{"32\n00:05:16,488 --> 00:07:18,949\n"};
    Subtitle title;
      title.putSubtitle(myTitle);
  }
  catch (WrongInput e) {
    myException = e.message();
  }
  ASSERT_EQ("Subtitle has no text", myException);
}
TEST(TestSecondTask, JednoduchytitleZleCasy) {
  std::string myException;
  try {
    const std::string myTitle{"32\n00:05:16,488 --> 00:02:18,949\nCo to za veselie."};
    Subtitle title;
      title.putSubtitle(myTitle);
  }
  catch (WrongInput e) {
    myException = e.message();
  }
  ASSERT_EQ("Subtitle begin time is not less than end time", myException);
}
TEST(TestSecondTask, ZlyFormatZaciatkuTitulku) {
  std::string myException;
  try {
    const std::string myTitle{"432\n00:x02:16,488 --> 00:02:18,949\nCo to za veselie.\nTo je title 2.\nTo je title 3."};
    Subtitle title;
    title.putSubtitle(myTitle);
  }
  catch (WrongInput e) {
    myException = e.message();
  }
  ASSERT_EQ("Wrong time format", myException);
}
TEST(TestSecondTask, ZlyCasZaciatkuTitulku) {
  std::string myException;
  try {
    const std::string myTitle{"432\n00:-02:16,488 --> 00:02:18,949\nCo to za veselie.\nTo je title 2.\nTo je title 3."};
    Subtitle title;
      title.putSubtitle(myTitle);
  }
  catch (WrongTime e) {
    myException = e.message();
  }
  ASSERT_EQ("Minute out of limits", myException);
}
TEST(TestSecondTask, JednoduchytitleText3) {
  std::string riadok;
  const std::string myTitle{"432\n00:02:16,488 --> 00:02:18,949\nCo to za veselie.\nTo je title 2.\nTo je title 3."};
  Subtitle title;
    title.putSubtitle(myTitle);
  riadok = title.getTextRow(2);
  ASSERT_EQ("To je title 3.", riadok);
}
TEST(TestSecondTask, JednoduchytitleZaciatok) {
  std::string riadok;
  const std::string myTitle{"432\n00:02:16,488 --> 00:02:18,949\nCo to za veselie.\nTo je title 2.\nTo je title 3."};
  Subtitle title;
    title.putSubtitle(myTitle);
  riadok = title.getBeginTime();
  ASSERT_EQ("00:02:16,488", riadok);
}
TEST(TestSecondTask, JednoduchytitleKoniec) {
  std::string riadok;
  const std::string myTitle{"432\n00:02:16,488 --> 00:02:18,949\nCo to za veselie.\nTo je title 2.\nTo je title 3."};
  Subtitle title;
    title.putSubtitle(myTitle);
  riadok = title.getEndTime();
  ASSERT_EQ("00:02:18,949", riadok);
}
TEST(TestSecondTask, JednoduchytitleCely) {
  std::string riadok;
  const std::string myTitle{"432\n00:02:16,488 --> 00:02:18,949\nCo to za veselie.\nTo je title 2.\nTo je title 3."};
  Subtitle title;
    title.putSubtitle(myTitle);
  riadok = title.getTextRow(2);
  ASSERT_EQ("To je title 3.", riadok);
}

//Uloha 3.
TEST(TestSecondTask, TriTitulky) {
  std::string myTitle {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
                          "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
  Subtitle title;
    title.putSubtitle(myTitle);
  const std::string myTitle2 {"124\n00:03:56,211 --> 00:04:06,123\nTo je riadokTitulku 2."
                                 "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
  Subtitle title2;
    title2.putSubtitle(myTitle2);(myTitle2);
  const std::string myTitle3 {"125\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 3."
                                 "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
  Subtitle title3;
    title3.putSubtitle(myTitle3);
  ASSERT_EQ("To je riadokTitulku 32.", title3.getTextRow(2));
  ASSERT_EQ("To je riadokTitulku 21.", title2.getTextRow(1));
  ASSERT_EQ("To je riadokTitulku 1.", title.getTextRow(0));
  ASSERT_EQ(123, title.getSubtitleNumber());
}

TEST(TestSecondTask, VsetkyTitulkyPocet) {
  const std::string myTitle {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
                                "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
  const std::string myTitle2 {"124\n00:03:56,211 --> 00:04:06,123\nTo je riadokTitulku 2."
                                 "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
  const std::string myTitle3 {"125\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 3."
                                 "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
  const std::string myTitle4 {"126\n06:02:16,488 --> 06:02:18,637\nTo je riadokTitulku 4."
                                 "\nTo je riadokTitulku 41.\nTo je riadokTitulku 42."};
  Subtitles vsetkyTitulky;
  vsetkyTitulky.putSubtitle(myTitle);
  vsetkyTitulky.putSubtitle(myTitle2);
  vsetkyTitulky.putSubtitle(myTitle3);
  vsetkyTitulky.putSubtitle(myTitle4);
  ASSERT_EQ(4, vsetkyTitulky.getNumberOfSubtitles());
}
TEST(TestSecondTask, JedentitleZly) {
  const std::string myTitle {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
                                "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
  const std::string myTitle2 {"124\n00:03:56,211 --> 00:04:06,123\nTo je riadokTitulku 2."
                                 "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
  const std::string myTitle3 {"125\n00:02:16,488 --> 00:02:12,949\nTo je riadokTitulku 3."
                                 "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
  const std::string myTitle4 {"126\n06:02:16,488 --> 06:02:18,637\nTo je riadokTitulku 4."
                                 "\nTo je riadokTitulku 41.\nTo je riadokTitulku 42."};
  Subtitles vsetkyTitulky;
  vsetkyTitulky.putSubtitle(myTitle);
  vsetkyTitulky.putSubtitle(myTitle2);
  vsetkyTitulky.putSubtitle(myTitle3);
  vsetkyTitulky.putSubtitle(myTitle4);
  ASSERT_EQ(3, vsetkyTitulky.getNumberOfSubtitles());
}
TEST(TestSecondTask, VsetkyZle) {
  const std::string myTitle {"123\n00:02:16x,488 --> 00:02:18,949\nTo je riadokTitulku 1."
                                "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
  const std::string myTitle2 {"124\n00:03:56,211 --> 00:04:06:123\nTo je riadokTitulku 2."
                                 "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
  const std::string myTitle3 {"125\n00:02:16,488 --> 00:02:12,949\nTo je riadokTitulku 3."
                                 "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
  const std::string myTitle4 {"126\n06:02:16,488 --> 06:02:18,-637\nTo je riadokTitulku 4."
                                 "\nTo je riadokTitulku 41.\nTo je riadokTitulku 42."};
  Subtitles vsetkyTitulky;
  vsetkyTitulky.putSubtitle(myTitle);
  vsetkyTitulky.putSubtitle(myTitle2);
  vsetkyTitulky.putSubtitle(myTitle3);
  vsetkyTitulky.putSubtitle(myTitle4);
  ASSERT_EQ(0, vsetkyTitulky.getNumberOfSubtitles());
}
TEST(TestSecondTask, JedentitlePocet) {
  const std::string myTitle3 {"125\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 3."
                                 "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
  Subtitles vsetkyTitulky;
  vsetkyTitulky.putSubtitle(myTitle3);
  ASSERT_EQ(1, vsetkyTitulky.getNumberOfSubtitles());
}
TEST(TestSecondTask, ZiadentitlePocet) {
  Subtitles vsetkyTitulky;
  ASSERT_EQ(0, vsetkyTitulky.getNumberOfSubtitles());
}
