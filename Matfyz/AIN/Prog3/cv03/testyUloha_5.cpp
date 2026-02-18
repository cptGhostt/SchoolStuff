// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"
#include "5_BitOperators.h"

using namespace ::testing;

TEST(TestyPiatejUlohy, AND_0) {
	ASSERT_EQ("0b000000", binaryAND("0b000000", "0b000000"));
}

TEST(TestyPiatejUlohy, WrongBinary) {
  ASSERT_EQ("Wrong binary number", binaryAND("0b1", "043"));
}

TEST(TestyPiatejUlohy, AND_1) {
    ASSERT_EQ("0b000001", binaryAND("0b000001", "0b000001"));
}

TEST(TestyPiatejUlohy, AND_1s) {
    ASSERT_EQ("0b000001", binaryAND("0b101011", "0b000001"));
}

TEST(TestyPiatejUlohy, AND_10101010) {
    ASSERT_EQ("0b10101010", binaryAND("0b10101010", "0b11111111"));
}

TEST(TestyPiatejUlohy, AND_Kratsi) {
  ASSERT_EQ("0b1010", binaryAND("0b10101010", "0b1111"));
}

TEST(TestyPiatejUlohy, AND_WrongFirst) {
    ASSERT_EQ("Wrong binary number", binaryAND("0b1010.010", "0b1111111"));
}

TEST(TestyPiatejUlohy, AND_WrongSecond) {
    ASSERT_EQ("Wrong binary number", binaryAND("0b1010010", "0b111x11111"));
}

TEST(TestyPiatejUlohy, AND_shortFirst) {
    ASSERT_EQ("0b10", binaryAND("0b10", "0b11111111"));
}

TEST(TestyPiatejUlohy, AND_shortSecond) {
    ASSERT_EQ("0b100", binaryAND("0b10101110", "0b101"));
}

TEST(TestyPiatejUlohy, AND_OutOfLimit) {
    ASSERT_EQ(     "0b0000000000001010101010000000000010101010101010000000101010",
         binaryAND("0b1010101010101010101010101010101010101010101010101010101010",
                   "0b000000000000000011111111111000000000011111111111111000000111111"));
}

TEST(TestyPiatejUlohy, AND_dlhy) {
    ASSERT_EQ("0b000000010101010000101010", binaryAND("0b010101000001010101010000101010", "0b111110011111110000111111"));
}

TEST(TestyPiatejUlohy, AND_dlhy2) {
    ASSERT_EQ("0b111000011111000000111100", binaryAND("0b11111001111111000011111100", "0b111110011111110000111111"));
}

TEST(TestyPiatejUlohy, OR_0) {
    ASSERT_EQ("0b000000", binaryOR("0b000000", "0b000000"));
}

TEST(TestyPiatejUlohy, OR_1) {
    ASSERT_EQ("0b000001", binaryOR("0b000001", "0b000001"));
}

TEST(TestyPiatejUlohy, OR_1s) {
    ASSERT_EQ("0b101011", binaryOR("0b101011", "0b000001"));
}

TEST(TestyPiatejUlohy, OR_10101010) {
    ASSERT_EQ("0b11111111", binaryOR("0b10101010", "0b11111111"));
}

TEST(TestyPiatejUlohy, OR_WrongFirst) {
    ASSERT_EQ("Wrong binary number", binaryOR("0b1010.010", "0b1111111"));
}

TEST(TestyPiatejUlohy, OR_WrongSecond) {
    ASSERT_EQ("Wrong binary number", binaryOR("0b1010010", "0b111x11111"));
}

TEST(TestyPiatejUlohy, OR_shortFirst) {
    ASSERT_EQ("0b11111111", binaryOR("0b10", "0b11111111"));
}

TEST(TestyPiatejUlohy, OR_shortSecond) {
    ASSERT_EQ("0b10101111", binaryOR("0b10101110", "0b101"));
}

TEST(TestyPiatejUlohy, OR_OutOfLimit) {
    ASSERT_EQ("0b111101010101010111111111111101010101011111111111111101010111111",
              binaryOR("0b1010101010101010101010101010101010101010101010101010101010",
                  "0b111100000000000011111111111000000000011111111111111000000111111"));
}

TEST(TestyPiatejUlohy, OR_dlhy) {
    ASSERT_EQ("0b010101111111011111110000111111", binaryOR("0b010101000001010101010000101010", "0b111110011111110000111111"));
}

TEST(TestyPiatejUlohy, OR_dlhy2) {
    ASSERT_EQ("0b11111111111111110011111111", binaryOR("0b11111001111111000011111100", "0b111110011111110000111111"));
}

TEST(TestyPiatejUlohy, negation_0) {
    ASSERT_EQ("0b111111", binaryNegation("0b000000"));
}

TEST(TestyPiatejUlohy, negation_1) {
    ASSERT_EQ("0b111110", binaryNegation("0b000001"));
}

TEST(TestyPiatejUlohy, negation_1s) {
    ASSERT_EQ("0b010100", binaryNegation("0b101011"));
}

TEST(TestyPiatejUlohy, negation_10101010) {
    ASSERT_EQ("0b01010101", binaryNegation("0b10101010"));
}

TEST(TestyPiatejUlohy, negation_Wrong) {
    ASSERT_EQ("Wrong binary number", binaryNegation("0b1010.010"));
}

TEST(TestyPiatejUlohy, negation_shortFirst) {
    ASSERT_EQ("0b0", binaryNegation("0b1"));
}

TEST(TestyPiatejUlohy, negation_OutOfLimit) {
    ASSERT_EQ("0b0101010101010101010101010101010101010101010101010101010101", binaryNegation("0b1010101010101010101010101010101010101010101010101010101010"));
}

TEST(TestyPiatejUlohy, negation_dlhy) {
    ASSERT_EQ("0b101010111110101010101111010101", binaryNegation("0b010101000001010101010000101010"));
}

TEST(TestyPiatejUlohy, shiftRight_0) {
    ASSERT_EQ("0b000000", binaryRightShift("0b000000", 2));
}

TEST(TestyPiatejUlohy, rightShift_1) {
    ASSERT_EQ("0b000000", binaryRightShift("0b000001", 42));
}

TEST(TestyPiatejUlohy, rightShift_1s) {
    ASSERT_EQ("0b001010", binaryRightShift("0b101011", 2));
}

TEST(TestyPiatejUlohy, rightShift_10101010) {
    ASSERT_EQ("0b00001010", binaryRightShift("0b10101010", 4));
}

TEST(TestyPiatejUlohy, rightShift_Wrong) {
    ASSERT_EQ("Wrong binary number", binaryRightShift("0b1010.010", 2));
}

TEST(TestyPiatejUlohy, rightShift_shortFirst) {
    ASSERT_EQ("0b0", binaryRightShift("0b1", 1));
}

TEST(TestyPiatejUlohy, rightShift_OutOfLimit) {
    ASSERT_EQ("0b0010101010101010101010101010101010101010101010101010101010", binaryRightShift("0b1010101010101010101010101010101010101010101010101010101010", 2));
}

TEST(TestyPiatejUlohy, rightShift_dlhy) {
    ASSERT_EQ("0b000000000000010101000001010101", binaryRightShift("0b010101000001010101010000101010", 12));
}

TEST(TestyPiatejUlohy, OR_LongFirst) {
  ASSERT_EQ(
    "0b111101010101010111111111111101010101011111111111111101010111111",
    binaryOR(
          "0b111101010101010101010101010101010101010101010101010101010101010",
               "0b0000000000011111111111000000000011111111111111000000111111")
  );
}
