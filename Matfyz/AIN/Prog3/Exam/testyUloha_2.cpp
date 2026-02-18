#include "gtest/gtest.h"

using namespace std;

#include "2_Employee.h"

using namespace ::testing;

TEST(TestSecondTask, EmployeeEmpty) {
	Employee emp;
	ASSERT_EQ("Empty employee", emp.getName());
	ASSERT_EQ(0, emp.getSalary());
	ASSERT_EQ(Employee::Position::POS_NONE, emp.getPosition());
}

TEST(TestSecondTask, Employee) {
	Employee emp("Elon Musk", 20000, Employee::Position::POS_CEO);
	ASSERT_EQ("Elon Musk", emp.getName());
	ASSERT_EQ(20000, emp.getSalary());
	ASSERT_EQ(Employee::Position::POS_CEO, emp.getPosition());
}

TEST(TestSecondTask, EmployeeEmptyName) {
	string message;
	try {
		Employee emp("", 20000, Employee::Position::POS_ARTIST);
	} catch (const ReadException &e) {
		message = e.what();
	}
	ASSERT_EQ("Name is empty", message);
}

TEST(TestSecondTask, EmployeeLowSalary) {
	string message;
	try {
		Employee emp("Elon Musk", 300, Employee::Position::POS_ARTIST);
	} catch (const ReadException &e) {
		message = e.what();
	}
	ASSERT_EQ("Salary is lower than minimum", message);
}

TEST(TestSecondTask, EmployeeMove) {
	Employee emp1("Elon Musk", 20000, Employee::Position::POS_CEO);
	Employee emp2 = move(emp1);
	ASSERT_EQ("Elon Musk", emp2.getName());
	ASSERT_EQ(20000, emp2.getSalary());
	ASSERT_EQ(Employee::Position::POS_CEO, emp2.getPosition());
	ASSERT_EQ("", emp1.getName());
	ASSERT_EQ(0, emp1.getSalary());
	ASSERT_EQ(Employee::Position::POS_NONE, emp1.getPosition());
}

TEST(TestSecondTask, EmployeeSetNameEmpty) {
	string message;
	Employee emp;
	try {
		emp.setName("");
	} catch (const ReadException &e) {
		message = e.what();
	}
	ASSERT_EQ("Name is empty", message);
}

TEST(TestSecondTask, EmployeeSetLowSalary) {
	string message;
	Employee emp;
	try {
		Employee emp;
		emp.setSalary(300);
	} catch (const ReadException &e) {
		message = e.what();
	}
	ASSERT_EQ("Salary is lower than minimum", message);
}

TEST(TestSecondTask, EmployeeAddProject) {
	Employee emp("Elon Musk", 20000, Employee::Position::POS_CEO);
	bool added = emp.addActiveProject("SpaceX");
	ASSERT_TRUE(added);
	ASSERT_EQ(1, emp.getProjects().size());
	ASSERT_EQ("SpaceX", *emp.getProjects().cbegin());
	ASSERT_FALSE(emp.addActiveProject("SpaceX"));
}

TEST(TestSecondTask, EmployeeClearProjects) {
	Employee emp("Elon Musk", 20000, Employee::Position::POS_CEO);
	emp.addActiveProject("SpaceX");
	emp.clearProjects();
	ASSERT_EQ(0, emp.getProjects().size());
}

TEST(TestSecondTask, EmployeeMoveProjects) {
	Employee emp1("Elon Musk", 20000, Employee::Position::POS_CEO);
	emp1.addActiveProject("SpaceX");
	Employee emp2 = move(emp1);
	ASSERT_EQ(1, emp2.getProjects().size());
	ASSERT_EQ("SpaceX", *emp2.getProjects().cbegin());
	ASSERT_EQ(0, emp1.getProjects().size());
}