#ifndef BASEPLUSCOMSSIONEMPLOYEE_H
#define BASEPLUSCOMSSIONEMPLOYEE_H

#include <iostream>
#include <string>
#include "Employee.h"
#include "ComissionEmployee.h"
#include "SalariedEmployee.h"

using namespace std;

class BasePLusComissionEmployee:public ComissionEmployee{
private:
	double baseSalary;
public:
	BasePLusComissionEmployee();
	BasePLusComissionEmployee(const string& first, const string& last, const string& ssn, double grossSalay = 0.0, double comissionRate = 0.0, double baseSalary = 0.0);
	virtual ~BasePLusComissionEmployee() = default;
	void setBaseSalary(double);
	double getBaseSalary()const;
	virtual double earnings()const override;
	virtual string toString()const override;
};

#endif BASEPLUSCOMSSIONEMPLOYEE_H
