#include <iostream>

#include "1_Guest.h"

//1.uloha
bool Guest::checkIn(const std::string &name) {
    if (name.empty()) {
        return false;
    }

    std::string stripped;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] != ' ') {
            stripped = name.substr(i, name.length());
            break;
        }
    }

    int spaces = 0;
    for (int i = stripped.length()-1; i >= 0; i--) {
        if (stripped[i] == ' ') {
            spaces++;
        }
        else {
            break;
        }
    }
    stripped = stripped.substr(0, stripped.length()-spaces);

    if (stripped.empty()) {
        return false;
    }

    int lastSpace = 0;
    spaces = 0;
    for (int i = 0; i < stripped.length(); i++) {
        if (stripped[i] == ' ') {
            spaces++;
            lastSpace = i;
        }
    }

    if (spaces > 0) {
        firstName = stripped.substr(0, lastSpace);
        secondName = stripped.substr(lastSpace+1, stripped.length());
    }else {
        return false;
    }

    return true;
};

bool Guest::isGuestIn() const {
    return !secondName.empty();
}

std::string Guest::getGuestName() const {
    if (!isGuestIn()) {
        return "";
    }
    std::string guestName = secondName + ", " + firstName;
    return guestName;
};

//2. uloha
bool Guest::checkOut() {
    if (secondName.empty()) {
        return false;
    }

    firstName = "";
    secondName = "";

    return true;
}
