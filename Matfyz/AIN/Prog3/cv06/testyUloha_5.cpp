// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace ::testing;

#include "4_5_HotelWithReception.h"

TEST(TestFifthTask, nacitajPrazdnuDatabazu) {
	HotelWithReception hotel(3, 2, 3);
	ASSERT_EQ(0, hotel.numberOfGuests());
}
TEST(TestFifthTask, nacitajDatabazu7) {
	HotelWithReception hotel(2, 2, 1);
	ASSERT_EQ(2, hotel.numberOfFreeApartments());
	hotel.checkIn("Jozef Sereg", "Anna Seregova", "Apartment");
	hotel.checkIn("Petra Seregova", "Apartment");
	hotel.checkIn("Peter Sereg", "Room");
	hotel.checkIn("Umelec Michelangelo", "Room");
	hotel.checkIn("Jozef Sereg", "Room");
	hotel.checkIn("Alex Tokos", "Peter Sereg", "Room");
	hotel.checkIn("Kristof Hucko", "Anna Huckova", "Apartment");
	ASSERT_EQ(0, hotel.numberOfFreeApartments());
	ASSERT_EQ(0, hotel.numberOfFreeRooms());
	ASSERT_EQ(8, hotel.numberOfGuests());
}
TEST(TestFifthTask, OdhlasenieHosta) {
	HotelWithReception hotel(2, 2, 1);
    hotel.checkIn("Jozef Sereg", "Anna Seregova", "Apartment");
    hotel.checkIn("Petra Seregova", "Apartment");
    hotel.checkIn("Peter Sereg", "Room");
    hotel.checkIn("Umelec Michelangelo", "Room");
    hotel.checkIn("Jozef Sereg", "Room");
    hotel.checkIn("Alex Tokos", "Peter Sereg", "Room");
    hotel.checkIn("Kristof Hucko", "Anna Huckova", "Apartment");
	ASSERT_EQ(0, hotel.numberOfFreeApartments());
	ASSERT_EQ(0, hotel.numberOfFreeRooms());
	ASSERT_EQ(8, hotel.numberOfGuests());
	hotel.checkOut(102);
	ASSERT_EQ(7, hotel.numberOfGuests());
}
TEST(TestFifthTask, upratajPonacitaniDatabazy7) {
	HotelWithReception hotel(2, 2, 1);
    hotel.checkIn("Jozef Sereg", "Anna Seregova", "Apartment");
    hotel.checkIn("Petra Seregova", "Apartment");
    hotel.checkIn("Peter Sereg", "Room");
    hotel.checkIn("Umelec Michelangelo", "Room");
    hotel.checkIn("Jozef Sereg", "Room");
    hotel.checkIn("Alex Tokos", "Peter Sereg", "Room");
    hotel.checkIn("Kristof Hucko", "Anna Huckova", "Apartment");
    ASSERT_EQ("Michelangelo, Umelec", hotel.guestNames(102));
	hotel.checkOut(102);
	ASSERT_EQ(7, hotel.numberOfGuests());
    ASSERT_EQ(25, hotel.cleaningAllRooms());
	hotel.checkOut(102);
	ASSERT_EQ(0, hotel.cleaningAllRooms());
}
TEST(TestFifthTask, opakovanieUpratania) {
	HotelWithReception hotel(2, 2, 1);
    hotel.setCleaningDefinition(55, 80, 30);
    int roomNumber = hotel.checkIn("Jozef Sereg", "Anna Seregova", "Apartment");
    hotel.checkIn("Petra Seregova", "Apartment");
    hotel.checkIn("Peter Sereg", "Room");
    hotel.checkIn("Umelec Michelangelo", "Room");
    hotel.checkIn("Jozef Sereg", "Room");
    hotel.checkIn("Kristof Hucko", "Anna Huckova", "Apartment");
	hotel.checkOut(102);
	ASSERT_EQ(55, hotel.cleaningAllRooms());
    hotel.checkOut(roomNumber);
    ASSERT_EQ(110, hotel.cleaningAllRooms());
    hotel.setCleaningDefinition(17, 26, 18);
    roomNumber = hotel.checkIn("Alex Tokos", "Peter Sereg", "Room");
    hotel.checkOut(roomNumber);
    ASSERT_EQ(35, hotel.cleaningAllRooms());
}
TEST(TestFifthTask, dalsieUpratania) {
	HotelWithReception hotel(3, 2, 1);
	hotel.checkIn("Sereg Jozef", "Seregova Anna", "Apartment");
	hotel.checkIn("Seregova Petra", "Apartment");
	hotel.checkIn("Sereg Peter", "Room");
	hotel.checkIn("Umelec Michelangelo", "Room");
	hotel.checkIn("Sereg Jozef", "Room");
	hotel.checkIn("Tokos Alex", "Sereg Peter", "Room");
	hotel.checkIn("Hucko Kristof", "Huckova Anna", "Apartment");
	hotel.checkOut(102);
	ASSERT_EQ(25, hotel.cleaningAllRooms());
	ASSERT_TRUE(hotel.checkOut(202));
	ASSERT_EQ(45, hotel.cleaningAllRooms());
}
TEST(TestFifthTask, UprataniaNeubytovaneho) {
	HotelWithReception hotel(2, 2, 1);
    hotel.checkIn("Jozef Sereg", "Anna Seregova", "Apartment");
    hotel.checkIn("Petra Seregova", "Apartment");
    hotel.checkIn("Peter Sereg", "Room");
    hotel.checkIn("Umelec Michelangelo", "Room");
    hotel.checkIn("Jozef Sereg", "Room");
    hotel.checkIn("Alex Tokos", "Peter Sereg", "Room");
    hotel.checkIn("Kristof Hucko", "Anna Huckova", "Apartment");
	ASSERT_FALSE(hotel.checkOut(404));
	ASSERT_EQ(0, hotel.cleaningAllRooms());
}
TEST(TestFifthTask, uprataniaPoViacerych) {
	HotelWithReception hotel(3, 2, 1);
    hotel.checkIn("Jozef Sereg", "Anna Seregova", "Apartment");
    hotel.checkIn("Petra Seregova", "Apartment");
    hotel.checkIn("Peter Sereg", "Room");
    hotel.checkIn("Umelec Michelangelo", "Room");
    hotel.checkIn("Jozef Sereg", "Room");
    hotel.checkIn("Alex Tokos", "Peter Sereg", "Room");
    hotel.checkIn("Kristof Hucko", "Anna Huckova", "Apartment");
	hotel.checkOut(101);
	ASSERT_EQ(25, hotel.cleaningAllRooms());
	hotel.checkOut(102);
	hotel.checkOut(203);
	ASSERT_EQ(65, hotel.cleaningAllRooms());
	ASSERT_FALSE(hotel.checkOut(302));
	ASSERT_EQ(0, hotel.cleaningAllRooms());
}
TEST(TestFifthTask, menoUbytovanych) {
	HotelWithReception hotel(3, 2, 1);
    hotel.checkIn("Jozef Sereg", "Anna Seregova", "Apartment");
    hotel.checkIn("Petra Seregova", "Apartment");
    hotel.checkIn("Peter Sereg", "Room");
    hotel.checkIn("Umelec Michelangelo", "Room");
    hotel.checkIn("Jozef Sereg", "Room");
    hotel.checkIn("Alex Tokos", "Peter Sereg", "Room");
    hotel.checkIn("Kristof Hucko", "Anna Huckova", "Apartment");

	ASSERT_EQ("Michelangelo, Umelec", hotel.guestNames(102));
	ASSERT_EQ("Sereg, Peter", hotel.guestNames(101));
}
TEST(TestFifthTask, uprataniaNarazPoViacerych) {
	HotelWithReception hotel(3, 2, 1);
    hotel.checkIn("Jozef Sereg", "Anna Seregova", "Apartment");
    hotel.checkIn("Petra Seregova", "Apartment");
    hotel.checkIn("Peter Sereg", "Room");
    hotel.checkIn("Umelec Michelangelo", "Room");
    hotel.checkIn("Jozef Sereg", "Room");
    hotel.checkIn("Alex Tokos", "Peter Sereg", "Room");
    hotel.checkIn("Kristof Hucko", "Anna Huckova", "Apartment");
	hotel.checkOut(301);
	hotel.checkOut(202);
	hotel.checkOut(203);
	ASSERT_EQ(85, hotel.cleaningAllRooms());
	ASSERT_EQ(202, hotel.checkIn("Hucko Kristof", "Room"));
}
TEST(TestFifthTask, UbytovanieOdhlasovanieUpratovanie) {
	HotelWithReception hotel(3, 2, 1);
  int roomNumber = 0;
    roomNumber = hotel.checkIn("Jozef Sereg", "Anna Seregova", "Apartment");
    roomNumber = hotel.checkIn("Petra Seregova", "Apartment");
    roomNumber = hotel.checkIn("Peter Sereg", "Room");
    roomNumber = hotel.checkIn("Umelec Michelangelo", "Room");
    roomNumber = hotel.checkIn("Jozef Sereg", "Room");
    roomNumber = hotel.checkIn("Alex Tokos", "Peter Sereg", "Room");
    roomNumber = hotel.checkIn("Kristof Hucko", "Anna Huckova", "Apartment");

	ASSERT_EQ("Sereg, Peter", hotel.guestNames(101));
	ASSERT_EQ("Sereg, Jozef;Seregova, Anna", hotel.guestNames(103));
	ASSERT_EQ("Tokos, Alex;Sereg, Peter", hotel.guestNames(202));
    ASSERT_EQ("Hucko, Kristof;Huckova, Anna", hotel.guestNames(303));
    ASSERT_TRUE(hotel.checkOut(101));
    ASSERT_TRUE(hotel.checkOut(203));
    ASSERT_TRUE(hotel.checkOut(303));
	ASSERT_FALSE(hotel.checkIn("Hucko, Kristof", "Apartment"));
    ASSERT_EQ(125, hotel.cleaningAllRooms());
	ASSERT_TRUE(hotel.checkIn("Hucko, Kristof", "Apartment"));
}
TEST(TestFifthTask, UbytovanieOdhlasovanieUpratovanie2) {
	HotelWithReception hotel(2, 2, 1);
    hotel.checkIn("Jozef Sereg", "Anna Seregova", "Apartment");
    hotel.checkIn("Petra Seregova", "Apartment");
    hotel.checkIn("Peter Sereg", "Room");
    hotel.checkIn("Umelec Michelangelo", "Room");
    hotel.checkIn("Jozef Sereg", "Room");
    hotel.checkIn("Alex Tokos", "Peter Sereg", "Room");

    ASSERT_EQ(0, hotel.checkIn("Hucko Kristof", "Huckova Anna", "Apartment"));
    ASSERT_EQ("Sereg, Peter", hotel.guestNames(101));
    ASSERT_EQ("Sereg, Jozef;Seregova, Anna", hotel.guestNames(103));
    ASSERT_EQ("Tokos, Alex;Sereg, Peter", hotel.guestNames(202));
    ASSERT_EQ("Seregova, Petra", hotel.guestNames(203));
    ASSERT_TRUE(hotel.checkOut(101));
    ASSERT_TRUE(hotel.checkOut(202));
    ASSERT_TRUE(hotel.checkOut(203));
	ASSERT_EQ(110, hotel.cleaningAllRooms());
    ASSERT_EQ(203, hotel.checkIn("Kristof Hucko", "Apartment"));
	hotel.checkOut(101);
	ASSERT_EQ(0, hotel.cleaningAllRooms());
}

TEST(TestFifthTask, KOntrola) {
    HotelWithReception hotel(3, 2, 1);
    int roomNumber = 0;
    roomNumber = hotel.checkIn("Jozef Sereg", "Anna Seregova", "Apartment");
    roomNumber = hotel.checkIn("Petra Seregova", "Apartment");
    roomNumber = hotel.checkIn("Peter Sereg", "Room");
    roomNumber = hotel.checkIn("Umelec Michelangelo", "Room");
    roomNumber = hotel.checkIn("Jozef Sereg", "Room");
    roomNumber = hotel.checkIn("Alex Tokos", "Peter Sereg", "Room");
    roomNumber = hotel.checkIn("Kristof Hucko", "Anna Huckova", "Apartment");
    hotel.checkOut(101);
    hotel.checkOut(203);
    hotel.checkOut(303);
    hotel.checkIn("Hucko, Kristof", "Apartment");
    ASSERT_EQ(125,  hotel.cleaningAllRooms());
}

