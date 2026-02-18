#pragma once

//1.uloha
class Guest {
    std::string firstName;
    std::string secondName;
public:
    bool checkIn(const std::string &name);
    bool checkOut();
    std::string getGuestName() const;

    bool isGuestIn() const;
};

const std::string DUMMY_STRING = "";
const int DUMMY_INT = -999;
const bool DUMMY_BOOL = false;

