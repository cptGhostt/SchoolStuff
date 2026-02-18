// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"
#include "4_NumberToNumber.h"

using namespace ::testing;

TEST(TestyStvrtejUlohy, ZleVstupneCIslo) {
    ASSERT_EQ("Wrong number", conversionFromOneNumberTypeIntoAnother("0b312097", DECIMAL_INT));
}

TEST(TestyStvrtejUlohy, 312097) {
    ASSERT_EQ("312097", conversionFromOneNumberTypeIntoAnother("312097", DECIMAL_INT));
}

TEST(TestyStvrtejUlohy, minus) {
    ASSERT_EQ("-93208", conversionFromOneNumberTypeIntoAnother("-93208", DECIMAL_INT));
}

TEST(TestyStvrtejUlohy, konverziaNuly) {
    ASSERT_EQ("0", conversionFromOneNumberTypeIntoAnother("0b0", DECIMAL_INT));
}

TEST(TestyStvrtejUlohy, patka) {
    ASSERT_EQ("05", conversionFromOneNumberTypeIntoAnother("05", OCTAL_INT));
}

TEST(TestyStvrtejUlohy, ZleCislo) {
    ASSERT_EQ("Wrong number", conversionFromOneNumberTypeIntoAnother("", DECIMAL_INT));
}

TEST(TestyStvrtejUlohy, 5123454321) {
    ASSERT_EQ("-05123454321", conversionFromOneNumberTypeIntoAnother("-05123454321", OCTAL_INT));
}

TEST(TestyStvrtejUlohy, 184) {
    ASSERT_EQ("Wrong number", conversionFromOneNumberTypeIntoAnother("0184", DECIMAL_INT));
}

TEST(TestyStvrtejUlohy, 777777) {
    ASSERT_EQ("0b111111011111111110", conversionFromOneNumberTypeIntoAnother("0773776", BINARY_INT));
}

TEST(TestyStvrtejUlohy, minus1847) {
    ASSERT_EQ("-10587975", conversionFromOneNumberTypeIntoAnother("-0xa18F47", DECIMAL_INT));
}

TEST(TestyStvrtejUlohy, nova100010011110) {
    ASSERT_EQ("0b100010011110", conversionFromOneNumberTypeIntoAnother("0b100010011110", BINARY_INT));
}

TEST(TestyStvrtejUlohy, trojkova1101001111011) {
    ASSERT_EQ("015173", conversionFromOneNumberTypeIntoAnother("0b1101001111011", OCTAL_INT));
}

TEST(TestyStvrtejUlohy, ZJedenastkovejDoStrnastkovej) {
    ASSERT_EQ("0521150", conversionFromOneNumberTypeIntoAnother("0x2A268", OCTAL_INT));
}

TEST(TestyStvrtejUlohy, ZSestnastkovej) {
    ASSERT_EQ("16702650", conversionFromOneNumberTypeIntoAnother("0xFEDCBA", DECIMAL_INT));
}

TEST(TestyStvrtejUlohy, zDecDoHex) {
    ASSERT_EQ("0x4ffb35", conversionFromOneNumberTypeIntoAnother("5241653", HEXADECIMAL_INT));
}

TEST(TestyStvrtejUlohy, MalyOctDoHex) {
    ASSERT_EQ("0x85a", conversionFromOneNumberTypeIntoAnother("04132", HEXADECIMAL_INT));
}

TEST(TestyStvrtejUlohy, MalyDecDoHex) {
    ASSERT_EQ("0x2e", conversionFromOneNumberTypeIntoAnother("46", HEXADECIMAL_INT));
}

TEST(TestyStvrtejUlohy, VstupneCisloMimoLimit2) {
    ASSERT_EQ("Out of limit",
              conversionFromOneNumberTypeIntoAnother("0b1111111111111111111111110000000000000011111", DECIMAL_INT));
}

TEST(TestyStvrtejUlohy, VstupneCisloMimoLimit10) {
    ASSERT_EQ("Out of limit", conversionFromOneNumberTypeIntoAnother("12345678901234567", OCTAL_INT));
}

TEST(TestyStvrtejUlohy, osmickoveNa10) {
    ASSERT_EQ("Out of limit", conversionFromOneNumberTypeIntoAnother("-0555555555555555555555555555", DECIMAL_INT));
}