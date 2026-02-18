#include <iostream>
#include "isDecimalNumber.h"

#include <cstring>

#define DUMMY_BOOL false

//2. a 4. uloha
bool isDecimalNumber(const char number[]) {
    if (std::strlen(number) == 0) return false;

    unsigned int i = 0;
    bool sign = false;
    bool divider = false;
    while (number[i] != '\0') {
        if (number[i] == '0') {
            i++;
            continue;
        }
        else if (number[i] == '1') {
            i++;
            continue;
        }
        else if (number[i] == '2') {
            i++;
            continue;
        }
        else if (number[i] == '3') {
            i++;
            continue;
        }
        else if (number[i] == '4') {
            i++;
            continue;
        }
        else if (number[i] == '5') {
            i++;
            continue;
        }
        else if (number[i] == '6') {
            i++;
            continue;
        }
        else if (number[i] == '7') {
            i++;
            continue;
        }
        else if (number[i] == '8') {
            i++;
            continue;
        }
        else if (number[i] == '9') {
            i++;
            continue;
        }
        else if (number[i] == '0') {
            i++;
            continue;
        }
        else if (number[i] == '-') {
            if (sign) {
                return false;
            }

            if (number[i+1] == '.' || number[i+1] == ',' || number[i+1] == '\0') return false;

            i++;
            sign = true;
            continue;
        }
        else if (number[i] == '.') {
            if (divider) {
                return false;
            }

            if (number[i+1] == '\0') return false;

            divider = true;
            i++;
            continue;
        }
        else if (number[i] == ',') {
            if (divider) {
                return false;
            }

            if (number[i+1] == '\0') return false;

            divider = true;
            i++;
            continue;
        }
        return false;
    }
    return divider;

}


