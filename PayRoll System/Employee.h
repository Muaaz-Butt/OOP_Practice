#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Employee {
private:
	string firstName;
	string lastName;
	string socialSecurityNumber;
public:
	Employee();
	Employee(const string&, const string&, const string&);
	virtual ~Employee() = default;	
	void setFirstName(const string&);
	void setLastName(const string&);
	void setSocialSecurityNumber(const string&);
	string getFirstName()const;
	string getLastName()const;
	string getSocialSecurityNumber()const;
	virtual double earnings()const = 0;
	virtual string toString()const;
};

#endif EMPLOYEE_H
