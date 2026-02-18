#include <fstream>
#include <sstream>
#include "algorithm"

#include "2_Subtitle.h"

#include <string.h>

//2.uloha
void Subtitle::putSubtitle(const std::string &subTitle) {
    std::istringstream is(subTitle);
    int tmp;
    if (!(is >> tmp)) {
        throw WrongInput("Subtitle has wrong format");
    }
    number = tmp;

    is = std::istringstream(subTitle);
    std::string timeRow;
    std::getline(is, timeRow, '\n');
    std::getline(is, timeRow, '\n');
    putTimeRow(timeRow);

    std::string text;
    std::getline(is, text, '\0');
    if (text.empty()) {
        throw WrongInput("Subtitle has no text");
    }

    subtitleText = text;
}

void Subtitle::putTimeRow(const std::string &timeRow) {
    std::istringstream is(timeRow);
    std::string begin, del, end;
    std::getline(is, begin, ' ');
    std::getline(is, del, ' ');
    std::getline(is, end, '\0');

    if (strcmp(del.c_str(), "-->")) {
        throw WrongInput("Subtitle time row has wrong format");
    }

    Time validator, validator2;

    std::istringstream tmp(begin);
    tmp >> validator;


    std::istringstream tmp2(end);
    tmp2 >> validator2;


    if (!(validator < validator2)) {
        throw WrongInput("Subtitle begin time is not less than end time");
    }

    std::istringstream tmp3(validator.getTime());
    tmp3 >> beginTime;
    std::istringstream tmp4(validator2.getTime());
    tmp4 >> endTime;

}

std::string Subtitle::getTextRow(int index) const {
    std::istringstream is(subtitleText);
    std::string s;
    int count = 0;
    while (std::getline(is, s, '\n')) {
        if (count == index) {
            return s;
        }
        count++;
    }

    return "";
};

std::string Subtitle::getSubtitle() const {
    return std::to_string(number) + '\n' + getBeginTime() + " --> " + getEndTime() + "\n" + subtitleText;
}
