#ifndef COMPLEXNUMER_H
#define COMPLEXNUMER_H
#include <iostream>
using namespace std;

class ComplexNumber {
private:
	double real;
	double imaginary;
public:
	ComplexNumber();
	ComplexNumber(double real, double imaginary);
	double getReal() const;
	double getImaginary() const;
	ComplexNumber operator+(const ComplexNumber& obj) const;
	ComplexNumber operator+(double scalar) const;
	ComplexNumber operator-(const ComplexNumber& obj) const;
	ComplexNumber operator*(const ComplexNumber& obj) const;
	ComplexNumber operator/(const ComplexNumber& obj) const;
	ComplexNumber operator++();
	ComplexNumber operator++(int dummy);
	ComplexNumber operator--();
	ComplexNumber operator--(int dummy);
	ComplexNumber& operator+=(const ComplexNumber& c);
	ComplexNumber& operator+=(double scalar);
	ComplexNumber& operator-=(double scalar);
	ComplexNumber& operator-=(const ComplexNumber& c);
	ComplexNumber& operator*=(double scalar);
	ComplexNumber operator*=(const ComplexNumber& obj);
	bool operator>(const ComplexNumber& c);
	bool operator<(const ComplexNumber& c);
	bool operator!=(const ComplexNumber& c);
	bool operator==(const ComplexNumber& c);
	bool operator>=(const ComplexNumber& c);
	bool operator<=(const ComplexNumber& c);
	friend ostream& operator<<(ostream& out, const ComplexNumber& c);
	friend istream& operator>>(istream& in, ComplexNumber& c);
};
#endif  COMPLEXNUMER_H
