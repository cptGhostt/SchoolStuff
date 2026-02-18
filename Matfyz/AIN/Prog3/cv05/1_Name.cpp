#include <iostream>
#include <math.h>

#include "1_Name.h"

//1. uloha
ElementStatus Name::put(const std::string &name) {
    if (name.empty()) {
        setStatus(EMPTY_ELEMENT);
        return getStatus();
    }

    int i = 0, j = name.length();

    while (i < j && name[i] == ' ') {
        i++;
    }

    while (j >= i && name[j - 1] == ' ') {
        j--;
    }

    std::string tmp;
    if (i == 0 && j == name.length()) {
        tmp = name;
    } else {
        tmp = name.substr(i, j - i);
    }
    if (tmp.empty()) {
        setStatus(EMPTY_ELEMENT);
        return getStatus();
    }

    std::string allowedChars = " -.";
    bool correct;

    for (i = 0; i < tmp.length(); i++) {
        correct = false;
        if ((tmp[i] >= 'a' && tmp[i] <= 'z') || (tmp[i] >= 'A' && tmp[i] <= 'Z')) {
            correct = true;
        } else {
            for (j = 0; j < allowedChars.length(); j++) {
                if (tmp[i] == allowedChars[j]) {
                    correct = true;
                }
            }
        }

        if (correct == false) {
            setStatus(WRONG_CHARACTERS);
            return getStatus();
        }
    }

    bool haveCapital = false;
    for (i = 0; i < tmp.length(); i++) {
        if (tmp[i] >= 'A' && tmp[i] <= 'Z') {
            haveCapital = true;
        }
    }
    if (haveCapital == false) {
        setStatus(WRONG_CHARACTERS);
        return getStatus();
    }

    return Element::put(tmp);

}
