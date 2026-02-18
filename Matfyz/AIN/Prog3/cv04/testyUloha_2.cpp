// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace ::testing;

#include "2_GetNthWord.h"

TEST(TestDruhejUlohy, findLastSpace) {
    std::string temp(" nasiel");
    ASSERT_EQ(temp, findNthOccurrenceOfChar("Ale som to predsa nasiel", ' ', 4));
}

TEST(TestDruhejUlohy, findOccurrenceLast) {
    std::string temp("l");
    ASSERT_EQ(temp, findNthOccurrenceOfChar("Ak som to nasiel", 'l', 1));
}

TEST(TestDruhejUlohy, findOccurrenceNull) {
    std::string temp("");
    ASSERT_EQ(temp, findNthOccurrenceOfChar(nullptr, 'a', 1));
}

TEST(TestDruhejUlohy, findOccurrenceA) {
    std::string temp("A");
    ASSERT_EQ(temp, findNthOccurrenceOfChar("A", 'A', 1));

}

TEST(TestDruhejUlohy, findOccurrenceAOut) {
    std::string temp("");
    ASSERT_EQ(temp, findNthOccurrenceOfChar("A", 'A', 2));
    ASSERT_EQ(temp, findNthOccurrenceOfChar("A", 'A', 0));
}

TEST(TestDruhejUlohy, findNoCharacter) {
    std::string temp("A");
    ASSERT_NE(temp, findNthOccurrenceOfChar("A", ' ', 1));
}

TEST(TestDruhejUlohy, findCharIn) {
    std::string temp("som to nasiel");
    ASSERT_EQ(temp, findNthOccurrenceOfChar("Ale som to nasiel", 's', 1));
}

TEST(TestDruhejUlohy, findSpace) {
    std::string temp(" to nasiel");
    ASSERT_EQ(temp, findNthOccurrenceOfChar("Ale som to nasiel", ' ', 2));
}

TEST(TestDruhejUlohy, findSpaces) {
    std::string temp(" nasiel");
    ASSERT_EQ(temp, findNthOccurrenceOfChar("Ale som to predsa nasiel", ' ', 4));
}

TEST(TestDruhejUlohy, findCharacterLast) {
    std::string temp("l");
    ASSERT_EQ(temp, findNthOccurrenceOfChar("Ak som to nasiel", 'l', 1));
}

TEST(TestDruhejUlohy, findCharacterEnd) {
    std::string temp("");
    ASSERT_EQ(temp, findNthOccurrenceOfChar("Ak som to nasiel", '\0', 1));
}

TEST(TestDruhejUlohy, prazdnyDruhy) {
    std::string temp("");
    ASSERT_EQ(temp, findNthWord(nullptr, 2));
}

TEST(TestDruhejUlohy, DruheJe) {
    std::string temp("je to? ");
    ASSERT_EQ(temp, findNthWord("Co je to? ", 2));
}

TEST(TestDruhejUlohy, DruhePoDel) {
    std::string temp("je to?????? ");
    ASSERT_EQ(temp, findNthWord(" ., ; () !!!!!!!!!!!!!!! Co je to?????? ", 2));
}

TEST(TestDruhejUlohy, JednoMalo) {
    std::string temp("");
    ASSERT_EQ(temp, findNthWord("Samota", 2));
}

TEST(TestDruhejUlohy, DruheSMedzerami) {
    std::string temp("Samota");
    ASSERT_EQ(temp, findNthWord("     Dlha              Samota", 2));
}

TEST(TestDruhejUlohy, DruheSVykricnikmi) {
    std::string temp("Samota!!!!!!!!!!!!!!");
    ASSERT_EQ(temp, findNthWord("    Hadava               Samota!!!!!!!!!!!!!!", 2));
}

TEST(TestDruhejUlohy, DvePismena) {
    std::string temp("B");
    ASSERT_EQ(temp, findNthWord("A B", 2));
}

TEST(TestDruhejUlohy, odSlova0) {
    ASSERT_EQ("Pravda", findNthWord("Pravda", 1));
}

TEST(TestDruhejUlohy, zaporneSlovo) {
    std::string temp("");
    ASSERT_EQ(temp, findNthWord("Pravda", -3));
}

TEST(TestDruhejUlohy, nullptr1) {
    std::string temp("");
    ASSERT_EQ(temp, findNthWord(nullptr, 1));
}

TEST(TestDruhejUlohy, odSlova1) {
    std::string temp("to je zac? Snad nie toto!!!!");
    ASSERT_EQ(temp, findNthWord("Co to je zac? Snad nie toto!!!!", 2));
}

TEST(TestDruhejUlohy, odSlovaZaciatku) {
    std::string temp("Co to je zac? Snad nie toto!!!!");
    ASSERT_EQ(temp, findNthWord("Co to je zac? Snad nie toto!!!!", 1));
}

TEST(TestDruhejUlohy, odMedzeryAZaciatku) {
    std::string temp("Co to je zac? Snad nie toto!!!!");
    ASSERT_EQ(temp, findNthWord("  .  .. Co to je zac? Snad nie toto!!!!", 1));
}

TEST(TestDruhejUlohy, odSlovaMinus1) {
    std::string temp("");
    ASSERT_EQ(temp, findNthWord("Co to je zac? Snad nie toto!!!!", -1));
}

TEST(TestDruhejUlohy, odSlova6) {
    std::string temp("toto!!!!");
    ASSERT_EQ(temp, findNthWord("Co to je zac? Snad nie toto!!!!", 7));
}

TEST(TestDruhejUlohy, odSlova7SoZatvorkou) {
    std::string temp("");
    ASSERT_EQ(temp, findNthWord("Co to je zac? Snad nie toto!!!!", 8));
}

TEST(TestDruhejUlohy, odSlova25) {
    std::string temp("");
    ASSERT_EQ(temp, findNthWord("Co to je zac? Snad nie toto!!!!", 25));
}

TEST(TestDruhejUlohy, odPrazdneho0) {
    std::string temp("");
    ASSERT_EQ(temp, findNthWord("", 1));
}

TEST(TestDruhejUlohy, odSlovaC) {
    std::string temp("D");
    ASSERT_EQ(temp, findNthWord("C D", 2));
}

TEST(TestDruhejUlohy, odSlova0C) {
    std::string temp("C C");
    ASSERT_EQ(temp, findNthWord("C C", 1));
}

TEST(TestDruhejUlohy, odSlovaZaciatok) {
    std::string temp("Co je ? ");
    ASSERT_EQ(temp, findNthWord("Co je ? \0 Snad nie !!!! C", 1));
}

TEST(TestDruhejUlohy, odSlova2) {
    std::string temp("Snad nie !!!! C");
    ASSERT_EQ(temp, findNthWord("Co je ? Snad nie !!!! C", 3));
}

TEST(TestDruhejUlohy, VelmiDlhyText10krat) {
    char text[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry."
                  "Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an "
                  "unknown printer took a galley of type and scrambled it to make a type specimen book. "
                  "It has survived not only five centuries, but also the leap into electronic typesetting, "
                  "remaining essentially unchanged. It was popularised in the 1960s with the release of "
                  "Letraset sheets containing Lorem Ipsum passages, and more recently with desktop"
                  "publishing software like Aldus PageMaker including versions of Lorem Ipsum."

                  "It is a long established fact that a reader will be distracted by the readable content "
                  "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
                  "more - or - less normal distribution of letters, as opposed to using "
                  "Content here, content here, making it look like readable English."
                  "Many desktop publishing packages and page editors now use Lorem Ipsum as their"
                  "default model text, and a search for lorem ipsum will uncover many web sites still "
                  "in their infancy.Various versions have evolved over the years, sometimes by accident, "
                  "sometimes on purpose(injected humour and the like)."
                  "It is a long established fact that a reader will be distracted by the readable content "
                  "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
                  "more - or - less normal distribution of letters, as opposed to using "
                  "Content here, content here, making it look like readable English."
                  "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
                  "default model text, and a search for lorem ipsum will uncover many web sites still "
                  "in their infancy.Various versions have evolved over the years, sometimes by accident, "
                  "sometimes on purpose(injected humour and the like)."
                  "It is a long established fact that a reader will be distracted by the readable content "
                  "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
                  "more - or - less normal distribution of letters, as opposed to using "
                  "Content here, content here, making it look like readable English."
                  "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
                  "default model text, and a search for lorem ipsum will uncover many web sites still "
                  "in their infancy.Various versions have evolved over the years, sometimes by accident, "
                  "sometimes on purpose(injected humour and the like)."

                  "It is a long established fact that a reader will be distracted by the readable content "
                  "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
                  "more - or - less normal distribution of letters, as opposed to using "
                  "Content here, content here, making it look like readable English."
                  "Many desktop publishing packages and page editors now use Lorem Ipsum as their"
                  "default model text, and a search for lorem ipsum will uncover many web sites still "
                  "in their infancy.Various versions have evolved over the years, sometimes by accident, "
                  "sometimes on purpose(injected humour and the like)."
                  "It is a long established fact that a reader will be distracted by the readable content "
                  "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
                  "more - or - less normal distribution of letters, as opposed to using "
                  "Content here, content here, making it look like readable English."
                  "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
                  "default model text, and a search for lorem ipsum will uncover many web sites still "
                  "in their infancy.Various versions have evolved over the years, sometimes by accident, "
                  "sometimes on purpose(injected humour and the like)."
                  "It is a long established fact that a reader will be distracted by the readable content "
                  "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
                  "more - or - less normal distribution of letters, as opposed to using "
                  "Content here, content here, making it look like readable English."
                  "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
                  "default model text, and a search for lorem ipsum will uncover many web sites still "
                  "in their infancy.Various versions have evolved over the years, sometimes by accident, "
                  "sometimes on purpose(injected humour and the like).";
    std::string temp("injected humour and the like).");
    ASSERT_EQ(temp, findNthWord(text, 726));
}

TEST(TestDruhejUlohy, zatvorkyGulate) {
    std::string temp("toto)? Snad nie !!!! C");
    ASSERT_EQ(temp, findNthWord("Co je (toto)? Snad nie !!!! C", 3));
}

TEST(TestDruhejUlohy, zatvorkyHranate) {
    std::string temp("Takto ] Snad nie !!!! C");
    ASSERT_EQ(temp, findNthWord("Co je toto? [ Takto ] Snad nie !!!! C", 4));
}

TEST(TestDruhejUlohy, PrazdnyRetazec) {
  char *word = new char[256];
  std::string temp("");
  ASSERT_EQ(temp, copyNthWord(nullptr, word, 0));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, PrazdnyWord) {
  std::string temp("");
  ASSERT_EQ(temp, copyNthWord("Pravda", nullptr, 0));
}

TEST(TestDruhejUlohy, PrazdneOba) {
  std::string temp("");
  ASSERT_EQ(temp, copyNthWord(nullptr, nullptr, 0));
}

TEST(TestDruhejUlohy, nuloveSlovo) {
  char *word = new char[256];
  std::string temp("");
  ASSERT_EQ(temp, copyNthWord(nullptr, word, 1));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, ZiadneSlovo) {
  char *word = new char[256];
  std::string temp("");
  ASSERT_EQ(temp, copyNthWord("  ,,,, .... !!!!", word, 1));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, prazdneSlovo) {
  char *word = new char[256];
  std::string temp("");
  ASSERT_EQ(temp, copyNthWord("", word, 1));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, to) {
  char *word = new char[256];
  std::string temp("to");
  ASSERT_EQ(temp, copyNthWord("Co to je zac? Snad nie toto!!!!", word, 2));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, VratCele) {
    char *word = new char[256];
    std::string temp("Pravda");
    ASSERT_EQ(temp, copyNthWord("Pravda", word, 1));
    if (word != nullptr) {
        delete[] word;
    }
}

TEST(TestDruhejUlohy, Co) {
  char *word = new char[256];
  std::string temp("Co");
  ASSERT_EQ(temp, copyNthWord("Co to je zac? Snad nie toto!!!!", word, 1));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, MedzeraCo) {
  char *word = new char[256];
  std::string temp("Co");
  ASSERT_EQ(temp, copyNthWord(" .   Co to je zac? Snad nie toto!!!!", word, 1));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, minusPrveSlovo) {
  char *word = new char[256];
  std::string temp("");
  ASSERT_EQ(temp, copyNthWord("Co to je zac? Snad nie toto!!!!", word, -1));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, NulteSlovo) {
  char *word = new char[256];
  std::string temp("");
  ASSERT_EQ(temp, copyNthWord("Co to je zac? Snad nie toto!!!!", word, 0));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, toto) {
  char *word = new char[256];
  std::string temp("toto");
  ASSERT_EQ(temp, copyNthWord("Co to je zac? Snad nie toto!!!!", word, 7));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, mimo) {
  char *word = new char[256];
  std::string temp("");
  ASSERT_EQ(temp, copyNthWord("Co to je zac? Snad nie toto!!!!", word, 8));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, mimoVelmi) {
  char *word = new char[256];
  std::string temp("");
  ASSERT_EQ(temp, copyNthWord("Co to je zac? Snad nie toto!!!!", word, 20));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, C) {
  char *word = new char[256];
  std::string temp("Q");
  ASSERT_EQ(temp, copyNthWord("C A Q", word, 3));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, prveC) {
  char *word = new char[256];
  std::string temp("C");
  ASSERT_EQ(temp, copyNthWord("C A C", word, 1));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, Snad) {
  char *word = new char[256];
  std::string temp("nie");
  ASSERT_EQ(temp, copyNthWord("Co je ? Snad nie !!!! C", word, 4));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, posledneC) {
  char *word = new char[256];
  std::string temp("F");
  ASSERT_EQ(temp, copyNthWord("Co je ? Snad nie !!!! F", word, 5));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, AD) {
  char *word = new char[256];
  std::string temp("AD");
  ASSERT_EQ(temp, copyNthWord(" F E G AD C B  ", word, 4));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, VelmiDlhyTextSlovo) {
  char text[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry."
                                                                          "Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an "
                                                                          "unknown printer took a galley of type and scrambled it to make a type specimen book. "
                                                                          "It has survived not only five centuries, but also the leap into electronic typesetting, "
                                                                          "remaining essentially unchanged. It was popularised in the 1960s with the release of "
                                                                          "Letraset sheets containing Lorem Ipsum passages, and more recently with desktop"
                                                                          "publishing software like Aldus PageMaker including versions of Lorem Ipsum."

                                                                          "It is a long established fact that a reader will be distracted by the readable content "
                                                                          "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
                                                                          "more - or - less normal distribution of letters, as opposed to using "
                                                                          "Content here, content here, making it look like readable English."
                                                                          "Many desktop publishing packages and page editors now use Lorem Ipsum as their"
                                                                          "default model text, and a search for lorem ipsum will uncover many web sites still "
                                                                          "in their infancy.Various versions have evolved over the years, sometimes by accident, "
                                                                          "sometimes on purpose(injected humour and the like)."
                                                                          "It is a long established fact that a reader will be distracted by the readable content "
                                                                          "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
                                                                          "more - or - less normal distribution of letters, as opposed to using "
                                                                          "Content here, content here, making it look like readable English."
                                                                          "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
                                                                          "default model text, and a search for lorem ipsum will uncover many web sites still "
                                                                          "in their infancy.Various versions have evolved over the years, sometimes by accident, "
                                                                          "sometimes on purpose(injected humour and the like)."
                                                                          "It is a long established fact that a reader will be distracted by the readable content "
                                                                          "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
                                                                          "more - or - less normal distribution of letters, as opposed to using "
                                                                          "Content here, content here, making it look like readable English."
                                                                          "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
                                                                          "default model text, and a search for lorem ipsum will uncover many web sites still "
                                                                          "in their infancy.Various versions have evolved over the years, sometimes by accident, "
                                                                          "sometimes on purpose(injected humour and the like)."

                                                                          "It is a long established fact that a reader will be distracted by the readable content "
                                                                          "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
                                                                          "more - or - less normal distribution of letters, as opposed to using "
                                                                          "Content here, content here, making it look like readable English."
                                                                          "Many desktop publishing packages and page editors now use Lorem Ipsum as their"
                                                                          "default model text, and a search for lorem ipsum will uncover many web sites still "
                                                                          "in their infancy.Various versions have evolved over the years, sometimes by accident, "
                                                                          "sometimes on purpose(injected humour and the like)."
                                                                          "It is a long established fact that a reader will be distracted by the readable content "
                                                                          "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
                                                                          "more - or - less normal distribution of letters, as opposed to using "
                                                                          "Content here, content here, making it look like readable English."
                                                                          "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
                                                                          "default model text, and a search for lorem ipsum will uncover many web sites still "
                                                                          "in their infancy.Various versions have evolved over the years, sometimes by accident, "
                                                                          "sometimes on purpose(injected humour and the like)."
                                                                          "It is a long established fact that a reader will be distracted by the readable content "
                                                                          "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
                                                                          "more - or - less normal distribution of letters, as opposed to using "
                                                                          "Content here, content here, making it look like readable English."
                                                                          "Many desktop publishing packages and  editors now use Lorem Ipsum as their"
                                                                          "default model text, and a search for lorem ipsum will uncover many web sites still "
                                                                          "in their infancy.Various versions have evolved over the years, sometimes by accident, "
                                                                          "sometimes on purpose(injected humour and the like).";
  auto pocet = numberOfWords(text);
  ASSERT_EQ(pocet, 728);
  char *word = new char[256];
  std::string temp("their");
  ASSERT_EQ(temp, copyNthWord(text, word, 709));
  temp = "infancy";
  ASSERT_EQ(temp, copyNthWord(text, word, 710));
  if (word != nullptr) {
    delete[] word;
  }
}

TEST(TestDruhejUlohy, CistyKod) {
  char *word = new char[256];
  std::string temp("druhy");
  ASSERT_EQ(temp, copyNthWord("prvy druhy treti", word, 2));
  if (word != nullptr) {
    delete[] word;
  }
}
