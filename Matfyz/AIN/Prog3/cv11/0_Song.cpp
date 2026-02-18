#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>

#include "0_Song.h"

int Song::addLine(const std::string &line) {
  if (line.length() == 0) {
    return numberOfLines();
  }
  lines.push_back(Line(line));
  addChords();
  return numberOfLines();
}

std::string Song::getLine(unsigned int index) const {
  if (index < numberOfLines()) {
    return lines[index].getLine();
  }
  return "Line does not exist";
}

int Song::numberOfPhrases() const {
  int pocitadloFraz = 0;
  for (unsigned int i = 0; i < numberOfLines(); i++) {
    pocitadloFraz += lines[i].numberOfPhrases();
  }
  return pocitadloFraz;
}

std::string Song::getPhrase(unsigned int index) const {
  if (index < numberOfPhrases()) {
    int pocitadloFraz = 0;
    for (unsigned int i = 0; i < numberOfLines(); i++) {
      if (pocitadloFraz <= index
          && index < (pocitadloFraz + lines[i].numberOfPhrases())) {
        std::string temp = lines[i].getPhraseChord(index - pocitadloFraz);
        temp += chordDelimiter;
        temp += lines[i].getPhraseText(index - pocitadloFraz);
        return temp;
      }
      pocitadloFraz += lines[i].numberOfPhrases();
    }
  }
  return "Phrase does not exist";
}

std::string Song::getPhraseText(unsigned int index) const {
  if (index < numberOfPhrases()) {
    int pocitadloFraz = 0;
    for (unsigned int i = 0; i < numberOfLines(); i++) {
      if (pocitadloFraz <= index
          && index < (pocitadloFraz + lines[i].numberOfPhrases())) {
        std::string temp = lines[i].getPhraseChord(index - pocitadloFraz);
        return lines[i].getPhraseText(index - pocitadloFraz);
      }
      pocitadloFraz += lines[i].numberOfPhrases();
    }
  }
  return "Phrase does not exist";
}

std::string Song::getPhraseChord(unsigned int index) const {
  if (index < numberOfPhrases()) {
    int pocitadloFraz = 0;
    for (unsigned int i = 0; i < numberOfLines(); i++) {
      if (pocitadloFraz <= index
          && index < (pocitadloFraz + lines[i].numberOfPhrases())) {
        std::string temp = lines[i].getPhraseChord(index - pocitadloFraz);
        return lines[i].getPhraseChord(index - pocitadloFraz);
      }
      pocitadloFraz += lines[i].numberOfPhrases();
    }
  }
  return "Phrase does not exist";
}

void Song::addChords() {
  for (unsigned int i = 0; i < lines[numberOfLines() - 1].numberOfPhrases(); i++) {
    std::string temp = lines[numberOfLines() - 1].getPhraseChord(i);
    if (temp.length() > 0) {
      addChord(temp);
    }
  }
}

bool Song::addChord(const std::string &chord) {
  for (unsigned int i = 0; i < chords.size(); i++) {
    if (chords[i] == chord) {
      return false;
    }
  }
  std::priority_queue<std::string> sortedChords;
  for (unsigned int i = 0; i < chords.size(); i++) {
    sortedChords.push(chords[i]);
  }
  sortedChords.push(chord);
  chords.clear();
  std::vector<std::string> reversedChordes;
  unsigned int pocet = sortedChords.size();
  for (unsigned int i = 0; i < pocet; i++) {
    std::string chord = sortedChords.top();
    reversedChordes.push_back(chord);
    sortedChords.pop();
  }
  for (int i = reversedChordes.size() - 1; i >= 0; i--) {
    std::string chord = reversedChordes[i];
    chords.push_back(chord);
  }
  return true;
}

std::string Song::getListOfChords() const {
  std::string temp = "";
  for (auto iter = chords.begin(); iter != chords.end(); iter++) {
    if (iter != chords.begin()) {
      temp += ",";
    }
    temp += *iter;
  }
  return temp;
}

std::string Song::getChord(unsigned int index) const {
  if (index < chords.size()) {
    auto iter = chords.begin();
    for (unsigned int i = 0; i < index; i++, iter++);
    return *iter;
  }
  return "Taky akord nie je";
}

bool Song::first() {
  if (numberOfPhrases() > 0) {
    current = 0;
    return true;
  }
  return false;
}

bool Song::next() {
  if (current < numberOfPhrases() - 1) {
    current++;
    return true;
  }
  return false;
}

bool Song::readSongFromFile(const std::string &songTitle) {
  std::ifstream inSongFile;
    inSongFile.open(songTitle);
    if (!inSongFile) {
        return false;
    }
    std::string line;
    while (getline(inSongFile, line)) {
        std::string newLine;
        for (char c : line) {
            switch (c) {
                case '\n':
                case '\r':
                case '\t':
                case '\b':
                case '\v':
                case '\0':
                    continue;
                default:
                    newLine += c;
            }
        }
        addLine(newLine);
    }
    return true;
}
