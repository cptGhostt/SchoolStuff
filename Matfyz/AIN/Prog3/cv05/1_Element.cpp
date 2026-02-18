#include "1_Element.h"


//1. uloha
ElementStatus Element::put(const std::string &element0) {
    if (element0.empty()) {
        status = EMPTY_ELEMENT;
        return status;
    }

    int i = 0, j = element0.length();

    while (i < j && element0[i] == ' ') {
        i++;
    }

    while (j >= i && element0[j-1] == ' ') {
        j--;
    }

    std::string tmp;
    if (i == 0 && j == element0.length()) {
        tmp = element0;
    } else {
        tmp = element0.substr(i, j-i);
    }
    if (tmp.empty()) {
        status = EMPTY_ELEMENT;
        return status;
    }

    element = tmp;
    status = OK;
    return status;
}

std::string Element::get() const {
    return this->element;
}

