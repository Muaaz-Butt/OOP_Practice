#ifndef COMISSIONEMPLOYEE_H
#define COMISSIONEMPLOYEE_H

#include <iostream>
#include <string>
#include "Employee.h"
#include "SalariedEmployee.h"

using namespace std;

class ComissionEmployee:public Employee {
private:
	double grossSales;
	double comissionRate;
public:
	ComissionEmployee();
	ComissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0);
	virtual ~ComissionEmployee() = default;
	void setGrossSale(double);
	double getGrossSale()const;
	void setComissionRate(double);
	double getComissionRate()const;
	virtual double earnings()const override;
	virtual string toString()const override;
};

#endif COMISSIONEMPLOYEE_H
