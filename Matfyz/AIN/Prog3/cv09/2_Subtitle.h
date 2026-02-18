#include <iostream>

#pragma once

#include "1_Time.h"

enum SubtitleError { SUBTITLE_FORMAT, NO_TEXT, TIME_ORDER, TIME_LINE_FORMAT };
const std::string SubtitleErrorMessages[] {"Subtitle has wrong format"
                                         , "Subtitle has no text"
                                         , "Subtitle begin time is not less than end time"
                                         , "Subtitle time row has wrong format"};

//2.uloha
class Subtitle {
    int number = 0;
    Time beginTime, endTime;
    std::string subtitleText {};
public:
    void putSubtitle(const std::string &subTitle);
    void putTimeRow(const std::string &timeRow);
    std::string getTextRow(int index) const;
    std::string getSubtitle() const;

    int getSubtitleNumber() const { return number; };
    std::string getBeginTime() const { return beginTime.getTime(); };
    std::string getEndTime() const { return endTime.getTime(); };
};
