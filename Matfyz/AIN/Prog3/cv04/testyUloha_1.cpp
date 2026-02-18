// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "1_Elements.h"

using namespace ::testing;

//Uloha 1.
TEST(TestPrvejUlohy, numberOfCharNull) {
    ASSERT_EQ(0, numberOChars(nullptr, 'a'));
}

TEST(TestPrvejUlohy, numberOfCharA) {
    ASSERT_EQ(1, numberOChars("A", 'A'));
}

TEST(TestPrvejUlohy, numberOfCharAOut) {
    ASSERT_EQ(2, numberOChars("AA", 'A'));
    ASSERT_NE(0, numberOChars("A", 'A'));
}

TEST(TestPrvejUlohy, numberOfCharNo) {
    ASSERT_EQ(0, numberOChars("A", ' '));
}

TEST(TestPrvejUlohy, numberOfCharIn) {
    ASSERT_EQ(2, numberOChars("Ale som to nasiel", 's'));
}

TEST(TestPrvejUlohy, findSecondSpace) {
    ASSERT_EQ(3, numberOChars("Ale som to nasiel", ' '));
}

TEST(TestPrvejUlohy, numberOfWords5) {
    ASSERT_EQ(5, numberOfWords("Co to je?   Za  co!!!!!?!. "));
}

TEST(TestPrvejUlohy, numberOfWords7) {
    ASSERT_EQ(7, numberOfWords("Co to je?  Za (iba) to  co!!!!!?!. "));
}

TEST(TestPrvejUlohy, numberOfWords6) {
    ASSERT_EQ(6, numberOfWords("  Co?   Oooo!!! !! Je  za co?? Kolko ? "));
}

TEST(TestPrvejUlohy, numberOfWords1) {
    ASSERT_EQ(1, numberOfWords("C"));
}

TEST(TestPrvejUlohy, empty) {
    ASSERT_EQ(0, numberOfWords(""));
}

TEST(TestPrvejUlohy, null) {
    ASSERT_EQ(0, numberOfWords(nullptr));
}

TEST(TestPrvejUlohy, numberOfWords0) {
    ASSERT_EQ(0, numberOfWords(".. ?? ::;"));
}

TEST(TestPrvejUlohy, numberOfNumbers) {
    ASSERT_EQ(5, numberOfWords("12345 54321 12 21 111"));
}

TEST(TestPrvejUlohy, numberOfWordsWithNonLetters) {
    ASSERT_EQ(3, numberOfWords(" Ako\n sa mas? \0Ved to je drina!!!!!"));
}

TEST(TestPrvejUlohy, numberOfWordsWithNonLetters2) {
    ASSERT_EQ(8, numberOfWords(" Ako sa mas?\nVed to je drina////X!!!!!"));
}

TEST(TestPrvejUlohy, numberOfWordsShort) {
    char textShort[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry."
                       "Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an "
                       "unknown printer took a galley of type and scrambled it to make a type specimen book. "
                       "It has survived not only five centuries, but also the leap into electronic typesetting, "
                       "remaining essentially unchanged. It was popularised in the 1960s with the release of "
                       "Letraset sheets containing Lorem Ipsum passages, and more recently with desktop"
                       "publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
    ASSERT_EQ(90, numberOfWords(textShort));
}

TEST(TestPrvejUlohy, numberOfWordsNormalny) {
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
                  "Content here, content here, making it look like readable English. "
                  "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
                  "default model text, and a search for lorem ipsum will uncover many web sites still "
                  "in their infancy.Various versions have evolved over the years, sometimes by accident, "
                  "sometimes on purpose(injected humour and the like)."
                  "It is a long established fact that a reader will be distracted by the readable content "
                  "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
                  "more - or - less normal distribution of letters, as opposed to using "
                  "Content here, content here, making it look like readable English. "
                  "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
                  "default model text, and a search for lorem ipsum will uncover many web sites still "
                  "in their infancy.Various versions have evolved over the years, sometimes by accident, "
                  "sometimes on purpose(injected humour and the like)."
                  "It is a long established fact that a reader will be distracted by the readable content "
                  "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
                  "more - or - less normal distribution of letters, as opposed to using "
                  "Content here, content here, making it look like readable English. "
                  "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
                  "default model text, and a search for lorem ipsum will uncover many web sites still "
                  "in their infancy.Various versions have evolved over the years, sometimes by accident, "
                  "sometimes on purpose(injected humour and the like).";
    ASSERT_EQ(411, numberOfWords(text));
}

TEST(TestPrvejUlohy, numberOfWordsLong) {
    char textLong[] =
            "Lorem Ipsum is simply dummy text of the printing and typesetting industry."
            "Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an "
            "unknown printer took a galley of type and scrambled it to make a type specimen book. "
            "It has survived not only five centuries, but also the leap into electronic typesetting, "
            "remaining essentially unchanged. It was popularised in the 1960s with the release of "
            "Letraset sheets containing Lorem Ipsum passages, and more recently with desktop"
            "publishing software like Aldus PageMaker including versions of Lorem Ipsum."

            "It is a long established fact that a reader will be distracted by the readable content "
            "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
            "more - or - less normal distribution of letters, as opposed to using "
            "Content here, content here, making it look like readable English. "
            "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
            "default model text, and a search for lorem ipsum will uncover many web sites still "
            "in their infancy.Various versions have evolved over the years, sometimes by accident, "
            "sometimes on purpose(injected humour and the like)."
            "It is a long established fact that a reader will be distracted by the readable content "
            "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
            "more - or - less normal distribution of letters, as opposed to using "
            "Content here, content here, making it look like readable English. "
            "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
            "default model text, and a search for lorem ipsum will uncover many web sites still "
            "in their infancy.Various versions have evolved over the years, sometimes by accident, "
            "sometimes on purpose(injected humour and the like)."
            "It is a long established fact that a reader will be distracted by the readable content "
            "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
            "more - or - less normal distribution of letters, as opposed to using "
            "Content here, content here, making it look like readable English. "
            "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
            "default model text, and a search for lorem ipsum will uncover many web sites still "
            "in their infancy.Various versions have evolved over the years, sometimes by accident, "
            "sometimes on purpose(injected humour and the like)."
            "Lorem Ipsum is simply dummy text of the printing and typesetting industry."
            "Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an "
            "unknown printer took a galley of type and scrambled it to make a type specimen book. "
            "It has survived not only five centuries, but also the leap into electronic typesetting, "
            "remaining essentially unchanged. It was popularised in the 1960s with the release of "
            "Letraset sheets containing Lorem Ipsum passages, and more recently with desktop"
            "publishing software like Aldus PageMaker including versions of Lorem Ipsum."

            "It is a long established fact that a reader will be distracted by the readable content "
            "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
            "more - or - less normal distribution of letters, as opposed to using "
            "Content here, content here, making it look like readable English. "
            "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
            "default model text, and a search for lorem ipsum will uncover many web sites still "
            "in their infancy.Various versions have evolved over the years, sometimes by accident, "
            "sometimes on purpose(injected humour and the like)."
            "It is a long established fact that a reader will be distracted by the readable content "
            "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
            "more - or - less normal distribution of letters, as opposed to using "
            "Content here, content here, making it look like readable English. "
            "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
            "default model text, and a search for lorem ipsum will uncover many web sites still "
            "in their infancy.Various versions have evolved over the years, sometimes by accident, "
            "sometimes on purpose(injected humour and the like)."
            "It is a long established fact that a reader will be distracted by the readable content "
            "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
            "more - or - less normal distribution of letters, as opposed to using "
            "Content here, content here, making it look like readable English. "
            "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
            "default model text, and a search for lorem ipsum will uncover many web sites still "
            "in their infancy.Various versions have evolved over the years, sometimes by accident, "
            "sometimes on purpose(injected humour and the like)."
            "Lorem Ipsum is simply dummy text of the printing and typesetting industry."
            "Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an "
            "unknown printer took a galley of type and scrambled it to make a type specimen book. "
            "It has survived not only five centuries, but also the leap into electronic typesetting, "
            "remaining essentially unchanged. It was popularised in the 1960s with the release of "
            "Letraset sheets containing Lorem Ipsum passages, and more recently with desktop"
            "publishing software like Aldus PageMaker including versions of Lorem Ipsum."

            "It is a long established fact that a reader will be distracted by the readable content "
            "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
            "more - or - less normal distribution of letters, as opposed to using "
            "Content here, content here, making it look like readable English. "
            "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
            "default model text, and a search for lorem ipsum will uncover many web sites still "
            "in their infancy.Various versions have evolved over the years, sometimes by accident, "
            "sometimes on purpose(injected humour and the like)."
            "It is a long established fact that a reader will be distracted by the readable content "
            "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
            "more - or - less normal distribution of letters, as opposed to using "
            "Content here, content here, making it look like readable English. "
            "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
            "default model text, and a search for lorem ipsum will uncover many web sites still "
            "in their infancy.Various versions have evolved over the years, sometimes by accident, "
            "sometimes on purpose(injected humour and the like)."
            "It is a long established fact that a reader will be distracted by the readable content "
            "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
            "more - or - less normal distribution of letters, as opposed to using "
            "Content here, content here, making it look like readable English. "
            "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
            "default model text, and a search for lorem ipsum will uncover many web sites still "
            "in their infancy.Various versions have evolved over the years, sometimes by accident, "
            "sometimes on purpose(injected humour and the like)."
            "Lorem Ipsum is simply dummy text of the printing and typesetting industry."
            "Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an "
            "unknown printer took a galley of type and scrambled it to make a type specimen book. "
            "It has survived not only five centuries, but also the leap into electronic typesetting, "
            "remaining essentially unchanged. It was popularised in the 1960s with the release of "
            "Letraset sheets containing Lorem Ipsum passages, and more recently with desktop"
            "publishing software like Aldus PageMaker including versions of Lorem Ipsum."

            "It is a long established fact that a reader will be distracted by the readable content "
            "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
            "more - or - less normal distribution of letters, as opposed to using "
            "Content here, content here, making it look like readable English. "
            "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
            "default model text, and a search for lorem ipsum will uncover many web sites still "
            "in their infancy.Various versions have evolved over the years, sometimes by accident, "
            "sometimes on purpose(injected humour and the like)."
            "It is a long established fact that a reader will be distracted by the readable content "
            "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
            "more - or - less normal distribution of letters, as opposed to using "
            "Content here, content here, making it look like readable English. "
            "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
            "default model text, and a search for lorem ipsum will uncover many web sites still "
            "in their infancy.Various versions have evolved over the years, sometimes by accident, "
            "sometimes on purpose(injected humour and the like)."
            "It is a long established fact that a reader will be distracted by the readable content "
            "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
            "more - or - less normal distribution of letters, as opposed to using "
            "Content here, content here, making it look like readable English. "
            "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
            "default model text, and a search for lorem ipsum will uncover many web sites still "
            "in their infancy.Various versions have evolved over the years, sometimes by accident, "
            "sometimes on purpose(injected humour and the like)."
            "Lorem Ipsum is simply dummy text of the printing and typesetting industry."
            "Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an "
            "unknown printer took a galley of type and scrambled it to make a type specimen book. "
            "It has survived not only five centuries, but also the leap into electronic typesetting, "
            "remaining essentially unchanged. It was popularised in the 1960s with the release of "
            "Letraset sheets containing Lorem Ipsum passages, and more recently with desktop"
            "publishing software like Aldus PageMaker including versions of Lorem Ipsum."

            "It is a long established fact that a reader will be distracted by the readable content "
            "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
            "more - or - less normal distribution of letters, as opposed to using "
            "Content here, content here, making it look like readable English. "
            "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
            "default model text, and a search for lorem ipsum will uncover many web sites still "
            "in their infancy.Various versions have evolved over the years, sometimes by accident, "
            "sometimes on purpose(injected humour and the like)."
            "It is a long established fact that a reader will be distracted by the readable content "
            "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
            "more - or - less normal distribution of letters, as opposed to using "
            "Content here, content here, making it look like readable English. "
            "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
            "default model text, and a search for lorem ipsum will uncover many web sites still "
            "in their infancy.Various versions have evolved over the years, sometimes by accident, "
            "sometimes on purpose(injected humour and the like)."
            "It is a long established fact that a reader will be distracted by the readable content "
            "of a page when looking at its layout.The point of using Lorem Ipsum is that it has a "
            "more - or - less normal distribution of letters, as opposed to using "
            "Content here, content here, making it look like readable English. "
            "Many desktop publishing packages and web page editors now use Lorem Ipsum as their"
            "default model text, and a search for lorem ipsum will uncover many web sites still "
            "in their infancy.Various versions have evolved over the years, sometimes by accident, "
            "sometimes on purpose(injected humour and the like)."

            "Lorem Ipsum is simply dummy text of the printing and typesetting industry."
            "Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an "
            "unknown printer took a galley of type and scrambled it to make a type specimen book. "
            "It has survived not only five centuries, but also the leap into electronic typesetting, "
            "remaining essentially unchanged. It was popularised in the 1960s with the release of "
            "Letraset sheets containing Lorem Ipsum passages, and more recently with desktop"
            "publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
    ASSERT_EQ(2145, numberOfWords(textLong));
}

TEST(TestPrvejUlohy, numberOfWordsIs7) {
    ASSERT_EQ(7, numberOfWords("Co to je zac? Snad nie toto!!!!"));
}

TEST(TestPrvejUlohy, findOne) {
    double data[] {34.5};
    ASSERT_EQ(34.5, *findMaximum(data, 1));
}

TEST(TestPrvejUlohy, findStredny) {
    double data[] {33.3, 11.1, 0.345, 635.2, 324.2};
    ASSERT_EQ(635.2, *findMaximum(data, 5));
}

TEST(TestPrvejUlohy, findNegative) {
    double data[] {-33.3, -11.1, -0.345, -635.2, -324.2};
    ASSERT_EQ(-0.345, *findMaximum(data, 5));
}

TEST(TestPrvejUlohy, findZero) {
    double data[] {-33.3, -11.1, -0.345, -635.2, 0};
    ASSERT_EQ(0, *findMaximum(data, 5));
}
TEST(TestPrvejUlohy, findNothing) {
    ASSERT_EQ(0.0, *findMaximum(nullptr, 5));
}

TEST(TestPrvejUlohy, findFirst) {
    double data[] {333.3, 11.1, 0.123, 235.2, 324.2};
    ASSERT_EQ(333.3, *findMaximum(data, 5));
}

TEST(TestPrvejUlohy, findFirstFromSame) {
    double data[] {123.456, 123.456, 123.456, 123.45600, 123.456000};
    ASSERT_EQ(123.456, *findMaximum(data, 5));
}

//***************************************************
TEST(TestPrvejUlohy, oneNumber) {
    double data[] {34.5};
    ASSERT_EQ(0, findNumber(data, 1, 34.5));
    ASSERT_EQ(-1, findNumber(data, 1, 32.0));
}

TEST(TestPrvejUlohy, middle) {
    double data[] {33.3, 11.1, 0.345, 635.2, 324.2};
    ASSERT_EQ(2, findNumber(data, 5, 0.345));
}

TEST(TestPrvejUlohy, negative) {
    double data[] {-33.3, -11.1, -0.345, -635.2, -324.2};
    ASSERT_EQ(4, findNumber(data, 5, -324.2));
}

TEST(TestPrvejUlohy, zero) {
    double data[] {-33.3, -11.1, -0.345, -635.2, 0};
    ASSERT_EQ(4, findNumber(data, 5, 0.0));
}
TEST(TestPrvejUlohy, nothing) {
    ASSERT_EQ(-1, findNumber(nullptr, 5, 2.0));
}

TEST(TestPrvejUlohy, first) {
    double data[] {333.3, 11.1, 0.123, 11.1, 324.2};
    ASSERT_EQ(1, findNumber(data, 5, 11.1));
}

