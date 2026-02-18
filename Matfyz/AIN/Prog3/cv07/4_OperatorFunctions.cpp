#include "4_OperatorFunctions.h"

//4.uloha
VeryLargeInteger operator+(const VeryLargeInteger &inputNumber1, const VeryLargeInteger &inputNumber2) {
    if (inputNumber1.isEmpty() && inputNumber2.isEmpty()) {
        return VeryLargeInteger();
    }
    if (inputNumber1.isEmpty()) {
        return inputNumber2;
    }
    if (inputNumber2.isEmpty()) {
        return inputNumber1;
    }

    std::string no1 = inputNumber1.get();
    std::string no2 = inputNumber2.get();
    std::string result = "";

    // ++
    if (!inputNumber1.negativeNumber() && !inputNumber2.negativeNumber()) {
        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        int i = no1.length() - 1;
        int tmp = 0;

        for (; i >= 0; i--) {
            tmp += (no1[i] - '0') + (no2[i] - '0');
            result = std::to_string((tmp % 10)) + result;
            tmp /= 10;
        }
        if (tmp > 0) {
            result = std::to_string((tmp % 10)) + result;
        }
    }

    // --
    else if (inputNumber1.negativeNumber() && inputNumber2.negativeNumber()) {
        no1[0] = '0';
        no2[0] = '0';

        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        int i = no1.length() - 1;
        int tmp = 0;

        for (; i >= 0; i--) {
            tmp += (no1[i] - '0') + (no2[i] - '0');
            result = std::to_string((tmp % 10)) + result;
            tmp /= 10;
        }
        if (tmp > 0) {
            result = std::to_string((tmp % 10)) + result;
        }

        result = '-' + result;
    }

    //+-
    else if (!inputNumber1.negativeNumber() && inputNumber2.negativeNumber()) {
        no2[0] = '0';
        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        bool isNegative = false;
        if (no2 > no1) {
            isNegative = true;
        }

        int i = no1.length() - 1;
        int tmp = 0;
        bool overflow = false;

        if (isNegative) {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no2[i] - '0') - (no1[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no2[i] - '0') - (no1[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        } else {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no1[i] - '0') - (no2[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no1[i] - '0') - (no2[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        }

        if (isNegative) {
            result = '-' + result;
        }
    }

    //-+
    else {
        no1[0] = '0';
        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        bool isNegative = false;
        if (no2 < no1) {
            isNegative = true;
        }

        int i = no1.length() - 1;
        int tmp = 0;
        bool overflow = false;

        if (!isNegative) {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no2[i] - '0') - (no1[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no2[i] - '0') - (no1[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        } else {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no1[i] - '0') - (no2[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no1[i] - '0') - (no2[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        }

        if (isNegative) {
            result = '-' + result;
        }
    }

    return VeryLargeInteger(result.c_str());
}

VeryLargeInteger operator-(const VeryLargeInteger &inputNumber1, const VeryLargeInteger &inputNumber2) {
    if (inputNumber1.isEmpty() && inputNumber2.isEmpty()) {
        return VeryLargeInteger();
    }
    if (inputNumber1.isEmpty()) {
        VeryLargeInteger tmp = inputNumber2;
        tmp.changeNumberSign();
        return tmp;
    }
    if (inputNumber2.isEmpty()) {
        return inputNumber1;
    }

    std::string no1 = inputNumber1.get();
    std::string no2 = inputNumber2.get();
    std::string result = "";

    //++
    if (!inputNumber1.negativeNumber() && !inputNumber2.negativeNumber()) {
        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        bool isNegative = false;
        if (no2 > no1) {
            isNegative = true;
        }

        int i = no1.length() - 1;
        int tmp = 0;
        bool overflow = false;

        if (isNegative) {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no2[i] - '0') - (no1[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no2[i] - '0') - (no1[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        } else {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no1[i] - '0') - (no2[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no1[i] - '0') - (no2[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        }

        if (isNegative) {
            result = '-' + result;
        }
    }

    //--
    else if (inputNumber1.negativeNumber() && inputNumber2.negativeNumber()) {
        no1[0] = '0';
        no2[0] = '0';
        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        bool isNegative = false;
        if (no2 < no1) {
            isNegative = true;
        }

        int i = no1.length() - 1;
        int tmp = 0;
        bool overflow = false;

        if (!isNegative) {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no2[i] - '0') - (no1[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no2[i] - '0') - (no1[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        } else {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no1[i] - '0') - (no2[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no1[i] - '0') - (no2[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        }

        if (isNegative) {
            result = '-' + result;
        }
    }

    //+-
    else if (!inputNumber1.negativeNumber() && inputNumber2.negativeNumber()) {
        no2[0] = '0';
        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        int i = no1.length() - 1;
        int tmp = 0;

        for (; i >= 0; i--) {
            tmp += (no1[i] - '0') + (no2[i] - '0');
            result = std::to_string((tmp % 10)) + result;
            tmp /= 10;
        }
        if (tmp > 0) {
            result = std::to_string((tmp % 10)) + result;
        }
    }

    //-+
    else {
        no1[0] = '0';
        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        int i = no1.length() - 1;
        int tmp = 0;

        for (; i >= 0; i--) {
            tmp += (no1[i] - '0') + (no2[i] - '0');
            result = std::to_string((tmp % 10)) + result;
            tmp /= 10;
        }
        if (tmp > 0) {
            result = std::to_string((tmp % 10)) + result;
        }

        result = '-' + result;
    }

    return VeryLargeInteger(result.c_str());
}

void VeryLargeInteger::operator+=(const VeryLargeInteger &inputNumber) {
    std::string no1 = number;
    std::string no2 = inputNumber.get();
    std::string result = "";

    // ++
    if (!this->negativeNumber() && !inputNumber.negativeNumber()) {
        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        int i = no1.length() - 1;
        int tmp = 0;

        for (; i >= 0; i--) {
            tmp += (no1[i] - '0') + (no2[i] - '0');
            result = std::to_string((tmp % 10)) + result;
            tmp /= 10;
        }
        if (tmp > 0) {
            result = std::to_string((tmp % 10)) + result;
        }
    }

    // --
    else if (this->negativeNumber() && inputNumber.negativeNumber()) {
        no1[0] = '0';
        no2[0] = '0';

        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        int i = no1.length() - 1;
        int tmp = 0;

        for (; i >= 0; i--) {
            tmp += (no1[i] - '0') + (no2[i] - '0');
            result = std::to_string((tmp % 10)) + result;
            tmp /= 10;
        }
        if (tmp > 0) {
            result = std::to_string((tmp % 10)) + result;
        }

        result = '-' + result;
    }

    //+-
    else if (!this->negativeNumber() && inputNumber.negativeNumber()) {
        no2[0] = '0';
        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        bool isNegative = false;
        if (no2 > no1) {
            isNegative = true;
        }

        int i = no1.length() - 1;
        int tmp = 0;
        bool overflow = false;

        if (isNegative) {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no2[i] - '0') - (no1[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no2[i] - '0') - (no1[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        } else {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no1[i] - '0') - (no2[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no1[i] - '0') - (no2[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        }

        if (isNegative) {
            result = '-' + result;
        }
    }

    //-+
    else {
        no1[0] = '0';
        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        bool isNegative = false;
        if (no2 < no1) {
            isNegative = true;
        }

        int i = no1.length() - 1;
        int tmp = 0;
        bool overflow = false;

        if (!isNegative) {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no2[i] - '0') - (no1[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no2[i] - '0') - (no1[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        } else {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no1[i] - '0') - (no2[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no1[i] - '0') - (no2[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        }

        if (isNegative) {
            result = '-' + result;
        }
    }
    this->put(result.c_str());
}

void VeryLargeInteger::operator-=(const VeryLargeInteger &inputNumber) {
    std::string no1 = number;
    std::string no2 = inputNumber.get();
    std::string result = "";

    //++
    if (!this->negativeNumber() && !inputNumber.negativeNumber()) {
        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        bool isNegative = false;
        if (no2 > no1) {
            isNegative = true;
        }

        int i = no1.length() - 1;
        int tmp = 0;
        bool overflow = false;

        if (isNegative) {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no2[i] - '0') - (no1[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no2[i] - '0') - (no1[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        } else {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no1[i] - '0') - (no2[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no1[i] - '0') - (no2[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        }

        if (isNegative) {
            result = '-' + result;
        }
    }

    //--
    else if (this->negativeNumber() && inputNumber.negativeNumber()) {
        no1[0] = '0';
        no2[0] = '0';
        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        bool isNegative = false;
        if (no2 < no1) {
            isNegative = true;
        }

        int i = no1.length() - 1;
        int tmp = 0;
        bool overflow = false;

        if (!isNegative) {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no2[i] - '0') - (no1[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no2[i] - '0') - (no1[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        } else {
            for (; i >= 0; i--) {
                if (overflow) {
                    tmp += (no1[i] - '0') - (no2[i] - '0') - 1;
                    overflow = false;
                }else {
                    tmp += (no1[i] - '0') - (no2[i] - '0');
                }
                if (tmp < 0) {
                    overflow = true;
                    tmp += 10;
                }
                result = std::to_string((tmp % 10)) + result;
                tmp = 0;
            }
        }

        if (isNegative) {
            result = '-' + result;
        }
    }

    //+-
    else if (!this->negativeNumber() && inputNumber.negativeNumber()) {
        no2[0] = '0';
        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        int i = no1.length() - 1;
        int tmp = 0;

        for (; i >= 0; i--) {
            tmp += (no1[i] - '0') + (no2[i] - '0');
            result = std::to_string((tmp % 10)) + result;
            tmp /= 10;
        }
        if (tmp > 0) {
            result = std::to_string((tmp % 10)) + result;
        }
    }

    //-+
    else {
        no1[0] = '0';
        while (no1.length() < no2.length()) {
            no1 = '0' + no1;
        }
        while (no2.length() < no1.length()) {
            no2 = '0' + no2;
        }
        int i = no1.length() - 1;
        int tmp = 0;

        for (; i >= 0; i--) {
            tmp += (no1[i] - '0') + (no2[i] - '0');
            result = std::to_string((tmp % 10)) + result;
            tmp /= 10;
        }
        if (tmp > 0) {
            result = std::to_string((tmp % 10)) + result;
        }

        result = '-' + result;
    }
    this->put(result.c_str());
}

VeryLargeInteger calculate(VeryLargeInteger (*calculateFuncion)(const VeryLargeInteger &, const VeryLargeInteger &),
                           const VeryLargeInteger &inputNumber1, const VeryLargeInteger &inputNumber2) {
    return calculateFuncion(inputNumber1, inputNumber2);
}
