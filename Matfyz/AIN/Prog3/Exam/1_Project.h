#pragma once

#include <ostream>
#include <istream>
#include <sstream>

struct Date {
	int day;
	int month;
	int year;

	Date(int year, int month, int day);
	friend std::ostream &operator <<(std::ostream &ost, const Date &date);

	// Provided
	Date() = default;

	// Task 5
	friend std::istream &operator >>(std::istream &ist, Date &date);
};

struct Project {
	std::string name;
	Date dateCreated;
	int income = 0;
	int soldFor = 0;

public:
	Project();
	Project(const std::string &name, Date created);
	Project(Project &&project);
	friend std::ostream &operator <<(std::ostream &ost, const Project &project);

	// Provided
	Project(const Project &) = default;
	Project& operator=(const Project &) = default;

	// Task 5
	friend std::istream &operator >>(std::istream &ist, Project &project);
};