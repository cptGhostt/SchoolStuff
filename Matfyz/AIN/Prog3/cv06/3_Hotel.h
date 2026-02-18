#pragma once

#include "1_Accommodation.h"

//3.uloha
class Hotel {
  int floors;
  int roomsPerFloor;
  int apartmentsPerFloor;
  Room **rooms = nullptr;
  Apartment **apartments = nullptr;
public:
    Hotel(int floors0, int roomsPerFloor0, int apartmentsPerFloor0);
    Hotel();
    ~Hotel();
    int numberOfAllRooms(const std::string &roomType) const ;
    Room * getRoom(int floor, int room) const ;
    Apartment * getApartment(int floor, int apartmant) const ;
 protected:
    int getFloors() const { return floors; };
    int getRoomsPerFloor() const { return roomsPerFloor; };
    int getApartmentsPerFloor() const { return apartmentsPerFloor; };
};
