#include "gtest/gtest.h"

using namespace std;

#include "1_Project.h"

using namespace ::testing;

TEST(TestFirstTask, Date) {
	Date date(2025, 1, 2);
	ASSERT_EQ(2025, date.year);
	ASSERT_EQ(1, date.month);
	ASSERT_EQ(2, date.day);
}

TEST(TestFirstTask, DatePrint) {
	Date date(2025, 1, 2);
	ostringstream ostr;
	ostr << date;
	ASSERT_EQ("2025-01-02", ostr.str());
}

TEST(TestFirstTask, DatePrintYearZeros) {
	Date date(14, 1, 2);
	ostringstream ostr;
	ostr << date;
	ASSERT_EQ("0014-01-02", ostr.str());
}

TEST(TestFirstTask, DatePrintAllZeros) {
	Date date(0, 0, 0);
	ostringstream ostr;
	ostr << date;
	ASSERT_EQ("0000-00-00", ostr.str());
}

TEST(TestFirstTask, ProjectEmpty) {
	Project project;
	ASSERT_EQ("Empty project", project.name);
	ostringstream ostr;
	ostr << project.dateCreated;
	ASSERT_EQ("0000-00-00", ostr.str());
	ASSERT_EQ(0, project.income);
	ASSERT_EQ(0, project.soldFor);
}

TEST(TestFirstTask, Project) {
	Project project("LibreOffice", Date(2025, 1, 3));
	ASSERT_EQ("LibreOffice", project.name);
	ostringstream ostr;
	ostr << project.dateCreated;
	ASSERT_EQ("2025-01-03", ostr.str());
	ASSERT_EQ(0, project.income);
	ASSERT_EQ(0, project.soldFor);
}

TEST(TestFirstTask, ProjectMove) {
	Project proj1("Firefox", Date(2025, 2, 28));
	Project proj2 = move(proj1);
	ASSERT_EQ("Firefox", proj2.name);
	ASSERT_EQ(2025, proj2.dateCreated.year);
	ASSERT_EQ("", proj1.name);
	ASSERT_EQ(0, proj1.dateCreated.year);
	ASSERT_EQ(0, proj1.dateCreated.month);
	ASSERT_EQ(0, proj1.dateCreated.day);
}

TEST(TestFirstTask, ProjectPrint) {
	Project project("LibreOffice", Date(2025, 1, 3));
	project.income = 5000;
	project.soldFor = 14000;
	ostringstream ostr;
	ostr << project;
	ASSERT_EQ("LibreOffice 2025-01-03 5000 14000", ostr.str());
}