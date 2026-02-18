#include <iostream>

#include "2_Date.h"

//2. uloha
ElementStatus Date::put(int d, int m, int y) {
    if (m < 1 || m > 12) {
        return WRONG_DATE;
    }

    if (d < 0 ) {
        return WRONG_DATE;
    }

    if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 31) {
        return WRONG_DATE;
    }

    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
        return WRONG_DATE;
    }

    if ((m == 2 && y % 4 == 0 and d > 29) ||(m == 2 && y % 4 != 0 && d > 28)) {
        return WRONG_DATE;
    }

    day = d;
    month = m;
    year = y;
    return OK;
}

std::string Date::date(DateFormat dateFormat) const {
    std::string tmp = "";
    if (dateFormat == EU_FORMAT) {
        return tmp + std::to_string(day) + '.' + std::to_string(month) + '.' + std::to_string(year);
    }
     return tmp + std::to_string(month) + '/' + std::to_string(day) + '/' + std::to_string(year);
}
