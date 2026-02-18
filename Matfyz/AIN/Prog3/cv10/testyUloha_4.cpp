// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "3_queue.h"
#include "4_priorityQueue.h"

using namespace ::testing;

//4. uloha
TEST(TestFourthTask, PriorityQueueInt) {
    PriorityQueue<int> a;
    ASSERT_EQ(a.pop(), 0);
    a.push(3);
    a.push(2);
    ASSERT_EQ(a.front(), 2);
    a.push(1);

    ASSERT_EQ(a.front(), 1);
    ASSERT_EQ(a.pop(), 1);
    a.push(6);
    a.push(5);
    a.push(4);
    ASSERT_EQ(a.list(), "2,3,4,5,6");
    ASSERT_EQ(a.size(), 5);
    ASSERT_EQ(a.front(), 2);
    ASSERT_EQ(a.pop(), 2);
    ASSERT_EQ(a.pop(), 3);
    ASSERT_EQ(a.pop(), 4);
}

TEST(TestFourthTask, PriorityQueueDouble) {
    PriorityQueue<double> d;
    d.push(1.1);
    d.push(-1.1);
    d.push(3.3);
    d.push(1.1);
    d.push(-4.4);
    d.push(-1.1);
    d.push(1.1);
    ASSERT_EQ(d.pop(), -4.4);
    ASSERT_EQ(d.pop(), -1.1);
    ASSERT_EQ(d.pop(), -1.1);
    ASSERT_EQ(d.pop(), 1.1);
    ASSERT_EQ(d.pop(), 1.1);
    ASSERT_EQ(d.pop(), 1.1);
    ASSERT_EQ(d.pop(), 3.3);
}

TEST(TestFourthTask, PriorityQueueString) {
    PriorityQueue<std::string> d;
    d.push("5");
    d.push("1234");
    d.push("Alenka");
    d.push("123");
    d.push("432");
    d.push("");
    d.push("Alena");
    ASSERT_EQ(d.pop(), "");
    ASSERT_EQ(d.pop(), "123");
    ASSERT_EQ(d.pop(), "1234");
    ASSERT_EQ(d.pop(), "432");
    ASSERT_EQ(d.pop(), "5");
    ASSERT_EQ(d.pop(), "Alena");
    ASSERT_EQ(d.size(), 1);
}

TEST(TestFourthTask, PriorityQueueAppend) {
    PriorityQueue<double> d;
    d.push(1.1);
    d.push(-1.1);
    d.push(3.3);
    d.push(-4.4);
    d.push(-1.1);
    ASSERT_EQ(d.size(), 5);
    ASSERT_EQ(d.front(), -4.4);
    ASSERT_EQ(d.list(), "-4.4,-1.1,-1.1,1.1,3.3");
    PriorityQueue<double> d1;
    d1.push(d);
    ASSERT_EQ(d1.list(), "-4.4,-1.1,-1.1,1.1,3.3");
    ASSERT_EQ(d.list(), "-4.4,-1.1,-1.1,1.1,3.3");
    ASSERT_EQ(d1.size(), 5);
    ASSERT_EQ(d1.front(), -4.4);
    ASSERT_EQ(d.pop(), -4.4);
    ASSERT_EQ(d1.pop(), -4.4);
    ASSERT_EQ(d.pop(), -1.1);
    d.push(d1);
    ASSERT_EQ(d.list(), "-1.1,-1.1,-1.1,1.1,1.1,3.3,3.3");
    ASSERT_EQ(d.size(), 7);
    ASSERT_EQ(d1.size(), 4);
    ASSERT_EQ(d1.pop(), -1.1);
    ASSERT_EQ(d.pop(), -1.1);
    ASSERT_EQ(d.pop(), -1.1);
    ASSERT_EQ(d.pop(), -1.1);
    ASSERT_EQ(d.size(), 4);
    ASSERT_EQ(d.pop(), 1.1);
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d.pop(), 1.1);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d.list(), "3.3,3.3");
}

TEST(TestFourthTask, AppendString) {
    PriorityQueue<std::string> d, d1;
    d.push("5");
    d.push("1234");
    d.push("Alenka");
    d1.push("123");
    d1.push("432");
    d1.push("");
    d.push("Alena");
    ASSERT_EQ(d.list(), "1234,5,Alena,Alenka");
    ASSERT_EQ(d1.list(), ",123,432");
    d1.push(d);
    ASSERT_EQ(d1.list(), ",123,1234,432,5,Alena,Alenka");
    d.push(d1);
    ASSERT_EQ(d.list(), ",123,1234,1234,432,5,5,Alena,Alena,Alenka,Alenka");
}

TEST(TestFourthTask, greaterOrder) {
    PriorityQueue<int> a;
    a.setOrder(bigger<int>);
    ASSERT_EQ(a.pop(), 0);
    a.push(3);
    a.push(2);
    ASSERT_EQ(a.front(), 3);
    a.push(1);
    ASSERT_EQ(a.front(), 3);
    ASSERT_EQ(a.size(), 3);
    ASSERT_EQ(a.list(), "3,2,1");
    ASSERT_EQ(a.pop(), 3);
    a.push(6);
    a.push(5);
    a.push(5);
    a.push(4);
    a.push(1);
    ASSERT_EQ(a.list(), "6,5,5,4,2,1,1");
    ASSERT_EQ(a.size(), 7);
    ASSERT_EQ(a.front(), 6);
    ASSERT_EQ(a.pop(), 6);
    ASSERT_EQ(a.pop(), 5);
    ASSERT_EQ(a.pop(), 5);
    ASSERT_EQ(a.list(), "4,2,1,1");
}

TEST(TestFourthTask, greaterString) {
    PriorityQueue<std::string> d;
    d.setOrder(bigger<std::string>);
    d.push("4321");
    d.push("1234");
    d.push("Alenka");
    d.push("123");
    d.push("432");
    d.push("Betka");
    ASSERT_EQ(d.size(), 6);
    ASSERT_EQ(d.list(), "Betka,Alenka,4321,432,1234,123");
    PriorityQueue<std::string> s;
    s.setOrder(lesser<std::string>);
    s.push(d);
    ASSERT_EQ(s.list(), "123,1234,432,4321,Alenka,Betka");
}

TEST(TestFourthTask, firstInFirstOut) {
    PriorityQueue<std::string> d;
    d.setOrder(fifo<std::string>);
    d.push("4321");
    d.push("1234");
    d.push("Alenka");
    d.push("123");
    d.push("432");
    d.push("Betka");
    ASSERT_EQ(d.size(), 6);
    ASSERT_EQ(d.list(), "4321,1234,Alenka,123,432,Betka");
    PriorityQueue<std::string> s;
    s.setOrder(lesser<std::string>);
    s.push(d);
    ASSERT_EQ(s.list(), "123,1234,432,4321,Alenka,Betka");
}

TEST(TestFourthTask, lastInFirstOut) {
    PriorityQueue<std::string> d;
    d.setOrder(lifo<std::string>);
    d.push("4321");
    d.push("Alenka");
    d.push("123");
    d.push("432");
    d.push("Betka");
    ASSERT_EQ(d.size(), 5);
    ASSERT_EQ(d.list(), "Betka,432,123,Alenka,4321");
}