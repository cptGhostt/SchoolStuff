#include "gtest/gtest.h"

using namespace std;

#include "3_Company.h"

using namespace ::testing;

TEST(TestThirdTask, CompanyEmpty) {
	Company comp;
	ASSERT_EQ("Empty company", comp.getName());
	ASSERT_EQ(0, comp.getDateCreated().year);
	ASSERT_EQ(0, comp.getDateCreated().month);
	ASSERT_EQ(0, comp.getDateCreated().day);
}

TEST(TestThirdTask, Company) {
	Company comp("Tesla", Date(2003, 7, 1));
	ASSERT_EQ("Tesla", comp.getName());
	ASSERT_EQ(2003, comp.getDateCreated().year);
	ASSERT_EQ(7, comp.getDateCreated().month);
	ASSERT_EQ(1, comp.getDateCreated().day);
}

TEST(TestThirdTask, CompanyEmptyName) {
	string message;
	try {
		Company comp("", Date(2003, 7, 1));
	} catch (const ReadException &e) {
		message = e.what();
	}
	ASSERT_EQ("Name is empty", message);
}

TEST(TestThirdTask, CompanyAddEmployee) {
	Company comp("Tesla", Date(2003, 7, 1));
	comp.addEmployee("Elon Musk", 20000, Employee::Position::POS_CEO);
	ASSERT_EQ(1, comp.getEmployees().size());
	ASSERT_EQ("Elon Musk", comp.getEmployees()[0].getName());
}

TEST(TestThirdTask, CompanyAddEmployeeMove) {
	Company comp("Tesla", Date(2003, 7, 1));
	Employee emp("Elon Musk", 20000, Employee::Position::POS_CEO);
	comp.addEmployee(move(emp));
	ASSERT_EQ(1, comp.getEmployees().size());
	ASSERT_EQ("Elon Musk", comp.getEmployees()[0].getName());
	ASSERT_EQ("", emp.getName());
	ASSERT_EQ(0, emp.getSalary());
}

TEST(TestThirdTask, CompanyAddProject) {
	Company comp("Tesla", Date(2003, 7, 1));
	comp.addProject("S", Date(2012, 6, 22));
	ASSERT_EQ(1, comp.getProjects().size());
	ASSERT_EQ("S", comp.getProjects()[0].name);
}

TEST(TestThirdTask, CompanyAddProjectMove) {
	Company comp("Tesla", Date(2003, 7, 1));
	Project proj("S", Date(2012, 6, 22));
	comp.addProject(move(proj));
	ASSERT_EQ(1, comp.getProjects().size());
	ASSERT_EQ("S", comp.getProjects()[0].name);
	ASSERT_EQ("", proj.name);
}

TEST(TestThirdTask, CompanyMove) {
	Company comp1("Tesla", Date(2003, 7, 1));
	comp1.addEmployee("Elon Musk", 20000, Employee::Position::POS_CEO);
	comp1.addProject("S", Date(2012, 6, 22));
	Company comp2 = move(comp1);
	ASSERT_EQ("Tesla", comp2.getName());
	ASSERT_EQ(2003, comp2.getDateCreated().year);
	ASSERT_EQ(7, comp2.getDateCreated().month);
	ASSERT_EQ(1, comp2.getDateCreated().day);

	ASSERT_EQ(1, comp2.getEmployees().size());
	ASSERT_EQ("Elon Musk", comp2.getEmployees()[0].getName());

	ASSERT_EQ(1, comp2.getProjects().size());
	ASSERT_EQ("S", comp2.getProjects()[0].name);

	ASSERT_EQ("", comp1.getName());
	ASSERT_EQ(0, comp1.getDateCreated().year);
	ASSERT_EQ(0, comp1.getEmployees().size());
	ASSERT_EQ(0, comp1.getProjects().size());
}

TEST(TestThirdTask, CompanyFindEmployee) {
	Company comp("Tesla", Date(2003, 7, 1));
	comp.addEmployee("Elon Musk", 20000, Employee::Position::POS_CEO);
	const Employee &emp = comp.findEmployeeByName("Elon Musk");
	ASSERT_EQ("Elon Musk", emp.getName());
}

TEST(TestThirdTask, CompanyFindEmployeeFail) {
	Company comp("Tesla", Date(2003, 7, 1));
	comp.addEmployee("Elon Musk", 20000, Employee::Position::POS_CEO);
	string message;
	try {
		const Employee &emp = comp.findEmployeeByName("Mark Zuckerberg");
	} catch (const FindException &e) {
		message = e.what();
	} catch (...) {

	}
	ASSERT_EQ("There is no such employee", message);
}

TEST(TestThirdTask, CompanyFindProject) {
	Company comp("Tesla", Date(2003, 7, 1));
	comp.addProject("S", Date(2012, 6, 22));
	const Project &proj = comp.findProjectByName("S");
	ASSERT_EQ("S", proj.name);
}

TEST(TestThirdTask, CompanyFindProjectFail) {
	Company comp("Tesla", Date(2003, 7, 1));
	comp.addProject("S", Date(2012, 6, 22));
	string message;
	try {
		const Project &proj = comp.findProjectByName("M");
	} catch (const FindException &e) {
		message = e.what();
	} catch (...) {

	}
	ASSERT_EQ("There is no such project", message);
}

TEST(TestThirdTask, CompanyMonthlyIncome) {
	Company comp("Tesla", Date(2003, 7, 1));
	Project proj1("S", Date(2012, 6, 22));
	proj1.income = 200000;
	Project proj2("X", Date(2015, 9, 1));
	proj2.income = 300000;
	Project proj3("3", Date(2016, 3, 31));
	proj3.soldFor = 20000000;
	comp.addProject(move(proj1));
	comp.addProject(move(proj2));
	comp.addProject(move(proj3));

	ASSERT_EQ(500000, comp.getMonthlyIncome());
}

TEST(TestThirdTask, CompanyTotalIncome) {
	Company comp("Tesla", Date(2003, 7, 1));
	Project proj1("S", Date(2012, 6, 22));
	proj1.income = 200000;
	Project proj2("X", Date(2015, 9, 1));
	proj2.income = 300000;
	Project proj3("3", Date(2016, 3, 31));
	proj3.income = 300000;
	proj3.soldFor = 20000000;
	comp.addProject(move(proj1));
	comp.addProject(move(proj2));
	comp.addProject(move(proj3));

	ASSERT_EQ(20500000, comp.getTotalIncome());
}

TEST(TestThirdTask, CompanyMonthlyBalance) {
	Company comp("Tesla", Date(2003, 7, 1));
	Project proj1("S", Date(2012, 6, 22));
	proj1.income = 200000;
	Project proj2("X", Date(2015, 9, 1));
	proj2.income = 300000;
	Project proj3("3", Date(2016, 3, 31));
	proj3.income = 300000;
	proj3.soldFor = 20000000;
	comp.addProject(move(proj1));
	comp.addProject(move(proj2));
	comp.addProject(move(proj3));

	comp.addEmployee("Elon Musk", 200000, Employee::Position::POS_CEO);

	ASSERT_EQ(300000, comp.getMonthlyBalance());
}