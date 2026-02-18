#pragma once

#include "3_Hotel.h"
#include "4_CleaningDefinition.h"

//4.uloha
class HotelWithReception : public Hotel {
  CleaningDefinition cleaningDefinition;
    int currGuests {0};
    int usedRooms {0};
    int usedApartments {0};
 public:
  HotelWithReception(int floors0, int roomsPerFloor0, int apartmentsPerFloor0);
  void setCleaningDefinition(int room, int apartment, int secondGuest);
  int checkIn(const std::string &guestName, const std::string &typeOfRoom);
  int checkIn(const std::string &firstGuestName, const std::string &secondGuestName, const std::string &typeOfRoom);
  int numberOfGuests() const ;
  int numberOfFreeRooms() const;
  int numberOfFreeApartments() const;

  //5.uloha
   std::string guestNames(int roomNumber) const;
   bool checkOut(int roomNumber);
   int cleaningAllRooms();
};
