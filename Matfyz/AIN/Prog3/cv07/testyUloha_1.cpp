// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "1_VeryLargeInteger.h"

using namespace ::testing;

//Uloha 1.
TEST(TestFirstTask, NoNumber) {
  VeryLargeInteger d;
  ASSERT_EQ("No number", d.get());
}
TEST(TestFirstTask, ZleCislo) {
	VeryLargeInteger d("12345678901234x6789");
	ASSERT_EQ("No number", d.get());
}
TEST(TestFirstTask, CisloSMedzerami) {
	VeryLargeInteger d(" 0 000 000 012 345 678 901 234 567 890 000 ");
	ASSERT_EQ("12345678901234567890000", d.get());
}
TEST(TestFirstTask, DlhaNula) {
	VeryLargeInteger d("000000000000");
	ASSERT_EQ("0", d.get());
}
TEST(TestFirstTask, Zaporne) {
	VeryLargeInteger d("-413282102");
	ASSERT_EQ("-413282102", d.get());
}
TEST(TestFirstTask, ZapornaNula) {
	VeryLargeInteger d("-00000");
	ASSERT_EQ("0", d.get());
}
TEST(TestFirstTask, VlozCislo) {
	VeryLargeInteger d("-2345212");
	d.put("420352352542352352");
	ASSERT_EQ("420352352542352352", d.get());
}
TEST(TestFirstTask, DlhaNulaSMedzerami) {
	VeryLargeInteger d("   000   0000000000   0000000000000000000000  0000000000000000000000  000000000000000000    ");
	ASSERT_EQ("0", d.get());
}
TEST(TestFirstTask, DlheCislo) {
	VeryLargeInteger d("   777777777777777777777777777777777777777777777777777777777777777777777777777    ");
	ASSERT_EQ("777777777777777777777777777777777777777777777777777777777777777777777777777", d.get());
}

TEST(TestFirstTask, VlozZle) {
    VeryLargeInteger d;
    ASSERT_FALSE(d.put("4203.52352542352352"));
    ASSERT_EQ("No number", d.get());
}
TEST(TestFirstTask, VlozZapornuNulu) {
    VeryLargeInteger d;
    ASSERT_EQ(true, d.put("- 000000 0000000 000000000000000 00000000000000"));
    ASSERT_EQ("0", d.get());
}
TEST(TestFirstTask, VlozZleCislo) {
    VeryLargeInteger d;
    ASSERT_EQ(false, d.put(" - "));
    ASSERT_EQ("No number", d.get());
}

TEST(TestFirstTask, LongLong) {
  VeryLargeInteger	 c(1234567890);
  ASSERT_EQ("1234567890", c.get());
}

TEST(TestFirstTask, ZapornyLongLong) {
  VeryLargeInteger c(-2325135);
  ASSERT_EQ("-2325135", c.get());
}
