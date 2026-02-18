// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include <exception>
#include "gtest/gtest.h"

#include "2_SongBook.h"

using namespace ::testing;

//Uloha 2.
TEST(TestSecondTask, VytvoritSpevnik) {
  Song p("Where the wild roses grow");
  ASSERT_TRUE(p.readSongFromFile("Where_the_wild_roses_grow.txt"));
  Song p2("We No Who U R");
  ASSERT_TRUE(p2.readSongFromFile("We_No_Who_U_R.txt"));
  Song p3("Suzanne");
  ASSERT_TRUE(p3.readSongFromFile("Suzanne.txt"));
  SongBook s;
  s.addSong(p);
  s.addSong(p2);
  s.addSong(p3);
  s.addSong(p2);
  ASSERT_EQ(3, s.getNumberOfSongs());
  ASSERT_EQ("Suzanne;We No Who U R;Where the wild roses grow", s.getPlayList());
}

TEST(TestSecondTask, SongIndex) {
  Song p("Where the wild roses grow");
  Song p2("We No Who U R");
  Song p3("Suzanne");
  Song p4("Atlantis");
  Song p5("Hello");
  SongBook s;
  s.addSong(p);
  s.addSong(p2);
  s.addSong(p3);
  s.addSong(p4);
  s.addSong(p5);
  ASSERT_EQ(5, s.getNumberOfSongs());
  ASSERT_EQ("Atlantis", s[1].getTitle());
  ASSERT_EQ("Suzanne", s[3].getTitle());
  ASSERT_EQ("Where the wild roses grow", s[5].getTitle());

  std::string message {};
  try {
    s[0].getTitle();
    ASSERT_TRUE(false);
  }
  catch (const std::out_of_range &error) {
      message = error.what();
    ASSERT_EQ("Wrong index", message);
  }
  try {
    ASSERT_EQ("Atlantis", s[-1].getTitle());
    ASSERT_TRUE(false);
  }
  catch (const std::out_of_range &error) {
    std::string temp = error.what();
    ASSERT_EQ("Wrong index", temp);
  }
  try {
    ASSERT_EQ("Atlantis", s[88].getTitle());
    ASSERT_TRUE(false);
  }
  catch (const std::out_of_range &error) {
    std::string temp = error.what();
    ASSERT_EQ("Wrong index", temp);
  }
}
