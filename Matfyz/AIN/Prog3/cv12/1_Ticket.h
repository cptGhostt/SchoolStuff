#include <iostream>
#include <vector>

#pragma once

// 1.uloha
enum TicketStatus { AVAILABLE, BOOKED, SOLD };

class Ticket {
    int price;
    TicketStatus status;
public:
    Ticket();
    void setPrice(int newPrice);
    bool sell();
    bool book();
    bool sellBooked();
    bool cancelBooking();

    int  ticketPrice() const { return price; };
    bool available() const { return status == AVAILABLE; };
    bool booked() const { return status == BOOKED; };
    bool sold() const { return status == SOLD; };
    TicketStatus ticketStatus() const { return status; };
};

const bool DUMMY_BOOL = false;
const std::string DUMMY_STRING = "";
const int DUMMY_INT = -1;

