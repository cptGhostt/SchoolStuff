#include <iostream>

#include "2_Customer.h"

//2. uloha
Customer::Customer(const std::string &name) : name(name) {}

bool Customer::bookTicket(std::shared_ptr<Ticket> &ticket) {
    if (ticket->book()) {
        bookedTickets.push_back(ticket);
        return true;
    }
    return false;
}

int Customer::buyBookedTickets() {
    int total = 0;

    for (int i = 0; i < bookedTickets.size(); i++) {
        if (bookedTickets[i]->sellBooked()) {
            total++;
        }
    }

    bookedTickets.clear();
    return total;
}

int Customer::cancelBookedTickets() {
    int total = 0;

    for (int i = 0; i < bookedTickets.size(); i++) {
        if (bookedTickets[i]->cancelBooking()) {
            total++;
        }
    }

    bookedTickets.clear();
    return total;
}

