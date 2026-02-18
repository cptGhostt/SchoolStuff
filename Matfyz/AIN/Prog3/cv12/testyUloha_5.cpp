// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "3_Concert.h"

using namespace ::testing;

//5.uloha
TEST(TestFifthTask, KupitRezervovaneListyPrivela) {
    std::vector<std::pair<int, int> > poctyListkov;
    poctyListkov.push_back(std::pair<int, int>(25, 25));
    poctyListkov.push_back(std::pair<int, int>(25, 10));
    poctyListkov.push_back(std::pair<int, int>(25, 10));
    poctyListkov.push_back(std::pair<int, int>(25, 25));
    Concert concert(poctyListkov);
    ASSERT_EQ("10:50, 25:50", concert.listOfAllTickets());
    concert.bookingTickets("Mrazik", 10, 33);
    concert.bookingTickets("Kurt", 10, 14);
    ASSERT_EQ(47, concert.bookedTickets(10));
    ASSERT_EQ(33, concert.bookedTickets("Mrazik"));
    ASSERT_EQ(33, concert.sellBookedTickets("Mrazik"));
    ASSERT_EQ("10:14", concert.listOfTickets(BOOKED));
    concert.cancelAllBookings();
    ASSERT_EQ("10:33", concert.listOfTickets(SOLD));
    ASSERT_EQ("10:17, 25:50", concert.listOfTickets(AVAILABLE));
    ASSERT_EQ(67, concert.availableTickets());
}

TEST(TestFifthTask, RezervovatAKupitListy) {
    std::vector<std::pair<int, int> > poctyListkov;
    poctyListkov.push_back(std::pair<int, int>(25, 25));
    poctyListkov.push_back(std::pair<int, int>(25, 10));
    poctyListkov.push_back(std::pair<int, int>(25, 10));
    poctyListkov.push_back(std::pair<int, int>(25, 25));
    Concert concert(poctyListkov);
    concert.bookingTickets("Mrazik", 25, 48);
    concert.sellBookedTickets("Mrazik");
    ASSERT_EQ(52, concert.availableTickets());
    concert.sellTickets(22, 10);
    concert.cancelAllBookings();
    ASSERT_EQ(30, concert.availableTickets());
}

TEST(TestFifthTask, UdalostPocet) {
    std::vector<std::pair<int, int> > poctyListkov;
    poctyListkov.push_back(std::pair<int, int>(12, 5));
    Concert concert(poctyListkov);
    ASSERT_EQ(12, concert.allTickets());
    ASSERT_EQ(12, concert.allTickets(5));
    ASSERT_EQ(0, concert.allTickets(2));
    ASSERT_EQ("5:12", concert.listOfAllTickets());
}

TEST(TestFifthTask, pocetListkovSCenami) {
    std::vector<std::pair<int, int> > poctyListkov;
    poctyListkov.push_back(std::pair<int, int>(25, 5));
    poctyListkov.push_back(std::pair<int, int>(25, 10));
    poctyListkov.push_back(std::pair<int, int>(25, 15));
    poctyListkov.push_back(std::pair<int, int>(15, 5));
    Concert concert(poctyListkov);
    ASSERT_EQ("5:40, 10:25, 15:25", concert.listOfAllTickets());
    ASSERT_EQ(90, concert.allTickets());
    ASSERT_EQ(25, concert.allTickets(15));
    ASSERT_EQ(40, concert.allTickets(5));
}

TEST(TestFifthTask, KupitListyPrivelaNaraz) {
  std::vector<std::pair<int, int> > poctyListkov;
  poctyListkov.push_back(std::pair<int, int>(25, 5));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 15));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  Concert concert(poctyListkov);
  ASSERT_EQ(100, concert.allTickets());
  concert.sellTickets(101, 10);
  ASSERT_EQ(100, concert.availableTickets());
}

TEST(TestFifthTask, KupitRozneListy72) {
  std::vector<std::pair<int, int> > poctyListkov;
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  Concert concert(poctyListkov);
  concert.sellTickets(10, 25);
  concert.sellTickets(22, 10);
  concert.sellTickets( 10, 25);
  concert.sellTickets( 11, 10);
  concert.sellTickets( 30, 25);
  ASSERT_EQ("10:22, 25:50", concert.listOfTickets(SOLD));
  ASSERT_EQ("10:3, 25:25", concert.listOfTickets(AVAILABLE));
  ASSERT_EQ(28, concert.availableTickets());
}

TEST(TestFifthTask, RezervovatListyPrivela) {
  std::vector<std::pair<int, int> > poctyListkov;
  poctyListkov.push_back(std::pair<int, int>(25, 5));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 5));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  Concert concert(poctyListkov);
  concert.bookingTickets("Mrazik", 5, 51);
  ASSERT_EQ(100, concert.availableTickets());
}

TEST(TestFifthTask, RezervovatListy) {
  std::vector<std::pair<int, int> > poctyListkov;
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  Concert concert(poctyListkov);
  concert.bookingTickets("Mrazik", 25, 72);
  ASSERT_EQ(28, concert.availableTickets());
}

TEST(TestFifthTask, KupitARezervovatListy) {
  std::vector<std::pair<int, int> > poctyListkov;
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  Concert concert(poctyListkov);
  concert.sellTickets(33, 10);
  concert.bookingTickets( "Jano", 25, 48);
  ASSERT_EQ(19, concert.availableTickets());
}

TEST(TestFifthTask, KupitARezervovatListyPrivela) {
  std::vector<std::pair<int, int> > poctyListkov;
  poctyListkov.push_back(std::pair<int, int>(25, 5));
  poctyListkov.push_back(std::pair<int, int>(25, 5));
  poctyListkov.push_back(std::pair<int, int>(25, 5));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  Concert concert(poctyListkov);
  ASSERT_EQ("5:75, 25:25", concert.listOfAllTickets());
  ASSERT_TRUE(concert.bookingTickets( "Mrazik", 5, 66));
  ASSERT_TRUE(concert.sellTickets(6, 5));
  ASSERT_EQ(66, concert.bookedTickets(5));
  concert.cancelAllBookings();
  ASSERT_EQ(94, concert.availableTickets());
}

TEST(TestFifthTask, RezervovatAKupitListyPrivela) {
  std::vector<std::pair<int, int> > poctyListkov;
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  Concert concert(poctyListkov);
  concert.bookingTickets( "Mrazik", 10, 48);
  concert.sellBookedTickets("Mrazik");
  concert.sellTickets(55, 10);
  ASSERT_EQ("10:48", concert.listOfTickets(SOLD));
  ASSERT_EQ("10:2, 25:50", concert.listOfTickets(AVAILABLE));
  concert.cancelAllBookings();
  ASSERT_EQ(52, concert.availableTickets());
}

TEST(TestFifthTask, KupitPoRezervacii) {
  std::vector<std::pair<int, int> > poctyListkov;
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  Concert concert(poctyListkov);
  concert.bookingTickets(  "Mrazik", 25, 48 );
  concert.sellTickets(15, 10);
  concert.sellBookedTickets("Mrazik");
  concert.bookingTickets(  "Junior", 25, 13 );
  concert.cancelAllBookings();
  concert.sellTickets(2, 10);
  concert.sellTickets(25, 10);
  concert.sellTickets(25, 10);
  ASSERT_EQ("10:42, 25:48", concert.listOfTickets(SOLD));
  ASSERT_EQ("", concert.listOfTickets(BOOKED));
  ASSERT_EQ("10:8, 25:2", concert.listOfTickets(AVAILABLE));
  ASSERT_EQ("10:50, 25:50", concert.listOfAllTickets());
  ASSERT_EQ(10, concert.availableTickets());
}

