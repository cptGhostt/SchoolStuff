#include <algorithm>
#include <sstream>

#include "3_Subtitles.h"

//4.uloha
bool Subtitles::setFirstSubtitle() {
    if (first == nullptr) {
        return false;
    }

    current = first;

    return true;
}

bool Subtitles::nextSubtitle(int numberOfSteps) {
    if (numberOfSteps < 1) {
        return false;
    }

    Element *tmp = current;
    for (int i = 0; i < numberOfSteps; i++) {
        if (tmp == nullptr) {
            return false;
        }
        tmp = tmp->getNext();
    }
    current = tmp;
    return true;
}

Element &Subtitles::currentSubtitle() {
    if (current == nullptr) {
        return *new Element(DUMMY_STRING);
    }

    //Element *tmp = current;
    return *current;
}

bool Subtitles::deleteCurrentSubtitle() {
    if (current == nullptr) {
        return false;
    }

    if (current == first) {
        current = current->getNext();
        first = nullptr;
        first = current;
        numberOfSubtitles--;
        return true;
    }
    Element *tmp = first;
    while (first->getNext() != current) {
        first = first->getNext();
    }
    first->setNext(first->getNext()->getNext());
    current = nullptr;
    current = first;
    first = tmp;
    numberOfSubtitles--;

    return true;
}

void Subtitles::eraseAll() {
    first = nullptr;
    current = nullptr;
    numberOfSubtitles = 0;
}

Subtitles::~Subtitles() {
    eraseAll();
}

