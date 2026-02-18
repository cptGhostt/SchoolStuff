#include <iostream>
#include <queue>
#include <sstream>

#include "3_Concert.h"

//5. uloha
std::string Concert::listOfAllTickets() const {
    std::map<int, int> myTickets;
    for (int i = 0; i < tickets.size(); i++) {
        if (myTickets.find(tickets[i]->ticketPrice()) == myTickets.end()) {
            myTickets[tickets[i]->ticketPrice()] = 1;
        }
        else {
            myTickets[tickets[i]->ticketPrice()]++;
        }
    }

    std::string toReturn = "";

    for (std::map<int, int>::iterator it = myTickets.begin(); it != myTickets.end(); ++it) {
        if (it != myTickets.begin()) {
            toReturn += ", " + std::to_string(it->first) + ':' + std::to_string(it->second);
        } else {
            toReturn += std::to_string(it->first) + ':' + std::to_string(it->second);
        }
    }

    return toReturn;
}

std::string Concert::listOfTickets(TicketStatus status) const {
    std::map<int, int> myTickets;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i]->ticketStatus() == status) {
            if (myTickets.find(tickets[i]->ticketPrice()) == myTickets.end()) {
                myTickets[tickets[i]->ticketPrice()] = 1;
            }
            else {
                myTickets[tickets[i]->ticketPrice()]++;
            }
        }
    }

    std::string toReturn = "";

    for (std::map<int, int>::iterator it = myTickets.begin(); it != myTickets.end(); ++it) {
        if (it != myTickets.begin()) {
            toReturn += ", " + std::to_string(it->first) + ':' + std::to_string(it->second);
        } else {
            toReturn += std::to_string(it->first) + ':' + std::to_string(it->second);
        }
    }

    return toReturn;
}

int Concert::sellBookedTickets(const std::string &name) {
    if (customers.find(name) == customers.end()) {
        return 0;
    }

    return customers.at(name).buyBookedTickets();
}

