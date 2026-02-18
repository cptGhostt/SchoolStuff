#pragma once

#include <vector>

#include "1_Project.h"
#include "2_Employee.h"

class FindException : std::exception {
public:
	FindException(const std::string &message) : message(message) {}
	const char *what() const noexcept override { return message.c_str(); }
private:
	std::string message;
};

class Company {
	std::string name;
	Date dateCreated;
	std::vector<Project> projects;
	std::vector<Employee> employees;

public:
	Company();
	Company(const std::string &name, Date dateCreated);

	void addEmployee(const std::string &name, int salary, Employee::Position position);
	void addEmployee(Employee &&employee);
	void addProject(const std::string &name, Date created);
	void addProject(Project &&project);

	Company(Company &&company);

	const Employee &findEmployeeByName(const std::string &name) const;
	const Project &findProjectByName(const std::string &name) const;
	bool removeEmployee(const Employee &employee);

	int getMonthlyIncome() const;
	int getTotalIncome() const;
	int getMonthlyBalance() const;

	bool operator <(const Company &other) const;

	// Provided
	Company(const Company &company) = default;
	Company &operator =(const Company &) = default;
	const std::string &getName() const { return name; }
	const std::vector<Project> &getProjects() const { return projects; }
	std::vector<Employee> &getEmployees() { return employees; }
	const Date &getDateCreated() const { return dateCreated; }


	// Task 4
	void transferEmployeeToCompany(const Employee &employee, Company &company);
	bool makeOfferFromCompany(const Employee &employee, Company &company, int offeredSalary);

	// Task 5
	friend std::istream &operator >>(std::istream &ist, Company &company);
};