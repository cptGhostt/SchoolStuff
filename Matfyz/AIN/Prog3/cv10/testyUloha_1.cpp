// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "1_2_array.h"

using namespace ::testing;

//Uloha 1.
TEST(TestFirstTask, ArrayIntEmpty) {
  Array<int> a;
  ASSERT_EQ(0, a.size());
  ASSERT_EQ(a.listOfItems(';'), "");
}

TEST(TestFirstTask, ArrayTooMuch) {
    Array<int> a;
    ASSERT_FALSE(a.reserve(2));
    a.append(0);
    a.append(1);
    a.append(5);
    ASSERT_FALSE(a.reserve(1));
    ASSERT_EQ(a.size(), 3);
    ASSERT_EQ(a.listOfItems(';'), "0;1;5");
}

TEST(TestFirstTask, WrongReserve) {
    Array<int> a;
    ASSERT_FALSE(a.reserve(0));
    ASSERT_FALSE(a.reserve(-5));
    ASSERT_TRUE(a.reserve(11));
    ASSERT_FALSE(a.reserve(10));
    ASSERT_FALSE(a.reserve(-1));
}

TEST(TestFirstTask, ArrayGet) {
    Array<int> a;
    a.reserve(20);
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.append(5);
    a.append(6);
    a.append(7);
    ASSERT_EQ(a.listOfItems(';'), "1;2;3;4;5;6;7");
    a.remove(3);
    ASSERT_EQ(a.listOfItems(';'), "1;2;3;5;6;7");
    ASSERT_FALSE(a.remove(-1));
    ASSERT_FALSE(a.remove(8));
    ASSERT_EQ(a.listOfItems(';'), "1;2;3;5;6;7");
    a.remove(0);
    ASSERT_EQ(a.listOfItems(';'), "2;3;5;6;7");
}

TEST(TestFirstTask, RemoveElem) {
    Array<int> a;
    a.reserve(20);
    a.append(12);
    a.append(15);
    a.append(-17);
    ASSERT_TRUE(a.remove(a.size() - 1));
    ASSERT_TRUE(a.remove(a.size() - 1));
    ASSERT_EQ(a.size(), 1);
    ASSERT_TRUE(a.remove(a.size() - 1));
    ASSERT_FALSE(a.remove(a.size() - 1));
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(a.listOfItems(';'), "");
}

TEST(TestFirstTask, insertElement) {
    Array<int> a;
    a.insert(5, 0);
    a.append(10);
    ASSERT_EQ(a.size(), 2);
    ASSERT_EQ(a.listOfItems(';'), "5;10");
}

TEST(TestFirstTask, remove) {
    Array<int> a;
    a.append(10);
    a.append(15);
    a.insert(5, 0);
    ASSERT_EQ(a.listOfItems(';'), "5;10;15");
    a.remove(2);
    ASSERT_EQ(a.listOfItems(';'), "5;10");
}

TEST(TestFirstTask, numberOfItems) {
    Array<int> a;
    for (size_t i = 0; i < MAX; i++) {
        a.append(i);
    }
    ASSERT_EQ(a.listOfItems(';'), "0;1;2;3;4;5;6;7;8;9");
    a.append(10);
    a.append(11);
    a.append(12);
    ASSERT_EQ(a.maxSize(), 20);
    ASSERT_EQ(a.listOfItems(';'), "0;1;2;3;4;5;6;7;8;9;10;11;12");
}

TEST(TestFirstTask, insertNegative) {
    Array<int> a;
    a.append(10);
    a.append(15);
    a.insert(5, 0);
    a.insert(0, -1);
    ASSERT_EQ(a.size(), 3);
    ASSERT_EQ(a.listOfItems(';'), "5;10;15");
}

TEST(TestFirstTask, insertElements) {
    Array<int> a;
    a.append(10);
    a.insert(5, 0);
    a.insert(20, 2);
    ASSERT_EQ(a.size(), 3);
    ASSERT_EQ(a.listOfItems(';'), "5;10;20");
}

