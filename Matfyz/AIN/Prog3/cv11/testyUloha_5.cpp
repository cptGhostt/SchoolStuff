// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "5_Musician.h"

using namespace ::testing;

//Uloha 5.
TEST(TestFifthTask, HodobnikBezPesniciek) {
	Musician hudobnik("Johnny Guitar");
	ASSERT_EQ("", hudobnik.getPlayList());
  ASSERT_EQ("Johnny Guitar", hudobnik.musicianName());
}

TEST(TestFifthTask, HodobnikSJednou) {
	Musician hudobnik;
  ASSERT_EQ("Unregistered", hudobnik.musicianName());
	SongBook s;
	Song p2("We No Who U R");
  p2.readSongFromFile("We_No_Who_U_R.txt");
	s.addSong(p2);
	ASSERT_EQ(1, hudobnik.learnSongsFromSongbook(std::move(s)));
  ASSERT_EQ(0, s.getNumberOfSongs());
}

TEST(TestFifthTask, HodobnikSJednouVPlayliste) {
	Musician hudobnik("Johnny Guitar");
	SongBook s;
	Song p2("We No Who U R");
  p2.readSongFromFile("We_No_Who_U_R.txt");
	s.addSong(p2);
	hudobnik.learnSongsFromSongbook(std::move(s));
	ASSERT_EQ("We No Who U R", hudobnik.getPlayList());
}

TEST(TestFifthTask, PridajAkVieZahrat) {
	Musician hudobnik("Johnny Guitar");
	SongBook s;
	Song p2("We No Who U R");
  p2.readSongFromFile("We_No_Who_U_R.txt");
	s.addSong(p2);
	hudobnik.learnSongsFromSongbook(std::move(s));
	Song p("Hello");
  p.readSongFromFile("Hello.txt");
	ASSERT_FALSE(hudobnik.addSongIfAbleToPlayIt(p));
}

TEST(TestFifthTask, NeznamyAkord) {
	Musician hudobnik("Johnny Guitar");
	SongBook s;
	Song p2("We No Who U R");
  p2.readSongFromFile("We_No_Who_U_R.txt");
	s.addSong(p2);
  ASSERT_EQ("Am,C,Dm,F,G", s.getListOfChords());
	hudobnik.learnSongsFromSongbook(std::move(s));
	Song p("Hello");
  p.readSongFromFile("Hello.txt");
  ASSERT_EQ("C,D,Em,G", p.getListOfChords());
	ASSERT_EQ("D,Em", hudobnik.unknownChord(p));
}

TEST(TestFifthTask, PridajAkVieZahratp3) {
	Musician hudobnik("Johnny Guitar");
	SongBook s;
	Song p("Hello");
  p.readSongFromFile("Hello.txt");
	Song p3("Suzanne");
  p3.readSongFromFile("Suzanne.txt");
	ASSERT_FALSE(hudobnik.addSongIfAbleToPlayIt(p3));
}

TEST(TestFifthTask, NaucitSaDvePesnicky) {
	Musician hudobnik("Johnny Guitar");
	SongBook s;
	Song p("Hello");
  p.readSongFromFile("Hello.txt");
	s.addSong(p);
	Song p3("Suzanne");
  p3.readSongFromFile("Suzanne.txt");
	s.addSong(p3);
	ASSERT_EQ(2, hudobnik.learnSongsFromSongbook(std::move(s)));
}

TEST(TestFifthTask, PridatZnovu) {
	Musician hudobnik("Johnny Guitar");
	SongBook s;
	Song p("Hello");
  p.readSongFromFile("Hello.txt");
	s.addSong(p);
	Song p3("Suzanne");
  p3.readSongFromFile("Suzanne.txt");
	s.addSong(p3);
	hudobnik.learnSongsFromSongbook(std::move(s));
	ASSERT_FALSE(hudobnik.addSongIfAbleToPlayIt(p));
}

TEST(TestFifthTask, BezNeznamehuAkordu) {
	Musician hudobnik("Johnny Guitar");
	SongBook s;
	Song p("Hello");
  p.readSongFromFile("Hello.txt");
	s.addSong(p);
	Song p3("Suzanne");
  p3.readSongFromFile("Suzanne.txt");
	s.addSong(p3);
	hudobnik.learnSongsFromSongbook(std::move(s));
	ASSERT_EQ("", hudobnik.unknownChord(p));
}

TEST(TestFifthTask, VsetkyAkordy) {
	Musician hudobnik("Johnny Guitar");
	SongBook s;
	Song p("Hello");
  p.readSongFromFile("Hello.txt");
	s.addSong(p);
	Song p3("Suzanne");
  p3.readSongFromFile("Suzanne.txt");
	s.addSong(p3);
	hudobnik.learnSongsFromSongbook(std::move(s));
	ASSERT_EQ("A,C,D,E,Em,Fm,G,Gm", hudobnik.getListOfChords());
}

TEST(TestFifthTask, ViePridatPiesen) {
	Musician hudobnik("Johnny Guitar");
	SongBook s;
	Song p("Hello");
  p.readSongFromFile("Hello.txt");
	s.addSong(p);
	Song p2("We No Who U R");
  p2.readSongFromFile("We_No_Who_U_R.txt");
	s.addSong(p2);
	Song p3("Suzanne");
  p3.readSongFromFile("Suzanne.txt");
	s.addSong(p3);
	Song p4("Where the wild roses grow");
  p4.readSongFromFile("Where the wild roses grow.txt");
	hudobnik.learnSongsFromSongbook(std::move(s));
  ASSERT_EQ("A,Am,C,D,Dm,E,Em,F,Fm,G,Gm", hudobnik.getListOfChords());
	ASSERT_TRUE(hudobnik.addSongIfAbleToPlayIt(p4));
  ASSERT_EQ("A,Am,C,D,Dm,E,Em,F,Fm,G,Gm", hudobnik.getListOfChords());
}