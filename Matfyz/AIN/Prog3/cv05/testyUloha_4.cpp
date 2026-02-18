// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "4_Persons.h"

using namespace ::testing;

TEST(TestyStvrtejUlohy, PrazdnyZoznam) {
  Persons persons;
	ASSERT_EQ(0, persons.numberOfRecords());
}
TEST(TestyStvrtejUlohy, JedenPrazdnyRecord) {
  Persons persons;
  persons.append("");
  ASSERT_EQ(0, persons.numberOfRecords());
}
TEST(TestyStvrtejUlohy, JedenRecord) {
  Persons persons;
  persons.append("Adam,Mudry:991231/1999");
  ASSERT_EQ(1, persons.numberOfRecords());
  ASSERT_EQ("Adam,Mudry:991231/1999", persons.get(1));
}
TEST(TestyStvrtejUlohy, DvaRecordy) {
  Persons persons;
  persons.append("Adam,Mudry:991231/1999;Adam,Hlupy:991231/1999");
  ASSERT_EQ(2, persons.numberOfRecords());
  ASSERT_EQ("Adam,Mudry:991231/1999", persons.get(1));
  ASSERT_EQ("Adam,Hlupy:991231/1999", persons.get(2));
}
TEST(TestyStvrtejUlohy, TriaDvaDobreRecordy) {
  Persons persons;
  persons.append("Adam,Mudry:991231/1999;asdasdad;Adam,Hlupy:991231/1999");
  ASSERT_EQ(2, persons.numberOfRecords());
}
TEST(TestyStvrtejUlohy, StyriDobreRecordy) {
  Persons persons;
  persons.append("Adam,Mudry:991231/1999;asdasdad;Adam,Hlupy:991231/1999;Anna,Hrava:220501/2222;Adam,Kahan:991230/1999");
  persons.append("Adam,Hlupy:991231/1999;Anna,Hrava:220501/2222;Adam,Kahan:991230/1999");
  ASSERT_EQ(7, persons.numberOfRecords());
}
TEST(TestyStvrtejUlohy, TriStoRecordov) {
  Persons persons;
  for (int i = 0; i < 100; i++) {
    persons.append("Adam,Hlupy:991231/1999;Anna,Hrava:220501/2222;Adam,Kahan:991230/1999");
  }
  ASSERT_EQ(300, persons.numberOfRecords());
}
TEST(TestyStvrtejUlohy, Record300) {
  Persons persons;
  for (int i = 0; i < 100; i++) {
    persons.append("Adam,Hlupy:991231/1999;Anna,Hrava:220501/2222;Adam,Kahan:011215/2001");
  }
  ASSERT_EQ("Adam,Hlupy:991231/1999", persons.get(1));
  ASSERT_EQ("Adam,Kahan:011215/2001", persons.get(3));
  ASSERT_EQ("Adam,Kahan:011215/2001", persons.get(300));
}
TEST(TestyStvrtejUlohy, Record0) {
  Persons persons;
  for (int i = 0; i < 100; i++) {
    persons.append("Adam,Hlupy:991231/1999;Anna,Hrava:220501/2222;Adam,Kahan:011215/2001");
  }
  ASSERT_EQ("Adam,Hlupy:991231/1999", persons.get(1));
}
TEST(TestyStvrtejUlohy, Record3) {
  Persons persons;
  for (int i = 0; i < 10; i++) {
    persons.append("Adam,Hlupy:991231/1999;Anna,Hrava:220501/2222");
  }
  ASSERT_EQ("Anna,Hrava:220501/2222", persons.get(2));
}
TEST(TestyStvrtejUlohy, Record7) {
  Persons persons;
  for (int i = 0; i < 9; i++) {
    persons.append("Adam,Hlupy:991231/1999;Anna,Hrava:220501/2222");
  }
  ASSERT_EQ("Anna,Hrava:220501/2222", persons.get(8));
}

TEST(TestyStvrtejUlohy, Record4) {
  Persons persons;
  for (int i = 0; i < 15; i++) {
    persons.append("Adam,Hlupy:991231/1999;Anna,Hrava:220501/2222");
  }
  ASSERT_EQ("Anna,Hrava:220501/2222", persons.get(4));
}

