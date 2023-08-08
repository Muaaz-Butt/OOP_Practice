#ifndef RATIONAL_H
#define RATIONAL_H
#include <string>
#include <iostream>
using namespace std;
class Rational {
private:
	int numerator;
	int denomirator;
	static int gcd(int numerator, int denomirator);
public:
	Rational();
	Rational(int numerator, int denomirator);
	const int getNumerator() const;
    const int getDenomirator()const;
	Rational add(const Rational& rationalNum) const;
	Rational subtract(const Rational& rationalNum) const;
	Rational multiply(const Rational& rationalNum) const;
	Rational divide(const Rational& rationalNum) const;
	int compareTo(const Rational& rationalNum) const;
	bool equals(const Rational& rationalNum) const;
	int intValue() const;
	double doubleValue() const;
	string toString() const;
	Rational operator+(const Rational& rationalNum) const;
	Rational operator-(const Rational& rationalNum) const;
	Rational operator*(const Rational& rationalNum) const;
	Rational operator/(const Rational& rationalNum) const;
	Rational& operator++(int dummy) ;                                  //postfix increment
	Rational& operator++() ;                                         //prefix increment
	Rational& operator--() ;                                         //pretfix decrement
	Rational& operator--(int dummy) ;                                 //postfix decrement
	bool operator<(const Rational& rationalNum) const;
	bool operator>(const Rational& rationalNum) const;
	bool operator<=(const Rational& rationalNum) const;
	bool operator>=(const Rational& rationalNum) const;
	bool operator!=(const Rational& rationalNum) const;
	bool operator==(const Rational& rationalNum) const;
	Rational operator+=(const Rational& rationalNum) ;
	Rational operator-=(const Rational& rationalNum) ;
	friend istream& operator>>(istream& in,  Rational& rationalNum);
	friend ostream& operator<<(ostream& out, const Rational& rationalNum);
	void simplifyRationalNum();
};
#endif RATIONAL_H