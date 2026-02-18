// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"
#include "3_Person.h"

using namespace ::testing;

TEST(TestyTretejUlohy, Empty) {
  Person person;
  person.put("     ");
  ASSERT_EQ(EMPTY_ELEMENT, person.getStatus());
}

TEST(TestyTretejUlohy, Correctperson) {
  Person person;
  person.put("  Jozef-Pavol R. Q.,Mistral:161127/2016   ");
  ASSERT_EQ(person.get(), "Jozef-Pavol R. Q.,Mistral:161127/2016");
}

TEST(TestyTretejUlohy, WrongName) {
  Person person;
  person.put("de_Jozef,Mistral:161127/2016");
  ASSERT_EQ(person.getStatus(), WRONG_CHARACTERS);
}

TEST(TestyTretejUlohy, DigitInName) {
  Person person;
  person.put("Jozef 3.,Mistral:161127/2016");
  ASSERT_EQ(person.getStatus(), WRONG_CHARACTERS);
}

TEST(TestyTretejUlohy, DigitInSecondName) {
  Person person;
  person.put("deJozef,3:161127/2016");
  ASSERT_EQ(person.getStatus(), WRONG_CHARACTERS);
}

TEST(TestyTretejUlohy, Returnperson) {
  Person person;
  person.put("  Adam,Mudry:991231/1999   ");
  ASSERT_EQ("Adam,Mudry:991231/1999", person.get());
  ASSERT_EQ("31.12.1999", person.getDate().date(EU_FORMAT));
  ASSERT_EQ(person.getStatus(), OK);
}

TEST(TestyTretejUlohy, ReturnEmpty) {
  Person person;
  ASSERT_EQ("", person.get());
}

TEST(TestyTretejUlohy, Diff) {
  Person person;
  person.put("Jozef,Mistral:161127/2016");
  Person person1;
  person1.put("Jozefa,Mistral:161127/2016");
  ASSERT_FALSE(person.get() == person1.get());
}

TEST(TestyTretejUlohy, Same) {
  Person person;
  person.put("Jozef I.,de-Mistral:231225/2023");
  Person person1;
  person1.put("Jozef I.,de-Mistral:231225/2023");
  ASSERT_TRUE(person.get() == person1.get());
}

TEST(TestyTretejUlohy, Pointer) {
  Person *person = new Person;
  person->put("Jozef,Mistral:011231/901");
  ASSERT_EQ(person->get(), "Jozef,Mistral:011231/901");
}