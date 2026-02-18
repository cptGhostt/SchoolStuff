#include "3_passwordStrength.h"

#include <string.h>

//3. uloha
PasswordStrength passwordStrength(const char password[]) {
    if (strlen(password) == 0 || strlen(password) == numberOfCharactersOfCertainType(password, SPACE)) {
        return EMPTY_PASSWORD;
    }

    if (containsNotAllowedCharacter(password)) {
        return NOT_ALLOWED_PASSWORD;
    }

    if (strlen(password) < 8) {
        if (strlen(password) == numberOfCharactersOfCertainType(password, DIGIT)
            || strlen(password) == numberOfCharactersOfCertainType(password, SMALL_LETTER)
            + numberOfCharactersOfCertainType(password, CAPITAL_LETTER)) {
            return VERY_WEAK_PASSWORD;
        }
        return WEAK_PASSWORD;
    }

    if (strlen(password) == numberOfCharactersOfCertainType(password, DIGIT)
        || strlen(password) == numberOfCharactersOfCertainType(password, SMALL_LETTER)
        + numberOfCharactersOfCertainType(password, CAPITAL_LETTER)) {
        return WEAK_PASSWORD;
    }

    if (containsOnlyAlphanumericCharacters(password)) {
        return STRONG_PASSWORD;
    }

    if (numberOfCharactersOfCertainType(password, DIGIT) > 0
        && numberOfCharactersOfCertainType(password, SMALL_LETTER) > 0
        && numberOfCharactersOfCertainType(password, CAPITAL_LETTER) > 0
        && (numberOfCharactersOfCertainType(password, SPACE) > 0
            || numberOfCharactersOfCertainType(password, OTHER) > 0)) {
        return VERY_STRONG_PASSWORD;
    }

    return STRONG_PASSWORD;
}


