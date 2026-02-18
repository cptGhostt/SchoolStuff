#pragma once

#include <stdlib.h>
#include "1_Element.h"

//moje
bool isValidDate(int day, int month, int year);

//2. uloha
enum DateFormat {EU_FORMAT, AMERICAN_FORMAT};
    //EU_FORMAT = D.M.YYYY, AMERICAN_FORMAT = M/D/YYYY

struct Date {
  int day = 0;
  int month = 0;
  int year = 0;

  ElementStatus put(int day, int month, int year);
  std::string date(DateFormat dateFormat) const;
};

const Date DUMMY_DATE;