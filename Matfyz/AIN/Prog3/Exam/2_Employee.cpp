#include "2_Employee.h"

using namespace std;

static const bool DUMMY_BOOL = false;

Employee::Employee() {
	name = "Empty employee";
	salary = 0;
	position = Position::POS_NONE;
}

Employee::Employee(const string &name, int salary, Employee::Position position) {
	if (name.empty()) {
		throw ReadException("Name is empty");
	}
	if (salary < MIN_SALARY) {
		throw ReadException("Salary is lower than minimum");
	}

	this->name = name;
	this->salary = salary;
	this->position = position;
}

Employee::Employee(Employee &&employee) {
	name = move(employee.name);
	salary = employee.salary;
	position = employee.position;
	projects = move(employee.projects);

	employee.salary = 0;
	employee.position = Position::POS_NONE;
}

void Employee::setName(const string &newName) {
	if (newName.empty()) {
		throw ReadException("Name is empty");
	}
	name = newName;
}

void Employee::setSalary(int newSalary) {
	if (newSalary < MIN_SALARY) {
		throw ReadException("Salary is lower than minimum");
	}
	salary = newSalary;
}

bool Employee::addActiveProject(const string &name) {
	if (projects.find(name) != projects.end()) {
		return false;
	}

	projects.insert(name);

	if (projects.find(name) == projects.end()) {
		return false;
	}
	return true;
}

void Employee::clearProjects() {
	projects.clear();
}