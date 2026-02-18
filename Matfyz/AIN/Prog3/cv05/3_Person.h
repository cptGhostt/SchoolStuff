#pragma once

#include <iostream>
#include <stdlib.h>

#include "1_Name.h"
#include "2_IdentificationNumber.h"

//3. uloha
class Person {
    Name firstName, secondName;
    IdentificationNumber IdNumber;
    ElementStatus status = EMPTY_ELEMENT;
    std::string element;
public:
    ElementStatus put(const std::string &inputPerson);

    std::string get();

    inline std::string getFirstName() const { return firstName.get(); };
    inline std::string getSecondName() const { return secondName.get(); };
    inline const Date getDate() const { return IdNumber.getDate(); };
    inline int getDay() const { return IdNumber.getDate().day; };
    inline int getMonth() const { return IdNumber.getDate().month; };
    inline int getYear() const { return IdNumber.getDate().year; };
    inline void setStatus(const ElementStatus status0) { status = status0; };
    inline ElementStatus getStatus() const { return status; };
};
