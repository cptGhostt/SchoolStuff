#include <iostream>

#include "3_Hotel.h"

//3.uloha
Hotel::Hotel(int floors0, int roomsPerFloor0, int apartmentsPerFloor0) {
    if (floors0 < 1 || roomsPerFloor0 + apartmentsPerFloor0 < 1) {
        floors = 0;
        roomsPerFloor = 0;
        apartmentsPerFloor = 0;
        return;
    }

    floors = floors0;
    apartmentsPerFloor = apartmentsPerFloor0;
    roomsPerFloor = roomsPerFloor0;

    if (roomsPerFloor > 0) {
        rooms = new Room*[floors];
        for (int i = 0; i < floors; i++) {
            rooms[i] = new Room[roomsPerFloor];
        }
    }
    if (apartmentsPerFloor > 0) {
        apartments = new Apartment*[floors];
        for (int i = 0; i < floors; i++) {
            apartments[i] = new Apartment[apartmentsPerFloor];
        }
    }
}

Hotel::Hotel() : floors(0), roomsPerFloor(0), apartmentsPerFloor(0) {}

Hotel::~Hotel() {
    if (rooms != nullptr) {
        for (int i = 0; i < floors; i++) {
            delete [] rooms[i];
        }
        delete [] rooms;
    }


    if (apartments != nullptr) {
        for (int i = 0; i < floors; i++) {
            delete [] apartments[i];
        }
        delete [] apartments;
    }

}

int Hotel::numberOfAllRooms(const std::string &roomType) const {
    if (roomType == "Room") {
        return floors * roomsPerFloor;
    }
    if (roomType == "Apartment") {
        return floors * apartmentsPerFloor;
    }
    return 0;
}

Room * Hotel::getRoom(int row, int col) const {
    if (rooms == nullptr || row > floors-1 || col > roomsPerFloor-1) {
        Room *room = new Room;
        return room;
    }

    return &rooms[row][col];
}
Apartment * Hotel::getApartment(int row, int col) const {
    if (apartments == nullptr || row > floors-1 || col > apartmentsPerFloor-1) {
        Apartment *room = new Apartment;
        return room;
    }

    return &apartments[row][col];
}

