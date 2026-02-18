#pragma once

#include <iostream>

int charToInt(char c);
char intToChar(int i);

enum CharacterType {SPACE, DIGIT, CAPITAL_LETTER, SMALL_LETTER, OTHER, NOT_ALLOWED};

CharacterType typeOfCharacter(char character);

const int DUMMY_INT = 0;
const char DUMMY_CHAR = '\0';
const bool DUMMY_BOOL = false;
const CharacterType DUMMY_CHARACTER_TYPE = NOT_ALLOWED;

