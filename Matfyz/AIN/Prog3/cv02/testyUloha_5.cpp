// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"
#include "5_moreAdaptedPasswordStrength.h"

using namespace ::testing;
using namespace std;

TEST(FifthTaskTests, dlzkaSekvenciePismen) {
  ASSERT_EQ(longestSequenceOfCharacters("abcdefgh"), 8);
  ASSERT_EQ(longestSequenceOfCharacters(""), 0);
  ASSERT_EQ(longestSequenceOfCharacters("wqywxyaw"), 3);
  ASSERT_EQ(longestSequenceOfCharacters("qwertyuio"), 0);
  ASSERT_EQ(longestSequenceOfCharacters("1234 98 2345678"), 7);
  ASSERT_EQ(longestSequenceOfCharacters(" srewg wewe wFEDCBAcsa asdf"), 6);
  ASSERT_EQ(longestSequenceOfCharacters("QRSTUVWXY "), 9);
  ASSERT_EQ(longestSequenceOfCharacters("rq"), 2);
  ASSERT_EQ(longestSequenceOfCharacters("98765 87654321"), 8);
}

TEST(FifthTaskTests, sekvenciaPismen) {
  const char password[] = "abcdefgh";
  ASSERT_EQ(moreAdaptedPasswordStrength(password), VERY_WEAK_PASSWORD);
}

TEST(FifthTaskTests, sekvenciaSilneho) {
  const char password[] = "abcdefgh123";
  ASSERT_EQ(moreAdaptedPasswordStrength(password), WEAK_PASSWORD);
}
TEST(FifthTaskTests, sekvenciaCisel) {
  const char password[] = "456Q";
  ASSERT_EQ(moreAdaptedPasswordStrength(password), VERY_WEAK_PASSWORD);
}
TEST(FifthTaskTests, sekvenciaCiselSilneho) {
  const char password[] = "530x0123456789v";
  ASSERT_EQ(moreAdaptedPasswordStrength(password), WEAK_PASSWORD);
}
TEST(FifthTaskTests, kratkaSekvencia) {
  const char password[] = "Abraahaam01234567890";
  ASSERT_EQ(moreAdaptedPasswordStrength(password), STRONG_PASSWORD);
}

TEST(FifthTaskTests, menejAkoTreba) {
  const char password[] = "AbcdeAss";
  ASSERT_EQ(moreAdaptedPasswordStrength(password), WEAK_PASSWORD);
}
TEST(FifthTaskTests, sekvencia60) {
  const char password[] = "abcdefAss";
  ASSERT_EQ(moreAdaptedPasswordStrength(password), VERY_WEAK_PASSWORD);
}
TEST(FifthTaskTests, SekvenciaPismenSilneho) {
  const char password[] = "aad435efghijklmnopqrst<<<";
  ASSERT_EQ(moreAdaptedPasswordStrength(password), WEAK_PASSWORD);
}
TEST(FifthTaskTests, sekvenciaSilnehoZnakovo) {
  const char password[] = "abcde1>>";
  ASSERT_EQ(moreAdaptedPasswordStrength(password), WEAK_PASSWORD);
}
TEST(FifthTaskTests, sekvenciaDole) {
    const char password[] = "EDCBA1>>";
    ASSERT_EQ(moreAdaptedPasswordStrength(password), WEAK_PASSWORD);
}
