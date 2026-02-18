#include <iostream>

#pragma once

#include "2_Subtitle.h"

//3.uloha
class Element : public Subtitle {
    Element *following = nullptr;
public:
    Element(const std::string &subtitle);

    void setNext(Element *nextSubtitle) { following = nextSubtitle; };
    Element *getNext() const { return following; };
};

class Subtitles {
    Element *first = nullptr;
    Element *current = nullptr;
    int numberOfSubtitles = 0;
public:
    void putSubtitle(const std::string &subtitle) noexcept;
    int getNumberOfSubtitles() const { return numberOfSubtitles; };

    //Methods from 2_Methods.cpp
    bool setFirstSubtitle();
    bool nextSubtitle(int numberOfSteps);
    Element &currentSubtitle();
    bool deleteCurrentSubtitle();
    void eraseAll();
    ~Subtitles() { };

    //3.uloha
    Element &getSubtitle(int index) const;
    void clearAllSubtitles();
    bool readFromFile(const std::string &fileName);
    bool saveToFile(const std::string &fileName) const;

    //4.uloha
    std::string getSubtitleText(int index) const;

    //5.uloha
    void shitfSubtitlesTimeUp(const Time &shift) noexcept;
    void shitfSubtitlesTimeDown(const Time &shift) noexcept;
};
