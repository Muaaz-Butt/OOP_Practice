#include <iostream>
#include <string>
#include <sstream>
#include "complexNumber.h"

using namespace std;

ComplexNumber::ComplexNumber() {
	real = 1;
	imaginary = 1;
}

ComplexNumber::ComplexNumber(double real, double imaginary):real(real),imaginary(imaginary)
{}

double ComplexNumber::getReal()const {
	return real;
}

double ComplexNumber::getImaginary()const {
	return imaginary;
}

ComplexNumber ComplexNumber:: operator+(const ComplexNumber& obj) const {
	double r = real + obj.real;
	double i = imaginary + obj.imaginary;
	return ComplexNumber(r,i);
}

ComplexNumber ComplexNumber:: operator+(double scalar) const {
	double r = real + scalar;
	double i = imaginary + 0;
	return ComplexNumber(r, i);
}

ComplexNumber ComplexNumber :: operator-(const ComplexNumber& obj) const {
	double r = real - obj.real;
	double i = imaginary - obj.imaginary;
	return ComplexNumber(r, i);
}

ComplexNumber ComplexNumber :: operator*(const ComplexNumber& obj) const {
	double resultReal = real * obj.real - imaginary * obj.imaginary;
	double resultImaginary = real * obj.imaginary + imaginary * obj.real;
	return ComplexNumber(resultReal, resultImaginary);
}

ComplexNumber ComplexNumber :: operator/(const ComplexNumber& obj) const {
	double divisor = obj.real * obj.real + obj.imaginary * obj.imaginary;
	double resultReal = (real * obj.real + imaginary * obj.imaginary) / divisor;
	double resultImaginary = (imaginary * obj.real - real * obj.imaginary) / divisor;
	return ComplexNumber(resultReal, resultImaginary);
}

ComplexNumber ComplexNumber :: operator++() {
	++real;
	//++imaginary;
	return *this;
}

ComplexNumber ComplexNumber::operator--() {
	--real;
	//--imaginary;
	return *this;
}

ComplexNumber ComplexNumber::operator++(int dummy) {
	real++;
	//imaginary++;
	return *this;
}

ComplexNumber ComplexNumber::operator--(int dummy) {
	real--;
	//imaginary--;
	return *this;
}

bool ComplexNumber :: operator>(const ComplexNumber& c) {
	double magnitude1 = real * real + imaginary * imaginary;
	double magnitude2 = c.real * c.real + c.imaginary * c.imaginary;
	return magnitude1 > magnitude2;
}

bool ComplexNumber :: operator<(const ComplexNumber& c) {
	double magnitude1 = real * real + imaginary * imaginary;
	double magnitude2 = c.real * c.real + c.imaginary * c.imaginary;
	return magnitude1 < magnitude2;
}

bool ComplexNumber:: operator!=(const ComplexNumber& c) {
	return !(*this == c);
}

bool ComplexNumber::operator==(const ComplexNumber& c) {
	return (real == c.real)&&(imaginary==c.imaginary);
}

bool ComplexNumber::operator>=(const ComplexNumber& c) {
	return (*this > c )|| (*this == c);
}

bool ComplexNumber::operator<=(const ComplexNumber& c) {
	return (*this < c) || (*this == c);
}

ComplexNumber& ComplexNumber :: operator+=(const ComplexNumber& c) {
	real += c.real;
	imaginary += c.imaginary;
	return *this;
}

ComplexNumber& ComplexNumber :: operator+=(double scalar) {
	real += scalar;
	return *this;
}

ComplexNumber& ComplexNumber :: operator-=(const ComplexNumber& c) {
	real -= c.real;
	imaginary -= c.imaginary;
	return *this;
}

ComplexNumber& ComplexNumber :: operator-= (double scalar) {
	real -= scalar;
	return *this;
}

ComplexNumber& ComplexNumber :: operator*=(double scalar) {
	real *= scalar;
	imaginary *= scalar;
	return *this;
}

ComplexNumber ComplexNumber :: operator*=(const ComplexNumber& obj) {
	double resultReal = real * obj.real - imaginary * obj.imaginary;
	double resultImaginary = real * obj.imaginary + imaginary * obj.real;
	return ComplexNumber(resultReal, resultImaginary);
}

ostream& operator<<(ostream& out, const ComplexNumber& c) {
	out << c.real << " + " << c.imaginary << "i\n";
	return out;
}

istream& operator>>(istream& in, ComplexNumber& c) {
	cout << "Enter Real part: ";
	in >> c.real;
	cout << "Enter Imaginary part: ";
	in >> c.imaginary;
	return in;
}