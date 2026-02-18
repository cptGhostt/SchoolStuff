#include <iostream>
#include <fstream>
#include <sstream>

#include "2_Subtitles.h"
#include "4_Operators.h"

//4.uloha
std::string Subtitles::getSubtitleText(int index) const {
    if (index > numberOfSubtitles || index < 1) return "";

    Element *e = first;
    while (index != 1) {
        e = e->getNext();
        index--;
    }

    return e->getSubtitle();
}

Time operator+(const Time &first, const Time &second) {
    std::istringstream t1(first.getTime()), t2(second.getTime());

    std::string h1, m1, s1, ms1, h2, m2, s2, ms2;
    std::getline(t1, h1, ':');
    std::getline(t1, m1, ':');
    std::getline(t1, s1, ',');
    std::getline(t1, ms1);
    std::getline(t2, h2, ':');
    std::getline(t2, m2, ':');
    std::getline(t2, s2, ',');
    std::getline(t2, ms2);

    int h = 0, m = 0, s = 0, ms = 0;
    ms += (std::stoi(ms1) + std::stoi(ms2));
    s += ms / 1000;
    ms %= 1000;

    s += (std::stoi(s1) + std::stoi(s2));
    m += s / 60;
    s %= 60;

    m += (std::stoi(m1) + std::stoi(m2));
    h += m / 60;
    m %= 60;

    h += (std::stoi(h1) + std::stoi(h2));


    Time result;
    try {
        result.putTime(h,m,s,ms);
    } catch (WrongTime &e) {
        throw WrongTimeMove(e.message().c_str());
    }
    return result;
}

Time operator-(const Time &first, const Time &second) {
    if (first < second) {
        throw WrongTimeMove("Result of time subtraction is less than zero");
    }

    std::istringstream t1(first.getTime()), t2(second.getTime());

    std::string h1, m1, s1, ms1, h2, m2, s2, ms2;
    std::getline(t1, h1, ':');
    std::getline(t1, m1, ':');
    std::getline(t1, s1, ',');
    std::getline(t1, ms1);
    std::getline(t2, h2, ':');
    std::getline(t2, m2, ':');
    std::getline(t2, s2, ',');
    std::getline(t2, ms2);

    int h = 0, m = 0, s = 0, ms = 0;

    ms += (std::stoi(ms1) - std::stoi(ms2));
    if (ms < 0) {
        ms += 1000;
        s -= 1;
    }

    s += (std::stoi(s1) - std::stoi(s2));
    if (s < 0) {
        s += 60;
        m -= 1;
    }

    m += (std::stoi(m1) - std::stoi(m2));
    if (m < 0) {
        m += 60;
        h -= 1;
    }

    h += (std::stoi(h1) - std::stoi(h2));

    Time result;
    try {
        result.putTime(h,m,s,ms);
    } catch (WrongTime &e) {
        throw WrongTimeMove(e.message().c_str());
    }
    return result;
}


