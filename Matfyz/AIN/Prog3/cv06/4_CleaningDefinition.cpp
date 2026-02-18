#include <iostream>

#include "4_CleaningDefinition.h"

// 4.uloha
CleaningDefinition::CleaningDefinition(int cleanRoom, int cleanApartment, int cleanAfterSecondGuest) {
    if (cleanRoom < 0 || cleanApartment < 0 || cleanAfterSecondGuest < 0) {
        cleaningRoom = CLEANING_ROOM_DEFAULT;
        cleaningApartment = CLEANING_APARTMENT_DEFAULT;
        cleaningForSecondGuest = CLEANING_SECOND_GUEST_DEFAULT;
        return;
    }

    cleaningRoom = cleanRoom;
    cleaningApartment = cleanApartment;
    cleaningForSecondGuest = cleanAfterSecondGuest;
}

CleaningDefinition::CleaningDefinition() :  cleaningRoom(CLEANING_ROOM_DEFAULT),
                                            cleaningApartment(CLEANING_APARTMENT_DEFAULT),
                                            cleaningForSecondGuest(CLEANING_SECOND_GUEST_DEFAULT) {}

bool CleaningDefinition::setCleaningDefinition(int cleanRoom, int cleanApartment, int cleanAfterSecondGuest){
    if (cleanRoom < 0 || cleanApartment < 0 || cleanAfterSecondGuest < 0) {
        cleaningRoom = CLEANING_ROOM_DEFAULT;
        cleaningApartment = CLEANING_APARTMENT_DEFAULT;
        cleaningForSecondGuest = CLEANING_SECOND_GUEST_DEFAULT;
        return false;
    }

    cleaningRoom = cleanRoom;
    cleaningApartment = cleanApartment;
    cleaningForSecondGuest = cleanAfterSecondGuest;

    return true;
}
