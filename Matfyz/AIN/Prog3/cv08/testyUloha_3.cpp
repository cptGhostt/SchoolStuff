// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "3_Subtitles.h"

using namespace ::testing;

//Uloha 3.
TEST(TestThirdTask, TriTitulky) {
    std::string mojTitulok {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
				"\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
	Subtitle titulok;
    titulok.putSubTitle(mojTitulok);
	const std::string mojTitulok2 {"124\n00:03:56,211 --> 00:04:06,123\nTo je riadokTitulku 2."
				"\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
	Subtitle titulok2;
    titulok2.putSubTitle(mojTitulok2);(mojTitulok2);
	const std::string mojTitulok3 {"125\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 3."
				"\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
	Subtitle titulok3;
    titulok3.putSubTitle(mojTitulok3);
		ASSERT_EQ("To je riadokTitulku 32.", titulok3.getTextRow(3));
		ASSERT_EQ("To je riadokTitulku 21.", titulok2.getTextRow(2));
		ASSERT_EQ(123, titulok.getSubtitleNumber());
}
TEST(TestThirdTask, VsetkyTitulkyPocet) {
    const std::string mojTitulok {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
        "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
    const std::string mojTitulok2 {"124\n00:03:56,211 --> 00:04:06,123\nTo je riadokTitulku 2."
        "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
    const std::string mojTitulok3 {"125\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 3."
        "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
    const std::string mojTitulok4 {"126\n06:02:16,488 --> 06:02:18,637\nTo je riadokTitulku 4."
        "\nTo je riadokTitulku 41.\nTo je riadokTitulku 42."};
    Subtitles vsetkyTitulky;
    vsetkyTitulky.putSubtitle(mojTitulok);
    vsetkyTitulky.putSubtitle(mojTitulok2);
    vsetkyTitulky.putSubtitle(mojTitulok3);
    vsetkyTitulky.putSubtitle(mojTitulok4);
    ASSERT_EQ(4, vsetkyTitulky.getNumberOfSubtitles());
}

TEST(TestThirdTask, JedenTitulokPocet) {
    const std::string mojTitulok3 {"125\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 3."
        "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
    Subtitles vsetkyTitulky;
    vsetkyTitulky.putSubtitle(mojTitulok3);
    ASSERT_EQ(1, vsetkyTitulky.getNumberOfSubtitles());
}

TEST(TestThirdTask, ZiadenTitulokPocet) {
    Subtitles vsetkyTitulky;
    ASSERT_EQ(0, vsetkyTitulky.getNumberOfSubtitles());
}

TEST(TestThirdTask, DvaChybneTitulky) {
    const std::string mojTitulok {"123\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 1."
                                  "\nTo je riadokTitulku 11.\nTo je riadokTitulku 12."};
    const std::string mojTitulok2 {"124\n00:03:56,211 --> 00:04:060,123\nTo je riadokTitulku 2."
                                   "\nTo je riadokTitulku 21.\nTo je riadokTitulku 22."};
    const std::string mojTitulok3 {"125\n00:02:16,488 --> 00:02:18,949\nTo je riadokTitulku 3."
                                   "\nTo je riadokTitulku 31.\nTo je riadokTitulku 32."};
    const std::string mojTitulok4 {"126\n06:02:19,488 --> 06:02:18,637\nTo je riadokTitulku 4."
                                   "\nTo je riadokTitulku 41.\nTo je riadokTitulku 42."};
    const std::string mojTitulok5 {"126\n06:02:16,488 --> 06:02:18,637\nTo je riadokTitulku 4."
                                   "\nTo je riadokTitulku 41.\nTo je riadokTitulku 42."};
    Subtitles vsetkyTitulky;
    ASSERT_TRUE(vsetkyTitulky.putSubtitle(mojTitulok));
    ASSERT_FALSE(vsetkyTitulky.putSubtitle(mojTitulok2));
    ASSERT_TRUE(vsetkyTitulky.putSubtitle(mojTitulok3));
    ASSERT_FALSE(vsetkyTitulky.putSubtitle(mojTitulok4));
    ASSERT_TRUE(vsetkyTitulky.putSubtitle(mojTitulok5));
    ASSERT_EQ(3, vsetkyTitulky.getNumberOfSubtitles());
}
