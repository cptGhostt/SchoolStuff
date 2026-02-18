#pragma once

#include "1_characterType.h"

//2. uloha
int numberOfAllCharacters(const char characters[]);
int numberOfCharactersOfCertainType(const char characters[], CharacterType type);
int numberOfAlphanumericCharacters(const char characters[]);
bool containsNotAllowedCharacter(const char characters[]);
bool containsOnlyAlphanumericCharacters(const char characters[]);
