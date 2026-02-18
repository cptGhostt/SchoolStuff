#include "1_characterType.h"

//1. uloha
int charToInt(char c) {
    return c;
}

char intToChar(int i) {
    if (i < 0 || i > 255) {
        return '\0';
    }

    return i;
}

CharacterType typeOfCharacter(char character) {
    if (character == 32) {
        return SPACE;
    }
    if (48 <= character && character <= 57) {
        return DIGIT;
    }
    if (65 <= character && character <= 90) {
        return CAPITAL_LETTER;
    }
    if (97 <= character && character <= 122) {
        return SMALL_LETTER;
    }
    if (character == '\0'
        || character == '\n'
        || character == '\r'
        || character == '\t'
        || character == '\"'
        || character == '\''
        || character == '\\'
        || character == '\?'
        || character == '\b'
        || character == '\f'
        || character == '\v') {
        return NOT_ALLOWED;
    }
    return OTHER;
}

