// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "2_SongBook.h"

using namespace ::testing;

//Uloha 4.
TEST(TestFourthTask, PridanieSongbookDanemu) {
    Song p("Where the wild roses grow");
    ASSERT_TRUE(p.readSongFromFile("Where_the_wild_roses_grow.txt"));
    Song p2("We No Who U R");
    ASSERT_TRUE(p2.readSongFromFile("We_No_Who_U_R.txt"));
    SongBook s;
    s.addSong(p);
    s.addSong(p2);
    ASSERT_EQ(2, s.getNumberOfSongs());
    Song p3("Suzanne");
    ASSERT_TRUE(p3.readSongFromFile("Suzanne.txt"));
    Song p4("Hello");
    ASSERT_TRUE(p4.readSongFromFile("Hello.txt"));
    SongBook s1;
    s1.addSong(p2);
    s1.addSong(p3);
    s1.addSong(p4);
    s += s1;
    ASSERT_EQ(3, s1.getNumberOfSongs());
    ASSERT_EQ(4, s.getNumberOfSongs());
}

TEST(TestFourthTask, PridajSpevnik) {
  SongBook s;
  Song p("Where the wild roses grow");
  p.readSongFromFile("Where_the_wild_roses_grow.txt");
  s.addSong(p);
  Song p2("We No Who U R");
  p2.readSongFromFile("We_No_Who_U_R.txt");
  s.addSong(p2);
  SongBook novy;
  Song p3("Suzanne");
  p3.readSongFromFile("Suzanne.txt");
  novy.addSong(p3);
  Song p4("Hello");
  p4.readSongFromFile("Hello.txt");
  novy.addSong(p3);
  novy.addSong(p4);
  novy.addSong(p2);
  ASSERT_EQ(2, s.addSongbook(std::move(novy)));
}

TEST(TestFourthTask, PesnickyPoPridaniSpevniku) {
  SongBook s;
  Song p("Hello");
  p.readSongFromFile("Hello.txt");
  s.addSong(p);
  Song p2("We No Who U R");
  p2.readSongFromFile("We_No_Who_U_R.txt");
  s.addSong(p2);
  SongBook novy;
  Song p3("Suzanne");
  p3.readSongFromFile("Suzanne.txt");
  novy.addSong(p3);
  Song p4("Where the wild roses grow");
  p4.readSongFromFile("Where the wild roses grow.txt");
  novy.addSong(p3);
  novy.addSong(p4);
  novy.addSong(p2);
  s.addSongbook(std::move(novy));
  ASSERT_EQ("Hello;Suzanne;We No Who U R;Where the wild roses grow", s.getPlayList());
}

TEST(TestFourthTask, NachadzaSaAkord) {
  Song p("Hello");
  p.readSongFromFile("Hello.txt");
  Song p2("We No Who U R");
  p2.readSongFromFile("We_No_Who_U_R.txt");
  Song p3("Suzanne");
  p3.readSongFromFile("Suzanne.txt");
  Song p4("Where the wild roses grow");
  p4.readSongFromFile("Where the wild roses grow.txt");
  SongBook s;
  s.addSong(p);
  ASSERT_EQ("C,D,Em,G", s.getListOfChords());
  ASSERT_EQ(0, s.countChordInSongs("Am"));
  s.addSong(p2);
  s.addSong(p3);
  s.addSong(p4);
  ASSERT_EQ(1,s.countChordInSongs("Am"));
}

TEST(TestFourthTask, AkordPoPridaniSpevniku) {
  SongBook s;
  Song p("Hello");
  p.readSongFromFile("Hello.txt");
  s.addSong(p);
  SongBook novy;
  Song p3("Suzanne");
  p3.readSongFromFile("Suzanne.txt");
  novy.addSong(p3);
  Song p4("Where the wild roses grow");
  p4.readSongFromFile("Where the wild roses grow.txt");
  novy.addSong(p3);
  novy.addSong(p4);
  Song p2("We No Who U R");
  p2.readSongFromFile("We_No_Who_U_R.txt");
  novy.addSong(p2);
  ASSERT_EQ(0, s.countChordInSongs("Am"));
  s.addSongbook(std::move(novy));
  ASSERT_EQ(1, s.countChordInSongs("Am"));
  ASSERT_EQ(0, novy.getNumberOfSongs());
}

TEST(TestFourthTask, Skuska) {
  Song p("Hello");
  p.readSongFromFile("Hello.txt");
  Song p2("We No Who U R");
  p2.readSongFromFile("We_No_Who_U_R.txt");
  Song p3("Suzanne");
  p3.readSongFromFile("Suzanne.txt");
  Song p4("Where the wild roses grow");
  p4.readSongFromFile("Where the wild roses grow.txt");
  SongBook s;
  s.addSong(p);
  ASSERT_EQ("C,D,Em,G", s.getListOfChords());
  s.addSong(p2);
  ASSERT_EQ("Am,C,D,Dm,Em,F,G", s.getListOfChords());
  s.addSong(p3);
  ASSERT_EQ("A,Am,C,D,Dm,E,Em,F,Fm,G,Gm", s.getListOfChords());
  s.addSong(p4);
  ASSERT_EQ("A,Am,C,D,Dm,E,Em,F,Fm,G,Gm", s.getListOfChords());
}
