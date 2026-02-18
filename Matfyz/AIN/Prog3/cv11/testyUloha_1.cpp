// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "1_Chords.h"

using namespace ::testing;

//Uloha 1.
TEST(TestFirstTask, PridajPrazdnyAkord) {
  Chords chords;
  ASSERT_EQ(0, chords.addChord(""));
}

TEST(TestFirstTask, PridajJedenAkord) {
  Chords chords;
  ASSERT_EQ(1, chords.addChord("A"));
  ASSERT_EQ(2, chords.addChord("A"));
  ASSERT_EQ(3, chords.addChord("A"));
  ASSERT_EQ(1, chords.getNumberOfChords());
  ASSERT_EQ(3, chords.getNumberOfAppearances("A"));
}

TEST(TestFirstTask, PridajAkordy) {
  Chords chords;
  ASSERT_EQ(1, chords.addChord("A"));
  ASSERT_EQ(1, chords.addChord("B"));
  ASSERT_EQ(2, chords.addChord("A"));
  ASSERT_EQ(3, chords.addChord("A"));
  ASSERT_EQ(1, chords.addChord("C"));
  ASSERT_EQ(4, chords.addChord("A"));
  ASSERT_EQ(3, chords.getNumberOfChords());
  ASSERT_EQ(4, chords.getNumberOfAppearances("A"));
  ASSERT_EQ("A,B,C", chords.getListOfChords());
}

TEST(TestFirstTask, PridajZoznamAkordov) {
  Chords chords;
  chords.addListOfChords("Am,B,D,Em,G");
  ASSERT_EQ(5, chords.getNumberOfChords());
  chords.addListOfChords("X,Y,Z,B,D,Em");
  ASSERT_EQ(8, chords.getNumberOfChords());
  ASSERT_EQ("Am,B,D,Em,G,X,Y,Z", chords.getListOfChords());
  ASSERT_EQ(1, chords.getNumberOfAppearances("G"));
  ASSERT_EQ(1, chords.getNumberOfAppearances("Am"));
  ASSERT_EQ(2, chords.getNumberOfAppearances("Em"));
}

TEST(TestFirstTask, OdoberAkordy) {
  Chords chords;
  chords.addListOfChords("Am,B,D,Em,G");
  chords.addListOfChords("X,Y,Z,B,D,Em");
  chords.addListOfChords("Q,W,AA,G");
  ASSERT_EQ(11, chords.getNumberOfChords());
  ASSERT_EQ("AA,Am,B,D,Em,G,Q,W,X,Y,Z", chords.getListOfChords());
  chords.removeChord("Q");
  ASSERT_EQ("AA,Am,B,D,Em,G,W,X,Y,Z", chords.getListOfChords());
  chords.removeChord("Am");
  chords.removeChord("Gaa");
  chords.removeChord("G");
  ASSERT_EQ("AA,B,D,Em,G,W,X,Y,Z", chords.getListOfChords());
  ASSERT_EQ(1, chords.getNumberOfAppearances("G"));
  ASSERT_EQ(0, chords.getNumberOfAppearances("Am"));
  ASSERT_EQ(2, chords.getNumberOfAppearances("Em"));
  chords.addChord("Am");
  ASSERT_EQ("AA,Am,B,D,Em,G,W,X,Y,Z", chords.getListOfChords());
}
