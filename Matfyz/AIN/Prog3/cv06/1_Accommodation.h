#pragma once

#include "1_Guest.h"
//#include "2_Cleaning.h"

const int MAX_ROOM_GUESTS = 2;
const int CLEANING_ROOM_DEFAULT = 25;
const int CLEANING_APARTMENT_DEFAULT = 40;
const int CLEANING_SECOND_GUEST_DEFAULT = 20;

class Accommodation {
  Guest guests[MAX_ROOM_GUESTS];
  int numberOfG {0};
 public:
  bool isRoomOccupied() const ;
  bool addGuests(const std::string &firstGuestName, const std::string &secondGuestName = "");
  std::string guestNames() const ;
  virtual std::string nameOfRoomType() const = 0;

  inline int numberOfGuests() const { return numberOfG; };
  //2. uloha
 private:
  int cleaningTime {0};
 public:
  bool checkIn(const std::string &guestName);
  bool checkIn(const std::string &firstGuestName, const std::string &secondGuestName);
  bool checkOut(int cleaning = CLEANING_ROOM_DEFAULT, int secondGuestCleaning = CLEANING_SECOND_GUEST_DEFAULT);
  int cleaningUp();
};

enum RoomType { ROOM, APARTMENT };
const std::string TypeOfRoom[] {"Room", "Apartment"};

class Room : public Accommodation {
    RoomType roomType = ROOM;
 public:
    std::string nameOfRoomType() const;
};

class Apartment : public Accommodation {
    RoomType roomType = APARTMENT;
 public:
    std::string nameOfRoomType() const;
};

