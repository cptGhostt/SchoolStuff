// Copyright 2005, Google Inc.
// All rights reserved.
#include <iostream>
#include "gtest/gtest.h"
#include "1_NumberType.h"

using namespace ::testing;

//Uloha 1.
/*
TEST(TestyPrvejUlohy, CelyRetazecJeZIntervalu) {
  ASSERT_TRUE(allCharsFromInterval("a", 'a', 'z'));
  ASSERT_TRUE(allCharsFromInterval("q", 'q', 'q'));
  ASSERT_TRUE(allCharsFromInterval("\n", '\n', '\n'));
  ASSERT_TRUE(allCharsFromInterval("abcdefgs", 'a', 'z'));
  ASSERT_TRUE(allCharsFromInterval("0000000000235235235235", '0', '9'));
  ASSERT_TRUE(allCharsFromInterval("XXX", 'X', 'X'));
}

TEST(TestyPrvejUlohy, CelyRetazecNieJeZIntervalu) {
  ASSERT_FALSE(allCharsFromInterval("a", 'b', 'z'));
  ASSERT_FALSE(allCharsFromInterval("abcdefgs", 'a', 'q'));
  ASSERT_FALSE(allCharsFromInterval("0000000000235235235235", '1', '9'));
  ASSERT_FALSE(allCharsFromInterval("XXX", 'x', 'Z'));
}
*/

TEST(TestyPrvejUlohy, Prazdny) {
    ASSERT_EQ(typeOfNumber(""), WRONG_INTEGER);
}

TEST(TestyPrvejUlohy, MaleCislo) {
	ASSERT_EQ(typeOfNumber("254"), DECIMAL_INT);
}

TEST(TestyPrvejUlohy, Cislo) {
  ASSERT_EQ(typeOfNumber("21421412154"), DECIMAL_INT);
}

TEST(TestyPrvejUlohy, Hex) {
	ASSERT_EQ(typeOfNumber("0x21421412154"), HEXADECIMAL_INT);
    ASSERT_EQ(typeOfNumber("0x2f"), HEXADECIMAL_INT);
    ASSERT_EQ(typeOfNumber("0x0"), HEXADECIMAL_INT);
}

TEST(TestyPrvejUlohy, Oct) {
	ASSERT_EQ(typeOfNumber("0214214"), OCTAL_INT);
}

TEST(TestyPrvejUlohy, 00) {
	ASSERT_EQ(typeOfNumber("00"), OCTAL_INT);
}

TEST(TestyPrvejUlohy, OctX) {
	ASSERT_EQ(typeOfNumber("021421412154"), OCTAL_INT);
}

TEST(TestyPrvejUlohy, PredBinary) {
	ASSERT_EQ(typeOfNumber("0b21421412154"), WRONG_INTEGER);
}

TEST(TestyPrvejUlohy, BezTypuPrazdny) {
	ASSERT_EQ(typeOfNumber(""), WRONG_INTEGER);
}

TEST(TestyPrvejUlohy, BezTypu) {
	ASSERT_EQ(typeOfNumber("qwqqwfdwxqwfxqwz"), WRONG_INTEGER);
}

TEST(TestyPrvejUlohy, TypBinaryPrazdny) {
    ASSERT_EQ(typeOfNumber("0b"), WRONG_INTEGER);
}

TEST(TestyPrvejUlohy, TypHexPrazdny) {
    ASSERT_EQ(typeOfNumber("0x"), WRONG_INTEGER);
}

TEST(TestyPrvejUlohy, TypOctPrazdny) {
    ASSERT_EQ(typeOfNumber("0"), DECIMAL_INT);
}

TEST(TestyPrvejUlohy, ZapornyBinaryPrazdny) {
	ASSERT_EQ(typeOfNumber("-0b"), WRONG_INTEGER);
}

TEST(TestyPrvejUlohy, ZapornyHexPrazdny) {
	ASSERT_EQ(typeOfNumber("-0x"), WRONG_INTEGER);
}

TEST(TestyPrvejUlohy, IbaCislice) {
  ASSERT_EQ(typeOfNumber("852031092"), DECIMAL_INT);
}

TEST(TestyPrvejUlohy, HexIbaCislice) {
  ASSERT_NE(typeOfNumber("0x852031092"), DECIMAL_INT);
}

TEST(TestyPrvejUlohy, MedzeraIbaCislice) {
  ASSERT_EQ(typeOfNumber(" 852031092 "), WRONG_INTEGER);
}

TEST(TestyPrvejUlohy, BinarneCisliceZle) {
  ASSERT_NE(typeOfNumber("852031092"), BINARY_INT);
}

TEST(TestyPrvejUlohy, BinarneCislice) {
  ASSERT_EQ(typeOfNumber("0b110011000101001010"), BINARY_INT);
}

TEST(TestyPrvejUlohy, CisliceNuly) {
  ASSERT_EQ(typeOfNumber("00000000000000"), OCTAL_INT);
}

TEST(TestyPrvejUlohy, OsmickoveCisliceZle) {
  ASSERT_NE(typeOfNumber("0852031092"), OCTAL_INT);
}

TEST(TestyPrvejUlohy, OsmickoveCislice) {
  ASSERT_EQ(typeOfNumber("04213101770"), OCTAL_INT);
}

TEST(TestyPrvejUlohy, HexCisliceZle) {
  ASSERT_EQ(typeOfNumber("85awsfr2031092"), WRONG_INTEGER);
}

TEST(TestyPrvejUlohy, HexKratke) {
  ASSERT_EQ(typeOfNumber("0x4aF1770"), HEXADECIMAL_INT);
}

TEST(TestyPrvejUlohy, HexCislice) {
  ASSERT_EQ(typeOfNumber("0x42abcDEF13101770"), HEXADECIMAL_INT);
}

TEST(TestyPrvejUlohy, HexCisliceNuly) {
  ASSERT_EQ(typeOfNumber("0x00000000000000"), HEXADECIMAL_INT);
}

TEST(TestyPrvejUlohy, DelimitedInt) {
  int test = 13'45678'90;
  ASSERT_EQ(typeOfNumber("134'567'890"), DECIMAL_INT);
}
TEST(TestyPrvejUlohy, DelimitedBinarneCislice) {
  ASSERT_EQ(typeOfNumber("0b11'0011'0001'0100'1010"), BINARY_INT);
}

TEST(TestyPrvejUlohy, DelimitedHexCislice) {
  ASSERT_EQ(typeOfNumber("0x4'2ab'cDE'F13'101'770"), HEXADECIMAL_INT);
}

