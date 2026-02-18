// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

#include "3_Concert.h"

using namespace ::testing;

//3. uloha
TEST(TestThirdTask, Udalost) {
	std::vector<std::pair<int, int> > numberOfTickets;
	Concert concert(numberOfTickets);
	ASSERT_EQ(0, concert.allTickets());
}

TEST(TestThirdTask, UdalostPocet) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(12, 5));
	Concert concert(numberOfTickets);
	ASSERT_EQ(12, concert.allTickets());
    ASSERT_EQ(12, concert.allTickets(5));
    ASSERT_EQ(0, concert.allTickets(2));
}

TEST(TestThirdTask, ZapornyPocet) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(-3, 5));
	Concert concert(numberOfTickets);
	ASSERT_EQ(0, concert.allTickets());
}

TEST(TestThirdTask, UdalostPocetVolnych) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(10, 5));
	Concert concert(numberOfTickets);
	ASSERT_EQ(10, concert.availableTickets());
}

TEST(TestThirdTask, KupitListokNaKoncert) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(10, 5));
	Concert concert(numberOfTickets);
	ASSERT_TRUE(concert.sellTickets(1, 5));
}

TEST(TestThirdTask, KupitListokbezListka) {
	std::vector<std::pair<int, int> > numberOfTickets;
	Concert concert(numberOfTickets);
	ASSERT_FALSE(concert.sellTickets(1, 10));
}

TEST(TestThirdTask, KupitViacAkoJe) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(1, 5));
	Concert concert(numberOfTickets);
	ASSERT_TRUE(concert.sellTickets(1, 5));
	ASSERT_FALSE(concert.sellTickets(1, 5));
}

TEST(TestThirdTask, JeEsteVolnyListok) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(2, 5));
	Concert concert(numberOfTickets);
	ASSERT_TRUE(concert.sellTickets(2, 5));
	ASSERT_EQ(0, concert.availableTickets());
}

TEST(TestThirdTask, PocetVolnych) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(5, 10));
	numberOfTickets.push_back(std::pair<int, int>(5, 10));
	Concert concert(numberOfTickets);
  concert.sellTickets(2, 10);
	ASSERT_FALSE(concert.sellTickets(3, 20));
  concert.sellTickets(1, 10);
	ASSERT_EQ(7, concert.availableTickets());
}

TEST(TestThirdTask, JeEsteNaKupu) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(3, 15));
	Concert concert(numberOfTickets);
  concert.sellTickets(2, 15);
	ASSERT_FALSE(concert.sellTickets(1, 5));
	ASSERT_TRUE(concert.sellTickets(1, 15));
}

TEST(TestThirdTask, JeEsteNaKupuMalo) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(5, 25));
	Concert concert(numberOfTickets);
  concert.sellTickets(5, 25);
	ASSERT_FALSE(concert.sellTickets(1, 25));
}

TEST(TestThirdTask, ViacParovSRovnakouCenou) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(25, 5));
	numberOfTickets.push_back(std::pair<int, int>(25, 10));
	numberOfTickets.push_back(std::pair<int, int>(25, 5));
	numberOfTickets.push_back(std::pair<int, int>(25, 25));
	Concert concert(numberOfTickets);
	ASSERT_EQ(100, concert.allTickets());
}

TEST(TestThirdTask, kupaListkovSCenami) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(25, 5));
	numberOfTickets.push_back(std::pair<int, int>(25, 10));
	numberOfTickets.push_back(std::pair<int, int>(25, 15));
	numberOfTickets.push_back(std::pair<int, int>(25, 25));
	Concert concert(numberOfTickets);
	ASSERT_EQ(100, concert.allTickets());
    concert.sellTickets(25, 25);
	ASSERT_FALSE(concert.sellTickets(1, 25));
    concert.sellTickets(5, 5);
    concert.sellTickets(7, 15);
	ASSERT_TRUE(concert.sellTickets(20, 5));
	ASSERT_FALSE(concert.sellTickets(1, 5));
	ASSERT_TRUE(concert.sellTickets(15, 15));
	ASSERT_EQ(72, concert.soldTicketsAll());
	ASSERT_TRUE(concert.sellTickets(2, 15));
	ASSERT_TRUE(concert.sellTickets(1, 15));
	ASSERT_FALSE(concert.sellTickets(1, 15));
	ASSERT_EQ(75, concert.soldTicketsAll());
    ASSERT_EQ(25, concert.allTickets(25));
}

TEST(TestThirdTask, KupitListy) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(25, 5));
	numberOfTickets.push_back(std::pair<int, int>(25, 10));
	numberOfTickets.push_back(std::pair<int, int>(25, 5));
	numberOfTickets.push_back(std::pair<int, int>(25, 25));
	Concert concert(numberOfTickets);
    concert.sellTickets(44, 5);
	ASSERT_EQ(56, concert.availableTickets());
}

TEST(TestThirdTask, KupitListyPrivela) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(25, 5));
	numberOfTickets.push_back(std::pair<int, int>(25, 10));
	numberOfTickets.push_back(std::pair<int, int>(25, 5));
	numberOfTickets.push_back(std::pair<int, int>(25, 25));
	Concert concert(numberOfTickets);
    concert.sellTickets(51, 5);
	ASSERT_EQ(100, concert.availableTickets());
}

TEST(TestThirdTask, KupitListy72) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(25, 25));
	numberOfTickets.push_back(std::pair<int, int>(25, 10));
	numberOfTickets.push_back(std::pair<int, int>(25, 25));
	numberOfTickets.push_back(std::pair<int, int>(25, 25));
	Concert concert(numberOfTickets);
    concert.sellTickets(72, 25);
	ASSERT_EQ(28, concert.availableTickets());
}

TEST(TestThirdTask, KontrolaKupenychListkov) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(25, 5));
	numberOfTickets.push_back(std::pair<int, int>(25, 10));
	numberOfTickets.push_back(std::pair<int, int>(25, 15));
	numberOfTickets.push_back(std::pair<int, int>(25, 25));
	Concert concert(numberOfTickets);
	ASSERT_EQ(100, concert.allTickets());
    concert.sellTickets(25, 25);
	ASSERT_FALSE(concert.sellTickets(1, 25));
	concert.sellTickets(5, 5);
	concert.sellTickets(7, 15);
	concert.sellTickets(10, 5);
	concert.sellTickets(15, 15);
	ASSERT_EQ(62, concert.soldTicketsAll());
	ASSERT_TRUE(concert.sellTickets(2, 15));
	ASSERT_TRUE(concert.sellTickets(10, 5));
	ASSERT_TRUE(concert.sellTickets(1, 15));
	ASSERT_FALSE(concert.sellTickets(1, 15));
	ASSERT_FALSE(concert.sellTickets(1, 5));
	ASSERT_EQ(75, concert.soldTicketsAll());
}

TEST(TestThirdTask, KontrolaKupenychListkov2) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(25, 5));
	numberOfTickets.push_back(std::pair<int, int>(25, 10));
	numberOfTickets.push_back(std::pair<int, int>(25, 15));
	numberOfTickets.push_back(std::pair<int, int>(25, 25));
	Concert concert(numberOfTickets);
	ASSERT_EQ(100, concert.allTickets());
    concert.sellTickets(25, 25);
	ASSERT_FALSE(concert.sellTickets(1, 25));
    concert.sellTickets(5, 5);
    concert.sellTickets(7, 15);
	ASSERT_TRUE(concert.sellTickets(10, 5));
	ASSERT_TRUE(concert.sellTickets(15, 15));
	ASSERT_EQ(62, concert.soldTicketsAll());
	ASSERT_TRUE(concert.sellTickets(2, 15));
	ASSERT_TRUE(concert.sellTickets(10, 5));
	ASSERT_TRUE(concert.sellTickets(1, 15));
	ASSERT_FALSE(concert.sellTickets(1, 15));
	ASSERT_FALSE(concert.sellTickets(1, 5));
	ASSERT_EQ(75, concert.soldTicketsAll());
}

TEST(TestThirdTask, KontrolaKupenychListkov3) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(20, 10));
	numberOfTickets.push_back(std::pair<int, int>(25, 15));
	numberOfTickets.push_back(std::pair<int, int>(25, 25));
	Concert concert(numberOfTickets);
	ASSERT_EQ(70, concert.allTickets());
	ASSERT_TRUE(concert.sellTickets(10, 10));
	ASSERT_TRUE(concert.sellTickets(5, 10));
	ASSERT_FALSE(concert.sellTickets(10, 10));
    ASSERT_TRUE(concert.sellTickets(3, 15));
	ASSERT_TRUE(concert.sellTickets(2, 10));
	ASSERT_FALSE(concert.sellTickets(4, 10));
	ASSERT_TRUE(concert.sellTickets(1, 10));
	ASSERT_FALSE(concert.sellTickets(3, 10));
	ASSERT_TRUE(concert.sellTickets(1, 10));
	ASSERT_EQ(22, concert.soldTicketsAll());
	ASSERT_EQ(48, concert.availableTickets());
    ASSERT_EQ(1, concert.availableTickets(10));
    ASSERT_EQ(22, concert.availableTickets(15));
    ASSERT_EQ(25, concert.availableTickets(25));
}

TEST(TestThirdTask, VsetkyPredaneListky) {
	std::vector<std::pair<int, int> > numberOfTickets;
	numberOfTickets.push_back(std::pair<int, int>(20, 10));
	numberOfTickets.push_back(std::pair<int, int>(25, 15));
	numberOfTickets.push_back(std::pair<int, int>(25, 25));
	Concert concert(numberOfTickets);
	ASSERT_EQ(70, concert.allTickets());
	ASSERT_TRUE(concert.sellTickets(10, 10));
	ASSERT_TRUE(concert.sellTickets(5, 10));
	ASSERT_FALSE(concert.sellTickets(10, 10));
	ASSERT_TRUE(concert.sellTickets(3, 10));
	ASSERT_FALSE(concert.sellTickets(3, 10));
	ASSERT_TRUE(concert.sellTickets(1, 10));
	ASSERT_FALSE(concert.sellTickets(3, 10));
	ASSERT_TRUE(concert.sellTickets(1, 10));
	ASSERT_EQ(20, concert.soldTicketsAll());
}

TEST(TestThirdTask, KupitListyPrivelaNaraz) {
    std::vector<std::pair<int, int> > numberOfTickets;
    numberOfTickets.push_back(std::pair<int, int>(25, 5));
    numberOfTickets.push_back(std::pair<int, int>(25, 10));
    numberOfTickets.push_back(std::pair<int, int>(25, 15));
    numberOfTickets.push_back(std::pair<int, int>(25, 25));
    Concert concert(numberOfTickets);
    ASSERT_EQ(100, concert.allTickets());
    ASSERT_EQ(100, concert.availableTickets());
}

TEST(TestThirdTask, KupitRozneListy72) {
    std::vector<std::pair<int, int> > numberOfTickets;
    numberOfTickets.push_back(std::pair<int, int>(25, 25));
    numberOfTickets.push_back(std::pair<int, int>(25, 10));
    numberOfTickets.push_back(std::pair<int, int>(25, 25));
    numberOfTickets.push_back(std::pair<int, int>(25, 25));
    Concert concert(numberOfTickets);
    concert.sellTickets(10, 25);
    concert.sellTickets(22, 10);
    concert.sellTickets( 10, 25);
    concert.sellTickets( 11, 10);
    concert.sellTickets( 30, 25);
    ASSERT_EQ(28, concert.availableTickets());
}
