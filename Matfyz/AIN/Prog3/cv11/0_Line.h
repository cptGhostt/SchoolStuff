#include <iostream>
#include <vector>

#pragma once

#include "0_Phrase.h"

const std::string wrongIndex = "Wrong index";

//zdedene riesenie
class Line {
    std::vector<Phrase> phrases;
    void putPhrase(const std::string &phrase);
    int putLine(const std::string &line);
public:
    Line(const std::string &line);
    int numberOfPhrases() const { return phrases.size(); };
    std::string getPhraseText(unsigned int index) const;
    std::string getPhraseChord(unsigned int index) const;
    std::string getLine() const;
};

