#pragma once

#include <stdlib.h>
#include "1_Element.h"
#include "2_Date.h"

//2. uloha
std::string subString(const std::string &text, int element, char del);

class IdentificationNumber : public Element {
    Date date;
 public:
    ElementStatus put(const std::string &identificationNumber) override;
    Date getDate() const;
};
