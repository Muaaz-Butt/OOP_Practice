#include <iostream>
#include <string>
#include <stdexcept>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "ComissionEmployee.h"

using namespace std;

ComissionEmployee::ComissionEmployee() {
	grossSales = 0.0;
	comissionRate = 0.0;
}

ComissionEmployee::ComissionEmployee(const string& first, const string& last, const string& ssn, double grossSales, double comissionRate) :
	Employee(first, last, ssn), grossSales(grossSales), comissionRate(comissionRate) {};

void ComissionEmployee::setGrossSale(double grossSales) {
	if (grossSales < 0.0) {
		throw invalid_argument("Gross sales must be >=0.0");
	}
	this->grossSales = grossSales;
}

double ComissionEmployee::getGrossSale()const {
	return grossSales;
}

void ComissionEmployee::setComissionRate(double comissionRate) {
	if (comissionRate <= 0.0 || comissionRate > 1.0) {
		throw invalid_argument("Comission rate cannot be<= 0.0 and > 1.0");
	}
	this->comissionRate = comissionRate;
}

double ComissionEmployee::getComissionRate()const {
	return comissionRate;
}

double ComissionEmployee::earnings()const {
	return getComissionRate() * getGrossSale();
}

string ComissionEmployee::toString()const {
	stringstream ss;
	ss << "\n\n------------------Comission Employee------------------\n\n";
	ss << Employee::toString() << "\nGross sales: " << getGrossSale() << "\nComission Rate: " << getComissionRate() << "\n";
	return ss.str();
}
