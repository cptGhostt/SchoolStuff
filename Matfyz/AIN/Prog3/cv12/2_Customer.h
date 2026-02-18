#include <iostream>
#include <vector>
#include <memory>

#pragma once

#include "1_Ticket.h"

class Customer {
    const std::string name;
    std::vector<std::shared_ptr<Ticket> > bookedTickets;
public:
    Customer(const std::string &name);
    bool bookTicket(std::shared_ptr<Ticket> &ticket);
    int buyBookedTickets();
    int cancelBookedTickets();

    int numberOfTickets() const { return bookedTickets.size(); };
};

