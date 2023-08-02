#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Employee.h"
#include "SalariedEmployee.h"

using namespace std;

SalariedEmployee::SalariedEmployee() {
	weeklySalary = 0.0;
}

SalariedEmployee::SalariedEmployee(const string& first, const string& last, const string& ssn, double salary) :Employee(first, last, ssn),
weeklySalary(salary) {};

void SalariedEmployee::setWeeklySalary(double salary) {
	if (salary < 0.0) {
		throw invalid_argument("Weekly Salary must be > 0.0");
	}

	weeklySalary = salary;
}

double SalariedEmployee::getWeeklySalary()const {
	return weeklySalary;
}

double SalariedEmployee::earnings() const {
	return getWeeklySalary();
}

string SalariedEmployee::toString() const {
	stringstream ss;
	ss << "\n\n--------------Salaried Employee--------------\n\n" << Employee::toString() << "\nWeekly Salary: " << getWeeklySalary() << "\n";
	return ss.str();
}
