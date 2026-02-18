#pragma once

#include "2_IntegerToString.h"

//3. uloha
const std::string MAX_VALUE_DECIMAL = "2147483647";
const std::string MAX_VALUE_OCTAL = "017777777777";
const std::string MAX_VALUE_HEXADECIMAL = "0x7fffffff";
const std::string MAX_VALUE_BINARY = "0b1111111111111111111111111111111";

NumberType isNumberStringInLimits(const char number[]);
int convertNumberStringIntoInt(const char number[]);

