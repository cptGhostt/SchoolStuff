#pragma once

#include <iostream>
#include <sstream>

enum TimeStatus {HOUR, MINUTE, SECOND, MILLISECOND
                , TIME_FORMAT, NO_TIME, OK};
const std::string statusMessages[] {"Hour out of limits", "Minute out of limits"
                                   , "Second out of limits", "Millisecond out of limits"
                                   , "Wrong time format", "No time", "OK"};
const int TimeLimit[] {24, 60, 60, 1000};

//1.uloha
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

bool operator>>(std::istringstream &is, Time &inputTime);

const bool DUMMY_BOOL = false;
const int DUMMY_INT = 0;
const std::string DUMMY_STRING = "";
