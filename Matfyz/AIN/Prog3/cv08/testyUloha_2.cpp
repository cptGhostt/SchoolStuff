// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "2_Subtitle.h"

using namespace ::testing;

//Uloha 2.
TEST(TestSecondTask, WrongSeconds) {
  const std::string casTitulku {"00:02:16,488 --> 00:02:418,949"};
  Subtitle titulok;
  ASSERT_FALSE(titulok.putTimeRow(casTitulku));
  ASSERT_EQ("Subtitle time has wrong format", titulok.getStatus());
}
TEST(TestSecondTask, WrongMilliseconds) {
  const std::string casTitulku {"00:02:16,488 --> 00:02:18,1949"};
  Subtitle titulok;
  ASSERT_FALSE(titulok.putTimeRow(casTitulku));
  ASSERT_EQ("Subtitle time has wrong format", titulok.getStatus());
}
TEST(TestSecondTask, correctTime) {
  const std::string casTitulku {"00:02:16,488 --> 00:02:18,549"};
  Subtitle titulok;
  ASSERT_TRUE(titulok.putTimeRow(casTitulku));
}
TEST(TestSecondTask, MaloPoloziekTitulku) {
  const std::string mojTitulok {"1\n00:02:16,488 --> 00:02:418,949\nAhoj"};
  Subtitle titulok;
  ASSERT_FALSE(titulok.putSubTitle(mojTitulok));
  ASSERT_EQ("Subtitle time has wrong format", titulok.getStatus());
}
TEST(TestSecondTask, ZlyCasTitulku) {
  const std::string mojTitulok {"1\n00:02:16,488 --> 00:02:418,949\nAhoj"};
  Subtitle titulok;
  ASSERT_FALSE(titulok.putSubTitle(mojTitulok));
  ASSERT_EQ("Subtitle time has wrong format", titulok.getStatus());
}
TEST(TestSecondTask, ZlyFormatCasuTitulku) {
  const std::string mojTitulok {"44\n00:02:16,488 -> 00:02:18,949\nPrepac"};
  Subtitle titulok;
  ASSERT_FALSE(titulok.putSubTitle(mojTitulok));
  ASSERT_EQ("Subtitle time has wrong format", titulok.getStatus());
}
TEST(TestSecondTask, ZlePoradieCasovTitulku) {
  const std::string mojTitulok {"13\n1:05:55,555 --> 1:05:55,555\nPrepac"};
  Subtitle titulok;
  ASSERT_FALSE(titulok.putSubTitle(mojTitulok));
  ASSERT_EQ("Subtitle begin time is not less than end time", titulok.getStatus());
}
TEST(TestSecondTask, ZlePoradieAjZlyFormatCasuTitulku) {
  const std::string mojTitulok{"xyz\n00:02:16,488 -> 00:02:18,949\nPrepac"};
  Subtitle titulok;
  ASSERT_FALSE(titulok.putSubTitle(mojTitulok));
  ASSERT_EQ("Subtitle has wrong format", titulok.getStatus());
}
TEST(TestSecondTask, JednoduchyTitulokText) {
  std::string riadok;
  const std::string mojTitulok{"32\n00:02:16,488 --> 00:02:18,949\nCo to za veselie."};
  Subtitle titulok;
  ASSERT_TRUE(titulok.putSubTitle(mojTitulok));
  riadok = titulok.getTextRow(1);
  ASSERT_EQ("Co to za veselie.", riadok);
}
TEST(TestSecondTask, JednoduchyTitulokZleCasy) {
  const std::string mojTitulok{"32\n00:05:16,488 --> 00:02:18,949\nCo to za veselie."};
  Subtitle titulok;
  ASSERT_FALSE(titulok.putSubTitle(mojTitulok));
  ASSERT_EQ("Subtitle begin time is not less than end time", titulok.getStatus());
}
TEST(TestSecondTask, JednoduchyTitulokText3) {
  std::string riadok;
  const std::string mojTitulok{"432\n00:02:16,488 --> 00:02:18,949\nCo to za veselie.\nTo je titulok 2.\nTo je titulok 3."};
  Subtitle titulok;
  titulok.putSubTitle(mojTitulok);
  riadok = titulok.getTextRow(3);
  ASSERT_EQ("To je titulok 3.", riadok);
}
TEST(TestSecondTask, JednoduchyTitulokZaciatok) {
  std::string riadok;
  const std::string mojTitulok{"432\n00:02:16,488 --> 00:02:18,949\nCo to za veselie.\nTo je titulok 2.\nTo je titulok 3."};
  Subtitle titulok;
  titulok.putSubTitle(mojTitulok);
  riadok = titulok.getBeginTime();
  ASSERT_EQ("00:02:16,488", riadok);
}
TEST(TestSecondTask, JednoduchyTitulokKoniec) {
  std::string riadok;
  const std::string mojTitulok{"432\n00:02:16,488 --> 00:02:18,949\nCo to za veselie.\nTo je titulok 2.\nTo je titulok 3."};
  Subtitle titulok;
  titulok.putSubTitle(mojTitulok);
  riadok = titulok.getEndTime();
  ASSERT_EQ("00:02:18,949", riadok);
}
TEST(TestSecondTask, ZlyCasZaciatkuTitulku) {
  const std::string mojTitulok{"432\n00:-02:16,488 --> 00:02:18,949\nCo to za veselie.\nTo je titulok 2.\nTo je titulok 3."};
  Subtitle titulok;
  ASSERT_FALSE(titulok.putSubTitle(mojTitulok));
  ASSERT_EQ("Subtitle time has wrong format", titulok.getStatus());
}
TEST(TestSecondTask, ZlyFormatZaciatkuTitulku) {
  const std::string mojTitulok{"432\n00:x02:16,488 --> 00:02:18,949\nCo to za veselie.\nTo je titulok 2.\nTo je titulok 3."};
  Subtitle titulok;
  ASSERT_FALSE(titulok.putSubTitle(mojTitulok));
  ASSERT_EQ("Subtitle time has wrong format", titulok.getStatus());
}
TEST(TestSecondTask, JednoduchyTitulokCely) {
  std::string riadok;
  const std::string mojTitulok{"432\n00:02:16,488 --> 00:02:18,949\nCo to za veselie.\nTo je titulok 2.\nTo je titulok 3."};
  Subtitle titulok;
  titulok.putSubTitle(mojTitulok);
  riadok = titulok.getTextRow(3);
  ASSERT_EQ("To je titulok 3.", riadok);
}

