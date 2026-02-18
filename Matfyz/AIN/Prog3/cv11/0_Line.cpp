#include <sstream>

#include "0_Line.h"

//zdedene riesenie
Line::Line(const std::string &line) {
  putLine(line);
};

int Line::putLine(const std::string &line) {
  if (line.length() == 0) {
    phrases.clear();
    return phrases.size();
  }
  phrases.clear();

  std::string temp = exchangeCharacters(line, ' ', spaceReplacer);
  temp = exchangeCharacters(temp, phraseDelimiter, ' ');
  std::istringstream rr(temp);
  std::string fraza;
  while (rr >> fraza) {
    putPhrase(fraza);
  }
  return phrases.size();
}

void Line::putPhrase(const std::string &phrase) {
  phrases.push_back(Phrase(phrase));
}

std::string Line::getPhraseText(unsigned int index) const {
  if (index >= 0 && index < phrases.size()) {
    return phrases[index].getPhraseText();
  }
  return wrongIndex;
}

std::string Line::getPhraseChord(unsigned int index) const {
  if (index >= 0 && index < phrases.size()) {
    return phrases[index].getPhraseChord();
  }
  return wrongIndex;
}

std::string Line::getLine() const {
  std::string vers;
  for (unsigned int i = 0; i < numberOfPhrases(); i++) {
    if (i > 0) {
      vers += phraseDelimiter;
    }
    if (phrases[i].getPhraseChord().length() > 0) {
      vers += phrases[i].getPhraseChord() + chordDelimiter;
    }
    vers += phrases[i].getPhraseText();
  }
  return vers;
}
