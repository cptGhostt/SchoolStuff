#include <iostream>
#include <sstream>
#include <queue>
#include <thread>

#include "3_Concert.h"

//3. uloha
Concert::Concert(const std::vector<std::pair<int, int> > ticketTypes) {
    for (int i = 0; i < ticketTypes.size(); i++) {
        std::pair<int, int> ticketType = ticketTypes[i];

        for (int j = 0; j < ticketType.first; j++) {
            auto tmp = std::make_shared<Ticket>();
            tmp->setPrice(ticketType.second);
            tickets.push_back(tmp);
        }
    }
}

int Concert::allTickets(int price) const {
    int count = 0;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i]->ticketPrice() == price) {
            count++;
        }
    }
    return count;
}

int Concert::allTickets() const {
    return tickets.size();
}

int Concert::availableTickets() const {
    int count = 0;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i]->available()) {
            count++;
        }
    }
    return count;
}

int Concert::availableTickets(int price) const {
    int count = 0;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i]->ticketPrice() == price && tickets[i]->available()) {
            count++;
        }
    }
    return count;
}

int Concert::soldTicketsAll() const {
    int count = 0;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i]->sold()) {
            count++;
        }
    }
    return count;
}

bool Concert::sellTickets(int number, int price) {
    if (availableTickets(price) < number) {
        return false;
    }

    std::vector<std::shared_ptr<Ticket>> myTickets;
    int counter = number;

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i]->available() && tickets[i]->ticketPrice() == price && number > 0) {
            myTickets.push_back(tickets[i]);
            counter--;
        }
        if (counter == 0) {
            break;
        }
    }

    if (myTickets.size() != number) {
        return false;
    }

    for (int i = 0; i < myTickets.size(); i++) {
        myTickets[i]->sell();
    }

    return true;
}


