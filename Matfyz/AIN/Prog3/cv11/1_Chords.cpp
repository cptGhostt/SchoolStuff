#include <sstream>
#include <fstream>
#include <set>
#include <queue>

#include "1_Chords.h"

#include <list>

//1.uloha
int Chords::addChord(const std::string &chord) {
    if (chord.empty()) {
        return 0;
    }

    if (chords.find(chord) == chords.end()) {
        chords[chord] = 1;
        return 1;
    }

    chords.at(chord)++;

    return chords.at(chord);
}

void Chords::addListOfChords(const std::string &chordList) {
    if (chordList.empty()) {
        return;
    }

    std::string tmp;

    for (int i = 0; i < chordList.length(); i++) {
        if (chordList.at(i) == ',') {
            if (chords.find(tmp) == chords.end()) {
                chords[tmp] = 1;
            }else {
                chords.at(tmp)++;
            }
            tmp = "";
            continue;
        }
        tmp += chordList.at(i);
    }

    if (chords.find(tmp) == chords.end()) {
        chords[tmp] = 1;
    }else {
        chords.at(tmp)++;
    }

}

int Chords::getNumberOfAppearances(const std::string &chord) const {
    if (chords.find(chord) == chords.end()) {
        return 0;
    }
    return chords.at(chord);
}

std::string Chords::getListOfChords() const {
    if (chords.empty()) {
        return "";
    }
    std::list<std::string> myList(0);
    std::map<std::string, int>::const_iterator iter = chords.begin();
    int i = 0;

    while (iter != chords.end()) {
        myList.push_back(iter->first);
        iter++;
    }

    std::string myStr;
    myList.sort();
    myStr += myList.front();
    myList.pop_front();

    while (myList.size() > 0) {
        myStr += ',' + myList.front();
        myList.pop_front();
    }

    return myStr;
}

int Chords::removeChord(const std::string &chord) {
    if (chords.find(chord) == chords.end()) {
        return 0;
    }
    if (chords.at(chord) > 1) {
        chords.at(chord)--;
        return chords.at(chord);
    }
    chords.erase(chord);
    return 0;
}

