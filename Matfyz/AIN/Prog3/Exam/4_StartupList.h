#pragma once

#include <vector>
#include <algorithm>
#include <set>

#include "3_Company.h"

class StartupList {
	std::vector<Company> startups;

public:
	void enlist(Company &&startup);
	void sortByBalance();
	void removeStartupsWithoutPotential();

	// Provided
	size_t getSize() const { return startups.size(); }
	Company &operator [](size_t idx) { return startups[idx]; }

	// Task 5
	void loadFromFile(const std::string &fileName);
};