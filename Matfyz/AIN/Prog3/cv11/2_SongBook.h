#include <iostream>
#include <vector>
#include <set>
#include <map>

#pragma once

#include "0_Song.h"
#include "1_Chords.h"

extern Song EMPTY_SONG;

//2-4.uloha
class SongBook {
    std::map<std::string, Song>  songbook;
    Chords chords;
public:
    //2.uloha
    SongBook() {};
    void addSong(const Song &song);
    bool isSongInSongbook(const std::string &songTitle) const;
    Song &operator[](int index);
    std::string getPlayList() const;
    std::string getListOfChords() const;
    int getNumberOfSongs() const { return songbook.size(); };

    //3.uloha
    SongBook(const SongBook &songBook);
    SongBook(SongBook &&songBook);
    std::pair<bool, Song> operator[](const std::string& songTitle);
    bool removeSong(const std::string &songTitle);

    //4.uloha
    int countChordInSongs(const std::string &chord) const;
    void operator+=(const SongBook &songBook);
    int addSongbook(SongBook &&songBook);
};
