
#include <iostream>
#include <vector>
#include <set>
#include <map>

#pragma once

#include "0_Line.h"

class Song {
  std::string title;
  std::vector<Line> lines;
  std::vector<std::string> chords;
  int current;
  void addChords();
public:
  Song(const std::string& title = "") : title(title), current(-1) {};
  std::string getTitle() const { return title; };
  int addLine(const std::string &line);
  int numberOfLines() const { return lines.size(); };
  std::string getLine(unsigned int index) const;
  int numberOfPhrases() const;
  std::string getPhrase(unsigned int index) const;
  std::string getPhraseChord(unsigned int index) const;
  std::string getPhraseText(unsigned int index) const;
  bool addChord(const std::string &chord);
  std::string getListOfChords() const;
  int numberOfChords() const { return chords.size(); };
  std::string getChord(unsigned int index) const;
  bool first();
  bool next();
  std::string getCurrentPhrase() const;
  std::string getCurrentPhraseText() const;
  std::string getCurrentPhraseChord() const;
  bool readSongFromFile(const std::string &songTitle);
};

