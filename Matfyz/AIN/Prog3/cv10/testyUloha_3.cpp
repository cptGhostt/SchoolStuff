// Copyright 2005, Google Inc.
// All rights repopd.

#include <iostream>
#include "gtest/gtest.h"

#include "3_stack.h"
#include "3_queue.h"

using namespace ::testing;

//3. uloha
TEST(TestThirdTask, StackIntEmpty) {
    Stack<int> a;
    ASSERT_TRUE(a.empty());
}

TEST(TestThirdTask, StackInt) {
    Stack<int> a;
    ASSERT_TRUE(a.empty());
    a.push(1);
    a.push(2);
    a.push(3);
    ASSERT_EQ(a.pop(), 3);
    ASSERT_EQ(a.pop(), 2);
}

TEST(TestThirdTask, StackIntEmptyPop) {
    Stack<int> a;
    ASSERT_EQ(a.pop(), 0);
}

TEST(TestThirdTask, StackIntPoEmpty) {
    Stack<int> a;
    a.push(10);
    a.push(20);
    a.push(-10);
    a.pop();
    a.pop();
    a.pop();
    ASSERT_TRUE(a.empty());
}

TEST(TestThirdTask, StackDouble) {
    Stack<double> d;
    d.push(0);
    d.push(5.5);
    d.push(10.1);
    d.push(-73.03);
    d.pop();
    ASSERT_EQ(d.pop(), 10.1);
}

TEST(TestThirdTask, PushStackString) {
    Stack<std::string> a;
    a.push("1");
    a.push("2");
    Stack<std::string> b;
    b.push("10");
    b.push("20");
    b.push("30");
    b.push("40");
    a.push(b);
    a.pop();
    a.pop();
    ASSERT_EQ(a.pop(), "20");
}

TEST(TestThirdTask, PushStack) {
    Stack<int> a;
    a.push(1);
    a.push(2);
    Stack<int> b;
    b.push(10);
    b.push(20);
    b.push(30);
    a.push(b);
    ASSERT_EQ(a.pop(), 30);
}

TEST(TestThirdTask, QueueInt) {
    Queue<int> a;
    ASSERT_EQ(a.pop(), 0);
    a.push(1);
    a.push(2);
    a.push(3);
    ASSERT_EQ(a.front(), 1);
    ASSERT_EQ(a.size(), 3);
    ASSERT_EQ(a.pop(), 1);
    a.push(4);
    a.push(5);
    a.push(6);
    ASSERT_EQ(a.size(), 5);
    ASSERT_EQ(a.front(), 2);
    ASSERT_EQ(a.pop(), 2);
    ASSERT_EQ(a.pop(), 3);
}

TEST(TestThirdTask, QueueDouble) {
    Queue<double> d;
    d.push(1.1);
    d.push(-1.1);
    d.push(3.3);
    d.push(-4.4);
    ASSERT_EQ(d.pop(), 1.1);
    d.pop();
    d.pop();
    ASSERT_EQ(d.pop(), -4.4);
}

TEST(TestThirdTask, QueueAppend) {
    Queue<double> d;
    d.push(1.0);
    d.push(2.2);
    d.push(3.3);
    d.push(-4.4);
    Queue<double> d1;
    d1.push(d);
    ASSERT_EQ(d1.pop(), 1.0);
    d.pop();
    d.pop();
    d.push(d1);
    ASSERT_EQ(d1.pop(), 2.2);
    d.pop();
    d.pop();
    d.pop();
    d.pop();
    d.pop();
    ASSERT_EQ(d.size(), 0);
    ASSERT_EQ(d.pop(), 0);
    ASSERT_EQ(d.size(), 0);
}

TEST(TestThirdTask, PushStackWrong) {
    Stack<int> a;
    a.push(1);
    a.push(2);
    Stack<int> b;
    b.push(10);
    b.push(20);
    b.push(30);
    b.push(40);
    a.push(b);
    ASSERT_EQ(a.pop(), 40);
    ASSERT_EQ(a.pop(), 30);
    ASSERT_EQ(a.pop(), 20);
    ASSERT_EQ(a.pop(), 10);
    ASSERT_EQ(a.pop(), 2);
    ASSERT_EQ(a.pop(), 1);
}

TEST(TestThirdTask, QueueAppendWrong) {
    Queue<double> d;
    d.push(1.0);
    d.push(2.2);
    d.push(3.3);
    d.push(-4.4);
    Queue<double> d1;
    d1.push(d);
    ASSERT_EQ(d1.pop(), 1.0);
    d.pop();
    d.pop();
    d.push(d1);
    ASSERT_EQ(d1.size(), 3);
    d1.pop();
    d.pop();
    d.pop();
    d.pop();
    ASSERT_EQ(d.pop(), 3.3);
}

