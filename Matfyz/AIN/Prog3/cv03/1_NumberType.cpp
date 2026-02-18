#include "1_NumberType.h"

//1. uloha
NumberType typeOfNumber(const char number[]) {
    if (number[0] == '\0') {
        return WRONG_INTEGER;
    }

    int counter;
    number[0] == '-' ? counter = 1 : counter = 0;

    if (number[counter] == '0' && number[counter + 1] == '\0') {
        return DECIMAL_INT;
    }

    if (number[counter] == '0' && number[counter + 1] == 'b') {
        counter += 2;
        if (number[counter] == '\0') {
            return WRONG_INTEGER;
        }

        while (number[counter] != '\0') {
            if (number[counter] == '0' || number[counter] == '1' || number[counter] == '\'') {
                counter++;
                continue;
            }
            return WRONG_INTEGER;
        }
        return BINARY_INT;
    }

    if (number[counter] == '0' && number[counter + 1] == 'x') {
        counter += 2;
        if (number[counter] == '\0') {
            return WRONG_INTEGER;
        }

        while (number[counter] != '\0') {
            if ((number[counter] >= '0' && number[counter] <= '9')
                || (number[counter] >= 'a' && number[counter] <= 'f')
                || (number[counter] >= 'A' && number[counter] <= 'F')
                || number[counter] == '\'') {
                counter++;
                continue;
            }
            return WRONG_INTEGER;
        }
        return HEXADECIMAL_INT;
    }

    if (number[counter] == '0') {
        counter++;
        while (number[counter] != '\0') {
            if ((number[counter] >= '0' && number[counter] <= '7') || number[counter] == '\'') {
                counter++;
                continue;
            }
            return WRONG_INTEGER;
        }
        return OCTAL_INT;
    }

    while (number[counter] != '\0') {
        if ((number[counter] >= '0' && number[counter] <= '9') || number[counter] == '\'') {
            counter++;
            continue;
        }
        return WRONG_INTEGER;
    }

    return DECIMAL_INT;
}