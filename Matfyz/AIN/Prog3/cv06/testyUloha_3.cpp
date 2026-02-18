// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace ::testing;

#include "3_Hotel.h"

TEST(TestThirdTask, Hotel) {
	Hotel mojHotel(4, 3, 3);
	ASSERT_EQ(12, mojHotel.numberOfAllRooms("Apartment"));
}
TEST(TestThirdTask, PrazdnyHotel0) {
	Hotel mojHotel(0, 3, 0);
	ASSERT_EQ(0, mojHotel.numberOfAllRooms("Room"));
}
TEST(TestThirdTask, PrazdnyHotel) {
	Hotel mojHotel(4, 0, 5);
	ASSERT_EQ(0, mojHotel.numberOfAllRooms("Room"));
	ASSERT_EQ(20, mojHotel.numberOfAllRooms("Apartment"));
}
TEST(TestThirdTask, PocetIzieb) {
	Hotel mojHotel(3, 6, 2);
	ASSERT_EQ(18, mojHotel.numberOfAllRooms("Room"));
}
TEST(TestThirdTask, PocetApart0) {
    Hotel mojHotel(3, 6, 0);
    ASSERT_EQ(18, mojHotel.numberOfAllRooms("Room"));
}
TEST(TestThirdTask, PocetApartmentov) {
	Hotel mojHotel(3, 6, 2);
	ASSERT_EQ(6, mojHotel.numberOfAllRooms("Apartment"));
}
TEST(TestThirdTask, PocetVolnychApartmentov2) {
	Hotel mojHotel(4, 3, 1);
	Hotel malyHotel(2, 4, 1);
	ASSERT_EQ(2, malyHotel.numberOfAllRooms("Apartment"));
	ASSERT_EQ(4, mojHotel.numberOfAllRooms("Apartment"));
}
TEST(TestThirdTask, PrazdnyHotel1) {
	Hotel mojHotel(0, 3, 1);
	ASSERT_EQ(0, mojHotel.numberOfAllRooms("Apartment"));
}
TEST(TestThirdTask, IbaApartmenty) {
	Hotel mojHotel(3, 8, 8);
	ASSERT_EQ(24, mojHotel.numberOfAllRooms("Apartment"));
}
TEST(TestThirdTask, NulovyHotel) {
	Hotel mojHotel(0, 0, 8);
	ASSERT_EQ(0, mojHotel.numberOfAllRooms("Apartment"));
}