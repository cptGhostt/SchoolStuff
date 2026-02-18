// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "2_IdentificationNumber.h"

using namespace ::testing;

TEST(TestyDruhejUlohy, EmptyDate) {
    Date date;
    ASSERT_EQ(date.date(EU_FORMAT), "0.0.0");
}

TEST(TestyDruhejUlohy, One) {
    Date date;
    date.put(1, 1, 1);
    ASSERT_EQ(date.date(EU_FORMAT), "1.1.1");
}

TEST(TestyDruhejUlohy, WrongDay) {
    Date date;
    date.put(32, 12, 1);
    ASSERT_EQ(date.date(EU_FORMAT), "0.0.0");
}

TEST(TestyDruhejUlohy, WrongApril) {
    Date date;
    date.put(31, 4, 1);
    ASSERT_EQ(date.date(EU_FORMAT), "0.0.0");
}

TEST(TestyDruhejUlohy, WrongNov) {
    Date date;
    date.put(31, 11, 14352);
    ASSERT_EQ(date.date(EU_FORMAT), "0.0.0");
}

TEST(TestyDruhejUlohy, Wrong29) {
    Date date;
    date.put(29, 2, 1999);
    ASSERT_EQ(date.date(EU_FORMAT), "0.0.0");
}

TEST(TestyDruhejUlohy, OK29) {
    Date date;
    date.put(29, 2, 2000);
    ASSERT_EQ(date.date(EU_FORMAT), "29.2.2000");
}

TEST(TestyDruhejUlohy, OKjune) {
    Date date;
    date.put(30, 6, -2000);
    ASSERT_EQ(date.date(EU_FORMAT), "30.6.-2000");
}

TEST(TestyDruhejUlohy, WrongChar) {
    IdentificationNumber identificationNumber;
    ASSERT_NE(identificationNumber.put("123456/434,"), 0);
}

TEST(TestyDruhejUlohy, GetElementCely) {
  ASSERT_EQ(subString("abcd", 1, ' '), "abcd");
}
TEST(TestyDruhejUlohy, GetElement0) {
  ASSERT_EQ(subString("  abcd   ", 0, ' '), "");
}
TEST(TestyDruhejUlohy, ElementPrazdny) {
  ASSERT_EQ(subString("", 1, ' '), "");
}
TEST(TestyDruhejUlohy, GetElementPrazdny) {
  ASSERT_EQ(subString("     ", 1, ' '), "");
}

TEST(TestyDruhejUlohy, GetElement1) {
  ASSERT_EQ(subString("prvy.druhy.treti", 1, '.'), "prvy");
  ASSERT_EQ(subString("..prvy.druhy.treti", 1, '.'), "");
  ASSERT_EQ(subString("prvy.druhy.treti", 0, '.'), "");
  ASSERT_EQ(subString("..prvy.druhy.treti", 3, '.'), "prvy");
  ASSERT_EQ(subString("prvy.druhy.treti", 1, ';'),"prvy.druhy.treti");
}

TEST(TestyDruhejUlohy, Dot) {
  ASSERT_EQ(subString("..abcd.efg.hij", 1, '.'), "");
  ASSERT_EQ(subString("..abcd.efg.hij", 3, '.'), "abcd");
}

TEST(TestyDruhejUlohy, PrazdnyDatum) {
  IdentificationNumber identificationNumber;
  identificationNumber.put("  ");
  ASSERT_EQ(-1, identificationNumber.getStatus());
}

TEST(TestyDruhejUlohy, EmptyId) {
  IdentificationNumber identificationNumber;
  ASSERT_EQ(identificationNumber.put("/"), -4);
}

TEST(TestyDruhejUlohy, WrongID) {
  IdentificationNumber identificationNumber;
  identificationNumber.put("x/x");
  ASSERT_EQ(identificationNumber.getStatus(), -4);
}

TEST(TestyDruhejUlohy, NeprazdnyZiaden) {
  IdentificationNumber identificationNumber;
  identificationNumber.put("x/x/z");
  ASSERT_EQ(identificationNumber.getStatus(), -4);
}

TEST(TestyDruhejUlohy, EmptyNumber) {
  IdentificationNumber identificationNumber;
  identificationNumber.put("   ");
  ASSERT_EQ(identificationNumber.getStatus(), -1);
}

TEST(TestyDruhejUlohy, WrongDayID) {
  IdentificationNumber identificationNumber;
  identificationNumber.put("330734/2222");
  ASSERT_EQ(identificationNumber.getStatus(), -3);
}

TEST(TestyDruhejUlohy, WrongNovember) {
  IdentificationNumber identificationNumber;
  identificationNumber.put("011131/1112");
  ASSERT_EQ(identificationNumber.getStatus(), -3);
}

TEST(TestyDruhejUlohy, WrongFebruar) {
  IdentificationNumber identificationNumber;
  identificationNumber.put("010229/2331");
  ASSERT_EQ(identificationNumber.getStatus(), -3);
}

TEST(TestyDruhejUlohy, DotInDate) {
  IdentificationNumber identificationNumber;
  identificationNumber.put("011.31/1901 ");
  ASSERT_EQ(identificationNumber.getStatus(), -4);
}

TEST(TestyDruhejUlohy, Date) {
  IdentificationNumber identificationNumber;
  identificationNumber.put("160229/2016 ");
  ASSERT_EQ(identificationNumber.getDate().date(EU_FORMAT), "29.2.2016");
}

TEST(TestyDruhejUlohy, Detail) {
  IdentificationNumber identificationNumber;
  identificationNumber.put("170228/2017");
  ASSERT_EQ(identificationNumber.getDate().year, 2017);
  ASSERT_EQ(identificationNumber.getDate().month, 2);
  ASSERT_EQ(identificationNumber.getDate().day, 28);
}

TEST(TestyDruhejUlohy, OldDate) {
  IdentificationNumber identificationNumber;
  identificationNumber.put("011231/901");
  ASSERT_EQ(identificationNumber.getDate().date(EU_FORMAT), "31.12.1901");
  ASSERT_EQ(identificationNumber.getDate().date(AMERICAN_FORMAT), "12/31/1901");
}

TEST(TestyDruhejUlohy, ZleCislo) {
  IdentificationNumber identificationNumber;
  identificationNumber.put("1222631/1901");
  ASSERT_EQ(identificationNumber.getStatus(), -4);
}
