#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H
#include <iostream>
#include "Employee.h"

using namespace std;

class SalariedEmployee:public Employee{
private:
	double weeklySalary;
public:
	SalariedEmployee();
	SalariedEmployee(const string&, const string&, const string&, double = 0.0);
	virtual ~SalariedEmployee() = default;
	void setWeeklySalary(double);
	double getWeeklySalary()const;
	virtual double earnings()const override;
	virtual string toString()const override;
};

#endif SALARIEDEMPLOYEE_H
