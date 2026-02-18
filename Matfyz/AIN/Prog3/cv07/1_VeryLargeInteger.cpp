#include <iostream>

#include "1_VeryLargeInteger.h"

const char VeryLargeInteger::NO_NUMBER[] = "No number";

//1.uloha
VeryLargeInteger::VeryLargeInteger(): number(NO_NUMBER) {}

VeryLargeInteger::VeryLargeInteger(const char input[]) {
    put(input);
}

VeryLargeInteger::VeryLargeInteger(long long inputNumber) {
    number = std::to_string(inputNumber);
}

bool VeryLargeInteger::isEmpty() const {
    return number == NO_NUMBER;
}

bool VeryLargeInteger::put(const char input[]) {
    std::string tmp0;

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            continue;
        }
        tmp0 += input[i];
    }

    if (tmp0 == "-") {
        return false;
    }

    std::string tmp;
    bool sign = false, isZero = true;

    for(int i = 0; i < strlen(tmp0.c_str()); i++) {
        if(i == 0 && tmp0[i] == '-') {
            sign = true;
            continue;
        }
        if(tmp0[i] >= '0' && tmp0[i] <= '9') {
            tmp += tmp0[i];
            continue;
        }
        number = NO_NUMBER;
        return false;
    }

    for(int i = 0; i < strlen(tmp.c_str()); i++) {
        if(tmp[i] != '0') {
            isZero = false;
            break;
        }
    }

    if (isZero) {
        number = "0";
        return true;
    }

    std::string tmp2;
    bool zero = true;
    for (int i = 0; i < strlen(tmp.c_str()); i++) {
        if(tmp[i] == '0' && zero) {
            continue;
        }
        zero = false;
        tmp2 += tmp[i];
    }


    if(sign) {
        number = "-";
        number += tmp2;
    }else {
        number = tmp2;
    }

    return true;
}

