#include <iostream>
#include <queue>

#include "1_Ticket.h"

//1. uloha

Ticket::Ticket() {
    price = 0;
    status = AVAILABLE;
}

void Ticket::setPrice(int newPrice) {
    if (newPrice >= 0) {
        price = newPrice;
    }
}

bool Ticket::sell() {
	if (status == AVAILABLE) {
	    status = SOLD;
	    return true;
	}
    return false;
}

bool Ticket::book() {
    if (status == AVAILABLE) {
        status = BOOKED;
        return true;
    }
    return false;
}

bool Ticket::sellBooked() {
    if (status == BOOKED) {
        status = SOLD;
        return true;
    }
    return false;
}

bool Ticket::cancelBooking() {
    if (status == BOOKED) {
        status = AVAILABLE;
        return true;
    }
    return false;
}

