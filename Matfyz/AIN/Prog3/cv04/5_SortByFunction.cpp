#include "5_SortByFunction.h"

#include <algorithm>

//5.uloha
int compareWithSmallAndCh(const void *a, const void *b) {
    const char *first = *(const char *const *)a;
    const char *second = *(const char *const *)b;

    char tmp1[strlen(first) + 1];
    char tmp2[strlen(second) + 1];

    strcpy(tmp1, first);
    strcpy(tmp2, second);

    toLower(tmp1);
    toLower(tmp2);

    if (tmp1[0] == 'c' && tmp1[1] == 'h' && tmp2[0] == 'c' && tmp2[1] == 'h') {
        return strcmp(tmp1, tmp2);
    }

    if (tmp1[0] == 'c' && tmp1[1] == 'h' && tmp2[0] <= 'h') {
        return 1;
    }

    if (tmp2[0] == 'c' && tmp2[1] == 'h' && tmp1[0] <= 'h') {
        return -1;
    }

    return strcmp(tmp1, tmp2);
}

void sortWordsInSmallAndCh(char *listOfWords[], int count) {
    qsort(listOfWords, count, sizeof(char *), compareWithSmallAndCh);
}

const char *sortAccordingToFunction(const char *text, char *output, void sortingFunction(char *arraysOfText[], int count)) {
    if (text == nullptr || output == nullptr || numberOfWords(text) == 0) {
        return "";
    }
    int count = numberOfWords(text);
    char **words = new char *[count];

    for (int i = 0; i < count; i++) {
        words[i] = new char[strlen(text) + 1];
        copyNthWord(text, words[i], i + 1);
    }

    sortingFunction(words, count);

    output[0] = '\0';
    for (int i = 0; i < count; i++) {
        strcat(output, words[i]);
        if (i < count - 1) {
            strcat(output, ",");
        }
    }

    for (int i = 0; i < count; i++) {
        delete[] words[i];
    }
    delete[] words;

    return output;
}
