#include <iostream>

#include "3_Person.h"

//3.uloha
ElementStatus Person::put(const std::string &inputPerson) {
    if (inputPerson.empty()) {
        setStatus(EMPTY_ELEMENT);
        return getStatus();
    }

    int i = 0, j = inputPerson.length();

    while (i < j && inputPerson[i] == ' ') {
        i++;
    }

    while (j >= i && inputPerson[j - 1] == ' ') {
        j--;
    }

    std::string tmp;
    if (i == 0 && j == inputPerson.length()) {
        tmp = inputPerson;
    } else {
        tmp = inputPerson.substr(i, j - i);
    }
    if (tmp.empty()) {
        setStatus(EMPTY_ELEMENT);
        return getStatus();
    }

    std::string name = subString(tmp, 1, ',');
    std::string surname = subString(subString(tmp, 2, ','), 1, ':');
    std::string id = subString(tmp, 2, ':');
    IdentificationNumber idValidator;
    Name nameValidator;

    if (nameValidator.put(name) != OK) {
        status = nameValidator.getStatus();
        return status;
    }

    if (nameValidator.put(surname) != OK) {
        status = nameValidator.getStatus();
        return status;
    }

    if (idValidator.put(id) != OK) {
        status = idValidator.getStatus();
        return status;
    }

    firstName.put(name);
    secondName.put(surname);
    IdNumber.put(id);
    status = OK;
    element = tmp;
    return status;
}

std::string Person::get() {
    return element;
}

