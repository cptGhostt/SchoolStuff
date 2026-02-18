#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "2_Subtitles.h"

//3.uloha
Element::Element(const std::string &subtitle) {
    this->putSubtitle(subtitle);
}

void Subtitles::putSubtitle(const std::string &subtitle) noexcept {
    try {
        Element *newElement = new Element(subtitle);

        if (first == nullptr) {
            first = newElement;
            current = first;
            numberOfSubtitles++;
            return;
        }


        current->setNext(newElement);
        current = current->getNext();
        numberOfSubtitles++;
    } catch (const std::exception &e) {
        return;
    }

}
