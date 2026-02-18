#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

#include "3_Subtitles.h"

//3.uloha
Element::Element(const std::string &subtitle){
    this->putSubTitle(subtitle);
}

bool Subtitles::putSubtitle(const std::string &subtitle) {
    if (subtitle.empty()) {
        return false;
    }

    Element *newElement = new Element(subtitle);
    if (newElement->getStatus() != "OK") {
        return false;
    }

    if (first == nullptr) {
        first = newElement;
        current = first;
        numberOfSubtitles++;
        return true;
    }

    Element *temp = current;
    while (temp->getNext() != nullptr) {
        temp = temp->getNext();
    }
    temp->setNext(newElement);
    // current->setNext(newElement);
    // current = current->getNext();
    numberOfSubtitles++;

    return true;
}
