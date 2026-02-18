// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace ::testing;

#include "5_SortByFunction.h"

TEST(TestPiatejUlohy, usporiadanieAscii) {
  int size = 6;
  const char *words[] = {"Ano", "nie", "cakam", "chcem", "gaggot", "Hura"};
  char **pole = new char *[size];
  for (auto i = 0; i < size; i++) {
    pole[i] = new char[strlen(words[i]) + 1];
    strcpy(pole[i], words[i]);
  }
  sortWords(pole, size);
  std::string temp("gaggot");
  ASSERT_EQ(temp, (char *) pole[4]);
  temp = "cakam";
  ASSERT_EQ(temp, (char *) pole[2]);
  for (unsigned int i = 0; i < size; i++) {
    delete[] pole[i];
  }
  delete[] pole;
}

TEST(TestPiatejUlohy, usporiadanieMaleBezCh) {
  int size = 5;
  const char *words[] = { "Ano", "Cakam", "chcem", "gaggot", "Hura"};
  char **pole = new char *[size];
  for (auto i = 0; i < size; i++) {
    pole[i] = new char[strlen(words[i]) + 1];
    strcpy(pole[i], words[i]);
  }
  sortWordsInSmall(pole, size);
  std::string temp("chcem");
  ASSERT_EQ(temp, (char *) pole[2]);
  temp = "Hura";
  ASSERT_EQ(temp, (char *) pole[4]);
  for (unsigned int i = 0; i < size; i++) {
    delete[] pole[i];
  }
  delete[] pole;
}

TEST(TestPiatejUlohy, usporiadanieMaleSCh) {
  int size = 7;
  const char *words[] = { "Ano", "nie", "Cakam", "chcem", "Gaggot", "Hura", "Chapem"};
  char **pole = new char *[size];
  for (auto i = 0; i < size; i++) {
    pole[i] = new char[strlen(words[i]) + 1];
    strcpy(pole[i], words[i]);
  }
  sortWordsInSmallAndCh(pole, size);
  std::string temp("Ano");
  ASSERT_EQ(temp, (char *) pole[0]);
  temp = "Cakam";
  ASSERT_EQ(temp, (char *) pole[1]);
  temp = "Gaggot";
  ASSERT_EQ(temp, (char *) pole[2]);
  temp = "Hura";
  ASSERT_EQ(temp, (char *) pole[3]);
  temp = "Chapem";
  ASSERT_EQ(temp, (char *) pole[4]);
  temp = "chcem";
  ASSERT_EQ(temp, (char *) pole[5]);
  temp = "nie";
  ASSERT_EQ(temp, (char *) pole[6]);
  for (unsigned int i = 0; i < size; i++) {
    delete[] pole[i];
  }
  delete[] pole;
}

TEST(TestPiatejUlohy, usporiadanieMaleSCh2) {
  int size = 7;
  const char *words[] = { "Ano", "nie", "Cakam", "chcem", "Gaggot", "Hura", "Chapem"};
  char **pole = new char *[size];
  for (auto i = 0; i < size; i++) {
    pole[i] = new char[strlen(words[i]) + 1];
    strcpy(pole[i], words[i]);
  }
  sortWordsInSmallAndCh(pole, size);
  std::string temp("Chapem");
  ASSERT_EQ(temp, (char *) pole[4]);
  temp = "Gaggot";
  ASSERT_EQ(temp, (char *) pole[2]);
  for (unsigned int i = 0; i < size; i++) {
    delete[] pole[i];
  }
  delete[] pole;
}

TEST(TestPiatejUlohy, usporiadanieMaleSChIbaJedno) {
  int size = 1;
  const char *words[] = { "chcem"};
  char **pole = new char *[size];
  for (auto i = 0; i < size; i++) {
    pole[i] = new char[strlen(words[i]) + 1];
    strcpy(pole[i], words[i]);
  }
  sortWordsInSmallAndCh(pole, size);
  std::string temp("chcem");
  ASSERT_EQ(temp, (char *) pole[0]);
  for (unsigned int i = 0; i < size; i++) {
    delete[] pole[i];
  }
  delete[] pole;
}

TEST(TestPiatejUlohy, usporiadanieMaleSChIbaDve) {
  int size = 2;
  const char *words[] = { "chcem", "Chapem"};
  char **pole = new char *[size];
  for (auto i = 0; i < size; i++) {
    pole[i] = new char[strlen(words[i]) + 1];
    strcpy(pole[i], words[i]);
  }
  sortWordsInSmallAndCh(pole, size);
  std::string temp("Chapem");
  ASSERT_EQ(temp, (char *) pole[0]);
  for (unsigned int i = 0; i < size; i++) {
    delete[] pole[i];
  }
  delete[] pole;
}

TEST(TestPiatejUlohy, usporiadanieMaleSChDve) {
  int size = 2;
  const char *words[] = { "horucka", "Chapem"};
  char **pole = new char *[size];
  for (auto i = 0; i < size; i++) {
    pole[i] = new char[strlen(words[i]) + 1];
    strcpy(pole[i], words[i]);
  }
  sortWordsInSmallAndCh(pole, size);
  std::string temp("Chapem");
  ASSERT_EQ(temp, (char *) pole[1]);
  for (unsigned int i = 0; i < size; i++) {
    delete[] pole[i];
  }
  delete[] pole;
}

TEST(TestPiatejUlohy, usporiadanieZoznamuSlov) {
  char *output = new char[256];
  std::string temp("Chcem,Co,Hadam,Veselie,ano,gaga,to,za");
  ASSERT_EQ(temp, sortAccordingToFunction("Co,ano,Veselie,gaga,Hadam,to,Chcem,za", output, sortWords));
  if (output != nullptr) delete[] output;
}

TEST(TestPiatejUlohy, usporiadanieZoznamuSlovMalePismena) {
  char *output = new char[256];
  std::string temp("ano,Chcem,Co,gaga,Hadam,to,Veselie,za");
  ASSERT_EQ(temp, sortAccordingToFunction("Co,ano,Veselie,gaga,Hadam,to,Chcem,za", output, sortWordsInSmall));
  if (output != nullptr) delete[] output;
}

TEST(TestPiatejUlohy, usporiadanieZoznamuSlovMalePismenaCh) {
  char *output = new char[256];
  std::string temp("ano,Co,gaga,Hadam,Chcem,to,Veselie,za");
  ASSERT_EQ(temp, sortAccordingToFunction("Co,ano,Veselie,gaga,Hadam,to,Chcem,za", output, sortWordsInSmallAndCh));
  if (output != nullptr) delete[] output;
}

TEST(TestPiatejUlohy, usporiadanieZoznamuCisel) {
  char *output = new char[256];
  std::string temp("333333,432999,55,555,65,8,91");
  ASSERT_EQ(temp, sortAccordingToFunction("555,432999,65,8,333333,55,91", output, sortWords));
  if (output != nullptr) delete[] output;
}

TEST(TestPiatejUlohy, usporiadanieZoznamuCiselMale) {
  char *output = new char[256];
  std::string temp("333333,432999,55,555,65,8,91");
  ASSERT_EQ(temp, sortAccordingToFunction("555,432999,65,8,333333,55,91", output, sortWordsInSmall));
  if (output != nullptr) delete[] output;
}

TEST(TestPiatejUlohy, usporiadaniePrazdnehoZoznamu) {
  char *output = new char[256];
  std::string temp("");
  ASSERT_EQ(temp, sortAccordingToFunction(",,,,,,,,,,", output, sortWordsInSmall));
  if (output != nullptr) delete[] output;
}

TEST(TestPiatejUlohy, usporiadanieNulovehoZoznamu) {
  char *output = new char[256];
  std::string temp("");
  ASSERT_EQ(temp, sortAccordingToFunction(nullptr, output, sortWords));
  if (output != nullptr) delete[] output;
}

TEST(TestPiatejUlohy, usporiadanieDoNulovehoRetazca) {
  std::string temp("");
  ASSERT_EQ(temp, sortAccordingToFunction("slovo dva", nullptr, sortWords));
}

TEST(TestPiatejUlohy, usporiadanieZoznamuSlovSPrazdnymi) {
  char *output = new char[256];
  std::string temp("Co,Co,co,to,veselie,za");
  ASSERT_EQ(temp, sortAccordingToFunction(",,,,Co,to,za,,,,veselie,Co,co,,,", output, sortWords));
  if (output != nullptr) delete[] output;
}
TEST(TestPiatejUlohy, usporiadanieZoznamuSlovSPrazdnymiCh) {
  char *output = new char[256];
  std::string temp("ano,Co,gaga,Hadam,Chcem,to,Veselie,za");
  ASSERT_EQ(temp,
            sortAccordingToFunction(",,,,ano,Co,,,gaga,Hadam,...Chcem,to,Veselie,za,,,", output, sortWordsInSmallAndCh));
  if (output != nullptr) delete[] output;
}
