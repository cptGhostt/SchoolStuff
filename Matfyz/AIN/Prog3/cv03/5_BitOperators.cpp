#include "5_BitOperators.h"

//5. uloha
std::string binaryAND(const char number1[], const char number2[]) {
    if (typeOfNumber(number1) != BINARY_INT || typeOfNumber(number2) != BINARY_INT) {
        return "Wrong binary number";
    }

    int size1 = 0, size2 = 0;
    std::string finalString = "";
    while (number1[size1] != '\0') {
        size1++;
    }
    while (number2[size2] != '\0') {
        size2++;
    }

    if (size1 < size2) {
        for (int i = size1-2; i > 0; i--) {
            if (number1[size1 - 1] == '1' && number2[size2 - 1] == '1') {
                finalString = '1' +finalString;
            } else {
                finalString = '0' +finalString;
            }
            size1--;
            size2--;
        }
    } else {
        for (int i = size2-2; i > 0; i--) {
            if (number1[size1 - 1] == '1' && number2[size2 - 1] == '1') {
                finalString = '1' +finalString;
            } else {
                finalString = '0' +finalString;
            }
            size1--;
            size2--;
        }
    }

    return "0b" + finalString;
}

std::string binaryOR(const char number1[], const char number2[]) {
    if (typeOfNumber(number1) != BINARY_INT || typeOfNumber(number2) != BINARY_INT) {
        return "Wrong binary number";
    }

    int size1 = 0, size2 = 0;
    std::string finalString = "";
    while (number1[size1] != '\0') {
        size1++;
    }
    while (number2[size2] != '\0') {
        size2++;
    }

    if (size1 < size2) {
        for (int i = size1-2; i > 0; i--) {
            if (number1[size1 - 1] == '1' || number2[size2 - 1] == '1') {
                finalString = '1' +finalString;
            } else {
                finalString = '0' +finalString;
            }
            size1--;
            size2--;
        }
        for (int i = size2-2; i > 0; i--) {
            finalString = number2[size2 - 1] + finalString;
            size2--;
        }
    } else {
        for (int i = size2-2; i > 0; i--) {
            if (number1[size1 - 1] == '1' || number2[size2 - 1] == '1') {
                finalString = '1' +finalString;
            } else {
                finalString = '0' +finalString;
            }
            size1--;
            size2--;
        }
        for (int i = size1-2; i > 0; i--) {
            finalString = number1[size1 - 1] + finalString;
            size1--;
        }
    }

    return "0b" + finalString;
}

std::string binaryNegation(const char number[]) {
    if (typeOfNumber(number) != BINARY_INT) {
        return "Wrong binary number";
    }

    auto negation = [] (char digit) {return digit == '1' ? '0' : '1';};
    std::string finalString = "";
    int i = 2;
    while (number[i] != '\0') {
        finalString += negation(number[i]);
        i++;
    }


    return "0b" + finalString;
}

std::string binaryRightShift(const char number[], size_t shift0) {
    if (typeOfNumber(number) != BINARY_INT) {
        return "Wrong binary number";
    }

    auto rightShift = [] (const char number[], size_t shift0) {
        int size = 0;
        std::string finalString = "";
        while (number[size] != '\0') {
            finalString += number[size];
            size++;
        }
        for (int i = shift0; i > 0; i--) {
            for (int j = size; j > 2; j--) {
                finalString[j-1] = finalString[j-2];
            }
            finalString[2] = '0';
        }

        return finalString;
    };

    return rightShift(number, shift0);
}
