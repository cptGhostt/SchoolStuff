// Copyright 2005, Google Inc.
// All rights reserved.
#include <iostream>
#include "gtest/gtest.h"
#include "getText.h"
using namespace ::testing;

//Uloha 1.
TEST(TestsFirstTask, Hello) {
	ASSERT_EQ(getText("Hello World !!!!"), "Hello World !!!!");
}
TEST(TestsFirstTask, Bongiorno) {
	std::string temp = "Bongiorno!";
	ASSERT_EQ(getText(temp), "Bongiorno!");
}
TEST(TestsFirstTask, Prazdny) {
	ASSERT_EQ(getText(""), "Empty input");
}
TEST(TestsFirstTask, Medzery) {
  ASSERT_EQ(getText("    "), "    ");
}
TEST(TestsFirstTask, Nerovnost) {
  ASSERT_NE(getText("Hello World !"), "Ahoj svet !");
}

