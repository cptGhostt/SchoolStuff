// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace std;

#include "1_Time.h"

using namespace ::testing;

//Uloha 1.
TEST(TestFirstTask, PrazdnyCas) {
	Time cas;
    ASSERT_EQ("No time", cas.getTime());
    ASSERT_EQ("No time", cas.getStatus());
}
TEST(TestFirstTask, CasNormalny) {
	Time cas;
	istringstream is("05:33:21,510");
	is >> cas;
    ASSERT_EQ("05:33:21,510", cas.getTime());
}
TEST(TestFirstTask, ZlyCas) {
  Time cas;
  istringstream is("05:33:121,1510");
  ASSERT_FALSE(is >> cas);
  ASSERT_EQ("Second out of limits", cas.getStatus());
}
TEST(TestFirstTask, ZapornyCas) {
  Time cas;
  istringstream is("-05:33:21,510");
  ASSERT_FALSE(is >> cas);
  ASSERT_EQ("Hour out of limits", cas.getStatus());
}
TEST(TestFirstTask, ZlyZapornyCas) {
  Time cas;
  istringstream is("05:33:-21,510");
  ASSERT_FALSE(is >> cas);
  ASSERT_EQ("Second out of limits", cas.getStatus());
}
TEST(TestFirstTask, CorrectTime) {
  Time cas;
  istringstream is("00:33:21,510");
  is >> cas;
	ASSERT_EQ("00:33:21,510", cas.getTime());
}

TEST(TestFirstTask, wrongFormat) {
	Time cas;
  istringstream is("00:33:21:510");
  ASSERT_FALSE(is >> cas);
  ASSERT_EQ("Wrong time format", cas.getStatus());
}
TEST(TestFirstTask, ZlyOddelovac) {
  Time cas;
  istringstream is("00:33:21;510");
  ASSERT_FALSE(is >> cas);
  ASSERT_EQ("Wrong time format", cas.getStatus());
}
TEST(TestFirstTask, ZlyFormatCasu) {
  Time cas;
  istringstream is("00:33:");
  ASSERT_FALSE(is >> cas);
  ASSERT_EQ("Wrong time format", cas.getStatus());
}
TEST(TestFirstTask, VelkaHodina) {
  Time cas;
  istringstream is("231:33:44,321");
  ASSERT_FALSE(is >> cas);
  ASSERT_EQ("Hour out of limits", cas.getStatus());
}
TEST(TestFirstTask, CasIbaSMedzerami) {
  Time cas;
  istringstream is("00 33 43 654");
  ASSERT_FALSE(is >> cas);
  ASSERT_EQ("Wrong time format", cas.getStatus());
}
TEST(TestFirstTask, CasIbaSDvojbodkami) {
  Time cas;
  istringstream is("00:33:43:654");
  ASSERT_FALSE(is >> cas);
  ASSERT_EQ("Wrong time format", cas.getStatus());
}
TEST(TestFirstTask, DobryCas) {
  Time cas;
  istringstream is("12:33:43,654");
  ASSERT_TRUE(is >> cas);
  ASSERT_EQ("OK", cas.getStatus());
}
TEST(TestFirstTask, VypisCasu) {
  Time cas;
  istringstream is("22:12:52,513");
  is >> cas;
	ASSERT_EQ("22:12:52,513", cas.getTime());
}
TEST(TestFirstTask, Kopia) {
  Time cas, cas1;
  istringstream is("22:12:52,513");
  is >> cas;
  cas1 = cas;
  ASSERT_EQ("22:12:52,513", cas1.getTime());
}
TEST(TestFirstTask, VypisCasuSNulami) {
  Time cas;
  istringstream is("00:02:02,010");
  is >> cas;
	ASSERT_EQ("00:02:02,010", cas.getTime());
}
TEST(TestFirstTask, PorovnanieCasov) {
	Time cas;
  istringstream is("22:12:52,513");
  is >> cas;
  Time cas1;
  istringstream is1("23:12:52,513");
  is1 >> cas1;
  ASSERT_FALSE(cas1 < cas);
	ASSERT_TRUE(cas < cas1);
}
TEST(TestFirstTask, PorovnanieRovnakych) {
	Time cas;
  istringstream is("22:12:52,513");
  is >> cas;
	ASSERT_FALSE(cas < cas);
}
TEST(TestFirstTask, PorovnanieSekund) {
	Time cas;
  istringstream is("3:12:53,513");
  is >> cas;
	Time cas1;
  istringstream is1("3:12:52,513");
  is1 >> cas1;
    ASSERT_FALSE(cas < cas1);
    ASSERT_FALSE(cas1 < cas1);
}

TEST(TestFirstTask, mojTest) {
  Time cas;
  istringstream is("00:02:418,949");
  ASSERT_FALSE(is >> cas);
  ASSERT_EQ("Second out of limits", cas.getStatus());
}

TEST(TestFirstTask, mojTest2) {
  Time cas;
  istringstream is("00:x02:16,488");
  ASSERT_FALSE(is >> cas);
}