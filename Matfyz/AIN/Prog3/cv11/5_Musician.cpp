#include <sstream>
#include <fstream>

#include "5_Musician.h"

//5.uloha
Musician::Musician(const std::string& name) : name(name) {
}

int Musician::learnSongsFromSongbook(SongBook &&songBook) {
    return songbook.addSongbook(std::move(songBook));
}

std::string Musician::getListOfChords() const {
    return songbook.getListOfChords();
}

std::string Musician::unknownChord(const Song &song) const {
    std::string toReturn = "";
    std::string chords = song.getListOfChords();
    std::string myChords = songbook.getListOfChords();
    std::string chord = "";

    if (chords == myChords) {
        return  "";
    }

    for (int i = 0; i < chords.size(); i++) {
        if (chords[i] == ',' || chords[i] == '\0') {
            std::string chord2 = "";
            bool isUnknown = true;
            for (int j = 0; j < myChords.size(); j++) {
                if (myChords[j] == ',' || myChords[j] == '\0') {
                    if (chord == chord2) {
                        isUnknown = false;
                        break;
                    }
                    chord2 = "";
                    continue;
                }
                chord2 += myChords[j];
            }

            if (isUnknown) {
                if (toReturn == "") {
                    toReturn += chord;
                }
                else {
                    toReturn += ',' + chord;
                }
            }
            chord = "";
            continue;
        }
        chord += chords[i];
    }

    return toReturn;
}

bool Musician::addSongIfAbleToPlayIt(const Song &songTitle) {
    if (unknownChord(songTitle) != "") {
        return false;
    }
    if (songbook.isSongInSongbook(songTitle.getTitle())) {
        return false;
    }
    songbook.addSong(songTitle);
    return true;
}
