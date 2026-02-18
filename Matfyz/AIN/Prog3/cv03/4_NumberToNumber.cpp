#include "4_NumberToNumber.h"

//4. uloha
std::string conversionFromOneNumberTypeIntoAnother(const char number[], NumberType newType) {
    NumberType type = isNumberStringInLimits(number);

    if (type == WRONG_INTEGER) {
        return "Wrong number";
    }

    if (type == OUT_OF_LIMIT) {
        return "Out of limit";
    }

    int numberAsInt = convertNumberStringIntoInt(number);

    return integerIntoNumberTypeString(numberAsInt, newType);
}


