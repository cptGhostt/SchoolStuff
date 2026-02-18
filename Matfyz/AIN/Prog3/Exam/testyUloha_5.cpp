#include "gtest/gtest.h"

using namespace std;

#include "4_StartupList.h"

using namespace ::testing;

TEST(TestFifthTask, DateRead) {
	Date date;
	istringstream istr("2025-01-02");
	istr >> date;
	ostringstream ostr;
	ostr << date;
	ASSERT_EQ("2025-01-02", ostr.str());
}

TEST(TestFifthTask, DateReadWrongFormat1) {
	Date date;
	istringstream istr("2025.01.02");
	bool correct = true;
	if (!(istr >> date)) {
		correct = false;
	}
	ASSERT_FALSE(correct);
}

TEST(TestFifthTask, DateReadWrongFormat2) {
	Date date;
	istringstream istr("2025-01.02");
	bool correct = true;
	if (!(istr >> date)) {
		correct = false;
	}
	ASSERT_FALSE(correct);
}

TEST(TestFifthTask, DateReadWrongFormat3) {
	Date date;
	istringstream istr("asdf 2025-01-02");
	bool correct = true;
	if (!(istr >> date)) {
		correct = false;
	}
	ASSERT_FALSE(correct);
}

TEST(TestFifthTask, DateReadMoreDates) {
	Date date1;
	Date date2;
	istringstream istr("  2025-01-02  1993-01-01  ");
	istr >> date1 >> date2;
	ostringstream ostr;
	ostr << date1;
	ostr << ' ';
	ostr << date2;
	ASSERT_EQ("2025-01-02 1993-01-01", ostr.str());
}

TEST(TestFifthTask, ProjectRead) {
	Project project;
	istringstream istr("CLion 2025-01-03 10000 50000");
	istr >> project;
	ostringstream ostr;
	ostr << project;
	ASSERT_EQ("CLion 2025-01-03 10000 50000", ostr.str());
}

TEST(TestFifthTask, ProjectReadTwoProjects) {
	Project proj1;
	Project proj2;
	istringstream istr("CLion 2025-01-03 10000 50000 \n LibreOffice 2025-01-03 5000 14000");
	istr >> proj1 >> proj2;
	ostringstream ostr;
	ostr << proj1 << ' ' << proj2;
	ASSERT_EQ("CLion 2025-01-03 10000 50000 LibreOffice 2025-01-03 5000 14000", ostr.str());
}

TEST(TestFifthTask, EmployeeRead) {
	Employee emp;
	istringstream istr("Elon Musk | 20000 CEO 2 SpaceX Tesla");
	istr >> emp;
	ASSERT_EQ("Elon Musk", emp.getName());
	ASSERT_EQ(20000, emp.getSalary());
	ASSERT_EQ(Employee::Position::POS_CEO, emp.getPosition());
	ASSERT_EQ(2, emp.getProjects().size());
	ASSERT_EQ("SpaceX", *emp.getProjects().cbegin());
}

TEST(TestFifthTask, EmployeeReadFail) {
	Employee emp;
	istringstream istr("Elon Musk 20000 CEO 2 SpaceX Tesla");
	bool read = true;
	if (!(istr >> emp)) {
		read = false;
	}
	ASSERT_FALSE(read);
}

TEST(TestFifthTask, EmployeeReadTwo) {
	Employee emp1;
	Employee emp2;
	istringstream istr("Elon Musk | 20000 CEO 2 SpaceX Tesla \n Mark Zuckerberg | 16000 MANAGER 1 Facebook");
	istr >> emp1 >> emp2;
	ASSERT_EQ("Elon Musk", emp1.getName());
	ASSERT_EQ(2, emp1.getProjects().size());
	ASSERT_EQ("SpaceX", *emp1.getProjects().cbegin());
	ASSERT_EQ("Mark Zuckerberg", emp2.getName());
	ASSERT_EQ(1, emp2.getProjects().size());
	ASSERT_EQ("Facebook", *emp2.getProjects().cbegin());
}

TEST(TestFifthTask, CompanyRead) {
	istringstream ist("Google 1998-09-04 2 2 \n"
							  "Search 1997-09-15 10000 50000 \n"
							  "TensorFlow 2017-02-11 20000 100000 \n"
							  "Larry Page | 15000 CEO 1 Search \n"
							  "Andrew Ng | 20000 DEVELOPER 2 Search TensorFlow");
	Company comp;
	ist >> comp;
	ASSERT_EQ("Google", comp.getName());
	ASSERT_EQ(2, comp.getProjects().size());
	ASSERT_EQ("Search", comp.getProjects()[0].name);
	ASSERT_EQ("TensorFlow", comp.getProjects()[1].name);
	ASSERT_EQ(2, comp.getEmployees().size());
	ASSERT_EQ("Larry Page", comp.getEmployees()[0].getName());
	ASSERT_EQ("Andrew Ng", comp.getEmployees()[1].getName());
	ASSERT_EQ(1, comp.getEmployees()[0].getProjects().size());
	ASSERT_EQ(2, comp.getEmployees()[1].getProjects().size());
}

TEST(TestFifthTask, CompanyReadFailure) {
	istringstream ist("Google 1998-09-04 3 2 \n"
							  "Search 1997-09-15 10000 50000 \n"
							  "TensorFlow 2017-02-11 20000 100000 \n"
							  "Larry Page | 15000 CEO 1 Search \n"
							  "Andrew Ng | 20000 DEVELOPER 2 Search TensorFlow");
	Company comp;
	bool result = true;
	if (!(ist >> comp)) {
		result = false;
	}
	ASSERT_FALSE(result);
}

TEST(TestFifthTask, StartupListLoadNonExistent) {
	StartupList list;
	string message;
	try {
		list.loadFromFile("nonexistent.txt");
	} catch (const ReadException &e) {
		message = e.what();
	}
	ASSERT_EQ("Failed to read the file", message);
}

TEST(TestFifthTask, StartupListLoad) {
	StartupList list;
	bool exception = false;

	try {
		list.loadFromFile("startuplist.txt");
	} catch (...) {
		exception = true;
	}

	ASSERT_FALSE(exception);

	ASSERT_EQ(2, list.getSize());

	ASSERT_EQ("Google", list[0].getName());
	ASSERT_EQ(2, list[0].getProjects().size());
	ASSERT_EQ("Search", list[0].getProjects()[0].name);
	ASSERT_EQ("TensorFlow", list[0].getProjects()[1].name);
	ASSERT_EQ(2, list[0].getEmployees().size());
	ASSERT_EQ("Larry Page", list[0].getEmployees()[0].getName());
	ASSERT_EQ("Andrew Ng", list[0].getEmployees()[1].getName());
	ASSERT_EQ(1, list[0].getEmployees()[0].getProjects().size());
	ASSERT_EQ(2, list[0].getEmployees()[1].getProjects().size());

	ASSERT_EQ("Tesla", list[1].getName());
	ASSERT_EQ(1, list[1].getProjects().size());
	ASSERT_EQ("S", list[1].getProjects()[0].name);
	ASSERT_EQ(2012, list[1].getProjects()[0].dateCreated.year);
	ASSERT_EQ(20000, list[1].getProjects()[0].income);
	ASSERT_EQ(1, list[1].getEmployees().size());
	ASSERT_EQ("Elon Musk", list[1].getEmployees()[0].getName());
	ASSERT_EQ(200000, list[1].getEmployees()[0].getSalary());
	ASSERT_EQ(Employee::Position::POS_CEO, list[1].getEmployees()[0].getPosition());
	ASSERT_EQ(1, list[1].getEmployees()[0].getProjects().size());
	ASSERT_EQ("S", *list[1].getEmployees()[0].getProjects().begin());
}
