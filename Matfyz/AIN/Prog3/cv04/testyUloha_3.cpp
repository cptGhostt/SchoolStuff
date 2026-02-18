// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace ::testing;

#include "3_GetItemsFromList.h"


TEST(TestTretejUlohy, nullRetazec) {
  int listOfOrders[]{ 0 };
  int numberOfOrders = sizeof(listOfOrders) / sizeof(int);
  std::string temp("");
  ASSERT_EQ(temp, selectWords(nullptr, nullptr, listOfOrders, numberOfOrders));
}

TEST(TestTretejUlohy, prazdnylistOfOrders) {
  int listOfOrders[]{ 0 };
  std::string temp("");
  ASSERT_EQ(temp, selectWords("", nullptr, listOfOrders, 1));
}

TEST(TestTretejUlohy, listOfOrdersBezSlov) {
  int listOfOrders[]{ 0 };
  char *listOfWords = new char[256];
  std::string temp("");
  ASSERT_EQ(temp, selectWords(" ,,, ... ??? ", listOfWords, listOfOrders, 1));
  if (listOfWords != nullptr) delete[] listOfWords;
}

TEST(TestTretejUlohy, jednoSlovo) {
  int listOfOrders[]{ 1 };
  char *listOfWords = new char[256];
  std::string temp("Slovo");
  ASSERT_EQ(temp, selectWords("Slovo", listOfWords, listOfOrders, 1));
  if (listOfWords != nullptr) delete[] listOfWords;
}

TEST(TestTretejUlohy, opakovaneJednoSlovo) {
  int listOfOrders[]{ 1, 1, 1 };
  char *listOfWords = new char[256];
  int numberOfOrders = sizeof(listOfOrders) / sizeof(int);
  std::string temp("Slovo,Slovo,Slovo");
  ASSERT_EQ(temp, selectWords("Slovo", listOfWords, listOfOrders, numberOfOrders));
  if (listOfWords != nullptr) delete[] listOfWords;
}

TEST(TestTretejUlohy, zdvojenyVyberSlov) {
  int listOfOrders[]{ 1,1,2,2,3,3,4,4 };
  char *listOfWords = new char[256];
  int numberOfOrders = sizeof(listOfOrders) / sizeof(int);
  std::string temp("Co,Co,to,to,za,za,veselie,veselie");
  ASSERT_EQ(temp, selectWords("Co to za veselie?", listOfWords, listOfOrders, numberOfOrders));
  if (listOfWords != nullptr) delete[] listOfWords;
}

TEST(TestTretejUlohy, otoceneSlova) {
  int listOfOrders[]{ 4, 3, 2, 1 };
  char *listOfWords = new char[256];
  int numberOfOrders = sizeof(listOfOrders) / sizeof(int);
  std::string temp("veselie,za,to,Co");
  ASSERT_EQ(temp, selectWords("Co to za veselie?", listOfWords, listOfOrders, numberOfOrders));
  if (listOfWords != nullptr) delete[] listOfWords;
}
TEST(TestTretejUlohy, kazdeDruhe) {
  int listOfOrders[]{ 6, 4, 2 };
  char *listOfWords = new char[256];
  int numberOfOrders = sizeof(listOfOrders) / sizeof(int);
  std::string temp("veselie,je,to");
  ASSERT_EQ(temp, selectWords("Co to tu je za veselie?", listOfWords, listOfOrders, numberOfOrders));
  if (listOfWords != nullptr) delete[] listOfWords;
}

TEST(TestTretejUlohy, stvorica) {
  int listOfOrders[]{ 2, 1, 3, 1 };
  char *listOfWords = new char[256];
  int numberOfOrders = sizeof(listOfOrders) / sizeof(int);
  std::string temp("to,Co,za,Co");
  ASSERT_EQ(temp, selectWords("Co to za veselie?", listOfWords, listOfOrders, numberOfOrders));
  if (listOfWords != nullptr) delete[] listOfWords;
}

TEST(TestTretejUlohy, VyberZVelmiDlhehoTextu) {
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
  int listOfOrders[]{ 101, 501, 706, 1 , 6, 7, 8, 9};
  char *listOfWords = new char[256];
  int numberOfOrders = sizeof(listOfOrders) / sizeof(int);
  std::string temp("be,have,sites,Lorem,text,of,the,printing");
  ASSERT_EQ(temp, selectWords(text, listOfWords, listOfOrders, numberOfOrders));
  auto celkovynumberOfOrdersSlov = numberOfWords(text);
  ASSERT_EQ(celkovynumberOfOrdersSlov, 728);
  if (listOfWords != nullptr) delete[] listOfWords;
}

TEST(TestTretejUlohy, slovoMimo) {
  int listOfOrders[]{ 2, 1, 7, 3, 1, 0, 88 };
  char *listOfWords = new char[256];
  int numberOfOrders = sizeof(listOfOrders) / sizeof(int);
  std::string temp("to,Co,za,Co");
  ASSERT_EQ(temp, selectWords("Co to za veselie?", listOfWords, listOfOrders, numberOfOrders));
  if (listOfWords != nullptr) delete[] listOfWords;
}

TEST(TestTretejUlohy, WordOutside) {
    int listOfOrders[]{ 4, 3, 5, -2, 2, 1 };
    char *listOfWords = new char[256];
    int numberOfOrders = sizeof(listOfOrders) / sizeof(int);
    std::string temp("veselie,za,to,Co");
    ASSERT_EQ(temp, selectWords("Co to za veselie?", listOfWords, listOfOrders, numberOfOrders));
    if (listOfWords != nullptr) delete[] listOfWords;
}
