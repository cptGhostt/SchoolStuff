#include "gtest/gtest.h"

using namespace std;

#include "4_StartupList.h"
using namespace ::testing;

TEST(TestFourthTask, CompanyRemoveEmployee) {
	Company comp("Tesla", Date(2003, 7, 1));
	comp.addEmployee("Elon Musk", 20000, Employee::Position::POS_CEO);
	comp.addEmployee("Bill Gates", 1300, Employee::Position::POS_DEVELOPER);
	const Employee &emp = comp.findEmployeeByName("Elon Musk");
	bool removed = comp.removeEmployee(emp);
	ASSERT_TRUE(removed);
	ASSERT_EQ(1, comp.getEmployees().size());
	const Employee elon("New Elon Musk", 20000, Employee::Position::POS_CEO);
	ASSERT_FALSE(comp.removeEmployee(elon));
}

TEST(TestFourthTask, CompanyTransfer) {
	Company comp1("Tesla", Date(2003, 7, 1));
	comp1.addEmployee("Elon Musk", 20000, Employee::Position::POS_CEO);
	Company comp2("Google", Date(1998, 9, 4));
	comp2.addEmployee("Larry Page", 15000, Employee::Position::POS_CEO);
	comp2.transferEmployeeToCompany(comp2.getEmployees()[0], comp1);
	ASSERT_EQ(2, comp1.getEmployees().size());
	ASSERT_EQ(0, comp2.getEmployees().size());
	ASSERT_EQ("Larry Page", comp1.getEmployees()[1].getName());
}

TEST(TestFourthTask, CompanyMakeOffer) {
	Company comp1("Tesla", Date(2003, 7, 1));
	comp1.addEmployee("Elon Musk", 20000, Employee::Position::POS_CEO);
	Company comp2("Google", Date(1998, 9, 4));
	comp2.addEmployee("Larry Page", 15000, Employee::Position::POS_CEO);
	ASSERT_FALSE(comp2.makeOfferFromCompany(comp2.getEmployees()[0], comp1, 15500));
	ASSERT_TRUE(comp2.makeOfferFromCompany(comp2.getEmployees()[0], comp1, 16000));
	ASSERT_EQ(2, comp1.getEmployees().size());
	ASSERT_EQ(0, comp2.getEmployees().size());
}

TEST(TestFourthTask, CompanyCompare) {
	Company comp1("Tesla", Date(2003, 7, 1));
	Project proj1("S", Date(2012, 6, 22));
	proj1.income = 200000;
	comp1.addProject(move(proj1));

	Company comp2("Tesla2", Date(2003, 7, 1));
	Project proj2("X", Date(2015, 9, 1));
	proj2.income = 300000;
	comp2.addProject(move(proj2));
	comp2.addEmployee("Elon Musk", 200000, Employee::Position::POS_CEO);

	ASSERT_TRUE(comp1 < comp2);
	ASSERT_FALSE(comp2 < comp1);
}

TEST(TestFourthTask, StartupListEnlist) {
	StartupList list;
	Company comp("Tesla", Date(2003, 7, 1));
	list.enlist(move(comp));
	ASSERT_EQ(1, list.getSize());
	ASSERT_EQ("Tesla", list[0].getName());
}

TEST(TestFourthTask, StartupListSort) {
	Company comp1("Google", Date(1998, 9, 4));
	comp1.addEmployee("Larry Page", 15000, Employee::Position::POS_CEO);

	Company comp2("Tesla", Date(2003, 7, 1));
	Project proj1("S", Date(2012, 6, 22));
	proj1.income = 200000;
	comp2.addProject(move(proj1));
	comp2.addEmployee("Elon Musk", 20000, Employee::Position::POS_CEO);

	StartupList list;
	list.enlist(move(comp1));
	list.enlist(move(comp2));
	list.sortByBalance();
	ASSERT_EQ(2, list.getSize());
	ASSERT_EQ("Tesla", list[0].getName());
	ASSERT_EQ("Google", list[1].getName());
}

TEST(TestFourthTask, StartupListRemove) {
	Company comp1("Google", Date(1998, 9, 4));
	comp1.addEmployee("Larry Page", 15000, Employee::Position::POS_CEO);

	Company comp2("Tesla", Date(2003, 7, 1));
	Project proj2("S", Date(2012, 6, 22));
	proj2.income = 20000;
	comp2.addProject(move(proj2));

	Company comp3("Facebook", Date());
	Project proj3;
	proj3.income = 12000;
	comp3.addProject(move(proj3));

	Company comp4("Microsoft", Date());
	Project proj4;
	proj4.income = 18000;
	comp4.addProject(move(proj4));

	Company comp5("Yahoo", Date());
	Project proj5;
	proj5.income = 10000;
	comp5.addProject(move(proj5));

	Company comp6("Apple", Date());
	Project proj6;
	proj6.income = 25000;
	comp6.addProject(move(proj6));

	StartupList list;
	list.enlist(move(comp1));
	list.enlist(move(comp2));
	list.enlist(move(comp3));
	list.enlist(move(comp4));
	list.enlist(move(comp5));
	list.enlist(move(comp6));

	list.removeStartupsWithoutPotential();

	ASSERT_EQ(1, list.getSize());
	ASSERT_EQ("Apple", list[0].getName());
}