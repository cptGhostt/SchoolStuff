// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "2_SongBook.h"

using namespace ::testing;

//Uloha 3.
TEST(TestThirdTask, VyprazdnitSpevnik) {
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
  ASSERT_TRUE(s.removeSong("Suzanne"));
  ASSERT_FALSE(s.removeSong("Suzanne"));
  ASSERT_EQ("We No Who U R;Where the wild roses grow", s.getPlayList());
  ASSERT_TRUE(s.removeSong("Where the wild roses grow"));
  ASSERT_TRUE(s.removeSong("We No Who U R"));
  ASSERT_EQ(0, s.getNumberOfSongs());
  ASSERT_FALSE(s.removeSong("We No Who U R"));
}

TEST(TestThirdTask, ZoznamPesniciek) {
  Song p("Where the wild roses grow");
  p.readSongFromFile("Where_the_wild_roses_grow.txt");
  Song p2("We No Who U R");
  p2.readSongFromFile("We_No_Who_U_R.txt");
  Song p3("Suzanne");
  p3.readSongFromFile("Suzanne.txt");
  Song p4("Hello");
  p4.readSongFromFile("Hello.txt");
	SongBook s;
	s.addSong(p);
	s.addSong(p2);
	s.addSong(p3);
	s.addSong(p4);
  ASSERT_EQ(4, s.getNumberOfSongs());
}

TEST(TestThirdTask, ZoznamAkordov) {
  Song p("Where the wild roses grow");
  ASSERT_TRUE(p.readSongFromFile("Where_the_wild_roses_grow.txt"));
  Song p2("We No Who U R");
  ASSERT_TRUE(p2.readSongFromFile("We_No_Who_U_R.txt"));
  Song p3("Suzanne");
  ASSERT_TRUE(p3.readSongFromFile("Suzanne.txt"));
  Song p4("Hello");
  ASSERT_TRUE(p4.readSongFromFile("Hello.txt"));
	SongBook s;
	s.addSong(p);
	ASSERT_EQ("Am,B,D,Em,G", s.getListOfChords());
	s.addSong(p2);
	s.addSong(p3);
	s.addSong(p4);
	ASSERT_EQ("A,Am,B,C,D,Dm,E,Em,F,Fm,G,Gm", s.getListOfChords());
}

TEST(TestThirdTask, ZoznamAkordovPoVyhodeni) {
  Song p("Where the wild roses grow");
  ASSERT_TRUE(p.readSongFromFile("Where_the_wild_roses_grow.txt"));
  Song p2("We No Who U R");
  ASSERT_TRUE(p2.readSongFromFile("We_No_Who_U_R.txt"));
  Song p3("Suzanne");
  ASSERT_TRUE(p3.readSongFromFile("Suzanne.txt"));
  Song p4("Hello");
  ASSERT_TRUE(p4.readSongFromFile("Hello.txt"));
	SongBook s;
	s.addSong(p);
  ASSERT_EQ("Am,B,D,Em,G", s.getListOfChords());
	s.addSong(p2);
  ASSERT_EQ("Am,B,C,D,Dm,Em,F,G", s.getListOfChords());
	s.addSong(p3);
  ASSERT_EQ("A,Am,B,C,D,Dm,E,Em,F,Fm,G,Gm", s.getListOfChords());
	s.addSong(p4);
  ASSERT_EQ("A,Am,B,C,D,Dm,E,Em,F,Fm,G,Gm", s.getListOfChords());
	ASSERT_TRUE(s.removeSong("Suzanne"));
	ASSERT_TRUE(s.removeSong("We No Who U R"));
	ASSERT_EQ("Am,B,C,D,Em,G", s.getListOfChords());
}

TEST(TestThirdTask, NastaveniePiesne) {
  Song p("Where the wild roses grow");
  ASSERT_TRUE(p.readSongFromFile("Where_the_wild_roses_grow.txt"));
  Song p2("We No Who U R");
  ASSERT_TRUE(p2.readSongFromFile("We_No_Who_U_R.txt"));
  Song p3("Suzanne");
  ASSERT_TRUE(p3.readSongFromFile("Suzanne.txt"));
  Song p4("Hello");
  ASSERT_TRUE(p4.readSongFromFile("Hello.txt"));
	SongBook s;
	s.addSong(p);
	s.addSong(p2);
	s.addSong(p3);
	s.addSong(p4);
	SongBook novySongBook(std::move(s));
	ASSERT_EQ(0, s.getNumberOfSongs());
	ASSERT_TRUE(novySongBook["Where the wild roses grow"].first);
}

TEST(TestThirdTask, KopirovanieNastavenejPiesne) {
  Song p("Where the wild roses grow");
  ASSERT_TRUE(p.readSongFromFile("Where_the_wild_roses_grow.txt"));
  Song p2("We No Who U R");
  ASSERT_TRUE(p2.readSongFromFile("We_No_Who_U_R.txt"));
  Song p3("Suzanne");
  ASSERT_TRUE(p3.readSongFromFile("Suzanne.txt"));
  Song p4("Hello");
  ASSERT_TRUE(p4.readSongFromFile("Hello.txt"));
  SongBook s;
  s.addSong(p);
  s.addSong(p2);
  s.addSong(p3);
  s.addSong(p4);
  SongBook novySongBook(std::move(s));
  ASSERT_EQ("Where the wild roses grow", novySongBook["Where the wild roses grow"].second.getTitle());
}

TEST(TestThirdTask, VlastnostiNastavenejPiesne) {
  Song p("Where the wild roses grow");
  ASSERT_TRUE(p.readSongFromFile("Where_the_wild_roses_grow.txt"));
  Song p2("We No Who U R");
  ASSERT_TRUE(p2.readSongFromFile("We_No_Who_U_R.txt"));
  Song p3("Suzanne");
  ASSERT_TRUE(p3.readSongFromFile("Suzanne.txt"));
  Song p4("Hello");
  ASSERT_TRUE(p4.readSongFromFile("Hello.txt"));
	SongBook s;
	s.addSong(p);
	s.addSong(p2);
	s.addSong(p3);
	s.addSong(p4);
	SongBook novySongBook(std::move(s));
	s.removeSong("Where the wild roses grow");
	s.removeSong("Hello");
	ASSERT_EQ("Suzanne", novySongBook["Suzanne"].second.getTitle());
	ASSERT_EQ("A,E,Fm,Gm", novySongBook["Suzanne"].second.getListOfChords());
	ASSERT_EQ("Fm", novySongBook["Suzanne"].second.getChord(2));
	ASSERT_EQ("And she #Gm$feeds you tea & oranges that come #A$all the way from China", novySongBook["Suzanne"].second.getLine(3));
	ASSERT_EQ("E$when you mean to tell her that you ", novySongBook["Suzanne"].second.getPhrase(7));
}

TEST(TestThirdTask, PrazdnySongBook) {
    SongBook novySongBook;
    std::string temp = novySongBook["XXX"].second.getChord(0);
    ASSERT_EQ("Taky akord nie je", temp);
}

