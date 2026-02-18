#include "1_VeryLargeInteger.h"

//2.uloha
VeryLargeInteger::VeryLargeInteger(const VeryLargeInteger &inputNumber): number(inputNumber.number) {}

VeryLargeInteger::VeryLargeInteger(VeryLargeInteger &&inputNumber): number(std::move(inputNumber.number)) {
    inputNumber.number = NO_NUMBER;
}

VeryLargeInteger & VeryLargeInteger::operator=(const VeryLargeInteger &inputNumber) {
    if (this != &inputNumber) {
        number = inputNumber.number;
    }
    return *this;
}

VeryLargeInteger & VeryLargeInteger::operator=(VeryLargeInteger &&inputNumber) {
    if (this != &inputNumber) {
        number = std::move(inputNumber.number);
        inputNumber.number = NO_NUMBER;
    }

    return *this;
}

VeryLargeInteger & VeryLargeInteger::operator=(const char input[]) {
    this->put(input);
    return *this;
}

VeryLargeInteger & VeryLargeInteger::operator=(std::string &&input) {
    number = std::move(input);
    this->put(number.c_str());
    input = NO_NUMBER;
    return *this;
}

