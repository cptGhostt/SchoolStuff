#include <iostream>

#pragma once

const char chordDelimiter = '$';
const char phraseDelimiter = '#';
const char spaceReplacer = '%';

//Legacy code
class Phrase {
    std::string text;
    std::string chord;
 public:
    Phrase(const std::string &phrase);
    bool putPhrase(const std::string &phrase);
    std::string getPhraseText() const;
    std::string getPhraseChord() const;
};

std::string exchangeCharacters(const std::string &text, const char co, const char za);
