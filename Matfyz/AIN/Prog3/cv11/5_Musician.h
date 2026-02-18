#include <iostream>
#include <vector>
#include <set>
#include <map>

#pragma once

#include "2_SongBook.h"

//5.uloha
class Musician {
  const std::string name;
  SongBook songbook;

 public:
  Musician(const std::string& name = "Unregistered");
  int learnSongsFromSongbook(SongBook &&songBook);
  bool addSongIfAbleToPlayIt(const Song &songTitle);
  std::string unknownChord(const Song &song) const;
  std::string getListOfChords() const;
  std::string getPlayList() const { return songbook.getPlayList(); };
  std::string musicianName() const { return name; };
};
