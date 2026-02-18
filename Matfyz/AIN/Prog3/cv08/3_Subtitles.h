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
  bool putSubtitle(const std::string &subtitle);
  int getNumberOfSubtitles() const { return numberOfSubtitles; };

  //4.uloha
  bool setFirstSubtitle();
  bool nextSubtitle(int numberOfSteps);
  Element &currentSubtitle();
  bool deleteCurrentSubtitle();

  void eraseAll();
  ~Subtitles();

  //5.uloha
  std::string wrongSubtitlesOrder();
  std::string wrongSubtitlesTimeOrder();
};
