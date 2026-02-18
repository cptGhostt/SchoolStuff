#include <algorithm>

#include "4_StartupList.h"

using namespace std;

static const bool DUMMY_BOOL = false;

bool Company::removeEmployee(const Employee &employee) {
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i].getName() == employee.getName()
			&& employees[i].getSalary() == employee.getSalary()
			&& employees[i].getPosition() == employee.getPosition()
			&& employees[i].getProjects() == employee.getProjects()) {
			employees.erase(employees.begin() + i);
			return true;
		}
	}
	return false;
}

void Company::transferEmployeeToCompany(const Employee &employee, Company &company) {
	Employee employee1 = move(employee);
	removeEmployee(employee);
	employee1.clearProjects();
	company.addEmployee(move(employee1));
}

bool Company::makeOfferFromCompany(const Employee &employee, Company &company, int offeredSalary) {
	if (employee.getSalary() + 1000 <= offeredSalary) {
		transferEmployeeToCompany(employee, company);
		return true;
	}
	return false;
}

bool Company::operator <(const Company &other) const {
	if (this->getMonthlyBalance() > other.getMonthlyBalance()) {
		return true;
	}
	return false;
}

void StartupList::enlist(Company &&startup) {
	startups.push_back(move(startup));
}

void StartupList::sortByBalance() {
	std::vector<Company> companies;
	while (startups.size() > 0) {
		int max = 0;
		for (int i = 1; i < startups.size(); i++) {
			if (startups[i].getMonthlyBalance() > startups[max].getMonthlyBalance()) {
				max = i;
			}
		}
		companies.push_back(move(startups[max]));
		startups.erase(startups.begin() + max);
	}
	startups = move(companies);
}

void StartupList::removeStartupsWithoutPotential() {
	std::vector<int> indexes;
	for (int i = 0; i < startups.size(); i++) {
		if (startups[i].getMonthlyBalance() < 0) {
			indexes.push_back(i);
		}
	}

	std::sort(indexes.begin(), indexes.end());
	for (int i = 0; i < indexes.size(); i++) {
		startups.erase(startups.begin() + indexes[i]);
	}

	sortByBalance();

	int percentage = startups.size() * 0.2;
	while (startups.size() > percentage) {
		startups.erase(startups.begin() + percentage);
	}

}