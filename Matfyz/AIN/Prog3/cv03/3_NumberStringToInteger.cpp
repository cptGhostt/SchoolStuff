#include "3_NumberStringToInteger.h"


//3. uloha
NumberType isNumberStringInLimits(const char number0[]) {
    NumberType type = typeOfNumber(number0);
    if (type == WRONG_INTEGER) {
        return WRONG_INTEGER;
    }

    int numberLenght = 0;
    bool minus;
    number0[0] == '-' ? minus = true : minus = false;
    while (number0[numberLenght] != '\0') {
        numberLenght++;
    }
    if (minus == true) {
        numberLenght--;
    }

    if (type == DECIMAL_INT) {
        int maxLength = 0;
        while (MAX_VALUE_DECIMAL[maxLength] != '\0') {
            maxLength++;
        }

        if (numberLenght < maxLength) {
            return type;
        }
        if (numberLenght == maxLength) {
            if (minus == true) {
                std::string negativeMaxNumber = '-' + MAX_VALUE_DECIMAL;
                for (int i = 0; i <= numberLenght; i++) {
                    if (number0[i] > negativeMaxNumber[i]) {
                        return OUT_OF_LIMIT;
                    }
                }
                return type;
            }
            for (int i = 0; i <= numberLenght; i++) {
                if (number0[i] > MAX_VALUE_DECIMAL[i]) {
                    return OUT_OF_LIMIT;
                }
            }
            return type;
        }
    }

    if (type == BINARY_INT) {
        int maxLength = 0;
        while (MAX_VALUE_BINARY[maxLength] != '\0') {
            maxLength++;
        }

        if (numberLenght < maxLength) {
            return type;
        }
        if (numberLenght == maxLength) {
            if (minus == true) {
                std::string negativeMaxNumber = '-' + MAX_VALUE_BINARY;
                for (int i = 0; i <= numberLenght; i++) {
                    if (number0[i] > negativeMaxNumber[i]) {
                        return OUT_OF_LIMIT;
                    }
                }
                return type;
            }
            for (int i = 0; i <= numberLenght; i++) {
                if (number0[i] > MAX_VALUE_BINARY[i]) {
                    return OUT_OF_LIMIT;
                }
            }
            return type;
        }
    }

    if (type == OCTAL_INT) {
        int maxLength = 0;
        while (MAX_VALUE_OCTAL[maxLength] != '\0') {
            maxLength++;
        }

        if (numberLenght < maxLength) {
            return type;
        }
        if (numberLenght == maxLength) {
            if (minus == true) {
                std::string negativeMaxNumber = '-' + MAX_VALUE_OCTAL;
                for (int i = 0; i <= numberLenght; i++) {
                    if (number0[i] > negativeMaxNumber[i]) {
                        return OUT_OF_LIMIT;
                    }
                }
                return type;
            }
            for (int i = 0; i <= numberLenght; i++) {
                if (number0[i] > MAX_VALUE_OCTAL[i]) {
                    return OUT_OF_LIMIT;
                }
            }
            return type;
        }
    }

    if (type == HEXADECIMAL_INT) {
        int maxLength = 0;
        while (MAX_VALUE_HEXADECIMAL[maxLength] != '\0') {
            maxLength++;
        }

        if (numberLenght < maxLength) {
            return type;
        }
        if (numberLenght == maxLength) {
            if (minus == true) {
                std::string negativeMaxNumber = '-' + MAX_VALUE_HEXADECIMAL;
                for (int i = 0; i <= numberLenght; i++) {
                    if (number0[i] > negativeMaxNumber[i]) {
                        return OUT_OF_LIMIT;
                    }
                }
                return type;
            }
            for (int i = 0; i <= numberLenght; i++) {
                if (number0[i] > MAX_VALUE_HEXADECIMAL[i]) {
                    return OUT_OF_LIMIT;
                }
            }
            return type;
        }
    }

    return OUT_OF_LIMIT;
}

int convertNumberStringIntoInt(const char number0[]) {
    NumberType type = isNumberStringInLimits(number0);
    if (type == WRONG_INTEGER) {
        return WRONG_INTEGER;
    }
    if (type == OUT_OF_LIMIT) {
        return OUT_OF_LIMIT;
    }

    int counter = 0, finalNumber = 0;
    bool minus = false;
    if (number0[0] == '-') {
        minus = true;
        counter = 1;
    }

    if (type == DECIMAL_INT) {
        while (number0[counter] != '\0') {
            finalNumber *= 10;
            finalNumber += number0[counter] - '0';
            counter++;
        }
    }

    if (type == BINARY_INT) {
        counter += 2;
        while (number0[counter] != '\0') {
            finalNumber *= 2;
            finalNumber += number0[counter] - '0';
            counter++;
        }
    }

    if (type == OCTAL_INT) {
        counter += 1;
        while (number0[counter] != '\0') {
            finalNumber *= 8;
            finalNumber += number0[counter] - '0';
            counter++;
        }
    }

    if (type == HEXADECIMAL_INT) {
        counter += 2;
        while (number0[counter] != '\0') {
            finalNumber *= 16;
            if (number0[counter] >= '0' && number0[counter] <= '9') {
                finalNumber += number0[counter] - '0';
            } else if (number0[counter] == 'A' || number0[counter] == 'a') {
                finalNumber += 10;
            } else if (number0[counter] == 'B' || number0[counter] == 'b') {
                finalNumber += 11;
            } else if (number0[counter] == 'C' || number0[counter] == 'c') {
                finalNumber += 12;
            } else if (number0[counter] == 'D' || number0[counter] == 'd') {
                finalNumber += 13;
            } else if (number0[counter] == 'E' || number0[counter] == 'e') {
                finalNumber += 14;
            } else if (number0[counter] == 'F' || number0[counter] == 'f') {
                finalNumber += 15;
            }
            counter++;
        }
    }

    return minus ? finalNumber * -1 : finalNumber;
}
