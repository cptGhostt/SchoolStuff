#include "4_SortWords.h"

//4.uloha
void toLower(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = word[i] + 32;
        }
    }
}

int compareWords(const void *a, const void *b) {
    const char *first = *(const char *const *) a;
    const char *second = *(const char *const *) b;
    return strcmp(first, second);
}

void sortWords(char *listOfWords[], int count) {
    qsort(listOfWords, count, sizeof(char *), compareWords);
}

int compareWithSmallLetters(const void *a, const void *b) {
    const char *first = *(const char *const *)a;
    const char *second = *(const char *const *)b;

    char tmp1[strlen(first) + 1];
    char tmp2[strlen(second) + 1];

    strcpy(tmp1, first);
    strcpy(tmp2, second);

    toLower(tmp1);
    toLower(tmp2);

    return strcmp(tmp1, tmp2);
}

void sortWordsInSmall(char *listOfWords[], int count) {
    qsort(listOfWords, count, sizeof(char *), compareWithSmallLetters);
}

