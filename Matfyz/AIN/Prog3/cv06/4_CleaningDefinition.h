#pragma once

#include "1_Accommodation.h"

class CleaningDefinition {
  int cleaningRoom;
  int cleaningApartment;
  int cleaningForSecondGuest;
 public:
  CleaningDefinition(int cleanRoom, int cleanApartment, int cleanAfterSecondGuest);
  CleaningDefinition();
  bool setCleaningDefinition(int cleanRoom, int cleanApartment, int cleanAfterSecondGuest);
  inline int getCleaningRoom() const { return cleaningRoom; };
  inline int getCleaningApartment() const { return cleaningApartment; };
  inline int getCleaningForSecondGuest() const { return cleaningForSecondGuest; };
};


