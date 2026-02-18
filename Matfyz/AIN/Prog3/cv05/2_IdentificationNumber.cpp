#include <iostream>

#include "2_IdentificationNumber.h"

//2. uloha
std::string subString(const std::string &text, int elementNumber, char del) {
    if (elementNumber < 1) {
        return "";
    }

    int counter = 1;
    std::string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == del) {
            counter++;
            continue;
        }
        if (counter == elementNumber) {
            result += text[i];
        }
    }

    return result;
}

ElementStatus IdentificationNumber::put(const std::string &identificationNumber) {
    if (identificationNumber.empty()) {
        setStatus(EMPTY_ELEMENT);
        return getStatus();
    }

    int i = 0, j = identificationNumber.length();

    while (i < j && identificationNumber[i] == ' ') {
        i++;
    }

    while (j >= i && identificationNumber[j - 1] == ' ') {
        j--;
    }

    std::string tmp;
    if (i == 0 && j == identificationNumber.length()) {
        tmp = identificationNumber;
    } else {
        tmp = identificationNumber.substr(i, j - i);
    }
    if (tmp.empty()) {
        setStatus(EMPTY_ELEMENT);
        return getStatus();
    }

    std::string firstPart = subString(tmp, 1, '/');
    std::string secondPart = subString(tmp, 2, '/');
    if (firstPart.length() != 6) {
        setStatus(WRONG_IDENTIFICATION_NUMBER);
        return getStatus();
    }

    if (secondPart.length() < 3 && secondPart.length() > 4) {
        setStatus(WRONG_IDENTIFICATION_NUMBER);
        return getStatus();
    }

    for (int i = 0; i < firstPart.length(); i++) {
        if (firstPart[i] < '0' || firstPart[i] > '9') {
            setStatus(WRONG_IDENTIFICATION_NUMBER);
            return getStatus();
        }
    }

    std::string dd = "";
    dd = dd + firstPart[4] + firstPart[5];
    date.day = atoi(dd.c_str());

    std::string mm = "";
    mm = mm + firstPart[2] + firstPart[3];
    if (atoi(mm.c_str()) > 12) {
        date.month = atoi(mm.c_str() - 50);
    }else {
        date.month = atoi(mm.c_str());
    }

    std::string yy = "";
    yy = yy + firstPart[0] + firstPart[1];
    if (secondPart.length() == 3) {
        date.year = atoi(yy.c_str()) + 1900;
    } else {
        if (atoi(yy.c_str()) > 53) {
            date.year = atoi(yy.c_str()) + 1900;
        }
        else {
            date.year = atoi(yy.c_str()) + 2000;
        }
    }

    Date validator;
    if (validator.put(date.day, date.month, date.year) == WRONG_DATE) {
        date.day = 0;
        date.month = 0;
        date.year = 0;
        setStatus(WRONG_DATE);
        return getStatus();
    }

    return Element::put(tmp);
};

Date IdentificationNumber::getDate() const {
    return date;
}

