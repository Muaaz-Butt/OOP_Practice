#include <iostream>
#include <string>
#include <sstream>
#include "Employee.h"

using namespace std;

Employee::Employee() {
	firstName = "";
	lastName = "";
	socialSecurityNumber = "";
}

Employee::Employee(const string& firstName, const string& lastName, const string& ssn) :firstName(firstName), lastName(lastName), socialSecurityNumber(ssn)
{};

void Employee::setFirstName(const string& firstName) {
	this->firstName = firstName;
}

void Employee::setLastName(const string& lastName) {
	this->lastName = lastName;
}

void Employee::setSocialSecurityNumber(const string& ssn) {
	socialSecurityNumber = ssn;
}

string Employee::getFirstName()const {
	return firstName;
}

string Employee::getLastName()const {
	return lastName;
}

string Employee::getSocialSecurityNumber()const {
	return socialSecurityNumber;
}

string Employee::toString()const {
	return getFirstName() + " "s + getLastName() +
		"\nsocial security number: "s + getSocialSecurityNumber();
}