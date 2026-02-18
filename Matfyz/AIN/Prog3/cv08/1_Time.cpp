#include <iostream>
#include <iomanip>

#include "1_Time.h"

#include <string.h>

//1.uloha
Time::Time() {
    hour = -1;
    minute = -1;
    second = -1;
    milliSecond = -1;
    status = NO_TIME;
}

bool Time::putTime(int hour0, int min0, int sec0, int mil0) {
    if (hour0 < 0 || hour0 > 23) {
        status = HOUR;
        return false;
    }

    if (min0 < 0 || min0 > 59) {
        status = MINUTE;
        return false;
    }

    if (sec0 < 0 || sec0 > 59) {
        status = SECOND;
        return false;
    }

    if (mil0 < 0 || mil0 > 999) {
        status = MILLISECOND;
        return false;
    }

    hour = hour0;
    minute = min0;
    second = sec0;
    milliSecond = mil0;
    status = OK;
    return true;
}

bool operator>>(std::istringstream &is, Time &time) {
    std::string h, m, s, ms;
    std::istringstream myInput(is.str());

    int sep1 = 0, sep2 = 0;

    for (int i = 0; i < strlen(myInput.str().c_str()); i++) {
        if (is.str()[i] == ':') {
            sep1++;

        }
        if (is.str()[i] == ',') {
            sep2++;
        }
    }

    if (sep1 != 2 || sep2 != 1) {
        time.setStatus(TIME_FORMAT);
        return false;
    }

    std::getline(myInput, h, ':');
    std::getline(myInput, m, ':');
    std::getline(myInput, s, ',');
    std::getline(myInput, ms);

    for (int i = 0; i < strlen(h.c_str()); i++) {
        if (h[i] < '0' || h[i] > '9') {
            time.setStatus(HOUR);
            return false;
        }
    }

    for (int i = 0; i < strlen(m.c_str()); i++) {
        if (m[i] < '0' || m[i] > '9') {
            time.setStatus(MINUTE);
            return false;
        }
    }

    for (int i = 0; i < strlen(s.c_str()); i++) {
        if (s[i] < '0' || s[i] > '9') {
            time.setStatus(SECOND);
            return false;
        }
    }

    for (int i = 0; i < strlen(ms.c_str()); i++) {
        if (ms[i] < '0' || ms[i] > '9') {
            time.setStatus(MILLISECOND);
            return false;
        }
    }

    return time.putTime(atoi(h.c_str()), atoi(m.c_str()), atoi(s.c_str()), atoi(ms.c_str()));
}

bool Time::operator<(const Time &inputTime) const {
    if (hour < inputTime.hour) return true;
    if (hour > inputTime.hour) return false;
    if (minute < inputTime.minute) return true;
    if (minute > inputTime.minute) return false;
    if (second < inputTime.second) return true;
    if (second > inputTime.second) return false;
    if (milliSecond < inputTime.milliSecond) return true;

    return false;
}

std::string Time::getTime() const {
    if (status == NO_TIME) {
        return "No time";
    }

    std::ostringstream toReturn("");
    toReturn << std::setfill('0') << std::setw(2) << hour << ":";
    toReturn << std::setw(2) << minute << ":";
    toReturn << std::setw(2) << second << ",";
    toReturn << std::setw(3) << milliSecond;
    return toReturn.str();
}

std::string Time::getStatus() const {
    return statusMessages[status];
};
