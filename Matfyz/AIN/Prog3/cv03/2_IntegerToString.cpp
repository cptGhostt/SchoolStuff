#include "2_IntegerToString.h"

//2. uloha
std::string integerIntoDecimalString(int number) {
    if (number == 0) {
        return "0";
    }

    std::string finalString;
    char tmpChar;
    int remain;
    bool minus = false;
    if (number < 0) {
        number *= -1;
        minus = true;
    }

    while (number != 0) {
        remain = number % 10;
        number /= 10;
        tmpChar = '0' + remain;
        finalString =  tmpChar + finalString;
    }

    if (minus == true) {
        finalString = "-" + finalString;
    }

    return finalString;
}

std::string integerIntoNumberTypeString(int number, NumberType type) {
    if (type == DECIMAL_INT) {
        return integerIntoDecimalString(number);
    }

    std::string finalString;
    char tmpChar;
    int remain;
    bool minus = false;
    if (number < 0) {
        number *= -1;
        minus = true;
    }

    if (type == BINARY_INT) {
        while (number != 0) {
            remain = number % 2;
            number /= 2;
            tmpChar = '0' + remain;
            finalString =  tmpChar + finalString;
        }

        finalString = "0b" + finalString;

        if (minus == true) {
            finalString = "-" + finalString;
        }

        return finalString;
    }

    if (type == OCTAL_INT) {
        while (number != 0) {
            remain = number % 8;
            number /= 8;
            tmpChar = '0' + remain;
            finalString =  tmpChar + finalString;
        }

        finalString = "0" + finalString;

        if (minus == true) {
            finalString = "-" + finalString;
        }

        return finalString;
    }

    if (type == HEXADECIMAL_INT) {
        while (number != 0) {
            remain = number % 16;
            number /= 16;
            if (remain < 10) {
                tmpChar = '0' + remain;
            } else {
                tmpChar = 'a' + remain - 10;
            }
            finalString =  tmpChar + finalString;
        }

        finalString = "0x" + finalString;

        if (minus == true) {
            finalString = "-" + finalString;
        }

        return finalString;
    }


    if (type == WRONG_INTEGER) {
        return "Wrong integer type";
    }

    return "Out of limit";
}