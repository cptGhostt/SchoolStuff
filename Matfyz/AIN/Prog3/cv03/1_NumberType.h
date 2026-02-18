#pragma once

#include <string>

enum NumberType {DECIMAL_INT,
                 OCTAL_INT,
                 HEXADECIMAL_INT,
                 BINARY_INT,
                 WRONG_INTEGER = -1,
                 OUT_OF_LIMIT = -2
};

//1. uloha
//fg bool allCharsFromInterval(const std::string &numberString, char begin, char end);
NumberType typeOfNumber(const char number[]);

const NumberType DUMMY_NUMBER_TYPE = DECIMAL_INT;
const int DUMMY_INT = -1;
const char DUMMY_CHAR = 'X';
const bool DUMMY_BOOL = false;
const std::string DUMMY_STRING {};

