// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace ::testing;

#include "4_SortWords.h"

TEST(TestStvrtejUlohy, capitalToLower) {
  char *word = new char[MAX];
  strcpy(word, "AbecEdaX");
  toLower(word);
  std::string result{ word };
  ASSERT_EQ("abecedax", result);
}

TEST(TestStvrtejUlohy, emptyToLower) {
  char *word = new char[MAX];
  strcpy(word, "");
  toLower(word);
  std::string result{ word };
  ASSERT_EQ("", result);
}

TEST(TestStvrtejUlohy, noCapitalToLower) {
  char *word = new char[MAX];
  strcpy(word, "asaf322325gsbasfs savav");
  toLower(word);
  std::string result{ word };
  ASSERT_EQ("asaf322325gsbasfs savav", result);
}

TEST(TestStvrtejUlohy, usporiadanieOdNajmensieho) {
  int pocet = 6;
  const char *slova[] = { "hlava", "telo", "ruky", "rozum", "prsty", "srdce"};
  char **pole = new char *[pocet];
  for (auto i = 0; i < pocet; i++) {
    pole[i] = new char[strlen(slova[i]) + 1];
    strcpy(pole[i], slova[i]);
  }
  sortWords(pole, pocet);
  std::string temp("hlava");
  ASSERT_EQ(temp, (char *) pole[0]);
  for (unsigned int i = 0; i < pocet; i++) {
    delete[] pole[i];
  }
  delete[] pole;
}
TEST(TestStvrtejUlohy, usporiadanieOdNajmensieho3) {
  int pocet = 6;
  const char *slova[] = { "hlava", "telo", "ruky", "rozum", "prsty", "srdce"};
  char **pole = new char *[pocet];
  for (auto i = 0; i < pocet; i++) {
    pole[i] = new char[strlen(slova[i]) + 1];
    strcpy(pole[i], slova[i]);
  }
  sortWords(pole, pocet);
  std::string temp("ruky");
  ASSERT_EQ(temp, (char *) pole[3]);
  for (unsigned int i = 0; i < pocet; i++) {
    delete[] pole[i];
  }
  delete[] pole;
}
TEST(TestStvrtejUlohy, usporiadanieOdNajmensiehoVelkePismena) {
  int pocet = 6;
  const char *slova[] = { "aaa", "AAA", "bbbb", "BB", "ccccccc", "CC"};
  char **pole = new char *[pocet];
  for (auto i = 0; i < pocet; i++) {
    pole[i] = new char[strlen(slova[i]) + 1];
    strcpy(pole[i], slova[i]);
  }
  sortWords(pole, pocet);
  std::string temp("bbbb");
  ASSERT_EQ(temp, (char *) pole[4]);
  temp = "CC";
  ASSERT_EQ(temp, (char *) pole[2]);
  for (unsigned int i = 0; i < pocet; i++) {
    delete[] pole[i];
  }
  delete[] pole;
}
TEST(TestStvrtejUlohy, usporiadanieMalePismena) {
  int pocet = 6;
  const char *slova[] = { "aaa", "AAA", "bbbb", "BB", "ccccccc", "CC"};
  char **pole = new char *[pocet];
  for (auto i = 0; i < pocet; i++) {
    pole[i] = new char[strlen(slova[i]) + 1];
    strcpy(pole[i], slova[i]);
  }
  sortWordsInSmall(pole, pocet);
  std::string temp("CC");
  ASSERT_EQ(temp, (char *) pole[4]);
  temp = "bbbb";
  ASSERT_EQ(temp, (char *) pole[3]);
  for (unsigned int i = 0; i < pocet; i++) {
    delete[] pole[i];
  }
  delete[] pole;
}