#include <iostream>

#include "BasePlusComissionEmployee.h"
#include "ComissionEmployee.h"
#include "Employee.h"
#include "SalariedEmployee.h"

using namespace std;

void virtualViaPointer(const Employee* const baseClassPtr) {
	cout << baseClassPtr->toString() << "\nearned $" << baseClassPtr->earnings() << "\n\n";
}

void virtualViaReference(const Employee& baseClassRef) {
	cout << baseClassRef.toString() << "\nearned $" << baseClassRef.earnings() << "\n\n";
}

int main() {
	SalariedEmployee salariedEmployee("Muaaz", "Butt", "111-111-111", 1000);
	ComissionEmployee comissionEmployee("Zayyad", "Butt", "222-222-222", 10000, .06);
	BasePLusComissionEmployee basePlusComissionEmployee("Hammad", "Butt", "333-333-333", 5000, .03, 300);
	cout << "\n-------------------Static Binding--------------------\n";
	cout << salariedEmployee.toString() << "\nearned $" << salariedEmployee.earnings() << "\n\n";
	cout << comissionEmployee.toString() << "\nearned $" << comissionEmployee.earnings() << "\n\n";
	cout << basePlusComissionEmployee.toString() << "\nearned $" << basePlusComissionEmployee.earnings() << "\n\n";
	Employee* employees[] = { &salariedEmployee, &comissionEmployee, &basePlusComissionEmployee };
	int numEmployees = sizeof(employees) / sizeof(Employee*);
	cout << "\n--------------Runtime Binding--------------\n";
	for (int i = 0; i < numEmployees; i++) {
		virtualViaPointer(employees[i]);
	}
	cout << "\n-----------------By Reference-----------------\n";
	for (int i = 0; i < numEmployees; i++) {
		virtualViaReference(*employees[i]);
	}
}