#include "4_adaptedPasswordStrength.h"

#include <string.h>

//4. uloha
int maximumOccurrencesOfSameCharacter(const char characters[]) {
    int countsOfCharacters[255] = {0};
    int mostFrequent = 0;

    for (int i = 0; i < strlen(characters); i++) {
        countsOfCharacters[characters[i]]++;
        if (countsOfCharacters[characters[i]] > mostFrequent) {
            mostFrequent = countsOfCharacters[characters[i]];
        }
    }

    return mostFrequent;
}

PasswordStrength decreasePasswordStrength(PasswordStrength strength) {
    if (strength == WEAK_PASSWORD) {
        return VERY_WEAK_PASSWORD;
    }
    if (strength == STRONG_PASSWORD) {
        return WEAK_PASSWORD;
    }
    if (strength == VERY_STRONG_PASSWORD) {
        return STRONG_PASSWORD;
    }
    return strength;
}

PasswordStrength adaptedPasswordStrength(const char password[]) {
    PasswordStrength strength = passwordStrength(password);
    if (strlen(password) / maximumOccurrencesOfSameCharacter(password) < 2) {
        return decreasePasswordStrength(strength);
    }
    return strength;
}
