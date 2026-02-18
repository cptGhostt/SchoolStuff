// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "1_Accommodation.h"

using namespace ::testing;

//Uloha 1.
TEST(TestFirstTask, GuestName) {
    Guest guest;
    guest.checkIn("Jano Babab");
    ASSERT_EQ(guest.getGuestName(), "Babab, Jano");
}

TEST(TestFirstTask, GuestNameBothSpaces) {
    Guest guest;
    guest.checkIn("  Anna Alzbeta Bathory   ");
    ASSERT_EQ(guest.getGuestName(), "Bathory, Anna Alzbeta");
}

TEST(TestFirstTask, GuestNameEmpty) {
    Guest guest;
    guest.checkIn("   ");
    ASSERT_EQ(guest.getGuestName(), "");
}
TEST(TestFirstTask, GuestNameNo) {
    Guest guest;
    ASSERT_EQ(guest.getGuestName(), "");
}

TEST(TestFirstTask, PrazdnaHotelovaroom) {
	Room room;
	ASSERT_FALSE(room.isRoomOccupied());
}

TEST(TestFirstTask, roomType) {
  Room room;
  ASSERT_EQ("Room", room.nameOfRoomType());
}

TEST(TestFirstTask, apartmentType) {
  Apartment apartment;
  ASSERT_EQ("Apartment", apartment.nameOfRoomType());
}

TEST(TestFirstTask, defaultType) {
  Room room;
  ASSERT_EQ("Room", room.nameOfRoomType());
}

TEST(TestFirstTask, PrazdnyZakaznik) {
	Room room;
	ASSERT_EQ("", room.guestNames());
}
TEST(TestFirstTask, NastahujZakaznika) {
	Room room;
	ASSERT_TRUE(room.addGuests("Irma Seregova "));
  ASSERT_EQ(1, room.numberOfGuests());
  ASSERT_EQ("Seregova, Irma", room.guestNames());
}

TEST(TestFirstTask, HostBezMena) {
	Room room;
	ASSERT_FALSE(room.addGuests(""));
	ASSERT_FALSE(room.isRoomOccupied());
    ASSERT_EQ(0, room.numberOfGuests());
}

TEST(TestFirstTask, Obsadenaroom) {
	Room room;
  room.addGuests("Seregova Irma");
	ASSERT_TRUE(room.isRoomOccupied());
}
TEST(TestFirstTask, ZakaznikVIzbe) {
	Room room;
  room.addGuests(" Irma Seregova", "Jan D. Sereg");
	ASSERT_EQ(2, room.numberOfGuests());
	ASSERT_EQ("Seregova, Irma;Sereg, Jan D.", room.guestNames());
}

TEST(TestFirstTask, apartment) {
  Apartment apartment;
  ASSERT_EQ("Apartment", apartment.nameOfRoomType());
}

TEST(TestFirstTask, room) {
  Room room;
  ASSERT_EQ("Room", room.nameOfRoomType());
}

