#include <iostream>

#include "2_numberOfCharacters.h"

#include <cstring>

//2. uloha
int numberOfAllCharacters(const char characters[]) {
    return (std::strlen(characters));
}

int numberOfCharactersOfCertainType(const char characters[], CharacterType type) {
    int count = 0;
    for (int i = 0; i < strlen(characters); i++) {
        if (typeOfCharacter(characters[i]) == type) {
            count++;
        }
    }

    return count;
}

int numberOfAlphanumericCharacters(const char characters[]) {
    int count = 0;
    for (int i = 0; i < strlen(characters); i++) {
        if (typeOfCharacter(characters[i]) == 1
            || typeOfCharacter(characters[i]) == 2
            || typeOfCharacter(characters[i]) == 3) {
            count++;
        }
    }
    return count;
}

bool containsNotAllowedCharacter(const char characters[]) {
    for (int i = 0; i < strlen(characters); i++) {
        if (typeOfCharacter(characters[i]) == 5){
            return true;
        }
    }

    return false;
}

bool containsOnlyAlphanumericCharacters(const char characters[]) {
    for (int i = 0; i < strlen(characters); i++) {
        if (typeOfCharacter(characters[i]) == 0
            || typeOfCharacter(characters[i]) == 4
            || typeOfCharacter(characters[i]) == 5) {
            return false;
        }
    }

    return true;
}
