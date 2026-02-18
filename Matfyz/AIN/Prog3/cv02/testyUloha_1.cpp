// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"
#include "1_characterType.h"

using namespace ::testing;

//Uloha 1.
TEST(FirstTaskTests, ZeroDigit) {
	ASSERT_EQ(typeOfCharacter('0'), DIGIT);
}

TEST(FirstTaskTests, NineDigit) {
	ASSERT_EQ(typeOfCharacter('9'), DIGIT);
}

TEST(FirstTaskTests, Space) {
    ASSERT_EQ(typeOfCharacter(' '), SPACE);
}

TEST(FirstTaskTests, xNotDigit) {
	ASSERT_FALSE(typeOfCharacter('x') == DIGIT);
}

TEST(FirstTaskTests, minusNotDigit) {
  ASSERT_FALSE(typeOfCharacter('-') == DIGIT);
}

TEST(FirstTaskTests, eofNotDigit) {
	ASSERT_FALSE(typeOfCharacter('\0') == DIGIT);
}

TEST(FirstTaskTests, aSmallLetter) {
	ASSERT_EQ(typeOfCharacter('a'), SMALL_LETTER);
}

TEST(FirstTaskTests, ZCapitalLetter) {
    ASSERT_EQ(typeOfCharacter('Z'), CAPITAL_LETTER);
}

TEST(FirstTaskTests, wNotCapitalLetter) {
    ASSERT_FALSE(typeOfCharacter('w') == CAPITAL_LETTER);
}

TEST(FirstTaskTests, eofNotLetter) {
	ASSERT_FALSE(typeOfCharacter('\0') == SMALL_LETTER);
}

TEST(FirstTaskTests, SpaceNotLetter) {
	ASSERT_FALSE(typeOfCharacter(' ') == SMALL_LETTER);
}

TEST(FirstTaskTests, newLineNotLetter) {
	ASSERT_FALSE(typeOfCharacter('\n') == OTHER);
}

TEST(FirstTaskTests, aNotAllowedSign) {
	ASSERT_FALSE(typeOfCharacter('a') == OTHER);
}

TEST(FirstTaskTests, NotAllowed) {
  ASSERT_TRUE(typeOfCharacter('\n') == NOT_ALLOWED);
}

TEST(FirstTaskTests, QuestionmarkNotAllowed) {
  ASSERT_TRUE(typeOfCharacter('\?') == NOT_ALLOWED);
}

TEST(FirstTaskTests, eofNotAllowed) {
  ASSERT_TRUE(typeOfCharacter('\0') == NOT_ALLOWED);
}

TEST(FirstTaskTests, BAckNotAllowed) {
    ASSERT_TRUE(typeOfCharacter('\\') == NOT_ALLOWED);
}

TEST(FirstTaskTests, DotOther) {
  ASSERT_EQ(typeOfCharacter('.'), OTHER);
}

TEST(FirstTaskTests, qOther) {
  ASSERT_FALSE(typeOfCharacter('q') == OTHER);
}

TEST(FirstTaskTests, aNotOther) {
  ASSERT_FALSE(typeOfCharacter('a') == OTHER);
}

TEST(FirstTaskTests, intZ_A) {
  ASSERT_EQ(charToInt('A'), 65);
}

TEST(FirstTaskTests, intZ_q) {
  ASSERT_EQ(charToInt('p'), 112);
}

TEST(FirstTaskTests, intZ_Lom_n) {
  ASSERT_EQ(charToInt('\n'), 10);
}

TEST(FirstTaskTests, intZ_Lom_0) {
  ASSERT_EQ(charToInt('\0'), 0);
}

TEST(FirstTaskTests, intZ_0) {
  ASSERT_EQ(charToInt('0'), 48);
}

TEST(FirstTaskTests, charZ_0) {
  ASSERT_EQ(intToChar(49), '1');
}

TEST(FirstTaskTests, charZ_72) {
  ASSERT_EQ(intToChar(72), 'H');
}

TEST(FirstTaskTests, charZ_48) {
  ASSERT_EQ(intToChar(48), '0');
}

TEST(FirstTaskTests, charZ_55555) {
  ASSERT_EQ(intToChar(55555), '\0');
}

TEST(FirstTaskTests, charZ_min999) {
  ASSERT_EQ(intToChar(-999), '\0');
}

TEST(FirstTaskTests, charZ_32) {
  ASSERT_EQ(intToChar(32), ' ');
}

TEST(FirstTaskTests, charZ_tab) {
  ASSERT_EQ(intToChar(9), '\t');
}

TEST(FirstTaskTests, charZ_newLine) {
  ASSERT_EQ(intToChar(10), '\n');
}

TEST(FirstTaskTests, charZ_zero) {
  ASSERT_EQ(intToChar(0), '\0');
}

