// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "0_Song.h"

using namespace ::testing;

//Uloha 0. Zdedene riesenie
TEST(TestPreviousTask, JednaFraza) {
	Phrase fraza("Em$first day I saw her I knew ");
	ASSERT_EQ("Em", fraza.getPhraseChord());
}

TEST(TestPreviousTask, FrazaBezAkordu) {
	Phrase fraza("From the ");
	ASSERT_EQ("", fraza.getPhraseChord());
	ASSERT_EQ("From the ", fraza.getPhraseText());
}

TEST(TestPreviousTask, CelyVers) {
	Line vers("She #Am$stared in my eyes #B$and smiled");
	ASSERT_EQ(3, vers.numberOfPhrases());
	ASSERT_EQ("Am", vers.getPhraseChord(1));
	ASSERT_EQ("B", vers.getPhraseChord(2));
	ASSERT_EQ("Wrong index", vers.getPhraseChord(-1));
	ASSERT_EQ("and smiled", vers.getPhraseText(2));
	ASSERT_EQ("Wrong index", vers.getPhraseText(99));
	ASSERT_EQ("She #Am$stared in my eyes #B$and smiled", vers.getLine());
}

TEST(TestPreviousTask, PocetFraz) {
	Song p("Where the wild roses grow");
	ASSERT_EQ(1, p.addLine("They #Em$call me the #Am$wild #Em$rose,#G$But my name #B$was Eliza Day"));
	ASSERT_EQ(2, p.addLine("Why they #Em$call me that I #Am$do #Em$not know,"));
	ASSERT_EQ(10, p.numberOfPhrases());
}

TEST(TestPreviousTask, AnalyzaFraz) {
	Song p("Where the wild roses grow");
	ASSERT_EQ(1, p.addLine("They #Em$call me the #Am$wild #Em$rose,#G$But my name #B$was Eliza Day"));
	ASSERT_EQ(2, p.addLine("Why they #Em$call me that I #Am$do #Em$not know,"));
	ASSERT_EQ("$Why they ", p.getPhrase(6));
	ASSERT_EQ("", p.getPhraseChord(6));
  ASSERT_EQ("Am$do ", p.getPhrase(8));
  ASSERT_EQ("Am", p.getPhraseChord(8));
}

TEST(TestPreviousTask, AnalyzaPesnicky) {
	Song p("Where the wild roses grow");
  ASSERT_EQ(1, p.addLine("They #Em$call me the #Am$wild #Em$rose,#G$But my name #B$was Eliza Day"));
  ASSERT_EQ(2, p.addLine("Why they #Em$call me that I #Am$do #Em$not know,"));
	ASSERT_EQ(3, p.addLine("#Em$For my #D$name was #Em$Eliza Day"));
	ASSERT_EQ(4, p.addLine("From the #Em$first day I saw her I knew #G$she was the one"));
	ASSERT_EQ(4, p.numberOfLines());
	ASSERT_EQ("Em", p.getChord(3));
	ASSERT_EQ("Am,B,D,Em,G", p.getListOfChords());
    ASSERT_EQ("Am", p.getChord(0));
	ASSERT_EQ("G", p.getPhraseChord(4));
	ASSERT_EQ("", p.getPhraseChord(0));
	ASSERT_EQ("B", p.getPhraseChord(5));
}

TEST(TestPreviousTask, CelkovyPocetFraz) {
	Song p("Where the wild roses grow");
  p.addLine("They #Em$call me the #Am$wild #Em$rose,#G$But my name #B$was Eliza Day");
	ASSERT_EQ(6, p.numberOfPhrases());
  p.addLine("Why they #Em$call me that I #Am$do #Em$not know,");
	ASSERT_EQ(10, p.numberOfPhrases());
  p.addLine("#Em$For my #D$name was #Em$Eliza Day");
	ASSERT_EQ(13, p.numberOfPhrases());
  p.addLine("From the #Em$first day I saw her I knew #G$she was the one");
	ASSERT_EQ(16, p.numberOfPhrases());
}

TEST(TestPreviousTask, Akordy) {
	Song p("Where the wild roses grow");
  p.addLine("They #Em$call me the #Am$wild #Em$rose,#G$But my name #B$was Eliza Day");
	p.addLine("Why they #Em$call me that I #Am$do #Em$not know,");
	p.addLine("#Em$For my #D$name was #Em$Eliza Day");
	p.addLine("From the #Em$first day I saw her I knew #G$she was the one");
	p.addLine("She #Am$stared in my eyes #B$and smiled");
	ASSERT_EQ("Am,B,D,Em,G", p.getListOfChords());
}

TEST(TestPreviousTask, NacitajSubor) {
	Song p("Where the wild roses grow");
	ASSERT_TRUE(p.readSongFromFile("Where_the_wild_roses_grow.txt"));
	ASSERT_EQ(38, p.numberOfPhrases());
	ASSERT_EQ("Em$call me the ", p.getPhrase(1));
	ASSERT_EQ("Em$For my ", p.getPhrase(11));
}

TEST(TestPreviousTask, NeexistujuciSubor) {
	Song p("Neexistujuci");
	ASSERT_FALSE(p.readSongFromFile("Neexistujuci.txt"));
}

TEST(TestPreviousTask, NacitajRoses) {
	Song p("Where the wild roses grow");
  p.readSongFromFile("Where_the_wild_roses_grow.txt");
	ASSERT_EQ("Am,B,D,Em,G", p.getListOfChords());
}

TEST(TestPreviousTask, RosesPocetVersov) {
	Song p("Where the wild roses grow");
  p.readSongFromFile("Where_the_wild_roses_grow.txt");
	ASSERT_EQ(11, p.numberOfLines());
}

TEST(TestPreviousTask, RosesPocetFraz) {
	Song p("Where the wild roses grow");
  p.readSongFromFile("Where_the_wild_roses_grow.txt");
	ASSERT_EQ(38, p.numberOfPhrases());
}

TEST(TestPreviousTask, RosesVratFrazu10) {
	Song p("Where the wild roses grow");
    p.readSongFromFile("Where_the_wild_roses_grow.txt");
	ASSERT_EQ("Em$rose,", p.getPhrase(3));
}

TEST(TestPreviousTask, RosesVratFrazu37) {
	Song p("Where the wild roses grow");
  p.readSongFromFile("Where_the_wild_roses_grow.txt");
	ASSERT_EQ("B$ran down my face", p.getPhrase(37));
}
