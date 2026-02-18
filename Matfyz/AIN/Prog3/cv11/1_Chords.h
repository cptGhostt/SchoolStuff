#include <iostream>
#include <vector>
#include <set>
#include <map>

#pragma once

//1.uloha
class Chords {
  std::map<std::string, int> chords;
 public:
  int addChord(const std::string &chord);
  void addListOfChords(const std::string &chordList);
  int getNumberOfAppearances(const std::string &chord) const;
  std::string getListOfChords() const;
  int removeChord(const std::string &chord);
  int getNumberOfChords() const { return chords.size(); };
  void eraseAll() { chords.clear(); };
};

const int DUMMY_INT = 0;
const std::string DUMMY_STRING = "";
const bool DUMMY_BOOL = true;

