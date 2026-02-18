// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include <string.h>
#include "gtest/gtest.h"
#include "3_NumberStringToInteger.h"

using namespace ::testing;

TEST(TestyTretejUlohy, limit2) {
  ASSERT_EQ(3, isNumberStringInLimits("0b10"));
}

TEST(TestyTretejUlohy, limit2presneBezJednej) {
  ASSERT_EQ(3, isNumberStringInLimits("0b111111111111111111111111111111"));
}

TEST(TestyTretejUlohy, limit2presne) {
  ASSERT_EQ(3, isNumberStringInLimits("0b1111111111111111111111111111111"));
}

TEST(TestyTretejUlohy, privelke8) {
  ASSERT_EQ(-2, isNumberStringInLimits("05555555555555555555555555555555"));
}

TEST(TestyTretejUlohy, limit2vacsi) {
  ASSERT_EQ(-2, isNumberStringInLimits("0b1111111111111111111111111111111001"));
}

TEST(TestyTretejUlohy, limit10) {
  ASSERT_EQ(0, isNumberStringInLimits("22222"));
}

TEST(TestyTretejUlohy, limit10presne) {
  ASSERT_EQ(0, isNumberStringInLimits("2147483647"));
}

TEST(TestyTretejUlohy, limit10vacsiMinus) {
  ASSERT_EQ(-2, isNumberStringInLimits("-2147483649"));
}

TEST(TestyTretejUlohy, limit8) {
  ASSERT_EQ(1, isNumberStringInLimits("076543210"));
}

TEST(TestyTretejUlohy, limit8akurat) {
  ASSERT_EQ(1, isNumberStringInLimits("017777777777"));
}

TEST(TestyTretejUlohy, limit8vacsi) {
  ASSERT_EQ(-2, isNumberStringInLimits("027777777777"));
}

TEST(TestyTretejUlohy, limit16) {
  ASSERT_EQ(2, isNumberStringInLimits("0xaaa10"));
}

TEST(TestyTretejUlohy, limit16akurat) {
  ASSERT_EQ(2, isNumberStringInLimits("-0x7fffffff"));
}

TEST(TestyTretejUlohy, limit16vacsi) {
  ASSERT_EQ(-2, isNumberStringInLimits("0x8fffffff"));
}

TEST(TestyTretejUlohy, limit16zleCislo) {
  ASSERT_EQ(-1, isNumberStringInLimits("0x8ffffgff"));
}

TEST(TestyTretejUlohy, privelkeLong) {
  ASSERT_EQ(-2, isNumberStringInLimits("9223372036854775807"));
}

TEST(TestyTretejUlohy, overLimit) {
  std::string stringMax = integerIntoNumberTypeString(std::numeric_limits<int>::max(), DECIMAL_INT);
  stringMax += "1";
  char strMax[256];
  strcpy(strMax, stringMax.c_str());
  ASSERT_EQ(-2, isNumberStringInLimits(strMax));
}

TEST(TestyTretejUlohy, dva) {
  ASSERT_EQ(2, convertNumberStringIntoInt("0b10"));
}

TEST(TestyTretejUlohy, 3) {
  ASSERT_EQ(3, convertNumberStringIntoInt("0b11"));
}

TEST(TestyTretejUlohy, 7) {
  ASSERT_EQ(-7, convertNumberStringIntoInt("-0b111"));
}

TEST(TestyTretejUlohy, 14) {
  ASSERT_EQ(-14, convertNumberStringIntoInt("-0b1110"));
}

TEST(TestyTretejUlohy, 109) {
  ASSERT_EQ(109, convertNumberStringIntoInt("0b1101101"));
}

TEST(TestyTretejUlohy, 19254826) {
  ASSERT_EQ(19254826, convertNumberStringIntoInt("19254826"));
}

TEST(TestyTretejUlohy, 502524) {
  ASSERT_EQ(502524, convertNumberStringIntoInt("01725374"));
}

TEST(TestyTretejUlohy, ZLE_CISLO) {
  ASSERT_EQ(-1, convertNumberStringIntoInt("091"));
}

TEST(TestyTretejUlohy, 3647) {
  ASSERT_EQ(-3647, convertNumberStringIntoInt("-07077"));
}

TEST(TestyTretejUlohy, 3584) {
  ASSERT_EQ(3584, convertNumberStringIntoInt("07000"));
}

TEST(TestyTretejUlohy, minus9) {
  ASSERT_EQ(-10, convertNumberStringIntoInt("-012"));
}

TEST(TestyTretejUlohy, zlePrazdne) {
  ASSERT_EQ(-1, convertNumberStringIntoInt(""));
}

TEST(TestyTretejUlohy, 51) {
  ASSERT_EQ(51, convertNumberStringIntoInt("0x33"));
}

TEST(TestyTretejUlohy, aBcDeF) {
  ASSERT_EQ(11259375, convertNumberStringIntoInt("0xaBcDeF"));
}

TEST(TestyTretejUlohy, cislo10vacsi) {
  ASSERT_EQ(-2, convertNumberStringIntoInt("-9999999999999999"));
}

TEST(TestyTretejUlohy, cislo8vacsi) {
  ASSERT_EQ(-2, convertNumberStringIntoInt("-05555555555555555555555555555555"));
}

TEST(TestyTretejUlohy, cislo16vacsiLong) {
  ASSERT_EQ(-2, convertNumberStringIntoInt("-0x8ffffffff"));
}

TEST(TestyTretejUlohy, wrongHex) {
  ASSERT_EQ(-1, convertNumberStringIntoInt("0x8ffffg"));
}

TEST(TestyTretejUlohy, hexOutOfLimit) {
  ASSERT_EQ(-2, convertNumberStringIntoInt("-0x8ffffffff"));
}

