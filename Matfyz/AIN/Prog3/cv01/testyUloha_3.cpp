// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"
#include "numberOfOccurrences.h"

using namespace ::testing;

//Uloha 2.
TEST(TestsThirdTask, Aaaa) {
  ASSERT_EQ(numberOfOccurrences("Aaaa", "aaa"), 1);
}
TEST(TestsThirdTask, AaaaB) {
  ASSERT_EQ(numberOfOccurrences("AaaaB", "aaa"), 1);
}
TEST(TestsThirdTask, bc) {
	ASSERT_EQ(numberOfOccurrences("aabbccaabcdeeaa", "bc"), 2);
}
TEST(TestsThirdTask, bbc) {
	ASSERT_EQ(numberOfOccurrences("aabbccaaddeeaa", "bbc"), 1);
}
TEST(TestsThirdTask, ac) {
	ASSERT_EQ(numberOfOccurrences("aabbccaaddeeaa", "ac"), 0);
}
TEST(TestsThirdTask, ziadna) {
  ASSERT_EQ(numberOfOccurrences("abcd", "cde"), 0);
}
TEST(TestsThirdTask, mensia) {
  ASSERT_EQ(numberOfOccurrences("bbc", "bbcc"), 0);
}
TEST(TestsThirdTask, aabbccaabcdeeaa) {
  ASSERT_EQ(numberOfOccurrences("aabbccaabcdeeaa", "aabbccaabcdeeaa"), 1);
}
