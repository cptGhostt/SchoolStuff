#include <iostream>

#pragma once

#include "1_Time.h"

enum SubtitleStatus {TIME_ROW_FORMAT, TIME_ORDER, SUBTITLE_FORMAT, SUBTITLE_OK};
const std::string subtitleMessages[] {"Subtitle time has wrong format"
      , "Subtitle begin time is not less than end time", "Subtitle has wrong format", "OK"};


//2.uloha
class Subtitle {
  int number = 0;
  Time beginTime, endTime;
  std::string subtitleText {};
  SubtitleStatus status = SUBTITLE_OK;
public:
  bool putSubTitle(const std::string &subTitle);
  bool putTimeRow(const std::string &timeRow);
  std::string getTextRow(int index) const;

  int getSubtitleNumber() const { return number; };
  std::string getBeginTime() const { return beginTime.getTime(); };
  std::string getEndTime() const { return endTime.getTime(); };

  void setStatus(SubtitleStatus status0){ status = status0; };
  std::string getStatus() const { return subtitleMessages[status]; };
};

