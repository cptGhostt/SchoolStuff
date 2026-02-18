// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>

#include "gtest/gtest.h"
#include "numberOfOccurrences.h"

using namespace ::testing;

//Uloha 5.
TEST(TestsFifthTask, aa) {
	ASSERT_EQ(numberOfOccurrences("aabbccaadaadeeaad", "aa"), 4);
}
TEST(TestsFifthTask, normalka) {
	ASSERT_EQ(numberOfOccurrences("aabbccaaddeeaa", "aa"), 3);
}
TEST(TestsFifthTask, viacnasobnaDlhsia) {
	ASSERT_EQ(numberOfOccurrences("aabbccaaddeea", "a"), 5);
}
TEST(TestsFifthTask, viacnasobna) {
	ASSERT_EQ(numberOfOccurrences("aabbccaaddeeab", "a"), 5);
}
TEST(TestsFifthTask, postupka) {
	ASSERT_EQ(numberOfOccurrences("aaaaaa", "aa"), 5);
}
TEST(TestsFifthTask, praznyRetazec) {
	ASSERT_EQ(numberOfOccurrences("", ""), 0);
}
TEST(TestsFifthTask, AaaAaaA) {
  ASSERT_EQ(numberOfOccurrences("AaaAaaA", "aaa"), 0);
}
TEST(TestsFifthTask, same) {
    ASSERT_EQ(numberOfOccurrences("12345", "12345"), 1);
}
TEST(TestsFifthTask, sameLength) {
    ASSERT_EQ(numberOfOccurrences("12345", "23456"), 0);
}

