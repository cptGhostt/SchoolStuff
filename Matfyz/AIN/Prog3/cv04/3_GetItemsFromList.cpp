#include "3_GetItemsFromList.h"

//3.uloha
const char *selectWords(const char *text, char *listOfWords
        , const int listOfOrders[], int numberOfOrders) {
    if (text == nullptr || listOfWords == nullptr) {
        return EMPTY_WORD;
    }

    int words = numberOfWords(text);
    strcpy(listOfWords, "");

    for (int i = 0; i < numberOfOrders; i++) {
        if (listOfOrders[i] > words) {
            continue;
        }

        char a[256] = "";
        strcat(listOfWords, copyNthWord(text, a, listOfOrders[i]));
        if (listOfWords[strlen(listOfWords) - 1] != ',') {
            strcat(listOfWords, ",");
        }

    }
    listOfWords[strlen(listOfWords)-1] = '\0';
    return listOfWords;
}

