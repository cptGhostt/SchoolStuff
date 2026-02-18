// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "1_VeryLargeInteger.h"

using namespace ::testing;

//Uloha 3.
TEST(TestThirdTask, NegativeNumber) {
    VeryLargeInteger d("-2345212");
    ASSERT_TRUE(d.negativeNumber());
    d.changeNumberSign();
    ASSERT_FALSE(d.negativeNumber());
}


TEST(TestThirdTask, PositiveNumber) {
    VeryLargeInteger d("2234345212");
    ASSERT_FALSE(d.negativeNumber());
    d.changeNumberSign();
    ASSERT_TRUE(d.negativeNumber());
}

TEST(TestThirdTask, NegativeZero) {
    VeryLargeInteger d("-000000000");
    ASSERT_FALSE(d.negativeNumber());
}


TEST(TestThirdTask, ZhodaSoStringom) {
	VeryLargeInteger c("1234567890");
	ASSERT_TRUE(c == "1234567890");
}
TEST(TestThirdTask, NezhodaDvochCisel) {
	VeryLargeInteger c("1234567890");
	VeryLargeInteger b("003189787780012321312123123123213123232300");
	ASSERT_FALSE(c == b);
}
TEST(TestThirdTask, PorovnanieDvochCisel) {
	VeryLargeInteger c("1234567890");
	VeryLargeInteger b("003189787780012321312123123123213123232300");
	ASSERT_FALSE(b < c);
  ASSERT_TRUE(b > c);
}
TEST(TestThirdTask, PorovnanieRovnakych) {
	VeryLargeInteger b("00318978773280012321312123123123213123232300");
	ASSERT_FALSE(b < b);
}
TEST(TestThirdTask, PorovnanieRovnakychNaMensieRovne) {
  VeryLargeInteger b("00318978773280012321312123123123213123232300");
  ASSERT_TRUE(b < b || b == b);
}
TEST(TestThirdTask, PorovnanieSCislom) {
	VeryLargeInteger b("00232300");
	ASSERT_TRUE(b < 232301);
}
TEST(TestThirdTask, PorovnanieSPriradenim) {
	VeryLargeInteger c("1234567890");
	VeryLargeInteger c1 {"1234567891" };
	ASSERT_TRUE(c < c1);
	ASSERT_FALSE(c1 < c);
	ASSERT_TRUE(c < c1);
	ASSERT_FALSE(c1 == c);
}
TEST(TestThirdTask, RovnostSCislom) {
	VeryLargeInteger b("00232300");
	ASSERT_FALSE(b == 232301);
	ASSERT_TRUE(b < 232301);
}
TEST(TestThirdTask, RovnostSCislomCezOperator) {
	VeryLargeInteger b;
	b = 543;
	ASSERT_TRUE(b == 543);
  ASSERT_FALSE(b < 543);
  ASSERT_FALSE(b > 543);
}

TEST(TestThirdTask, PorovnanieSoZlymCislom) {
	VeryLargeInteger b("1234343634x3423");
	ASSERT_FALSE(b ==  "0");
}

TEST(TestThirdTask, PorovnanieSCislomCezOperator) {
	VeryLargeInteger b;
	b = 54321;
	ASSERT_TRUE(b < "22335678932145342325157");
}

TEST(TestThirdTask, PorovnanieDvochZapornych) {
	VeryLargeInteger b;
	b = static_cast<std::string>( "-2233567893213");
	ASSERT_TRUE(b < "-22335678");
}

TEST(TestThirdTask, PorovnanieSoStringom) {
    VeryLargeInteger b {"-2233567893213" };
    ASSERT_TRUE(b == "-2233567893213");
}

TEST(TestThirdTask, PorovnanieNuly) {
    VeryLargeInteger b {" - 0000000000000000 " };
    ASSERT_TRUE(b == "00000");
    ASSERT_TRUE(b <= "00000");
    ASSERT_TRUE(b >= "00000");
}

TEST(TestThirdTask, PorovnanieDvochVelmiVelkychCisel) {
  VeryLargeInteger c("12345678901234567890123456789012345678901234567890");
  VeryLargeInteger b("22345678901234567890123456789012345678901234567890");
  ASSERT_TRUE(b > c);
  ASSERT_TRUE(b >= c);
  ASSERT_FALSE(b <= c);
}

TEST(TestThirdTask, Nenastavene1) {
    VeryLargeInteger c;
    VeryLargeInteger b("22345678901234567890123456789012345678901234567890");
    ASSERT_FALSE(b > c);
}

TEST(TestThirdTask, Nenastavene2) {
    VeryLargeInteger c("12345678901234567890123456789012345678901234567890");
    VeryLargeInteger b;
    ASSERT_FALSE(b > c);
}

TEST(TestThirdTask, NenastaveneObe) {
    VeryLargeInteger c, b;
    ASSERT_FALSE(b < c);
    ASSERT_TRUE(b >= c);
}


