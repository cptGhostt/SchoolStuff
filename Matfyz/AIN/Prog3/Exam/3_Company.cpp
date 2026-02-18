#include <algorithm>
#include <numeric>

#include "3_Company.h"

using namespace std;

static const int DUMMY_INT = -1;
static const Employee DUMMY_EMPLOYEE;
static const Project DUMMY_PROJECT;

Company::Company() {
	name = "Empty company";
	dateCreated = Date(0, 0, 0);
}

Company::Company(const string &name, Date dateCreated) {
	if (name.empty()) {
		throw ReadException("Name is empty");
	}
	this->name = name;
	this->dateCreated = Date(dateCreated.year, dateCreated.month, dateCreated.day);
}

void Company::addEmployee(const string &name, int salary, Employee::Position position) {
	employees.push_back(Employee(name, salary, position));
};

void Company::addEmployee(Employee &&employee) {
	employees.push_back(std::move(employee));
}

void Company::addProject(const string &name, const Date created) {
	projects.push_back(Project(name, created));
}

void Company::addProject(Project &&project) {
	projects.push_back(std::move(project));
}

Company::Company(Company &&company) {
	name = move(company.name);
	dateCreated = Date(company.dateCreated.year, company.dateCreated.month, company.dateCreated.day);
	projects = move(company.projects);
	employees = move(company.employees);

	company.dateCreated = Date(0, 0, 0);
}

const Employee &Company::findEmployeeByName(const string &name) const {
	std::vector<Employee>::const_iterator it = employees.begin();

	while (it != employees.end()) {
		if (it->getName() == name) {
			return *it;
		}
		it++;
	}

	throw FindException("There is no such employee");
}

const Project &Company::findProjectByName(const string &name) const {
	std::vector<Project>::const_iterator it = projects.begin();

	while (it != projects.end()) {
		if (it->name == name) {
			return *it;
		}
		it++;
	}

	throw FindException("There is no such project");
}

int Company::getMonthlyIncome() const {
	int monthlyIncome = 0;

	for (int i = 0; i < projects.size(); i++) {
		if (projects[i].soldFor == 0) {
			monthlyIncome += projects[i].income;
		}
	}

	return monthlyIncome;
}

int Company::getTotalIncome() const {
	int totalIncome = 0;

	for (int i = 0; i < projects.size(); i++) {
		if (projects[i].soldFor == 0) {
			totalIncome += projects[i].income;
		} else {
			totalIncome += projects[i].soldFor;
		}
	}

	return totalIncome;
}

int Company::getMonthlyBalance() const {
	int monthlyBalance = getMonthlyIncome();

	for (int i = 0; i < employees.size(); i++) {
		monthlyBalance -= employees[i].getSalary();
	}

	return monthlyBalance;
}