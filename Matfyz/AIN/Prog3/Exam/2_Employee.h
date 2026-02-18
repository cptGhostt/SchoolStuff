#pragma once

#include <string>
#include <set>

const int MIN_SALARY = 500;

class ReadException : std::exception {
public:
	ReadException(const std::string &message) : message(message) {}
	const char *what() const noexcept override { return message.c_str(); }
private:
	std::string message;
};

class Employee {
public:
	enum class Position;

private:
	std::string name;
	int salary;
	Position position;
	std::set<std::string> projects;

public:
	enum class Position {
		POS_NONE, POS_DEVELOPER, POS_ARTIST, POS_MANAGER, POS_CEO
	};

	Employee();
	Employee(const std::string &name, int salary, Position position);
	Employee(Employee &&employee);

	void setName(const std::string &newName);
	void setSalary(int newSalary);

	bool addActiveProject(const std::string &name);
	void clearProjects();

	// Provided
	Employee(const Employee &employee) = default;
	Employee& operator =(const Employee&) = default;
	bool operator ==(const Employee &employee) { return name == employee.name; }
	const std::string &getName() const { return name; }
	int getSalary() const { return salary; }
	Position getPosition() const { return position; }
	const std::set<std::string> &getProjects() const { return projects; }
	void setPosition(Position newPosition) { position = newPosition; }

	// Task 5
	friend std::istream &operator >>(std::istream &ist, Employee &employee);
};