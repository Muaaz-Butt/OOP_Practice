#include <iostream>
#include <string>
#include <stdexcept>

#include "Employee.h"
#include "BasePlusComissionEmployee.h"
#include "ComissionEmployee.h"

using namespace std;

BasePLusComissionEmployee::BasePLusComissionEmployee() {
	baseSalary = 0.0;
}

BasePLusComissionEmployee::BasePLusComissionEmployee(const string& first, const string& last, const string& ssn, double grossSalay, double comissionRate, double baseSalary) :
	ComissionEmployee(first, last, ssn, grossSalay, comissionRate), baseSalary(baseSalary) {};

void BasePLusComissionEmployee::setBaseSalary(double baseSalary) {
	if (baseSalary <= 0.0) {
		throw invalid_argument("Salary must be greater than 0.0");
	}
	this->baseSalary = baseSalary;
}

double BasePLusComissionEmployee::getBaseSalary()const {
	return baseSalary;
}

double BasePLusComissionEmployee::earnings()const {
	return getBaseSalary() + ComissionEmployee::earnings();
}

string BasePLusComissionEmployee::toString()const {
	stringstream ss;
	ss << "\n\n---------------Base PLus Comission Employee---------------\n\n";
	ss << ComissionEmployee::toString() << ": Base Salary: " << getBaseSalary() << "\n";
	return ss.str();
}