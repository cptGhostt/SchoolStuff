#include <iostream>
#include <vector>
#include <map>
#include <memory>

#pragma once

#include "2_Customer.h"

class Concert {
    std::vector<std::shared_ptr<Ticket> > tickets;
    std::map<std::string, Customer> customers;
public:
  //3. uloha
    Concert(const std::vector<std::pair<int, int> > ticketTypes);
    int allTickets(int price) const;
    int allTickets() const;
    int availableTickets(int price) const;
    int availableTickets() const;
    bool sellTickets(int number, int price);
    int soldTicketsAll() const;

   //4. uloha
    bool bookingTickets(const std::string &name, int price, int number);
    int bookedTickets(int price) const;
    int bookedTickets(const std::string &name) const;
    int allBookedTickets() const;
    int cancelAllBookings();

    //5. uloha
    std::string listOfAllTickets() const;
    std::string listOfTickets(TicketStatus status) const;
    int sellBookedTickets(const std::string &name);
};


