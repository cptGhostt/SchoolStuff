#pragma once

#include <iostream>
#include "4_Persons.h"

//5. uloha
class SelectPersons {
 public:
  int numberOfPersonsForCriteria(Persons &listOfPersons, const std::string &criteria) const;
};
