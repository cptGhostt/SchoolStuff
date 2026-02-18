#pragma once

#include <iostream>
#include "3_Person.h"

//moja
int delimiterCounter(const std::string &text, char delimeter);

//4. uloha
class Persons {
  Person *persons = nullptr;
  int maximum = 0;
  int numberOfRecs = 0;
  void increaseSizeOfPersons(int numberOfNewPersons);
 public:
  bool append(const std::string &list);
  std::string get(int personNumber) const;
  Person getPerson(int personNumber) const;
  inline int numberOfRecords() const { return numberOfRecs; };
  ~Persons() { if (persons != nullptr) delete [] persons; };
};
