// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "1_2_array.h"

using namespace ::testing;

//2. uloha
TEST(TestSecondTask, ArrayGetWrong) {
    Array<int> a;
    a.reserve(20);
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.append(5);
    ASSERT_EQ(a[4], 5);
    ASSERT_EQ(a[1], 2);
    ASSERT_EQ(a[-1], 0);
}

TEST(TestSecondTask, ArrayString) {
    Array<std::string> a;
    a.reserve(20);
    a.append("Jedna");
    a.append("Dva");
    a.append("Tri");
    a.append("Styri");
    ASSERT_EQ(a[2], "Tri");
    ASSERT_EQ(a[0], "Jedna");
    ASSERT_EQ(a[1], "Dva");
    ASSERT_EQ(a[3], "Styri");
    ASSERT_EQ(a[-1], "Index out of scope");
    ASSERT_EQ(a.listOfItems(';'), "Jedna;Dva;Tri;Styri");
}

TEST(TestSecondTask, RemoveSome) {
    Array<int> a;
    for (size_t i = 0; i < 15; i++) {
        a.append(i * 10);
    }
    ASSERT_EQ(a.size(), 15);
    ASSERT_TRUE(a.remove(0));
    ASSERT_TRUE(a.remove(0));
    ASSERT_TRUE(a.remove(0));
    ASSERT_EQ(a[1], 40);
    ASSERT_EQ(a.size(), 12);
}

TEST(TestSecondTask, RemoveSomeLast) {
    Array<int> a;
    a.reserve(20);
    for (size_t i = 0; i < 15; i++) {
        a.append(i * 10);
    }
    ASSERT_EQ(a.size(), 15);
    ASSERT_TRUE(a.remove(14));
    ASSERT_TRUE(a.remove(13));
    ASSERT_TRUE(a.remove(12));
    ASSERT_TRUE(a.remove(11));
    ASSERT_FALSE(a.remove(11));
    ASSERT_TRUE(a.remove(10));
    ASSERT_TRUE(a.remove(9));
    ASSERT_EQ(a[0], 0);
    ASSERT_EQ(a.size(), 9);
    ASSERT_EQ(a[8], 80);
    ASSERT_EQ(a.listOfItems(';'), "0;10;20;30;40;50;60;70;80");
}

TEST(TestSecondTask, ArrayIntEmptyPop) {
    Array<int> a;
    ASSERT_FALSE(a.remove(0));
}

TEST(TestSecondTask, ArrayFirstLast) {
    Array<std::string> a;
    a.reserve(10);
    a.append("first");
    a.append("15");
    a.append("abrakadabra");
    ASSERT_EQ(a[0], "first");
    ASSERT_EQ(a[a.size() - 1], "abrakadabra");
}

TEST(TestSecondTask, CopyArray) {
    Array<std::string> a;
    a.reserve(10);
    a.append("first");
    a.append("15");
    a.append("abrakadabra");
    ASSERT_EQ(a[a.size() - 1], "abrakadabra");
    ASSERT_EQ(a[0], "first");
    Array<std::string> b;
    b = a;
    ASSERT_EQ(b[b.size() - 1], "abrakadabra");
    ASSERT_EQ(b[0], "first");
    ASSERT_EQ(a[a.size() - 1], "abrakadabra");
    ASSERT_EQ(a[0], "first");
    ASSERT_EQ(a.listOfItems(';'), "first;15;abrakadabra");
}

TEST(TestSecondTask, CopyWithOperators) {
    Array<std::string> a, b, c, d;
    a.reserve(10);
    a.append("first");
    a.append("15");
    a.append("abrakadabra");
    ASSERT_EQ(a[a.size() - 1], "abrakadabra");
    ASSERT_EQ(a[0], "first");
    d = c = a;
    ASSERT_EQ(d[d.size() - 1], "abrakadabra");
    ASSERT_EQ(c[0], "first");
    ASSERT_EQ(b[0], "Index out of scope");
    ASSERT_EQ(a[a.size() - 1], "abrakadabra");
    ASSERT_EQ(a[0], "first");
}

TEST(TestSecondTask, MoveArray) {
    Array<std::string> a;
    a.append("first");
    a.append("15");
    a.append("abrakadabra");
    ASSERT_EQ(a[a.size() - 1], "abrakadabra");
    ASSERT_EQ(a[0], "first");
    Array<std::string> b;
    b = std::move(a);
    ASSERT_EQ(b[b.size() - 1], "abrakadabra");
    ASSERT_EQ(b[0], "first");
    ASSERT_EQ(a[0], "Index out of scope");
    ASSERT_EQ(a[a.size() - 1], "Index out of scope");
}

TEST(TestSecondTask, MoveWithOperators) {
    Array<std::string> a, b, c, d;
    a.reserve(10);
    a.append("first");
    a.append("15");
    a[0] = "new first";
    a.append("abrakadabra");
    a[88] = "out";
    ASSERT_EQ(a[a.size() - 1], "abrakadabra");
    ASSERT_EQ(a[0], "new first");
    b = std::move(a);
    c = std::move(b);
    d = std::move(c);
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(c.size(), 0);
    ASSERT_EQ(d[d.size() - 1], "abrakadabra");
    ASSERT_EQ(c[0], "Index out of scope");
    ASSERT_EQ(b[0], "Index out of scope");
    ASSERT_EQ(a[a.size() - 1], "Index out of scope");
    ASSERT_EQ(c[0], "Index out of scope");
    ASSERT_EQ(a.listOfItems(';'), "");
}

TEST(TestSecondTask, AddArray) {
    Array<std::string> a;
    a.reserve(10);
    a.append("first");
    a.append("second");
    a.append("third");
    Array<std::string> b;
    b.append("fourth");
    b.append("fifth");
    b.append("sixth");
    a += b;
    ASSERT_EQ(b.size(), 3);
    ASSERT_EQ(a.size(), 6);
    ASSERT_EQ(a[0], "first");
    ASSERT_EQ(a[2], "third");
    ASSERT_EQ(a[3], "fourth");
    ASSERT_EQ(a[5], "sixth");
}
TEST(TestSecondTask, addMoveArray) {
    Array<std::string> a;
    a.reserve(10);
    a.append("first");
    a.append("second");
    a.append("third");
    Array<std::string> b;
    b.append("fourth");
    b.append("fifth");
    b.append("sixth");
    a += move(b);
    ASSERT_EQ(b.size(), 0);
    ASSERT_EQ(a.size(), 6);
    ASSERT_EQ(a[0], "first");
    ASSERT_EQ(a[2], "third");
    ASSERT_EQ(a[3], "fourth");
    ASSERT_EQ(a[5], "sixth");
    ASSERT_EQ(b[0], "Index out of scope");
}

TEST(TestSecondTask, IndexMax) {
    Array<int> a;
    for (size_t i = 0; i < a.maxSize(); i++) {
        a.append(i);
    }
    ASSERT_EQ(a[10], 0);
}

TEST(TestSecondTask, emptyString) {
    Array<std::string> a;
    a.append("Jedna");
    a.append("Dva");
    a.append("Tri");
    a.append("Styri");
    ASSERT_EQ(a[4], "Index out of scope");
}

