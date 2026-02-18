#include "1_Elements.h"

//1. uloha
int numberOChars(char const *text, const char character) {
    if (text == nullptr) {
        return 0;
    }

    int counter = 0, i = 0;
    while (*text != '\0') {
        if (text[i] == character) {
            counter++;
        }
        *text++;
    }
    return counter;
}

int numberOfWords(const char *text) {
    if (text == nullptr) {
        return 0;
    }

    int numberOfWords = 0;
    char separators[] = " .,:;?!()[]/\\\n";
    bool sep = false, word = true;

    for (int i = 0; i < strlen(text); i++) {
        for (int j = 0; j < strlen(separators); j++) {
            if (text[i] == separators[j]) {
                word = false;
            }
            if (text[i+1] == separators[j] || text[i+1] == '\0') {
                sep = true;
            }
        }
        if (word && sep) {
            numberOfWords++;
        }
        sep = false;
        word = true;
    }


    return numberOfWords;

}

int findNumber(const double data[], size_t size, double number) {
    if (data == nullptr) {
        return NOT_FOUND;
    }

    for (int i = 0; i < size; i++) {
        if (data[i] == number) {
            return i;
        }
    }

    return NOT_FOUND;
}

const double *findMaximum(const double data[], size_t count) {
    if (data == nullptr) {
        return &EMPTY_DOUBLE;
    }

    int max = 0;

    for (int i = 0; i < count; i++) {
        if (data[i] > data[max]) {
            max = i;
        }
    }

    return &data[max];

}

