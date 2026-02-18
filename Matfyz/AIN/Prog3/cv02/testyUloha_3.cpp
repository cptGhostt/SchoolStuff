// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"
#include "3_passwordStrength.h"

using namespace ::testing;

//3. uloha
TEST(ThirdTaskTests, PrazdneHeslo) {
	PasswordStrength password = passwordStrength("");
	ASSERT_EQ(password, EMPTY_PASSWORD);
}
TEST(ThirdTaskTests, HesloSMedzerami) {
    PasswordStrength password = passwordStrength("            ");
    ASSERT_EQ(password, EMPTY_PASSWORD);
}
TEST(ThirdTaskTests, HesloSMedzerou) {
    PasswordStrength password = passwordStrength(" ");
    ASSERT_EQ(password, EMPTY_PASSWORD);
}
TEST(ThirdTaskTests, JedenNepovoleneZnaky) {
	PasswordStrength password = passwordStrength("\"");
	ASSERT_EQ(password, NOT_ALLOWED_PASSWORD);
}
TEST(ThirdTaskTests, NepovoleneZnaky) {
	PasswordStrength password = passwordStrength("    \n\n\n\"\\\'");
	ASSERT_EQ(password, NOT_ALLOWED_PASSWORD);
}
TEST(ThirdTaskTests, VelmiSlabeHeslo) {
	PasswordStrength password = passwordStrength("5362342");
	ASSERT_EQ(password, VERY_WEAK_PASSWORD);
}
TEST(ThirdTaskTests, VelmiSlabeHesloPismenove) {
	PasswordStrength password = passwordStrength("aQXXASa");
	ASSERT_EQ(password, VERY_WEAK_PASSWORD);
}
TEST(ThirdTaskTests, SlabeHeslo) {
	PasswordStrength password = passwordStrength("a4Q");
	ASSERT_EQ(password, WEAK_PASSWORD);
}
TEST(ThirdTaskTests, SlabeHesloSNepovolenymZnakom) {
	PasswordStrength password = passwordStrength("aQXX ASa");
	ASSERT_EQ(password, STRONG_PASSWORD);
}
TEST(ThirdTaskTests, JednoCislo) {
	PasswordStrength password = passwordStrength("0");
	ASSERT_EQ(password, VERY_WEAK_PASSWORD);
}
TEST(ThirdTaskTests, JednoPismeno) {
	PasswordStrength password = passwordStrength("Z");
	ASSERT_EQ(password, VERY_WEAK_PASSWORD);
}
TEST(ThirdTaskTests, JedenZnak) {
	PasswordStrength password = passwordStrength("|");
	ASSERT_EQ(password, WEAK_PASSWORD);
}
TEST(ThirdTaskTests, SlabeHesloSCislami) {
	PasswordStrength password = passwordStrength("5362001241342");
	ASSERT_EQ(password, WEAK_PASSWORD);
}
TEST(ThirdTaskTests, SlabeHesloSPismenami) {
	PasswordStrength password = passwordStrength("AbrahamSlovak");
	ASSERT_EQ(password, WEAK_PASSWORD);
}
TEST(ThirdTaskTests, SlabeHesloSPismenami8) {
	PasswordStrength password = passwordStrength("AbswwAss");
	ASSERT_EQ(password, WEAK_PASSWORD);
}
TEST(ThirdTaskTests, SpatneLomitko) {
	PasswordStrength password = passwordStrength("\\");
	ASSERT_EQ(password, NOT_ALLOWED_PASSWORD);
}
TEST(ThirdTaskTests, VelmiSilneHeslo) {
	PasswordStrength password = passwordStrength("aad><435..,Geras");
	ASSERT_EQ(password, VERY_STRONG_PASSWORD);
}
TEST(ThirdTaskTests, IbaSilneHeslo) {
    PasswordStrength password = passwordStrength("aad><435..,geras");
    ASSERT_EQ(password, STRONG_PASSWORD);
}
TEST(ThirdTaskTests, KratkeVelmiSilneHeslo) {
	PasswordStrength password = passwordStrength("aad><4g");
	ASSERT_EQ(password, WEAK_PASSWORD);
}
TEST(ThirdTaskTests, SilneHeslo) {
	PasswordStrength password = passwordStrength("AAAA7865876aad435geras");
	ASSERT_EQ(password, STRONG_PASSWORD);
}
TEST(ThirdTaskTests, SilneHesloSIntmZnakom) {
	PasswordStrength password = passwordStrength("AAAA7865.876aad435geras");
	ASSERT_EQ(password, VERY_STRONG_PASSWORD);
}

