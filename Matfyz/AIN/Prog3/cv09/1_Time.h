#pragma once

#include <iostream>
#include <sstream>

/*
enum TimeParts { HOUR, MINUTE, SECOND, MILLISECOND };
const int TimeLimit[] {24, 60, 60, 1000};

const int TimeSize = 4;
const std::string TimeNames[] {"Hour", "Minute", "Second", "Millisecond"};
*/

enum TimeStatus {HOUR, MINUTE, SECOND, MILLISECOND
    , TIME_FORMAT, NO_TIME, OK};

const int TimeSize = 4;
const int TimeLimit[] {24, 60, 60, 1000};
const std::string TimeNames[] {"Hour", "Minute", "Second", "Millisecond"};
const std::string outOfLimit {" out of limits"};
const std::string timeFormatWrong {"Wrong time format"};

/*
const std::string statusMessages[] {"Hour out of limits", "Minute out of limits"
        , "Second out of limits", "Millisecond out of limits"
        , "Wrong time format", "No time", "OK"};
*/


class WrongInput : public std::exception {
    std::string text;
public:
    WrongInput(const char *v) { text = v; };
    std::string message() const { return text; };
};

class WrongTime : public WrongInput {
public:
    WrongTime(const char *v) : WrongInput(v) {};
};

class WrongTimeMove : public WrongInput {
public:
    WrongTimeMove(const char *v) : WrongInput(v) {};
};

//1.uloha
class Time {
    int hour, minute, second, millisecond;
public:
    Time();
    void putTime(int hour0, int min0, int sec0, int mill0);
    std::string getTime() const;
    bool operator<(const Time &inputTime) const;
};
/*
class Time {
    int hour, minute, second, milliSecond;
    TimeStatus status;
public:
    Time();
    bool putTime(int hour0, int min0, int sec0, int mil0);
    std::string getTime() const;
    bool operator<(const Time &inputTime) const;
    void setStatus(TimeStatus status0) { status = status0; };
    std::string getStatus() const;
};
*/

void operator>>(std::istringstream &is, Time &inputTime);

const bool DUMMY_BOOL = false;
const int DUMMY_INT = 0;
const std::string DUMMY_STRING = "";
const std::string EMPTY_SUBTITLE {"0\n0:0:0,000 --> 0:0:0,001\nEmpty titulok"};
