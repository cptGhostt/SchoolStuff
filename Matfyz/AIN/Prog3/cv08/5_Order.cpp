#include <sstream>

#include "3_Subtitles.h"

//5.uloha
std::string Subtitles::wrongSubtitlesOrder() {
    std::string toReturn = "";
    int i = 1;

    Element *tmp = first;

    while (tmp->getNext() != nullptr) {
        if (tmp->getSubtitleNumber() > tmp->getNext()->getSubtitleNumber()) {
            if (toReturn == "") {
                toReturn += std::to_string(i) + ": " + std::to_string(tmp->getSubtitleNumber());
                toReturn += " is not less than next " + std::to_string(tmp->getNext()->getSubtitleNumber());
            } else {
                toReturn += '\n' + std::to_string(i) + ": " + std::to_string(tmp->getSubtitleNumber());
                toReturn += " is not less than next " + std::to_string(tmp->getNext()->getSubtitleNumber());
            }
        }
        tmp = tmp->getNext();
        i++;
    }

    return toReturn;
}

std::string Subtitles::wrongSubtitlesTimeOrder() {
    std::string toReturn = "";
    int i = 1;

    Element *tmp = first;

    while (tmp->getNext() != nullptr) {
        if (tmp->getNext()->getBeginTime() < tmp->getEndTime()) {
            if (toReturn == "") {
                toReturn += std::to_string(i) + ": " + tmp->getEndTime();
                toReturn += " is not less than next " + tmp->getNext()->getBeginTime();
            } else {
                toReturn += '\n' + std::to_string(i) + ": " + tmp->getEndTime();
                toReturn += " is not less than next " + tmp->getNext()->getBeginTime();
            }
        }
        tmp = tmp->getNext();
        i++;
    }

    return toReturn;
}
