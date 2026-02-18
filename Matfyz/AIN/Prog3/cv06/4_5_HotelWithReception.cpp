#include <iostream>
#include <cstring>  /* strcpy */

#include "4_5_HotelWithReception.h"

//4.uloha
HotelWithReception::HotelWithReception(int floors0, int roomsPerFloor0, int apartmentsPerFloor0) : Hotel(floors0, roomsPerFloor0, apartmentsPerFloor0) {
    cleaningDefinition.setCleaningDefinition(CLEANING_ROOM_DEFAULT, CLEANING_APARTMENT_DEFAULT, CLEANING_SECOND_GUEST_DEFAULT);
}

void HotelWithReception::setCleaningDefinition(int cleanRoom, int cleanApartment, int cleanAfterSecondGuest) {
    cleaningDefinition.setCleaningDefinition(cleanRoom, cleanApartment, cleanAfterSecondGuest);
}

int HotelWithReception::checkIn(const std::string &guestName, const std::string &typeOfRoom) {
    if (guestName.empty()) {
        return 0;
    }
    if (typeOfRoom == "Room") {
        for (int i = 0; i < getFloors(); i++) {
            for (int j = 0; j < getRoomsPerFloor(); j++) {
                Room *r = getRoom(i, j);
                if (!r->isRoomOccupied() && r->checkIn(guestName)) {
                    currGuests++;
                    usedRooms++;
                    return (i+1) * 100 + j+1;
                }
            }
        }
    }
    if (typeOfRoom == "Apartment") {
        for (int i = 0; i < getFloors(); i++) {
            for (int j = 0; j < getApartmentsPerFloor(); j++) {
                Apartment *a = getApartment(i, j);
                if (!a->isRoomOccupied() && a->checkIn(guestName)) {
                    currGuests++;
                    usedApartments++;
                    return (i+1) * 100 + j+1 + getRoomsPerFloor();
                }
            }
        }
    }
    return 0;
}

int HotelWithReception::checkIn(const std::string &firstGuestName, const std::string &secondGuestName, const std::string &typeOfRoom) {
    if (firstGuestName.empty() && secondGuestName.empty()) {
        return 0;
    }

    if (firstGuestName.empty()) {
        return checkIn(secondGuestName, typeOfRoom);
    }
    if (secondGuestName.empty()) {
        return checkIn(firstGuestName, typeOfRoom);
    }

    if (typeOfRoom == "Room") {
        for (int i = 0; i < getFloors(); i++) {
            for (int j = 0; j < getRoomsPerFloor(); j++) {
                Room *r = getRoom(i, j);
                if (!r->isRoomOccupied() && r->checkIn(firstGuestName, secondGuestName)) {
                    currGuests += 2;
                    usedRooms++;
                    return (i+1) * 100 + j+1;
                }
            }
        }
    }
    if (typeOfRoom == "Apartment") {
        for (int i = 0; i < getFloors(); i++) {
            for (int j = 0; j < getApartmentsPerFloor(); j++) {
                Apartment *a = getApartment(i, j);
                if (!a->isRoomOccupied() && a->checkIn(firstGuestName, secondGuestName)) {
                    currGuests += 2;
                    usedApartments++;
                    return (i+1) * 100 + j+1 + getRoomsPerFloor();
                }
            }
        }
    }
    return 0;
}

int HotelWithReception::numberOfGuests() const {
    return currGuests;
}

int HotelWithReception::numberOfFreeRooms() const {
    return getRoomsPerFloor()*getFloors() - usedRooms;
}

int HotelWithReception::numberOfFreeApartments() const {
    return getApartmentsPerFloor()*getFloors() - usedApartments;
}

//5.uloha
std::string HotelWithReception::guestNames(int roomNumber) const {
    if (roomNumber % 100 > getRoomsPerFloor()+getApartmentsPerFloor()) {
        return "";
    }
    if (roomNumber / 100 > getFloors()) {
        return "";
    }

    int number = roomNumber % 100;
    int floor = roomNumber / 100;

    if (number > getRoomsPerFloor()) {
        number -= getRoomsPerFloor();
        return getApartment(floor-1, number-1)->guestNames();
    }

    return getRoom(floor-1, number-1)->guestNames();
}

bool HotelWithReception::checkOut(int roomNumber) {
    if (roomNumber % 100 > getRoomsPerFloor()+getApartmentsPerFloor()) {
        return false;
    }
    if (roomNumber / 100 > getFloors()) {
        return false;
    }

    int number = roomNumber % 100;
    int floor = roomNumber / 100;

    if (number > getRoomsPerFloor()) {
        number -= getRoomsPerFloor();
        Apartment *a = getApartment(floor-1, number-1);
        if (!a->isRoomOccupied()) {
            return false;
        }
        currGuests -= a->numberOfGuests();
        return a->checkOut(cleaningDefinition.getCleaningApartment(), cleaningDefinition.getCleaningForSecondGuest());
    }

    Room *r = getRoom(floor-1, number-1);
    if (!r->isRoomOccupied()) {
        return false;
    }
    currGuests -= r->numberOfGuests();
    return r->checkOut(cleaningDefinition.getCleaningRoom(), cleaningDefinition.getCleaningForSecondGuest());
}

int HotelWithReception::cleaningAllRooms() {
    int timeToClean = 0;

    for (int i = 0; i < getFloors(); i++) {
        for (int j = 0; j < getRoomsPerFloor(); j++) {
            Room *r = getRoom(i, j);
            if (!r->isRoomOccupied()) {
                timeToClean += r->cleaningUp();
            }
        }
    }

    for (int i = 0; i < getFloors(); i++) {
        for (int j = 0; j < getApartmentsPerFloor(); j++) {
            Apartment *a = getApartment(i, j);
            if (!a->isRoomOccupied()) {
                timeToClean += a->cleaningUp();
            }
        }
    }

    return timeToClean;
}

