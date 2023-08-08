#include <iostream>
#include <string>
#include <sstream>
#include "rational.h"

using namespace std;

Rational::Rational() {
	numerator = 0;
	denomirator = 1;
}

Rational::Rational(int numerator, int denomirator) {
	cout << "In parameterized\n";
	int factor = gcd(numerator, denomirator);
	this->numerator = ((denomirator > 0) ? 1 : -1) * (numerator / factor);
	this->denomirator = abs(denomirator) / factor;	
}
int Rational::gcd(int n, int d) {
	int n1 = abs(n);
	int n2 = abs(d);
	int gcd = 1;
	for (int k = 1; k <= n1 && k <= n2; k++) {
		if (n1 % k == 0 && n2 % k == 0) {
			gcd = k;
		}
	}
	return gcd;
}

const int Rational::getDenomirator() const{
	return denomirator;
}

const int Rational::getNumerator() const {
	return numerator;
}

Rational Rational::add(const Rational& rationalNum) const {
	Rational temp;
	
	return temp;
}

Rational Rational::subtract(const Rational& rationalNum) const {
	//Rational temp;
	int n = (numerator * rationalNum.denomirator) - (rationalNum.numerator * denomirator);
	int d = denomirator * rationalNum.denomirator;
	return Rational(n,d);
}

Rational Rational::multiply(const Rational& rationalNum) const {
	//Rational temp;
	int n = (numerator * rationalNum.numerator);
	int d = denomirator * rationalNum.denomirator;
	return Rational(n,d);
}

Rational Rational::divide(const Rational& rationalNum) const {
	//Rational temp;
	int n = numerator * rationalNum.getDenomirator(); 
	int d = denomirator * rationalNum.getNumerator();
	return Rational (n,d);
}

int Rational::compareTo(const Rational& rationalNum) const {
	Rational temp = subtract(rationalNum);
	if (temp.getNumerator() == 0) {
		return 0;
	}
	else if (temp.getNumerator() > 0) {
		return 1;
	}
	else {
		return -1;
	}
}

bool Rational::equals(const Rational& rationalNum) const {
	if (compareTo(rationalNum) == 0){
		return true;
	}
	else {
		return false;
	}
}

int Rational::intValue() const {
	//cout << "in int\n";
	return getNumerator() / getDenomirator();
}

double Rational::doubleValue() const {
	//cout << "in double\n";
	return (1.0) * getNumerator() / getDenomirator();
}

string Rational::toString() const{
	stringstream ss;
	if (numerator == 0) {
		ss << numerator;
		return ss.str();
	}
	ss << numerator;
	if (denomirator > 1) {
		ss << "/" << denomirator;
	}
	return ss.str();
} 

Rational Rational :: operator+(const Rational& rationalNum) const {
	Rational b;
	b.numerator = numerator * rationalNum.denomirator + rationalNum.numerator * denomirator;
	b.denomirator = denomirator * rationalNum.denomirator;
	return b;
}

Rational Rational :: operator-(const Rational& rationalNum) const {
	int n = (numerator * rationalNum.denomirator) - (rationalNum.numerator * denomirator);
	int d = denomirator * rationalNum.denomirator;
	return Rational(n, d);
}

Rational Rational :: operator*(const Rational& rationalNum) const {
	int n = (numerator * rationalNum.numerator);
	int d = denomirator * rationalNum.denomirator;
	return Rational(n, d);
}

Rational Rational :: operator/(const Rational& rationalNum) const {
	int n = numerator * rationalNum.getDenomirator();
	int d = denomirator * rationalNum.getNumerator();
	return Rational(n, d);
}

Rational& Rational :: operator++(int dummy)  {
	cout << "In ++ operator\n";
	Rational temp(numerator, denomirator);
	numerator += denomirator;
	return temp;
}

Rational& Rational :: operator--() {
	cout << "in predecre\n";
	numerator -= denomirator;
	return *this;
}

Rational& Rational :: operator++() {
	cout << "in preincre\n";
	numerator += denomirator;
	return *this;
}

Rational& Rational :: operator--(int dummy) {
	cout << "in postincre\n";
	Rational temp(numerator, denomirator);
	numerator -= denomirator;
	return temp;
}

bool Rational :: operator<(const Rational& rationalNum) const {
	if (compareTo(rationalNum) < 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Rational :: operator<=(const Rational& rationalNum) const {
	if (compareTo(rationalNum) <= 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Rational :: operator>(const Rational& rationalNum) const {
	if (compareTo(rationalNum) >0) {
		return true;
	}
	else {
		return false;
	}
}

bool Rational :: operator>=(const Rational& rationalNum) const {
	if (compareTo(rationalNum) >= 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Rational :: operator==(const Rational& rationalNum)const {
	if (compareTo(rationalNum) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Rational :: operator!=(const Rational& rationalNum) const {
	if (compareTo(rationalNum) != 0) {
		return true;
	}
	else {
		return false;
	}
}



Rational Rational :: operator+=(const Rational& rationalNum)  {
	int n = (numerator * rationalNum.denomirator) + (rationalNum.numerator * denomirator);
	int d = denomirator * rationalNum.denomirator;
	return Rational(n,d);
}

Rational Rational:: operator-=(const Rational& rationalNum) {
	int n = (numerator * rationalNum.denomirator) - (rationalNum.numerator * denomirator);
	int d = denomirator * rationalNum.denomirator;
	return Rational(n,d);
}

void Rational::simplifyRationalNum() {
	int factor = gcd(this->numerator, this->denomirator);
	this->numerator = ((this->denomirator > 0) ? 1 : -1) * (this->numerator / factor);
	this->denomirator = abs(this->denomirator) / factor;
}

ostream& operator<<(ostream& out, const Rational& rationalNum) {
	//rationalNum.simplifyRationalNum();
	Rational temp = rationalNum;
	temp.simplifyRationalNum();
	out << temp.numerator << "/" << temp.denomirator << "\n";
	return out;
}

istream& operator>>(istream& in, Rational& rationalNum) {
	cout << "Enter Numerator: ";
	in >> rationalNum.numerator;
	cout << "Enter denomirator: ";
	in >> rationalNum.denomirator;
	return in;
}

