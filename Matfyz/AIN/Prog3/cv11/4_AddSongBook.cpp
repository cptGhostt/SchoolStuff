#include <sstream>
#include <fstream>
#include <queue>

#include "2_SongBook.h"

//4.uloha
int SongBook::countChordInSongs(const std::string &chord) const {
    //if (chords.getNumberOfAppearances(chord) == 0) return 0;

    return chords.getNumberOfAppearances(chord);
}

void SongBook::operator+=(const SongBook &songBook) {
    for (auto it = songBook.songbook.begin(); it != songBook.songbook.end(); it++) {
        addSong(it->second);
    }
}

int SongBook::addSongbook(SongBook &&songBook) {
    int count = 0;
    std::vector<std::string> songsToRemove;
    for (auto it = songBook.songbook.begin(); it != songBook.songbook.end(); ++it) {
        if (!isSongInSongbook(it->first)) {
            addSong(it->second);
            count++;
            songsToRemove.push_back(it->first);
        }
    }

    for (auto songTitle : songsToRemove) {
        songBook.songbook.erase(songTitle);
    }

    return count;
}

