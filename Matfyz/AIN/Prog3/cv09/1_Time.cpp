#include <iostream>
#include <iomanip>

#include "1_Time.h"

#include <string.h>

//1.uloha
Time::Time() {
    hour = 0;
    minute = 0;
    second = 0;
    millisecond = 0;
}

void Time::putTime(int hour0, int min0, int sec0, int mill0) {
    if (hour0 < 0 || hour0 > 23) {
        throw WrongTime("Hour out of limits");
    }
    if (min0 < 0 || min0 > 59) {
        throw WrongTime("Minute out of limits");
    }
    if (sec0 < 0 || sec0 > 59) {
        throw WrongTime("Second out of limits");
    }
    if (mill0 < 0 || mill0 > 999) {
        throw WrongTime("Millisecond out of limits");
    }

    hour = hour0;
    minute = min0;
    second = sec0;
    millisecond = mill0;

}

void operator>>(std::istringstream &is, Time &time) {
    std::string h, m, s, ms;
    std::istringstream myInput(is.str());

    int sep1 = 0, sep2 = 0;

    for (int i = 0; i < strlen(myInput.str().c_str()); i++) {
        if (is.str()[i] == ':') {
            sep1++;
            continue;
        }
        if (is.str()[i] == ',') {
            sep2++;
            continue;
        }
        if ((is.str()[i] < '0' || is.str()[i] > '9') && is.str()[i] != '-') {
            throw WrongInput("Wrong time format");
        }
    }

    if (sep1 != 2 || sep2 != 1) {
        throw WrongInput("Wrong time format");
    }

    std::getline(myInput, h, ':');
    std::getline(myInput, m, ':');
    std::getline(myInput, s, ',');
    std::getline(myInput, ms);

    for (int i = 0; i < strlen(h.c_str()); i++) {
        if (h[i] < '0' || h[i] > '9') {
            throw WrongTime("Hour out of limits");
        }
    }

    for (int i = 0; i < strlen(m.c_str()); i++) {
        if (m[i] < '0' || m[i] > '9') {
            throw WrongTime("Minute out of limits");
        }
    }

    for (int i = 0; i < strlen(s.c_str()); i++) {
        if (s[i] < '0' || s[i] > '9') {
            throw WrongTime("Second out of limits");
        }
    }

    for (int i = 0; i < strlen(ms.c_str()); i++) {
        if (ms[i] < '0' || ms[i] > '9') {
            throw WrongTime("Millisecond out of limits");
        }
    }

    time.putTime(std::stoi(h), std::stoi(m), std::stoi(s), std::stoi(ms));
}

bool Time::operator<(const Time &inputTime) const {
    if (hour < inputTime.hour) return true;
    if (hour > inputTime.hour) return false;
    if (minute < inputTime.minute) return true;
    if (minute > inputTime.minute) return false;
    if (second < inputTime.second) return true;
    if (second > inputTime.second) return false;
    if (millisecond < inputTime.millisecond) return true;

    return false;
}

std::string Time::getTime() const {
    std::ostringstream toReturn("");
    toReturn << std::setfill('0') << std::setw(2) << hour << ":";
    toReturn << std::setw(2) << minute << ":";
    toReturn << std::setw(2) << second << ",";
    toReturn << std::setw(3) << millisecond;
    return toReturn.str();
}
