#pragma once

#include "1_VeryLargeInteger.h"

//4.uloha
VeryLargeInteger operator+(const VeryLargeInteger &inputNumber1, const VeryLargeInteger &inputNumber2);
VeryLargeInteger operator-(const VeryLargeInteger &inputNumber1, const VeryLargeInteger &inputNumber2);

VeryLargeInteger calculate(
    VeryLargeInteger (*calculateFuncion)(const VeryLargeInteger &, const VeryLargeInteger &),
        const VeryLargeInteger &inputNumber1, const VeryLargeInteger &inputNumber2);
