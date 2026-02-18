// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "5_SelectPersons.h"

using namespace ::testing;

TEST(TestyPiatejUlohy, Recordy2) {
  Persons persons;
  persons.append("Adam,Hlupy:170530/2217;Anna,Hrava:220531/2222");
  ASSERT_EQ(persons.numberOfRecords(), 2);

  SelectPersons selectPersons;
  int number = selectPersons.numberOfPersonsForCriteria(persons, "Day=31");
  ASSERT_EQ(number, 1);
  number = selectPersons.numberOfPersonsForCriteria(persons, "Month=5");
  ASSERT_EQ(number, 2);
}

TEST(TestyPiatejUlohy, RecordyAnna) {
  Persons persons;
  for (int i = 0; i < 15; i++) {
    persons.append("Anna,Hlupa:171231/2017;Anna,Hrava:220531/2222");
  }
  SelectPersons selectPersons;
  
  int number = selectPersons.numberOfPersonsForCriteria(persons, "First name=Anna&Second name=Hrava");
  ASSERT_EQ(number, 15);
  number = selectPersons.numberOfPersonsForCriteria(persons, "First name=Anna");
  ASSERT_EQ(number, 30);
}

TEST(TestyPiatejUlohy, Recordy31) {
  Persons persons;
  for (int i = 0; i < 30; i++) {
    persons.append("Adam,Hlupy:171230/2217;Anna,Hrava:220530/2222;Peter,Slon:110925/111");
  }

  SelectPersons selectPersons;
  int number = selectPersons.numberOfPersonsForCriteria(persons, "Day=30");
  ASSERT_EQ(number, 60);
  number = selectPersons.numberOfPersonsForCriteria(persons, "Day>=25");
  ASSERT_EQ(number, 90);
}

TEST(TestyPiatejUlohy, RecordyAnnien) {
  Persons persons;
  for (int i = 0; i < 15; i++) {
    persons.append("Anna,Hlupa:171231/2017;Anna Maria,Hrava:220531/2222");
  }
  SelectPersons selectPersons;
  int number = selectPersons.numberOfPersonsForCriteria(persons, "First name=Anna Maria&First name=Anna");
  ASSERT_EQ(number, 0);
}

TEST(TestyPiatejUlohy, RecordyMesiacRok) {
  Persons persons;
  for (int i = 0; i < 20; i++) {
    persons.append("Anna,Hlupa:171231/2017;Peter,Kral:120507/2012;Anna Maria,Hrava:120531/2222");
  }
  SelectPersons selectPersons;
  
  int number = selectPersons.numberOfPersonsForCriteria(persons, "Month=5&Year=2012");
  ASSERT_EQ(number, 40);
}

TEST(TestyPiatejUlohy, RecordyMesiacRok3) {
  Persons persons;
  for (int i = 0; i < 15; i++) {
    persons.append("Anna,Hlupa:171231/2017;Peter,Kral:120215/2012;Anna Maria,Hrava:120521/2222");
  }
  SelectPersons selectPersons;
  
  int number = selectPersons.numberOfPersonsForCriteria(persons, "Day>10&Day<25");
  ASSERT_EQ(number, 30);
}
