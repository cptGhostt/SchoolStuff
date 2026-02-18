#include <iostream>
#include <queue>
#include <map>

#include "3_Concert.h"

//4. uloha
bool Concert::bookingTickets(const std::string &name, int price, int number) {
    if (tickets.empty()) {
        return false;
    }
    if (number > availableTickets(price) || number < 0) {
        return false;
    }

    std::vector<std::shared_ptr<Ticket>> myTickets;
    for (int i = 0; i < tickets.size(); i++) {
        if (myTickets.size() >= number) {
            break;
        }
        if (tickets[i]->available() && tickets[i]->ticketPrice() == price) {
            myTickets.push_back(tickets[i]);
        }
    }

    if (customers.find(name) == customers.end()) {
        customers.emplace(name, Customer(name));

    }

    for (int i = 0; i < myTickets.size(); i++) {
        customers.at(name).bookTicket(myTickets[i]);
    }

    return true;
}

int Concert::bookedTickets(int price) const {
    int count = 0;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i]->ticketPrice() == price && tickets[i]->booked()) {
            count++;
        }
    }
    return count;
}

int Concert::bookedTickets(const std::string &name) const {
    if (customers.find(name) == customers.end()) {
        return 0;
    }
    return customers.at(name).numberOfTickets();
}

int Concert::allBookedTickets() const {
    int count = 0;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i]->booked()) {
            count++;
        }
    }
    return count;
}

int Concert::cancelAllBookings() {
    int count = 0;
    for (std::map<std::string, Customer>::iterator it = customers.begin(); it != customers.end(); ++it) {
        count += it->second.cancelBookedTickets();
    }
    return count;
}

