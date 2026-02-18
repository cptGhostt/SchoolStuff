// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "3_Concert.h"

using namespace ::testing;

//4. uloha
TEST(TestFourthTask, RezervovatListyPrivela) {
  std::vector<std::pair<int, int> > poctyListkov;
  poctyListkov.push_back(std::pair<int, int>(25, 5));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 5));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  Concert concert(poctyListkov);
  ASSERT_FALSE(concert.bookingTickets("Mrazik", 5, 51));
  ASSERT_FALSE(concert.bookingTickets("Mrazik", 5, -22));
  ASSERT_EQ(0, concert.bookedTickets(5));
  ASSERT_EQ(0, concert.bookedTickets("Mrazik"));
  ASSERT_EQ(100, concert.availableTickets());
}

TEST(TestFourthTask, RezervovatListy) {
  std::vector<std::pair<int, int> > poctyListkov;
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  Concert concert(poctyListkov);
  concert.bookingTickets("Mrazik", 25, 72);
  ASSERT_EQ(28, concert.availableTickets());
}

TEST(TestFourthTask, KupitARezervovatListyPrivela) {
  std::vector<std::pair<int, int> > poctyListkov;
  poctyListkov.push_back(std::pair<int, int>(25, 5));
  poctyListkov.push_back(std::pair<int, int>(25, 5));
  poctyListkov.push_back(std::pair<int, int>(25, 5));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  Concert concert(poctyListkov);
  concert.bookingTickets("Mrazik", 5, 48);
  ASSERT_EQ(52, concert.availableTickets());
  ASSERT_FALSE(concert.sellTickets(66, 5));
  ASSERT_EQ(52, concert.availableTickets());
  ASSERT_EQ(48, concert.bookedTickets(5));
  ASSERT_EQ(48, concert.cancelAllBookings());
  ASSERT_EQ(0, concert.bookedTickets(5));
  ASSERT_EQ(100, concert.availableTickets());
}

TEST(TestFourthTask, KupitARezervovatListy) {
    std::vector<std::pair<int, int> > poctyListkov;
    poctyListkov.push_back(std::pair<int, int>(25, 25));
    poctyListkov.push_back(std::pair<int, int>(25, 10));
    poctyListkov.push_back(std::pair<int, int>(25, 10));
    poctyListkov.push_back(std::pair<int, int>(25, 25));
    Concert concert(poctyListkov);
    concert.bookingTickets("Jano", 25, 48);
    concert.bookingTickets("Peter", 25, 11);
    concert.bookingTickets("Kurt", 10, 14);
    ASSERT_EQ(48, concert.bookedTickets(25));
    ASSERT_EQ(14, concert.bookedTickets(10));
    ASSERT_EQ(62, concert.allBookedTickets());
    ASSERT_EQ(38, concert.availableTickets());
}

TEST(TestFourthTask, RezervovatAKupitListyPrivela) {
  std::vector<std::pair<int, int> > poctyListkov;
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  Concert concert(poctyListkov);
  concert.bookingTickets("Mrazik", 10, 33);
  concert.bookingTickets("Kurt", 10, 14);
  ASSERT_EQ(47, concert.bookedTickets(10));
  ASSERT_EQ(33, concert.bookedTickets("Mrazik"));
  concert.cancelAllBookings();
  ASSERT_EQ(100, concert.availableTickets());
}

TEST(TestFourthTask, RezervovatAKupitListy) {
  std::vector<std::pair<int, int> > poctyListkov;
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 10));
  poctyListkov.push_back(std::pair<int, int>(25, 25));
  Concert concert(poctyListkov);
  concert.bookingTickets("Mrazik", 25, 48);
  concert.sellTickets(22, 10);
  concert.cancelAllBookings();
  ASSERT_EQ(78, concert.availableTickets());
}

