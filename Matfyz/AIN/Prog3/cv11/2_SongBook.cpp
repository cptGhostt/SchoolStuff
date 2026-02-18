#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>

#include "2_SongBook.h"

Song EMPTY_SONG = Song("Empty song");

//2.uloha
void SongBook::addSong(const Song &song) {
    std::string tmpChords = song.getListOfChords();
    songbook[song.getTitle()] = song;
    chords.addListOfChords(tmpChords);
}

bool SongBook::isSongInSongbook(const std::string &songTitle) const {
    if (songbook.find(songTitle) != songbook.end()) {
        return true;
    }
    return false;
}

std::string SongBook::getPlayList() const {
    if (songbook.empty()) {
        return "";
    }

    std::list<std::string> myList(0);
    std::map<std::string, Song>::const_iterator iter = songbook.begin();
    int i = 0;

    while (iter != songbook.end()) {
        myList.push_back(iter->first);
        iter++;
    }

    std::string myStr;
    myList.sort();
    myStr += myList.front();
    myList.pop_front();

    while (myList.size() > 0) {
        myStr += ';' + myList.front();
        myList.pop_front();
    }

    return myStr;
}

Song &SongBook::operator[](int index) {
    if (index < 1 || index > songbook.size()) {
        throw std::out_of_range("Wrong index");
    }

    std::map<std::string, Song>::iterator iter = songbook.begin();
    for (int i = 1; i <= songbook.size(); i++) {
        if (i == index) {
            return iter->second;
        }
        iter++;
    }

    Song *empty = new Song("Dummy");
    return *empty;
}

std::string SongBook::getListOfChords() const {
    return chords.getListOfChords();
}
