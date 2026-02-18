// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "5_list.h"

using namespace ::testing;

TEST(TestFifthTask, ListInt) {
    List<int> a;
    ASSERT_EQ(a.size(), 0);
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    ASSERT_EQ(a.size(), 5);
    for (bool elem = a.setCurrent(FIRST); elem == true; elem = a.setCurrent(NEXT)) {
        int currentny = a.current();
    }
    ASSERT_EQ(a.listOfItems(), "5,4,3,2,1");
    a.setCurrent(FIRST);
    ASSERT_EQ(a.deleteCurrent(), 5);
    ASSERT_EQ(a.listOfItems(), "4,3,2,1");
    ASSERT_EQ(a.deleteCurrent(), 4);
    ASSERT_EQ(a.listOfItems(), "3,2,1");
    ASSERT_EQ(a.deleteCurrent(), 3);
    ASSERT_EQ(a.deleteCurrent(), 2);
    ASSERT_EQ(a.deleteCurrent(), 1);
    ASSERT_EQ(a.size(), 0);
}

TEST(TestFifthTask, ListJeden) {
    List<int> a;
    a.insert(5);
    ASSERT_FALSE(a.size() == 0);
    a.deleteCurrent();
    ASSERT_EQ(a.size(), 0);
}
TEST(TestFifthTask, ListDouble) {
    List<double> d;
    d.insert(5.5);
    d.insert(1.1);
    d.insert(-1.1);
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d.deleteCurrent(), -1.1);
    ASSERT_EQ(d.deleteCurrent(), 1.1);
    ASSERT_EQ(d.deleteCurrent(), 5.5);
    ASSERT_EQ(d.size(), 0);
}

TEST(TestFifthTask, ListAppendInt) {
  List<int> a;
  a.insert(5);
  a.append(2);
  a.insert(1);
  a.append(1);
  a.insert(-1);
  ASSERT_EQ(a.tail(), 1);
  ASSERT_EQ(a.head(), -1);
  a.setCurrent(LAST);
  ASSERT_EQ(a.deleteCurrent(), 1);
  a.deleteCurrent();
  a.deleteCurrent();
  a.head();
  a.deleteCurrent();
  a.deleteCurrent();
  ASSERT_EQ(a.size(), 0);
}

TEST(TestFifthTask, ListAppendString) {
  List<std::string> d;
  d.append("first");
  d.append("last");
  ASSERT_EQ(d.tail(), "last");
  ASSERT_EQ(d.head(), "first");
  ASSERT_EQ(d.deleteCurrent(), "first");
  d.deleteCurrent();
  ASSERT_EQ(d.size(), 0);
}

TEST(TestFifthTask, ListInsertInt) {
    List<int> a;
    a.insert(7);
    a.insert(5);
    ASSERT_EQ(a.current(), 5);
    a.insert(3);
    ASSERT_EQ(a.setCurrent(PREVIOUS), false);
    ASSERT_EQ(a.current(), 3);
    a.insert(1);
    a.setCurrent(NEXT);
    ASSERT_EQ(a.current(), 3);
    a.setCurrent(PREVIOUS);
    ASSERT_EQ(a.current(), 1);
    ASSERT_EQ(a.deleteCurrent(), 1);
    ASSERT_EQ(a.current(), 3);
    ASSERT_EQ(a.deleteCurrent(), 3 );
    ASSERT_EQ(a.tail(), 7);
    ASSERT_EQ(a.head(), 5);
    a.deleteCurrent();
    a.deleteCurrent();
    ASSERT_EQ(a.size(), 0);
}

TEST(TestFifthTask, ListInsertDouble) {
    List<double> d;
    d.insert(5.1);
    ASSERT_EQ(d.current(), 5.1);
    d.insert(3.1);
    ASSERT_EQ(d.setCurrent(PREVIOUS), false);
    ASSERT_EQ(d.current(), 3.1);
    d.insert(1.1);
    ASSERT_EQ(d.deleteCurrent(), 1.1);
    ASSERT_EQ(d.current(), 3.1);
}

TEST(TestFifthTask, ListInsertDelete) {
    List<double> d;
    d.insert(5.1);
    d.insert(3.1);
    d.setCurrent(NEXT);
    ASSERT_EQ(d.setCurrent(PREVIOUS), true);
    ASSERT_EQ(d.current(), 3.1);
    d.insert(1.1);
    ASSERT_EQ(d.deleteCurrent(), 1.1);
    ASSERT_EQ(d.deleteCurrent(), 3.1);
    d.deleteCurrent();
    d.insert(4.4);
    ASSERT_EQ(d.deleteCurrent(), 4.4);
}


