// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"
#include "2_numberOfCharacters.h"

using namespace ::testing;

//2. Uloha
TEST(SecondTaskTests, sizeEmpty) {
	const char retazec[] = "";
	ASSERT_EQ(numberOfAllCharacters(retazec), 0);
}

TEST(SecondTaskTests, sizeShort) {
    const char retazec[] = "1234567";
    ASSERT_EQ(numberOfAllCharacters(retazec), 7);
}

TEST(SecondTaskTests, size) {
    const char retazec[] = "0wqd\\q01q2345\vqw 678qwd9";
    ASSERT_EQ(numberOfAllCharacters(retazec), 24);
}

TEST(SecondTaskTests, sizeWithEof) {
    const char retazec[] = "12345678\0asdfghu\npoiuy";
    ASSERT_EQ(numberOfAllCharacters(retazec), 8);
}

TEST(SecondTaskTests, sizeLong) {
    const char retazec[] = "ok234\\2\n35 *()*()2 \t1 3 asa\vda;";
    ASSERT_EQ(numberOfAllCharacters(retazec), 31);
}

TEST(SecondTaskTests, retazecBezCislic) {
	const char retazec[] = " askoknopwejw;e qwo qwp' qwf qwpf   ";
	ASSERT_EQ(numberOfCharactersOfCertainType(retazec, DIGIT), 0);
}

TEST(SecondTaskTests, numberOfAllAlphasNula) {
	const char retazec[] = ",./\n^%!$@\f\t) (*&^";
	ASSERT_EQ(numberOfAlphanumericCharacters(retazec), 0);
}

TEST(SecondTaskTests, numberOfAllAlphasIbaDigits) {
    const char retazec[] = "0123\n456\t78\f9\va";
    ASSERT_EQ(numberOfAlphanumericCharacters(retazec), 11);
}

TEST(SecondTaskTests, numberOfAlphanumericCharacters) {
	const char retazec[] = "wev AOPJ JCP s";
	ASSERT_EQ(numberOfAlphanumericCharacters(retazec), 11);
}

TEST(SecondTaskTests, numberOfAlphanumericDigits) {
    const char retazec[] = "123 32342325 2 35231 2435235 121341";
    ASSERT_EQ(numberOfAlphanumericCharacters(retazec), 30);
}

TEST(SecondTaskTests, ibaMedzery) {
	const char retazec[] = "                ";
	ASSERT_EQ(numberOfAlphanumericCharacters(retazec), 0);
}
TEST(SecondTaskTests, spatneLomitko) {
	const char retazec[] = "a\\\\\\\\b";
	ASSERT_TRUE(containsNotAllowedCharacter(retazec));
}
TEST(SecondTaskTests, textSMedzerou) {
	const char retazec[] = "a b";
	ASSERT_FALSE(containsNotAllowedCharacter(retazec));
}
TEST(SecondTaskTests, bezVelkychPismen) {
  const char retazec[] = "askok234235*()*()213 asada;;;-/";
  ASSERT_EQ(numberOfCharactersOfCertainType(retazec, CAPITAL_LETTER), 0);
}

TEST(SecondTaskTests, pocetVelkychPismen) {
  ASSERT_EQ(numberOfCharactersOfCertainType("wev AOPJ JCP s", CAPITAL_LETTER), 7);
}

TEST(SecondTaskTests, pocetPismen) {
  ASSERT_EQ(numberOfAlphanumericCharacters("wev AOPJ J215CP s"), 14);
}

TEST(SecondTaskTests, pocetVelkychPismen4) {
    const char retazec[] = "askOk234235*Q()*()213 Asada;;B;-/";
    ASSERT_EQ(numberOfCharactersOfCertainType(retazec, CAPITAL_LETTER), 4);
}

TEST(SecondTaskTests, pocetZnakov) {
	const char retazec[] = " askok234\\2\n35*()*()2 \t13 asa\vda;;\";-/   ";
	int pocetNepovolenychZnakov = 0;
	int retazecSize = numberOfAllCharacters(retazec);
	for (unsigned int i = 0; i < retazecSize; i++) {
		if (typeOfCharacter(retazec[i]) == NOT_ALLOWED) {
			pocetNepovolenychZnakov++;
		}
	}
	ASSERT_EQ(pocetNepovolenychZnakov, 5);
	ASSERT_EQ(retazecSize - pocetNepovolenychZnakov, 36);
}

TEST(SecondTaskTests, pocetNePovolenychZnakov) {
	const char retazec[] = " \\\n \t   ";
	auto pocetNepovolenychZnakov = 0;
	for (unsigned int i = 0; i < numberOfAllCharacters(retazec); i++) {
		if (typeOfCharacter(retazec[i]) == NOT_ALLOWED) {
			pocetNepovolenychZnakov++;
		}
	}
	ASSERT_EQ(pocetNepovolenychZnakov, 3);
}

TEST(SecondTaskTests, pocetInychZnakov) {
	const char retazec[] = " askok234235*()*()213 asada;;;-/   ";
	ASSERT_EQ(numberOfCharactersOfCertainType(retazec, OTHER), 11);
}

TEST(SecondTaskTests, bezInychZnakov) {
	const char retazec[] = " askok   234235213 \\\n \t \r\" asada   ";
	ASSERT_EQ(numberOfCharactersOfCertainType(retazec, OTHER), 0);
}

TEST(SecondTaskTests, ibaAlphanum) {
  const char retazec[] = "abcd989898KASans0";
  ASSERT_TRUE(containsOnlyAlphanumericCharacters(retazec));
}

TEST(SecondTaskTests, ibaq) {
  const char retazec[] = "q";
  ASSERT_TRUE(containsOnlyAlphanumericCharacters(retazec));
}

TEST(SecondTaskTests, ajMedzera) {
  const char retazec[] = "abcd989898KASans0 ";
  ASSERT_FALSE(containsOnlyAlphanumericCharacters(retazec));
}

TEST(SecondTaskTests, ibaLine) {
  const char retazec[] = "abcd989898KASa\ns0";
  ASSERT_FALSE(containsOnlyAlphanumericCharacters(retazec));
}

TEST(SecondTaskTests, numberOfAllDigits10000) {
  char *retazec = new char[30000];
  strcpy(retazec, "");
  for (unsigned int i = 0; i < 999; i++)	{
    strcat(retazec, "xx0123ab4567x89cd");
  }
  ASSERT_EQ(numberOfCharactersOfCertainType(retazec, DIGIT), 9990);
  ASSERT_EQ(numberOfCharactersOfCertainType(retazec, SMALL_LETTER), 6993);
}
