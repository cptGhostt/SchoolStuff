#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "2_Subtitle.h"

#include <string.h>

//2.uloha
bool Subtitle::putTimeRow(const std::string &timeRow) {
    std::istringstream is(timeRow);
    std::string begin, del, end;
    std::getline(is, begin, ' ');
    std::getline(is, del, ' ');
    std::getline(is, end, '\0');

    if (strcmp(del.c_str(), "-->")) {
        status = TIME_ROW_FORMAT;
        return false;
    }

    Time validator, validator2;

    std::istringstream tmp(begin);
    tmp >> validator;
    if (validator.getStatus() != "OK") {
        status = TIME_ROW_FORMAT;
        return false;
    }

    std::istringstream tmp2(end);
    tmp2 >> validator2;
    if (validator2.getStatus() != "OK") {
        status = TIME_ROW_FORMAT;
        return false;
    }

    if (!(validator < validator2)) {
        status = TIME_ORDER;
        return false;
    }

    std::istringstream tmp3(validator.getTime());
    tmp3 >> beginTime;
    std::istringstream tmp4(validator2.getTime());
    tmp4 >> endTime;

    status = SUBTITLE_OK;
    return true;
}

bool Subtitle::putSubTitle(const std::string &subTitle) {
    std::istringstream is(subTitle);
    int tmp;
    if (!(is >> tmp)) {
        status = SUBTITLE_FORMAT;
        return false;
    }
    number = tmp;

    is = std::istringstream(subTitle);
    std::string timeRow;
    std::getline(is, timeRow, '\n');
    std::getline(is, timeRow, '\n');
    if (!putTimeRow(timeRow)) {
        return false;
    }
    std::getline(is, subtitleText, '\0');
    status = SUBTITLE_OK;

    return true;
}

std::string Subtitle::getTextRow(int index) const {
    std::istringstream is(subtitleText);
    std::string s;
    int count = 1;
    while (std::getline(is, s, '\n')) {
        if (count == index) {
            return s;
        }
        count++;
    }

    return "";
};