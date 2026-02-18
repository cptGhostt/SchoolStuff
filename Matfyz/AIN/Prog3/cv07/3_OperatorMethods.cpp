#include "1_VeryLargeInteger.h"

//3.uloha
bool VeryLargeInteger::negativeNumber() const {
    return number[0] == '-';
}

void VeryLargeInteger::changeNumberSign() {
    if (number == "0") {
        return;
    }
    if (number[0] == '-') {
        number = number.substr(1, number.size() - 1);
        return;
    }

    number = '-' + number;
}

bool VeryLargeInteger::operator==(const VeryLargeInteger &inputNumber) const {
    return !strcmp(number.c_str(), inputNumber.number.c_str());
}

bool VeryLargeInteger::operator==(const char input[]) const {
    std::string tmp = VeryLargeInteger(input).get();
    return !strcmp(number.c_str(), tmp.c_str());
}

bool VeryLargeInteger::operator<(const VeryLargeInteger &inputNumber) const {
    if (number == NO_NUMBER || inputNumber.get() == NO_NUMBER) {
        return false;
    }

    if (this->negativeNumber() && !inputNumber.negativeNumber()) {
        return true;
    }
    if (!this->negativeNumber() && inputNumber.negativeNumber()) {
        return false;
    }
    if (!this->negativeNumber() && !inputNumber.negativeNumber()) {
        std::string tmp1 = number;
        std::string tmp2 = inputNumber.get();

        while (tmp1.length() < tmp2.length()) {
            tmp1 = "0" + tmp1;
        }
        while (tmp2.length() < tmp1.length()) {
            tmp2 = "0" + tmp2;
        }
        return tmp1.compare(tmp2) < 0;
    }
    std::string tmp1 = number;
    std::string tmp2 = inputNumber.get();
    tmp1 = tmp1.substr(1, tmp1.length() - 1);
    tmp2 = tmp2.substr(1, tmp2.length() - 1);

    while (tmp1.length() < tmp2.length()) {
        tmp1 = "0" + tmp1;
    }
    while (tmp2.length() < tmp1.length()) {
        tmp2 = "0" + tmp2;
    }
    return tmp1.compare(tmp2) > 0;
}

bool VeryLargeInteger::operator>(const VeryLargeInteger &inputNumber) const {
    if (number == NO_NUMBER || inputNumber.get() == NO_NUMBER) {
        return false;
    }

    if (this->negativeNumber() && !inputNumber.negativeNumber()) {
        return false;
    }
    if (!this->negativeNumber() && inputNumber.negativeNumber()) {
        return true;
    }
    if (!this->negativeNumber() && !inputNumber.negativeNumber()) {
        std::string tmp1 = number;
        std::string tmp2 = inputNumber.get();

        while (tmp1.length() < tmp2.length()) {
            tmp1 = "0" + tmp1;
        }
        while (tmp2.length() < tmp1.length()) {
            tmp2 = "0" + tmp2;
        }
        return tmp1.compare(tmp2) > 0;
    }
    std::string tmp1 = number;
    std::string tmp2 = inputNumber.get();
    tmp1 = tmp1.substr(1, tmp1.length() - 1);
    tmp2 = tmp2.substr(1, tmp2.length() - 1);

    while (tmp1.length() < tmp2.length()) {
        tmp1 = "0" + tmp1;
    }
    while (tmp2.length() < tmp1.length()) {
        tmp2 = "0" + tmp2;
    }
    return tmp1.compare(tmp2) < 0;
}

bool VeryLargeInteger::operator<=(const VeryLargeInteger &inputNumber) const {
    if (number == NO_NUMBER && inputNumber.get() == NO_NUMBER) {
        return true;
    }

    if (number == NO_NUMBER || inputNumber.get() == NO_NUMBER) {
        return false;
    }

    if (this->negativeNumber() && !inputNumber.negativeNumber()) {
        return true;
    }
    if (!this->negativeNumber() && inputNumber.negativeNumber()) {
        return false;
    }
    if (!this->negativeNumber() && !inputNumber.negativeNumber()) {
        std::string tmp1 = number;
        std::string tmp2 = inputNumber.get();

        while (tmp1.length() < tmp2.length()) {
            tmp1 = "0" + tmp1;
        }
        while (tmp2.length() < tmp1.length()) {
            tmp2 = "0" + tmp2;
        }
        return tmp1.compare(tmp2) <= 0;
    }
    std::string tmp1 = number;
    std::string tmp2 = inputNumber.get();
    tmp1 = tmp1.substr(1, tmp1.length() - 1);
    tmp2 = tmp2.substr(1, tmp2.length() - 1);

    while (tmp1.length() < tmp2.length()) {
        tmp1 = "0" + tmp1;
    }
    while (tmp2.length() < tmp1.length()) {
        tmp2 = "0" + tmp2;
    }
    return tmp1.compare(tmp2) >= 0;
}

bool VeryLargeInteger::operator>=(const VeryLargeInteger &inputNumber) const {
    if (number == NO_NUMBER && inputNumber.get() == NO_NUMBER) {
        return true;
    }

    if (number == NO_NUMBER || inputNumber.get() == NO_NUMBER) {
        return false;
    }

    if (this->negativeNumber() && !inputNumber.negativeNumber()) {
        return false;
    }
    if (!this->negativeNumber() && inputNumber.negativeNumber()) {
        return true;
    }
    if (!this->negativeNumber() && !inputNumber.negativeNumber()) {
        std::string tmp1 = number;
        std::string tmp2 = inputNumber.get();

        while (tmp1.length() < tmp2.length()) {
            tmp1 = "0" + tmp1;
        }
        while (tmp2.length() < tmp1.length()) {
            tmp2 = "0" + tmp2;
        }
        return tmp1.compare(tmp2) >= 0;
    }
    std::string tmp1 = number;
    std::string tmp2 = inputNumber.get();
    tmp1 = tmp1.substr(1, tmp1.length() - 1);
    tmp2 = tmp2.substr(1, tmp2.length() - 1);

    while (tmp1.length() < tmp2.length()) {
        tmp1 = "0" + tmp1;
    }
    while (tmp2.length() < tmp1.length()) {
        tmp2 = "0" + tmp2;
    }
    return tmp1.compare(tmp2) <= 0;
}