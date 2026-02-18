#pragma once

#include "1_NumberType.h"

//2. uloha
const char charZero = '0';
const std::string wrongIntegerString = "Wrong integer type";
const std::string  outOfLimitString = "Out of limit";

std::string integerIntoDecimalString(int number);
std::string integerIntoNumberTypeString(int number, NumberType type);
