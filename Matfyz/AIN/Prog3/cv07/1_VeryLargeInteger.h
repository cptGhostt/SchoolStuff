#pragma once

#include <iostream>
#include <cstring>

//1.uloha
class VeryLargeInteger {
    std::string number;
    static const char NO_NUMBER[];
 public:
    VeryLargeInteger();
    VeryLargeInteger(const char input[]);
    VeryLargeInteger(long long inputNumber);
    bool put(const char input[]);
    bool isEmpty() const;
    inline std::string get() const { return number; };

  //2.uloha
  VeryLargeInteger(const VeryLargeInteger &inputNumber);
  VeryLargeInteger(VeryLargeInteger &&inputNumber);
  VeryLargeInteger &operator=(const VeryLargeInteger &inputNumber);
  VeryLargeInteger &operator=(VeryLargeInteger &&inputNumber);
  VeryLargeInteger &operator=(const char input[]);
  VeryLargeInteger &operator=(std::string &&inputNumber);

  //3.uloha
  bool negativeNumber() const;
  void changeNumberSign();
  bool operator==(const VeryLargeInteger &inputNumber) const;
  bool operator==(const char input[]) const;
  bool operator<(const VeryLargeInteger &inputNumber) const;
  bool operator>(const VeryLargeInteger &inputNumber) const;
  bool operator<=(const VeryLargeInteger &inputNumber) const;
  bool operator>=(const VeryLargeInteger &inputNumber) const;

//4.uloha
  void operator +=(const VeryLargeInteger &inputNumber);
  void operator -=(const VeryLargeInteger &inputNumber);

  //pomocna
  int numberOfDigits() const { return number.size(); };
};

const std::string DUMMY_STRING {""};
const int DUMMY_INT = -999;
const bool DUMMY_BOOL = false;

