// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"
#include "2_IntegerToString.h"

TEST(TestyDruhejUlohy, minus93208) {
    ASSERT_EQ("-93207", integerIntoDecimalString(-93207));
}

TEST(TestyDruhejUlohy, minus312) {
  std::string temp {"-312"};
    ASSERT_EQ(temp, integerIntoDecimalString(-312));
}

TEST(TestyDruhejUlohy, nula) {
    ASSERT_EQ("0", integerIntoDecimalString(0));
}

TEST(TestyDruhejUlohy, 76543210) {
    ASSERT_EQ("76543210", integerIntoDecimalString(76543210));
}

TEST(TestyDruhejUlohy, minusnula) {
    ASSERT_EQ("0", integerIntoDecimalString(-0));
}

TEST(TestyDruhejUlohy, 932408) {
    ASSERT_EQ("932408", integerIntoNumberTypeString(932408, DECIMAL_INT));
}

TEST(TestyDruhejUlohy, minus52623) {
    ASSERT_EQ("-52623", integerIntoNumberTypeString(-52623, DECIMAL_INT));
}

TEST(TestyDruhejUlohy, minus314) {
    ASSERT_EQ("-314", integerIntoNumberTypeString(-314, DECIMAL_INT));
}

TEST(TestyDruhejUlohy, 0) {
    ASSERT_EQ("0", integerIntoNumberTypeString(0, DECIMAL_INT));
}

TEST(TestyDruhejUlohy, 5) {
    ASSERT_EQ("5", integerIntoNumberTypeString(5, DECIMAL_INT));
}

TEST(TestyDruhejUlohy, minusJedna) {
    ASSERT_EQ("-1", integerIntoNumberTypeString(-1, DECIMAL_INT));
}

TEST(TestyDruhejUlohy, desatVDvojke) {
    ASSERT_EQ("0b10", integerIntoNumberTypeString(2, BINARY_INT));
}

TEST(TestyDruhejUlohy, jedenast) {
    ASSERT_EQ("0b110", integerIntoNumberTypeString(6, BINARY_INT));
}

TEST(TestyDruhejUlohy, minus999) {
    ASSERT_EQ("-0b1111100111", integerIntoNumberTypeString(-999, BINARY_INT));
}

TEST(TestyDruhejUlohy, 111vDvojke) {
    ASSERT_EQ("0b1101111", integerIntoNumberTypeString(111, BINARY_INT));
}

TEST(TestyDruhejUlohy, triOctal) {
    ASSERT_EQ("-03", integerIntoNumberTypeString(-3, OCTAL_INT));
}

TEST(TestyDruhejUlohy, 18Octal) {
    ASSERT_EQ("022", integerIntoNumberTypeString(18, OCTAL_INT));
}

TEST(TestyDruhejUlohy, minus13vOsmicke) {
    ASSERT_EQ("-015", integerIntoNumberTypeString(-13, OCTAL_INT));
}

TEST(TestyDruhejUlohy, 888) {
    ASSERT_EQ("01570", integerIntoNumberTypeString(888, OCTAL_INT));
}

TEST(TestyDruhejUlohy, Naabcdef) {
    ASSERT_EQ("0xabcdef", integerIntoNumberTypeString(11259375, HEXADECIMAL_INT));
}
