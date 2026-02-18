#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>

#include "2_SongBook.h"

//3.uloha
SongBook::SongBook(const SongBook &songBook) {
    chords = songBook.chords;
    songbook = songBook.songbook;
}

SongBook::SongBook(SongBook &&songBook) {
    chords = std::move(songBook.chords);
    songbook = std::move(songBook.songbook);

}

std::pair<bool, Song> SongBook::operator[](const std::string& songTitle) {
    std::pair<bool, Song> result;
    if (songbook.find(songTitle) == songbook.end()) {
        result.first = false;
        result.second = EMPTY_SONG;
    } else {
        result.first = true;
        result.second = songbook.at(songTitle);
    }
    return result;
}

bool SongBook::removeSong(const std::string &songTitle) {
    if (songbook.find(songTitle) == songbook.end()) {
        return false;
    }
    for (int i = 0 ; i < songbook.at(songTitle).numberOfChords(); i++) {
        chords.removeChord(songbook.at(songTitle).getChord(i));
    }
    songbook.erase(songTitle);
    return true;
}
