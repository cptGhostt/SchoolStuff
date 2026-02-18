#pragma once

#include <cstring> /* strcmp */

//moje
bool isDelimiter(char d);

const char EMPTY_WORD[] { '\0' };
const double EMPTY_DOUBLE { 0.0 };
const int NOT_FOUND { -1 };

//1. uloha
int numberOChars(char const *text, const char character);
int numberOfWords(const char *text);
int findNumber(const double data[], size_t size, double number);
const double *findMaximum(const double data[], size_t size);

const int DUMMY_INT {-1};
const char DUMMY_CHAR_ARRAY[] {'\0' };
const double DUMMY_DOUBLE { 0.0 };
const double DUMMY_DOUBLE_ARRAY[] { -1.1 };

