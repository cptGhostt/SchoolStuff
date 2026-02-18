#include <iomanip>

#include "1_Project.h"

using namespace std;

Date::Date(int year, int month, int day) :year(year), month(month), day(day) {}

ostream &operator <<(ostream &ost, const Date &date) {
	ost << setfill('0') << setw(4) << date.year << "-" << setw(2) << date.month << "-" << setw(2) << date.day;
	return ost;
}

Project::Project() {
	name = "Empty project";
	dateCreated = Date(0, 0, 0);
}

Project::Project(const string &name, Date created) : name(name){
	dateCreated = Date(created.year, created.month, created.day);
}

Project::Project(Project &&project) {
	name = move(project.name);
	dateCreated = Date(project.dateCreated.year, project.dateCreated.month, project.dateCreated.day);
	income = project.income;
	soldFor = project.soldFor;

	project.dateCreated = Date(0, 0, 0);
	project.income = 0;
	project.soldFor = 0;
}

ostream &operator <<(ostream &ost, const Project &project) {
	ost << project.name << ' ' << project.dateCreated << ' '  << project.income << ' '  << project.soldFor;
	return ost;
}