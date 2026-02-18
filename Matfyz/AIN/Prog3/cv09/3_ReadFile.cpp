#include <fstream>
#include <sstream>
#include <string.h>

#include "2_Subtitles.h"

//3.uloha
Element & Subtitles::getSubtitle(int index) const {
    if (index > numberOfSubtitles || index < 1) {
        Element *h = new Element(EMPTY_SUBTITLE);
        return *h;
    }
    int tmp = 1;
    Element *h = first;
    while (tmp != index) {
        h = h->getNext();
        tmp++;
    }
    return *h;
}

bool Subtitles::readFromFile(const std::string &fileName) {
    std::ifstream ifs;
    ifs.open(fileName);

    if (!ifs) {
        return false;
    }

    clearAllSubtitles();

    std::string tmp;

    while (std::getline(ifs, tmp)) {
        std::string tmp2 = "";
        tmp2 += tmp;
        while (!tmp.empty() && !ifs.eof()) {
            std::getline(ifs, tmp);
            if (!tmp.empty()) {
                tmp2 += "\n" + tmp;
            }
        }

        putSubtitle(tmp2);
    }

    ifs.close();
    return true;
}

bool Subtitles::saveToFile(const std::string &fileName) const {
    std::ofstream ofs;
    ofs.open(fileName);

    if (!ofs || numberOfSubtitles == 0) {
        return false;
    }

    Element *h = first;
    while (h != nullptr) {
        ofs << h->getSubtitle() << std::endl << std::endl;

        h = h->getNext();
    }

    ofs.close();
    return true;
}

void Subtitles::clearAllSubtitles() {
    while (current) {
        delete first;
        first = current;
        current = current->getNext();
    }

    delete first;
    first = nullptr;
    current = nullptr;

    numberOfSubtitles = 0;
}

