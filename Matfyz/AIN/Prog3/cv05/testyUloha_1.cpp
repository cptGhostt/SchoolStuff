// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "1_Name.h"

using namespace ::testing;

//Uloha 1.
TEST(TestyPrvejUlohy, PrazdnyItem) {
  Element text;
  ASSERT_EQ(text.put(""), -1);
  ASSERT_EQ(-1, text.getStatus());
  text.put("QWERTY");
  ASSERT_EQ(0, text.getStatus());
  text.put("              ");
  ASSERT_EQ(-1, text.getStatus());
}

TEST(TestyPrvejUlohy, NormalnyItem) {
  Element text;
  ASSERT_EQ(text.put("abcd"), 0);
  ASSERT_EQ(0, text.getStatus());
}

TEST(TestyPrvejUlohy, NormalnyGet) {
  Element text;
  text.put("  abcd   ");
  ASSERT_EQ(text.get(), "abcd");
}

TEST(TestyPrvejUlohy, EmptyElement) {
  Element text;
  ASSERT_EQ(text.put("          "), -1);
  ASSERT_EQ(-1, text.getStatus());
}

TEST(TestyPrvejUlohy, MenoJedenZnak) {
  Name text;
  ASSERT_EQ(text.put("A"), 0);
}

TEST(TestyPrvejUlohy, MenoJedenZnakMaly) {
  Name text;
  ASSERT_NE(text.put("abc"), 0);
}
TEST(TestyPrvejUlohy, deGaspieri) {
  Name text;
  ASSERT_EQ(text.put("  de Gaspieri   "), 0);
}

TEST(TestyPrvejUlohy, JedenZnakMalyCezItem) {
  Element *text = new Name;
  ASSERT_EQ(text->put("  John W. "), 0);
  ASSERT_EQ(text->put("  John-W. "), 0);
}

TEST(TestyPrvejUlohy, MenoDlhsiTextOK) {
  Name text;
  ASSERT_EQ(text.put("Jozef"), 0);
}
TEST(TestyPrvejUlohy, MenoDlhsiText) {
  Name text;
  text.put("Ascdf");
  ASSERT_EQ(text.get(), "Ascdf");
}
TEST(TestyPrvejUlohy, MenoViacVelkych) {
  Name text;
  text.put("Ascdf");
  ASSERT_EQ(text.put("McNamara"), 0);
  ASSERT_EQ(text.get(), "McNamara");
}
TEST(TestyPrvejUlohy, MenoSPomlckou) {
  Name text;
  text.put("Anna-Maria");
  ASSERT_EQ(text.get(), "Anna-Maria");
}
TEST(TestyPrvejUlohy, MenoSBodkou) {
  Name text;
  text.put("Anna.Maria");
  ASSERT_EQ(text.get(), "Anna.Maria");
}
TEST(TestyPrvejUlohy, MenoSMedzeramiABodkou) {
  Name text;
  text.put(" Richard III.   ");
  ASSERT_EQ(text.get(), "Richard III.");
}
TEST(TestyPrvejUlohy, MenoSMedzerami) {
  Name text;
  text.put(" Jean - Paul H.  ");
  ASSERT_EQ(text.get(), "Jean - Paul H.");
}

TEST(TestyPrvejUlohy, PriezviskoSMedzerou) {
  Name text;
  text.put("   de Angeli    ");
  ASSERT_EQ(text.get(), "de Angeli");
}
