// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "1_Ticket.h"

using namespace ::testing;

// 1.uloha
TEST(TestFirstTask, ListokCenaBezNastavenia) {
    Ticket ticket;
    ASSERT_EQ(0, ticket.ticketPrice());
}

TEST(TestFirstTask, ListokCena) {
    Ticket ticket;
    ticket.setPrice(10);
    ASSERT_EQ(10, ticket.ticketPrice());
}

TEST(TestFirstTask, ListokCenaDvakrat) {
    Ticket ticket;
    ticket.setPrice(10);
    ticket.setPrice(20);
    ASSERT_EQ(20, ticket.ticketPrice());
}

TEST(TestFirstTask, CenaViackrat) {
    Ticket ticket;
    ticket.setPrice(10);
    ticket.setPrice(-20);
    ASSERT_EQ(10, ticket.ticketPrice());
    ticket.setPrice(0);
    ASSERT_EQ(0, ticket.ticketPrice());
}

TEST(TestFirstTask, ListokCenaZaporna) {
    Ticket ticket;
    ticket.setPrice(-10);
    ASSERT_EQ(0, ticket.ticketPrice());
}

TEST(TestFirstTask, Listok) {
    Ticket ticket;
    ASSERT_TRUE(ticket.available());
}

TEST(TestFirstTask, ListokPrazdny) {
    Ticket ticket;
    ASSERT_FALSE(ticket.sold());
}

TEST(TestFirstTask, KupitListok) {
    Ticket ticket;
    ASSERT_TRUE(ticket.sell());
    ASSERT_TRUE(ticket.sold());
}

TEST(TestFirstTask, KupitKupeny) {
    Ticket ticket;
    ticket.sell();
    ASSERT_FALSE(ticket.sell());
}

TEST(TestFirstTask, UvolnenieKupeneho) {
    Ticket ticket;
    ticket.sell();
    ASSERT_FALSE(ticket.cancelBooking());
}

TEST(TestFirstTask, UvolnenieRezervy) {
    Ticket ticket;
    ticket.book();
    ASSERT_TRUE(ticket.cancelBooking());
}
