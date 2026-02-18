#include <istream>
#include <fstream>

#include "1_Project.h"
#include "2_Employee.h"
#include "3_Company.h"
#include "4_StartupList.h"

using namespace std;

istream &operator >>(istream &ist, Date &date) {
	string year, month, day;
	getline(ist, year, '-');
	getline(ist, month, '-');
	getline(ist, day, ' ');
	string year2, month2, day2;

	for (int i = 0; i < year.length(); i++) {
		if (std::isdigit(year[i]) || year[i] == '-' || year[i] == ' ') {
			if (year[i] != ' ') {
				year2 += year[i];
			}
			continue;
		}
		ist.setstate(ios::failbit);
		return ist;
	}

	for (int i = 0; i < month.length(); i++) {
		if (std::isdigit(month[i]) || month[i] == '-' || month[i] == ' ') {
			if (month[i] != ' ') {
				month2 += month[i];
			}
			continue;
		}
		ist.setstate(ios::failbit);
		return ist;
	}

	for (int i = 0; i < day.length(); i++) {
		if (std::isdigit(day[i]) || day[i] == '-' || day[i] == ' ') {
			if (day[i] != ' ') {
				day2 += day[i];
			}
			continue;
		}
		ist.setstate(ios::failbit);
		return ist;
	}


	if (year2.empty()) {
		return ist;
	}

	date.year = stoi(year2);
	date.month = stoi(month2);
	date.day = stoi(day2);


	return ist;
}

istream &operator >>(istream &ist, Project &project) {
	string name, date, income, soldFor, tmp;
	getline(ist, name, ' ');
	getline(ist, date, ' ');
	getline(ist, income, ' ');
	getline(ist, soldFor, '\n');


	project.name = name;
	istringstream iss(date);
	iss >> project.dateCreated;
	project.income = stoi(income);
	project.soldFor = stoi(soldFor);
	getline(ist, tmp, ' ');


	return ist;
}

istream &operator >>(istream &ist, Employee &employee) {
	string name, salary, position, numberOfProjects, projects, tmp;

	getline(ist, name, '|');
	getline(ist, tmp, ' ');
	getline(ist, salary, ' ');
	getline(ist, position, ' ');
	getline(ist, numberOfProjects, ' ');
	getline(ist, projects, '\n');

	if (projects.empty()) {
		ist.setstate(ios::failbit);
		return ist;
	}
	employee.name = name.substr(0, name.length() - 1);
	employee.salary = stoi(salary);
	if (position == "NONE") {
		employee.position = Employee::Position::POS_NONE;
	} else if (position == "DEVELOPER") {
		employee.position = Employee::Position::POS_DEVELOPER;
	} else if (position == "ARTIST") {
		employee.position = Employee::Position::POS_ARTIST;
	} else if (position == "MANAGER") {
		employee.position = Employee::Position::POS_MANAGER;
	} else if (position == "CEO") {
		employee.position = Employee::Position::POS_CEO;
	} else {
		ist.setstate(ios::failbit);
		return ist;
	}

	int nop = stoi(numberOfProjects);
	string project;
	istringstream iss(projects);
	for (int i = 0; i < nop; i++) {
		getline(iss, project, ' ');
		employee.projects.insert(project);
	}
	getline(ist, project, ' ');
	return ist;
}

istream &operator >>(istream &ist, Company &company) {
	string name, date, numOfProjects, numOfEmployees, tmp;

	getline(ist, name, ' ');
	getline(ist, date, ' ');
	getline(ist, numOfProjects, ' ');
	getline(ist, numOfEmployees, ' ');
	getline(ist, tmp, '\n');

	company.name = name;
	istringstream iss(date);
	iss >> company.dateCreated;


	try {
		for (int i = 0; i < stoi(numOfProjects); i++) {
			string project;
			getline(ist, project, '\n');
			istringstream is(project.substr(0, project.length() - 1));
			Project p;
			is >> p;
			company.projects.push_back(p);
		}
	} catch (...) {
		ist.setstate(ios::failbit);
		return ist;
	}

	try {
		for (int i = 0; i < stoi(numOfEmployees); i++) {
			string employee;
			getline(ist, employee, '\n');
			istringstream is(employee.substr(0, employee.length() - 1));
			Employee e;
			is >> e;
			company.employees.push_back(e);
		}
	} catch (...) {
		ist.setstate(ios::failbit);
		return ist;
	}

	return ist;
}

void StartupList::loadFromFile(const string &fileName) {
	ifstream ifs;
	ifs.open(fileName);
	if (!ifs) {
		throw ReadException("Failed to read the file");
	}

	string company, tmp;
	while (getline(ifs, tmp, '\n')) {
		if (tmp.empty()) {
			Company c;
			istringstream iss(company);
			iss >> c;
			startups.push_back(c);
			tmp = "";
			company = tmp;
			continue;
		}

		if (!company.empty()) {
			company += '\n';
		}
		company += tmp + ' ';
	}
	Company c;
	istringstream iss(company);
	iss >> c;
	startups.push_back(c);
	company = tmp;

	ifs.close();
}