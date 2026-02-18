// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "4_5_HotelWithReception.h"

using namespace ::testing;

TEST(TestFourthTask, CleaningRoom) {
    CleaningDefinition cleaning;
    ASSERT_EQ(25, cleaning.getCleaningRoom());
}

TEST(TestFourthTask, CleaningSecond) {
    CleaningDefinition cleaning;
    ASSERT_EQ(20, cleaning.getCleaningForSecondGuest());
}

TEST(TestFourthTask, Cleaning100) {
    CleaningDefinition cleaning(50, 100, 20);
    ASSERT_EQ(100, cleaning.getCleaningApartment());
}

TEST(TestFourthTask, CleaningWrong) {
    CleaningDefinition cleaning(-100, 0, 20);
    ASSERT_EQ(25, cleaning.getCleaningRoom());
}

TEST(TestFourthTask, CleaningWrongRoom) {
    CleaningDefinition cleaning(30,100, -20);
    ASSERT_EQ(25, cleaning.getCleaningRoom());
}

TEST(TestFourthTask, nulovyHotel) {
	HotelWithReception hotel(0, 6, 2);
	ASSERT_EQ(0, hotel.numberOfFreeRooms());
	ASSERT_FALSE(hotel.checkIn("Kovac;Samo", "Apartment"));
	ASSERT_EQ(0, hotel.numberOfGuests());
}
TEST(TestFourthTask, pocetVolnychIzieb) {
	HotelWithReception mojHotel(4, 3, 2);
	ASSERT_EQ(12, mojHotel.numberOfFreeRooms());
	ASSERT_EQ(8, mojHotel.numberOfFreeApartments());
}
TEST(TestFourthTask, nulovyZoznamHosti) {
	HotelWithReception mojHotel(4, 3, 2);
	ASSERT_EQ(0, mojHotel.numberOfGuests());
}
TEST(TestFourthTask, ubytujHosta) {
	HotelWithReception hotel(2, 2, 1);
	ASSERT_EQ(2, hotel.numberOfFreeApartments());
	ASSERT_EQ(103, hotel.checkIn("Hucko Peter", "Kristof Vesely", "Apartment"));
	ASSERT_EQ(2, hotel.numberOfGuests());
	ASSERT_EQ(1, hotel.numberOfFreeApartments());
}
TEST(TestFourthTask, pocetHosti) {
	HotelWithReception hotel(2, 2, 1);
	ASSERT_EQ(103, hotel.checkIn("Hucko Peter", "Kristof Vesely", "Apartment"));
	ASSERT_EQ(101, hotel.checkIn("Achen Zobor","Karol Vlach", "Room"));
	ASSERT_EQ(4, hotel.numberOfGuests());
}
TEST(TestFourthTask, menejHostiAkoApartmentov) {
	HotelWithReception hotel(2, 1, 1);
	ASSERT_EQ(102, hotel.checkIn("Hucko Vlado","Kristof Vesely", "Apartment"));
	ASSERT_EQ(101, hotel.checkIn("Achen Karol", "Room"));
	ASSERT_EQ(202, hotel.checkIn("Hucko Jan", "Apartment"));
	ASSERT_EQ(0, hotel.checkIn("Kovac Jan", "Samo Kral", "Apartment"));
	ASSERT_EQ(4, hotel.numberOfGuests());
}
