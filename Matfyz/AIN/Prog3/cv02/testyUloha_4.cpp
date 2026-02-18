// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"
#include "4_adaptedPasswordStrength.h"

using namespace ::testing;

TEST(FourthTaskTests, PocetA) {
	ASSERT_EQ(maximumOccurrencesOfSameCharacter("d ea b c b aaaa d"), 6);
}
TEST(FourthTaskTests, IbaMedzery3) {
	ASSERT_EQ(maximumOccurrencesOfSameCharacter("   "), 3);
}
TEST(FourthTaskTests, PrazdnyRetazec0) {
	ASSERT_EQ(maximumOccurrencesOfSameCharacter(""), 0);
}
TEST(FourthTaskTests, Cislice1) {
	ASSERT_EQ(maximumOccurrencesOfSameCharacter("+1234567.890/-*;"), 1);
}
TEST(FourthTaskTests, VselicoX) {
	ASSERT_EQ(maximumOccurrencesOfSameCharacter("DELL, Microsoft, Apple."), 2);
}

TEST(FourthTaskTests, VelmiDlhyText) {
	const char text0[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry."
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
	ASSERT_EQ(maximumOccurrencesOfSameCharacter(text0), 397);
}
TEST(FourthTaskTests, VelmiDlhyText10krat) {
    const char text0[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry."
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
  std::string text = "";
	for (unsigned int i = 0; i < 10; i++) {
		text += text0;
	}
	ASSERT_EQ(maximumOccurrencesOfSameCharacter(text.c_str()), 3970);
}

TEST(FourthTaskTests, DecreasePasswordStrength) {
  ASSERT_EQ(decreasePasswordStrength(WEAK_PASSWORD), VERY_WEAK_PASSWORD);
  ASSERT_EQ(decreasePasswordStrength(STRONG_PASSWORD), WEAK_PASSWORD);
  ASSERT_EQ(decreasePasswordStrength(VERY_STRONG_PASSWORD), STRONG_PASSWORD);
  ASSERT_EQ(decreasePasswordStrength(VERY_WEAK_PASSWORD), VERY_WEAK_PASSWORD);
}

TEST(FourthTaskTests, VelmiSlabeOpakovaneQ) {
  const char heslo[] = "QQQQaQQ";
	ASSERT_EQ(adaptedPasswordStrength(heslo), VERY_WEAK_PASSWORD);
}
TEST(FourthTaskTests, SlabeHesloOpakovane) {
  const char heslo[] = "a4a";
	ASSERT_EQ(adaptedPasswordStrength(heslo), VERY_WEAK_PASSWORD);
}
TEST(FourthTaskTests, SlabeHesloNeopakovane) {
  const char heslo[] = "a4Q";
	ASSERT_EQ(adaptedPasswordStrength(heslo), WEAK_PASSWORD);
}
TEST(FourthTaskTests, OpakovaneSNepovolenymZnakom) {
	const char heslo[] = "XXXX AXa";
	ASSERT_EQ(adaptedPasswordStrength(heslo), WEAK_PASSWORD);
}
TEST(FourthTaskTests, OpakovanyJedenZnak) {
	const char heslo[] = "||";
	ASSERT_EQ(adaptedPasswordStrength(heslo), VERY_WEAK_PASSWORD);
}
TEST(FourthTaskTests, SlabeHesloSCislamiOpakovane6) {
	const char heslo[] = "53620016666666666";
	ASSERT_EQ(adaptedPasswordStrength(heslo), VERY_WEAK_PASSWORD);
}
TEST(FourthTaskTests, SlabeHesloSPismenamiOpakovanea) {
	const char heslo[] = "AbraahaamSlovaaaakaaaaa";
	ASSERT_EQ(adaptedPasswordStrength(heslo), VERY_WEAK_PASSWORD);
}
TEST(FourthTaskTests, SlabeSMenejAkoPolovicous) {
	const char heslo[] = "AbswwAss";
	ASSERT_EQ(adaptedPasswordStrength(heslo), WEAK_PASSWORD);
}
TEST(FourthTaskTests, SlabeHesloSViacs) {
	const char heslo[] = "AsswsAss";
	ASSERT_EQ(adaptedPasswordStrength(heslo), VERY_WEAK_PASSWORD);
}
TEST(FourthTaskTests, VelmiSilneHesloOpakovane) {
	const char heslo[] = "aad><435geras<<<<<<<<<<<<<<<<<";
	ASSERT_EQ(adaptedPasswordStrength(heslo), WEAK_PASSWORD);
}
TEST(FourthTaskTests, KratkeVelmiSilneHesloOpakovane) {
	const char heslo[] = "aad1>>>>>";
	ASSERT_EQ(adaptedPasswordStrength(heslo), WEAK_PASSWORD);
}
