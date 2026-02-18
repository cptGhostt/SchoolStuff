#include "5_moreAdaptedPasswordStrength.h"

#include <string.h>

//5. uloha
int longestSequenceOfCharacters(const char input[]) {
    if (strlen(input) == 0) {
        return 0;
    }
    int longest = 0, count = 0;
    bool control = false;

    for (int i = 0; i < strlen(input)-1; i++) {
        if (control == false) {
            count = 0;
        }

        if (input[i] == input[i+1] - 1 || input[i] == input[i+1] + 1) {
            control = true;
            count++;
            if (count > longest) {
                longest = count;
            }
            continue;
        }
        control = false;
    }

    return longest == 0 ? 0 : longest + 1;
}

PasswordStrength moreAdaptedPasswordStrength(const char password[]) {
    PasswordStrength strength = passwordStrength(password);

    if (strlen(password) * 0.6 <= longestSequenceOfCharacters(password)) {
        return decreasePasswordStrength(strength);
    }

    if (strlen(password) / maximumOccurrencesOfSameCharacter(password) < 2) {
        return decreasePasswordStrength(strength);
    }

    return strength;
}

