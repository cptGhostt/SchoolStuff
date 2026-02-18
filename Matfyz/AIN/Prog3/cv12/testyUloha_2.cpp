// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "2_Customer.h"

using namespace ::testing;

// 2.uloha
TEST(TestSecondTask, BookTickets) {
    Customer customer("Eva");
    std::shared_ptr<Ticket> ticket { new Ticket()};
    customer.bookTicket(ticket);
    ASSERT_FALSE(customer.bookTicket(ticket));
    ASSERT_EQ(1, customer.numberOfTickets());
    std::shared_ptr<Ticket> ticket2 { new Ticket()};
    ASSERT_TRUE(customer.bookTicket(ticket2));
    ASSERT_FALSE(customer.bookTicket(ticket));
    ASSERT_FALSE(customer.bookTicket(ticket2));
    ASSERT_EQ(2, customer.numberOfTickets());
}

TEST(TestSecondTask, buyBookedTickets) {
    Customer customer("Eva");
    std::shared_ptr<Ticket> ticket { new Ticket()};
    ASSERT_TRUE(customer.bookTicket(ticket));
    ASSERT_EQ(1, customer.buyBookedTickets());
    std::shared_ptr<Ticket> ticket2 { new Ticket()};
    ASSERT_TRUE(customer.bookTicket(ticket2));
    ASSERT_TRUE(ticket2->booked());
    ASSERT_EQ(1, customer.buyBookedTickets());
    ASSERT_FALSE(ticket2->booked());
    ASSERT_EQ(0, customer.buyBookedTickets());
    ASSERT_EQ(0, customer.numberOfTickets());
}

TEST(TestSecondTask, cancelBooking) {
    Customer customer("Jana");
    std::shared_ptr<Ticket> ticket { new Ticket()};
    ASSERT_TRUE(customer.bookTicket(ticket));
    ASSERT_EQ(1, customer.cancelBookedTickets());
    std::shared_ptr<Ticket> ticket2 { new Ticket()};
    ASSERT_EQ(0, customer.cancelBookedTickets());
    ASSERT_TRUE(customer.bookTicket(ticket2));
    ASSERT_TRUE(ticket2->booked());
    ASSERT_EQ(1, customer.cancelBookedTickets());
    ASSERT_FALSE(ticket2->booked());
    ASSERT_TRUE(ticket2->available());
    ASSERT_TRUE(ticket2->sell());
    ASSERT_EQ(0, customer.numberOfTickets());
}

