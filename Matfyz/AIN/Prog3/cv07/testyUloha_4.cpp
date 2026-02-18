// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "4_OperatorFunctions.h"

using namespace ::testing;

//Uloha 4.
TEST(TestFourthTask, ScitaniePrazdnych) {
    VeryLargeInteger a, b, d;
    d = a + b;
    ASSERT_EQ("No number", d.get());
}

TEST(TestFourthTask, OdcitaniePrazdneho) {
    VeryLargeInteger a("3189787780012321312123123123213123232300");
    VeryLargeInteger b, d;
    d = a - b;
    ASSERT_EQ("3189787780012321312123123123213123232300", d.get());
}

TEST(TestFourthTask, ScitanieDvochKladnych) {
	VeryLargeInteger a("3189787780012321312123123123213123232300");
	VeryLargeInteger c("444"), d;
	d = a + c;
	ASSERT_EQ("3189787780012321312123123123213123232744", d.get());
}
TEST(TestFourthTask, ScitanieKladnehoSNulou) {
	VeryLargeInteger a("3189787780012321312123123123213123232300");
	VeryLargeInteger c, d;
	d = a + c;
	ASSERT_EQ("3189787780012321312123123123213123232300", d.get());
}
TEST(TestFourthTask, ScitanieDvochZapornych) {
	VeryLargeInteger a("-3189787780012321312123123123213123232300");
	VeryLargeInteger c("-6666"), d;
	d = a + c;
	ASSERT_EQ("-3189787780012321312123123123213123238966", d.get());
}
TEST(TestFourthTask, DvojiteScitanieKladnych) {
	VeryLargeInteger a("3189787780012321312123123123213123232300");
	VeryLargeInteger c("444"), d;
	d = a + c;
  a.put("11111");
	d = a + d;
	ASSERT_EQ("3189787780012321312123123123213123243855", d.get());
}
TEST(TestFourthTask, ScitanieNul) {
	VeryLargeInteger e, f;
	f = e + f;
	ASSERT_EQ("No number", f.get());
}
TEST(TestFourthTask, ScitanieDoCelej) {
	VeryLargeInteger a{"999999999999999" }, b{ "1" };
	a = a + b;
	ASSERT_EQ("1000000000000000", a.get());
}
TEST(TestFourthTask, OdcitanieZCelej) {
	VeryLargeInteger a{"1000000000000000" }, b{"-1" };
	a = a + b;
	ASSERT_EQ("999999999999999", a.get());
}
TEST(TestFourthTask, OdcitanieZCelejZaporne) {
	VeryLargeInteger a{"-1000000000000000" }, b{"1" };
	a = a + b;
	ASSERT_EQ("-999999999999999", a.get());
}
TEST(TestFourthTask, OdcitanieZCelejZapornej) {
	VeryLargeInteger a{"-1000000000000000" }, b{"-1" };
	a = a - b;
	ASSERT_EQ("-999999999999999", a.get());
}
TEST(TestFourthTask, OdcitaniePoScitani) {
	VeryLargeInteger a{"-1000000000000000" }, b{"1" };
	a = a + b;
	a = a - b;
	ASSERT_EQ("-1000000000000000", a.get());
}
TEST(TestFourthTask, OdcitanieVelkych) {
	VeryLargeInteger a{"999999999999999" }, b{"999999999990900" };
	a = a - b;
	ASSERT_EQ("9099", a.get());
}
TEST(TestFourthTask, OdcitanieMalych) {
	VeryLargeInteger a{"9099" }, b{"1011" };
	a = a - b;
	ASSERT_EQ("8088", a.get());
}
TEST(TestFourthTask, OpakovaneOdcitanieVelkych) {
	VeryLargeInteger a{"999999999999999" }, b{"999999999990900" };
a = a - b;
b = "1011";
a = a - b;
ASSERT_EQ("8088", a.get());
}
TEST(TestFourthTask, OdcitanieNuly) {
	VeryLargeInteger a{"999999999999999" }, b;
	a = a - b;
	ASSERT_EQ("999999999999999", a.get());
}
TEST(TestFourthTask, OdcitanieNulyOdZaporneho) {
	VeryLargeInteger a{"-9988899999999" }, b;
	a = a - b;
	ASSERT_EQ("-9988899999999", a.get());
}
TEST(TestFourthTask, OdcitanieOdNuly) {
	VeryLargeInteger a{"999999999999999" }, b;
	a = b - a;
	ASSERT_EQ("-999999999999999", a.get());
}
TEST(TestFourthTask, OdcitanieOdNulyOdZaporneho) {
	VeryLargeInteger a{"-9988899999999" }, b;
	a = b - a;
	ASSERT_EQ("9988899999999", a.get());
}
TEST(TestFourthTask, OdcitanieOdNulyNulu) {
	VeryLargeInteger a{"000000000000" }, b;
	a = b - a;
	ASSERT_EQ("0", a.get());
}
TEST(TestFourthTask, OdcitanieSamehoSeba) {
	VeryLargeInteger a{"67969698324326342626234753737" };
	a = a - a;
	ASSERT_EQ("0", a.get());
}
TEST(TestFourthTask, OdcitanieRovnakeho) {
	VeryLargeInteger a{"534346342626234753737" };
	VeryLargeInteger b{"534346342626234753737" };
	a = a - b;
	ASSERT_EQ("0", a.get());
}
TEST(TestFourthTask, OdcitanieCezFunkciu) {
	VeryLargeInteger a{"534346342626234753737" };
    VeryLargeInteger b{"534346342626234753748" };
    VeryLargeInteger (*pointerToFunction)(const VeryLargeInteger &a, const VeryLargeInteger &b);
    pointerToFunction = operator-;
	ASSERT_EQ("-11", pointerToFunction(a, b).get());
}
TEST(TestFourthTask, PripocitanieCezFunkciu) {
	VeryLargeInteger a{"534346342626234753736" };
	VeryLargeInteger (*pointerToFunction)(const VeryLargeInteger &a, const VeryLargeInteger &b);
    pointerToFunction = operator+;
    ASSERT_EQ("1068692685252469507472", pointerToFunction(a, a).get());
}
TEST(TestFourthTask, OdcitanieRovnakehoCezFunkciu) {
    VeryLargeInteger a{"534346342626234753737" };
    VeryLargeInteger (*pointerToFunction)(const VeryLargeInteger &a, const VeryLargeInteger &b);
    pointerToFunction = operator-;
    ASSERT_EQ("0", pointerToFunction(a, a).get());
}
TEST(TestFourthTask, OdcitanieRovnakehoCezCalculate) {
  const VeryLargeInteger a{"534346342626234753737" };
  ASSERT_EQ("0", calculate(operator-, a, a).get());
}
TEST(TestFourthTask, OdcitanieRoznehoCezCalculate) {
  const VeryLargeInteger a{"534346342626234753737" };
  const VeryLargeInteger b{"1068692685252469507474" };
  ASSERT_EQ("-534346342626234753737", calculate(operator-, a, b).get());
}
TEST(TestFourthTask, SpocitanieRovnakehoCezCalculate) {
  const VeryLargeInteger a{"534346342626234753737" };
  ASSERT_EQ("1068692685252469507474", calculate(operator+, a, a).get());
}
TEST(TestFourthTask, PripocitanieRoznehoCezCalculate) {
  const VeryLargeInteger a{"534346342626234753737" };
  const VeryLargeInteger b{"1068692685252469507476" };
  ASSERT_EQ("1603039027878704261213", calculate(operator+, a, b).get());
}

TEST(TestFourthTask, MoreNumbers) {
  VeryLargeInteger a{"5343" };
  VeryLargeInteger b{"43" };
  VeryLargeInteger c;
  c = a + a - b;
  ASSERT_EQ("10643", c.get());
}

TEST(TestFourthTask, MoreNumbers2) {
  VeryLargeInteger a{"5343" };
  VeryLargeInteger b{"43" };
  VeryLargeInteger c;
  c = a - b + a;
  ASSERT_EQ("10643", c.get());
}

TEST(TestFourthTask, SumFive11111) {
  VeryLargeInteger a{"11111" };
  VeryLargeInteger b;
  b = a + a + a + a + a;
  ASSERT_EQ("55555", b.get());
}

TEST(TestFourthTask, AddNumber) {
  VeryLargeInteger a{"1234" };
  VeryLargeInteger b{"6543" };
  a += b;
  ASSERT_EQ("7777", a.get());
}

TEST(TestFourthTask, AddNegative) {
  VeryLargeInteger a{"1234" };
  VeryLargeInteger b{"-1233" };
  a += b;
  ASSERT_EQ("1", a.get());
}

TEST(TestFourthTask, SubtractNumber) {
  VeryLargeInteger a{"1234" };
  VeryLargeInteger b{"42" };
  a -= b;
  ASSERT_EQ("1192", a.get());
}

TEST(TestFourthTask, SubtractNegative) {
  VeryLargeInteger a{"-987654321987654321" };
  VeryLargeInteger b{"987654315000" };
  a -= b;
  ASSERT_EQ("-987655309641969321", a.get());
}

TEST(TestFourthTask, SubtractIdentical) {
  VeryLargeInteger a{"-987654321" };
  a -= a;
  ASSERT_EQ("0", a.get());
}
