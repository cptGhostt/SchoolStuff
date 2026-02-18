// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>

#include "gtest/gtest.h"
#include "isDecimalNumber.h"

using namespace ::testing;

//Uloha 3.
TEST(TestsSecondTask, number) {
	ASSERT_TRUE(isDecimalNumber("2.2"));
}

TEST(TestsSecondTask, DelimiterComma) {
    ASSERT_TRUE(isDecimalNumber("123,0789"));
}

TEST(TestsSecondTask, negativeNumber) {
	ASSERT_TRUE(isDecimalNumber("-0,2"));
}

TEST(TestsSecondTask, Zero) {
	ASSERT_TRUE(isDecimalNumber("0.0000"));
}

TEST(TestsSecondTask, moreZeros) {
	ASSERT_TRUE(isDecimalNumber("0002.2"));
}

TEST(TestsSecondTask, WrongLetter) {
	ASSERT_FALSE(isDecimalNumber("22x2"));
}


