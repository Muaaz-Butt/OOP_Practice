#include <iostream>
#include <string>
#include <sstream>
#include "rational.h"

using namespace std;

int main() {
	Rational r1(4, 2);
	Rational r2(2, 3);
	cout << r1.toString() << " + " << r2.toString() << " = "<< r1.add(r2).toString() << "\n";
    cout << r1.toString() << " - " << r2.toString() << " = "<< r1.subtract(r2).toString() << "\n";
	cout << r1.toString() << " * " << r2.toString() << " = "<< r1.multiply(r2).toString() << "\n";
    cout << r1.toString() << " / " << r2.toString() << " = " << r1.divide(r2).toString() << "\n";	
	cout << "r2.intValue()" << " is " << r2.intValue() << "\n";
	cout << "r2.doubleValue()" << " is " << r2.doubleValue() << "\n";
	cout << "r1.compareTo(r2) is " << r1.compareTo(r2) << "\n";
	cout << "r2.compareTo(r1) is " << r2.compareTo(r1) << "\n";
	cout << "r1.compareTo(r1) is " << r1.compareTo(r1) << "\n";
	cout << "r1.equals(r1) is " << (r1.equals(r1) ? "true" : "false") << "\n";
	cout << "r1.equals(r2) is "<< (r1.equals(r2) ? "true" : "false") << "\n";
	Rational r3(1, 2);
	Rational r4(1, 2);
	Rational r5,r6;
	r5=r3++;
	cout << r3.toString() << "\n";
	cout << r5.toString() << "\n";
	r6 = --r4;
	cout << r4.toString() << "\n";
	cout << r6.toString() << "\n";
	cout << r3.toString() << " + " << r4.toString() << " = " << (r3 + r4).toString() << "\n";
	cout << r3.toString() << " - " << r4.toString() << " = " << (r3 - r4).toString() << "\n";
	cout << r3.toString() << " * " << r4.toString() << " = " << (r3 * r4).toString() << "\n";
	cout << r3.toString() << " / " << r4.toString() << " = " << (r3 / r4).toString() << "\n";
	cout << r5.toString()<<"\n";
	cout << "r3>r4: " << (r3 > r4)<<"\n";
	cout << r3.toString() << " " << r4.toString() << "\n";
	cout << "r3<r4: " << (r3 < r4) << "\n";
	cout << "r3==r4: " << (r3 == r4) << "\n";
	Rational r7,r8;
	cout << "Enter first rational number\n";
	cin >> r7;
	cout << "Enter second rational number\n";
	cin >> r8;
	cout << "r7 + r8: " << ( r7+r8) << "\n";
	cout << "r7 * r8: " << r7 * r8 << "\n";
	cout << (r1 += Rational(2, 3))<<" "<<(r1 += Rational(5,1));
	return 0;
}
