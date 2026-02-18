#pragma once

#include <iostream>

//1. uloha
enum ElementStatus {OK, EMPTY_ELEMENT = -1, WRONG_CHARACTERS = -2,
                    WRONG_DATE = -3, WRONG_IDENTIFICATION_NUMBER = -4};

class Element {
  std::string element;
  ElementStatus status = EMPTY_ELEMENT;
 public:
  virtual ElementStatus put(const std::string &element0);
  virtual std::string get() const;

  inline void setStatus(const ElementStatus status0) { status = status0; };
  inline ElementStatus getStatus() const { return status; };
};

const bool DUMMY_BOOL = false;
const std::string DUMMY_STRING = "";
const int DUMMY_INT = -99;
const ElementStatus DUMMY_STATUS = EMPTY_ELEMENT;

