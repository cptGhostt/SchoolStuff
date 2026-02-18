// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace ::testing;

#include "1_Accommodation.h"

TEST(TestSecondTask, UpratovanieApartmanu) {
	Apartment izba;
  izba.checkIn("Smoliar Imro");
	izba.checkOut(50, 10);
	ASSERT_EQ(50, izba.cleaningUp());
}
TEST(TestSecondTask, UpratovanieApartmanuPreDvoch) {
	Apartment izba;
  izba.checkIn("Smoliar Imro", "Hana Serkavova");
	ASSERT_EQ(2, izba.numberOfGuests());
	izba.checkOut( 50, 10);
	ASSERT_EQ(60, izba.cleaningUp());
}
TEST(TestSecondTask, NastahovanieDruheho) {
	Apartment izba;
  izba.checkIn("Smoliar Imro");
	ASSERT_EQ(1, izba.numberOfGuests());
	izba.checkOut();
  izba.cleaningUp();
	ASSERT_TRUE(izba.checkIn("Smoliar Imro"));
}
TEST(TestSecondTask, InyCasUpratania) {
	Room izba;
  izba.checkIn("Smoliar Imro");
	izba.checkOut(30);
	ASSERT_EQ(30, izba.cleaningUp());
}
TEST(TestSecondTask, VystahujPrazdnuHotelovuIzbu) {
	Room izba;
	ASSERT_FALSE(izba.checkOut());
}
TEST(TestSecondTask, VystahujZakaznika) {
	Room izba;
  izba.checkIn("Seregova Irma");
	ASSERT_TRUE(izba.checkOut());
}
TEST(TestSecondTask, MenoVystahovanehoZakaznika) {
	Room izba;
  izba.checkIn("Seregova Irma");
	izba.checkOut(30);
	ASSERT_EQ("", izba.guestNames());
}
TEST(TestSecondTask, ObsadenostVystahovanejIzby) {
	Room izba;
  izba.checkIn("Seregova Irma");
	izba.checkOut(30);
	ASSERT_FALSE(izba.isRoomOccupied());
}
TEST(TestSecondTask, UpratanieVystahovanej) {
	Room izba;
  izba.checkIn("Seregova Irma");
	izba.checkOut(30);
	ASSERT_EQ(30, izba.cleaningUp());
}
TEST(TestSecondTask, NastahovanieDoNeupratanej) {
	Room izba;
  izba.checkIn("Seregova Irma");
	izba.checkOut(30);
	ASSERT_FALSE(izba.checkIn("Serega Imro"));
}
TEST(TestSecondTask, NastahovanieDoUpratanej) {
	Room izba;
  izba.checkIn("Seregova Irma");
	izba.checkOut(30);
  izba.cleaningUp();
	ASSERT_TRUE(izba.checkIn("Smoliar Imro"));
}
TEST(TestSecondTask, UprataniePrazdnej) {
	Room izba;
  ASSERT_EQ(0, izba.cleaningUp());
}
TEST(TestSecondTask, UpratanieObsadenej) {
	Room izba;
  izba.checkIn("Seregova Irma");
  ASSERT_EQ(0, izba.cleaningUp());
}
