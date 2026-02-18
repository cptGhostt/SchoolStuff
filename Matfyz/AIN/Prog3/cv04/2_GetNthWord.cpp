#include "2_GetNthWord.h"

//2. uloha
const char *findNthOccurrenceOfChar(const char *text, char character, int orderNumber) {
    if (text == nullptr) {
        return EMPTY_WORD;
    }

    int counter = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == character) {
            counter++;
        }
        if (counter == orderNumber) {
            return &text[i];
        }
    }
    return EMPTY_WORD;
}

const char *findNthWord(const char *text, int orderNumber) {
    if (text == nullptr) {
        return EMPTY_WORD;
    }

    if (numberOfWords(text) < orderNumber || orderNumber <= 0) {
        return EMPTY_WORD;
    }

    int counter = 0;
    char separators[] = " .,:;?!()[]/\\\n";
    bool sep = false, word = true;
    for (int i = 0; i < strlen(text); i++) {
        for (int j = 0; j < strlen(separators); j++) {
            if (text[i] == separators[j]) {
                word = false;
            }
            if (i != 0 && text[i - 1] == separators[j]) {
                sep = true;
            }
        }
        if ((word && sep) || (word and i == 0)) {
            counter++;
        }
        if (counter == orderNumber) {
            return &text[i];
        }
        word = true;
        sep = false;
    }

    return EMPTY_WORD;
}

const char *copyNthWord(const char *text, char *word, int orderNumber) {
    if (text == nullptr or word == nullptr) {
        return EMPTY_WORD;
    }

    if (numberOfWords(text) < orderNumber || orderNumber <= 0) {
        return EMPTY_WORD;
    }

    char *tmp = (char*)(findNthWord(text, orderNumber));
    bool end = false;
    char separators[] = " .,:;?!()[]/\\\n";

    for (int i = 0; i < strlen(tmp); i++) {
        for (int j = 0; j < strlen(separators); j++) {
            if (tmp[i] == separators[j]) {
                end = true;
                break;
            }
        }
        if (end) {
            break;
        }
        word[i] = tmp[i];
        word[i+1] = '\0';
    }

    return word;
}

