#include <sstream>

#include "0_Phrase.h"

//Zdedene riesenie programu
std::string exchangeCharacters(const std::string &text, const char co, const char za) {
  std::string vystup;
  for (unsigned int i = 0; i < text.length(); i++) {
    if (text[i] == co)
      vystup += za;
    else
      vystup += text[i];
  }
  return vystup;
}

Phrase::Phrase(const std::string &phrase) : text(""), chord("") {
  putPhrase(phrase);
};

bool Phrase::putPhrase(const std::string &phrase) {
  if (phrase.length() == 0) {
    return false;
  }

  std::string temp = exchangeCharacters(phrase, ' ', spaceReplacer);
  temp = exchangeCharacters(temp, chordDelimiter, ' ');
  std::istringstream rr(temp);
  std::string prvy, druhy;
  if (rr >> prvy) {
    if (rr >> druhy) {
      chord = prvy;
      druhy = exchangeCharacters(druhy, spaceReplacer, ' ');
      text = druhy;
    }
    else {
      prvy = exchangeCharacters(prvy, spaceReplacer, ' ');
      text = prvy;
      chord = "";
    }
    return true;
  }
  return false;
}

std::string Phrase::getPhraseText() const {
  return text;
}

std::string Phrase::getPhraseChord() const {
  return chord;
}
