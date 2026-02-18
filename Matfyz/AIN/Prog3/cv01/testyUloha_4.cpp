#include <iostream>

#include "gtest/gtest.h"
#include "isDecimalNumber.h"

using namespace ::testing;

//Uloha 4.
TEST(TestsFourthTask, number) {
    ASSERT_TRUE(isDecimalNumber("2.2"));
}

TEST(TestsFourthTask, DelimiterComma) {
    ASSERT_TRUE(isDecimalNumber("123,0789"));
}

TEST(TestsFourthTask, dveBodkySpolu) {
	ASSERT_FALSE(isDecimalNumber("2..2"));
}
TEST(TestsFourthTask, dveBodky) {
    ASSERT_FALSE(isDecimalNumber("1.2.3"));
}
TEST(TestsFourthTask, minusBodka) {
	ASSERT_FALSE(isDecimalNumber("-.2"));
}
TEST(TestsFourthTask, dveCiarky) {
    ASSERT_FALSE(isDecimalNumber("2,,2"));
}
TEST(TestsFourthTask, dveCiarkyNieSpolu) {
    ASSERT_FALSE(isDecimalNumber("1,2,3"));
}
TEST(TestsFourthTask, BodkaCiarka) {
    ASSERT_FALSE(isDecimalNumber("1.2,3"));
}
TEST(TestsFourthTask, minusDveBodky) {
    ASSERT_FALSE(isDecimalNumber("-.2.5"));
}
TEST(TestsFourthTask, prazdny) {
	ASSERT_FALSE(isDecimalNumber(""));
}
TEST(TestsFourthTask, nula) {
    ASSERT_FALSE(isDecimalNumber("0"));
}
TEST(TestsFourthTask, dvaMinusy) {
	ASSERT_FALSE(isDecimalNumber("-0-"));
}
TEST(TestsFourthTask, bodkaCisloBodka) {
	ASSERT_FALSE(isDecimalNumber(".9."));
}
TEST(TestsFourthTask, cisloMinus) {
	ASSERT_FALSE(isDecimalNumber("8-"));
}
TEST(TestsFourthTask, kombinacia) {
	ASSERT_FALSE(isDecimalNumber("5-8-"));
}
TEST(TestsFourthTask, ibaBodka) {
  ASSERT_FALSE(isDecimalNumber("."));
}
TEST(TestsFourthTask, minus) {
  ASSERT_FALSE(isDecimalNumber("-"));
}
TEST(TestsFourthTask, minusCiarka) {
  ASSERT_FALSE(isDecimalNumber("-,"));
}
TEST(TestsFourthTask, plusCislo) {
    ASSERT_FALSE(isDecimalNumber("+0.2"));
}
TEST(TestsFourthTask, plusCisloCiarka) {
    ASSERT_FALSE(isDecimalNumber("+43,223"));
}

TEST(TestsFourthTask, minusFive) {
    ASSERT_FALSE(isDecimalNumber("-5"));
}

TEST(TestsFourthTask, NoDelimiter) {
    ASSERT_FALSE(isDecimalNumber("222"));
}

TEST(TestsFourthTask, AferDecimal) {
    ASSERT_FALSE(isDecimalNumber("24."));
}

TEST(TestsFourthTask, Testovac1) {
    ASSERT_TRUE(isDecimalNumber("6,7"));
}
