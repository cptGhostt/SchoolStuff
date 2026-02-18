// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "1_VeryLargeInteger.h"

using namespace ::testing;

//Uloha 1.
TEST(TestSecondTask, KopirovaciKonstruktor) {
	VeryLargeInteger b("   00 3189 7877 8001 2321 3121 2312 3123 2131 2323 2300   ");
	VeryLargeInteger a(b);
	ASSERT_EQ("3189787780012321312123123123213123232300", b.get());
}
TEST(TestSecondTask, KopirovanieDoSeba) {
	VeryLargeInteger b("   00 3189 7877 8001 2321 3121 2312 3123 2131 2323 2300   ");
	b = b;
	ASSERT_EQ("3189787780012321312123123123213123232300", b.get());
}
TEST(TestSecondTask, KopirovanieAVlozenie) {
	VeryLargeInteger a("00 3189 8001 3121 2312 3123 2131 2323 2300   ");
	VeryLargeInteger b{a };
	ASSERT_EQ("31898001312123123123213123232300", b.get());
  a.put("566890");
	ASSERT_EQ("566890", a.get());
}
TEST(TestSecondTask, VkladanieZaporneho) {
  VeryLargeInteger f = -1234343;
  ASSERT_EQ("-1234343", f.get());
}
TEST(TestSecondTask, PresuvaciKonstruktor) {
  VeryLargeInteger b("   00 3189 7877 8001 2321 3121 2312 3123 2131 2323 2300   ");
  VeryLargeInteger a(std::move(b));
  ASSERT_EQ("3189787780012321312123123123213123232300", a.get());
  ASSERT_EQ("No number", b.get());
}

TEST(TestSecondTask, KopirovanieCezOperator) {
	VeryLargeInteger a, b("   00 3189 7877 8001 2321 3121 2312 3123 2131 2323 2300   ");
	a = b;
	ASSERT_EQ("3189787780012321312123123123213123232300", b.get());
	ASSERT_EQ("3189787780012321312123123123213123232300", a.get());
}
TEST(TestSecondTask, PresuvanieDoSeba) {
  VeryLargeInteger b("   00 3189 7877 8001 2321 3121 2312 3123 2131 2323 2300   ");
  b = std::move(b);
  ASSERT_EQ("3189787780012321312123123123213123232300", b.get());
}

TEST(TestSecondTask, PresuvanieCezOperator) {
	VeryLargeInteger a, b("   00 3189 7877 8001 2321 3121 2312 3123 2131 2323 2300   ");
	a = std::move(b);
	ASSERT_EQ("No number", b.get());
	ASSERT_EQ("3189787780012321312123123123213123232300", a.get());
}
TEST(TestSecondTask, KopirovanieZapornehoCezOperator) {
	VeryLargeInteger a, b(" -  00 3189 7877 8001 2321 3121 2312 3123 2131 2323 2300   ");
	a = b;
	ASSERT_EQ("-3189787780012321312123123123213123232300", b.get());
	ASSERT_EQ("-3189787780012321312123123123213123232300", a.get());
}
TEST(TestSecondTask, KopirovanieCislaCezOperator) {
	VeryLargeInteger a;
	a = 321;
	ASSERT_EQ("321", a.get());
}
TEST(TestSecondTask, KopirovanieStringuCezOperator) {
	VeryLargeInteger a;
	char s[] {" -  00000003212345678901234567890"};
  a = s;
  ASSERT_EQ("-3212345678901234567890", a.get());
	a = " -  00000003212345678901234567894";
	ASSERT_EQ("-3212345678901234567894", a.get());
}

TEST(TestSecondTask, PresuvanieZoStringu) {
    VeryLargeInteger a;
    std::string b {"   00 3189 7877 8001 2321 3121 2312 3123 2131 2323 2300   "};
    a = std::move(b);
    ASSERT_EQ("3189787780012321312123123123213123232300", a.get());
    ASSERT_EQ("No number", b);
}

TEST(TestSecondTask, PresuvanieZlehoStringu) {
    VeryLargeInteger a;
    std::string b {"32.56"};
    a = std::move(b);
    ASSERT_EQ("No number", a.get());
    ASSERT_EQ("No number", b);
}

TEST(TestSecondTask, ViacnasobneKopirovanie) {
    VeryLargeInteger a, b, c, d, e;
    VeryLargeInteger f("   01 3189 7877 8001 2321 3121 2312 3123 2131 2323 2300   ");
    a = b = c = d = e = f;
    ASSERT_EQ("13189787780012321312123123123213123232300", a.get());
    ASSERT_EQ("13189787780012321312123123123213123232300", d.get());
    ASSERT_EQ("13189787780012321312123123123213123232300", a.get());
    ASSERT_EQ("13189787780012321312123123123213123232300", b.get());
}

TEST(TestSecondTask, ViacnasobnePresuvanie) {
    VeryLargeInteger a, b, c, d, e;
    VeryLargeInteger f("   10 3189 7877 8001 2321 3121 2312 3123 2131 2323 2300   ");
    c = d = e = f;
    a = b = std::move(c);
    ASSERT_EQ("103189787780012321312123123123213123232300", a.get());
    ASSERT_EQ("103189787780012321312123123123213123232300", d.get());
    ASSERT_EQ("No number", c.get());
    ASSERT_EQ("103189787780012321312123123123213123232300", a.get());
    ASSERT_EQ("103189787780012321312123123123213123232300", b.get());
}

