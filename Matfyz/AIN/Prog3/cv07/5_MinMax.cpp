#include <cstdarg>

#include "4_OperatorFunctions.h"
#include "5_MinMax.h"

//5.uloha
VeryLargeInteger minimum(const VeryLargeInteger arrayOfNumbers[], int sizeOfArray) {
    if (sizeOfArray < 1) {
        return VeryLargeInteger();
    }
    VeryLargeInteger minimum = arrayOfNumbers[0];
    for (int i = 1; i < sizeOfArray; i++) {
        if (arrayOfNumbers[i] < minimum) {
            minimum = arrayOfNumbers[i];
        }
    }
    return minimum;
}

int indexToMinimum(const VeryLargeInteger arrayOfNumbers[] ,int sizeOfArray) {
    int minimum = 0;
    for (int i = 1; i < sizeOfArray; i++) {
        if (arrayOfNumbers[i] < arrayOfNumbers[minimum]) {
            minimum = i;
        }
    }
    return minimum;
}

VeryLargeInteger maximum(const VeryLargeInteger arrayOfNumbers[], int sizeOfArray) {
    if (sizeOfArray < 1) {
        return VeryLargeInteger();
    }
    VeryLargeInteger maximum = arrayOfNumbers[0];
    for (int i = 1; i < sizeOfArray; i++) {
        if (arrayOfNumbers[i] > maximum) {
            maximum = arrayOfNumbers[i];
        }
    }
    return maximum;
}

int indexToMaximum(const VeryLargeInteger arrayOfNumbers[] ,int sizeOfArray) {
    int maximum = 0;
    for (int i = 1; i < sizeOfArray; i++) {
        if (arrayOfNumbers[i] > arrayOfNumbers[maximum]) {
            maximum = i;
        }
    }
    return maximum;
}

VeryLargeInteger sum(const VeryLargeInteger arrayOfNumbers[], int sizeOfArray) {
    if (sizeOfArray < 1) {
        return VeryLargeInteger();
    }
    VeryLargeInteger sum("0");
    int counter = 0;

    for (int i = 0; i < sizeOfArray; i++) {
        if (arrayOfNumbers[i].isEmpty()) {
            counter++;
            continue;
        }
        sum += arrayOfNumbers[i];
    }

    if (counter == sizeOfArray) {
        return VeryLargeInteger();
    }
    return sum;
}
