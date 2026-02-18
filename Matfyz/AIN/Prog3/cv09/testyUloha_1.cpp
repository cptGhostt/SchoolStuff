// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "1_Time.h"

using namespace ::testing;

//Uloha 1.
TEST(TestFirstTask, PrazdnyCas) {
  Time cas;
  ASSERT_EQ("00:00:00,000", cas.getTime());
}
TEST(TestFirstTask, CasNormalny) {
  Time cas;
  std::istringstream is("05:33:21,510");
  is >> cas;
  ASSERT_EQ("05:33:21,510", cas.getTime());
}
TEST(TestFirstTask, ZlyCas) {
  std::string vynimka;
  try {
    Time cas;
    std::istringstream is("05:33:121,1510");
    is >> cas;
  }
  catch (WrongTime e) {
    vynimka = e.message();
  }
  ASSERT_EQ("Second out of limits", vynimka);
}
TEST(TestFirstTask, ZapornyCas) {
  std::string vynimka;
  try {
    Time cas;
    std::istringstream is("-05:33:21,510");
    is >> cas;
  }
  catch (WrongTime e) {
    vynimka = e.message();
  }
  ASSERT_EQ("Hour out of limits", vynimka);
}
TEST(TestFirstTask, ZlyZapornyCas) {
  std::string vynimka;
  try {
    Time cas;
    std::istringstream is("05:33:-21,510");
    is >> cas;
  }
  catch (WrongTime e) {
    vynimka = e.message();
  }
  ASSERT_EQ("Second out of limits", vynimka);
}
TEST(TestFirstTask, CasHodina) {
  Time cas;
  std::istringstream is("00:33:21,510");
  is >> cas;
  ASSERT_EQ("00:33:21,510", cas.getTime());
}
TEST(TestFirstTask, wrongFormat) {
  std::string vynimka;
  try {
    Time cas;
    std::istringstream is("00:33:21:510");
    is >> cas;
  }
  catch (WrongInput e) {
    vynimka = e.message();
  }
  ASSERT_EQ("Wrong time format", vynimka);
}
TEST(TestFirstTask, ZlyOddelovac) {
  std::string vynimka;
  try {
    Time cas;
    std::istringstream is("00:33:21;510");
    is >> cas;
  }
  catch (WrongInput e) {
    vynimka = e.message();
  }
  ASSERT_EQ("Wrong time format", vynimka);
}
TEST(TestFirstTask, ZlyFormatCasu) {
  std::string vynimka;
  try {
    Time cas;
    std::istringstream is("00:33:");
    is >> cas;
  }
  catch (WrongInput e) {
    vynimka = e.message();
  }
  ASSERT_EQ("Wrong time format", vynimka);
}
TEST(TestFirstTask, VelkaHodina) {
  std::string vynimka;
  try {
    Time cas;
    std::istringstream is("231:33:44,321");
    is >> cas;
  }
  catch (WrongTime e) {
    vynimka = e.message();
  }
  ASSERT_EQ("Hour out of limits", vynimka);
}
TEST(TestFirstTask, CasIbaSMedzerami) {
  std::string vynimka;
  try {
    Time cas;
    std::istringstream is("00 33 43 654");
    is >> cas;
  }
  catch (WrongInput e) {
    vynimka = e.message();
  }
  ASSERT_EQ("Wrong time format", vynimka);
}
TEST(TestFirstTask, CasIbaSDvojbodkami) {
  std::string vynimka;
  try {
    Time cas;
    std::istringstream is("00:33:43:654");
    is >> cas;
  }
  catch (WrongInput e) {
    vynimka = e.message();
  }
  ASSERT_EQ("Wrong time format", vynimka);
}
TEST(TestFirstTask, VypisCasu) {
  Time cas;
  std::istringstream is("22:12:52,513");
  is >> cas;
	ASSERT_EQ("22:12:52,513", cas.getTime());
}
TEST(TestFirstTask, Kopia) {
  Time cas, cas1;
  std::istringstream is("22:12:52,513");
  is >> cas;
  cas1 = cas;
  ASSERT_EQ("22:12:52,513", cas1.getTime());
}
TEST(TestFirstTask, VypisCasuSNulami) {
  Time cas;
  std::istringstream is("00:02:02,010");
  is >> cas;
	ASSERT_EQ("00:02:02,010", cas.getTime());
}
TEST(TestFirstTask, PorovnanieCasov) {
	Time cas;
  std::istringstream is("22:12:52,513");
  is >> cas;
  Time cas1;
  std::istringstream is1("23:12:52,513");
  is1 >> cas1;
  ASSERT_FALSE(cas1 < cas);
	ASSERT_TRUE(cas < cas1);
}
TEST(TestFirstTask, PorovnanieRovnakych) {
	Time cas;
  std::istringstream is("22:12:52,513");
  is >> cas;
	ASSERT_FALSE(cas < cas);
}
TEST(TestFirstTask, PorovnanieSekund) {
	Time cas;
  std::istringstream is("3:12:53,513");
  is >> cas;
	Time cas1;
  std::istringstream is1("3:12:52,513");
  is1 >> cas1;
    ASSERT_FALSE(cas < cas1);
    ASSERT_FALSE(cas1 < cas1);
}