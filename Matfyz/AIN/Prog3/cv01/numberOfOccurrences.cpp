#include <iostream>

#define DUMMY_INT -1

//3. uloha
int numberOfOccurrences(const char text[], const char subtext[]) {
    unsigned int lengthOfText = 0;
    while (text[lengthOfText] != '\0') {
        lengthOfText++;
    }
    unsigned int lengthOfSubtext = 0;
    while (subtext[lengthOfSubtext] != '\0') {
        lengthOfSubtext++;
    }

    int count = 0;
    unsigned int i = 0;
    while (i < lengthOfText) {
        if (text[i] == subtext[0]) {
            bool equal = true;
            unsigned int j = 0;
            while (j < lengthOfSubtext) {
                if (text[i + j] != subtext[j]) {
                    equal = false;
                }
                j++;
            }
            if (equal) {
                count++;
            }
        }
        i++;
    }
    return count;
}
