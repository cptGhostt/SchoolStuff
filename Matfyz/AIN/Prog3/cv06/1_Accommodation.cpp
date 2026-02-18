#include <iostream>

#include "1_Accommodation.h"

//1.uloha
bool Accommodation::isRoomOccupied() const {
    return numberOfG != 0;
}

bool Accommodation::addGuests(const std::string &firstGuestName, const std::string &secondGuestName) {
    if (!firstGuestName.empty()) {
        guests[numberOfG++].checkIn(firstGuestName);
    }
    if (!secondGuestName.empty()) {
        guests[numberOfG++].checkIn(secondGuestName);
    }

    return numberOfG != 0;
}

std::string Accommodation::guestNames() const {
    if (numberOfG == 1) {
        return guests[0].getGuestName();
    }
    if (numberOfG == 2) {
        return guests[0].getGuestName() + ';' + guests[1].getGuestName();
    }
    return "";
}

std::string Room::nameOfRoomType() const {
    return TypeOfRoom[ROOM];
}

std::string Apartment::nameOfRoomType() const {
    return TypeOfRoom[APARTMENT];
}

//2. uloha
bool Accommodation::checkIn(const std::string &guestName) {
    if (cleaningTime > 0) {
        return false;
    }

    return addGuests(guestName, "");
}

bool Accommodation::checkIn(const std::string &firstGuestName, const std::string &secondGuestName) {
    if (cleaningTime > 0) {
        return false;
    }

    return addGuests(firstGuestName, secondGuestName);
}

bool Accommodation::checkOut(int cleaning, int secondGuestCleaning) {
    if (numberOfG == 0) {
        return false;
    }
    cleaningTime = cleaning;
    guests[0].checkOut();
    if (numberOfG == 2) {
        cleaningTime += secondGuestCleaning;
        guests[1].checkOut();
    }
    numberOfG = 0;
    return true;
}

int Accommodation::cleaningUp() {
    if (numberOfG > 0 || cleaningTime == 0) {
        return 0;
    }

    int tmp = cleaningTime;
    cleaningTime = 0;
    return tmp;
}
