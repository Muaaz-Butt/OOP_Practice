#include <iostream>
#include "complexNumber.h"

using namespace std;

int main() {
	ComplexNumber c1, c2;
	cout << "Enter first complex Number\n";
	cin >> c1;
	cout << "Enter second complex Number:\n ";
	cin >> c2;
	cout << "c1+c2: " << c1 + c2 << "\n";
	cout << "c1+5: " << c1 + 5 << "\n";
	cout << "c1-c2: " << c1 - c2 << "\n";
	cout << "c1*c2: " << c1 * c2 << "\n";
	cout << "c1/c2: " << c1 / c2 << "\n";
	cout << "++c1: " << ++c1 << "\n";
	cout << "--c1: " << --c1 << "\n";
	cout << "c2++: " << c2++ << "\n";
	cout << "c2--: " << c2-- << "\n";
	cout << "c1>c2: " << (c1 > c2) << "\n";
	cout << "c1<c2: " << (c1 < c2) << "\n";
	cout << "c1==c2: " << (c1 == c2) << "\n";
	cout << "c1!=c2: " << (c1 != c2) << "\n";
	cout << "c1>=c2: " << (c1 >= c2) << "\n";
	cout << "c1<=c2: " << (c1 <= c2) << "\n";
	cout << "c1+=c2: " << (c1 += c2) << "\n";
	cout << "c1-=c2: " << (c1 -= c2) << "\n";
	cout << "c1+=5: " << (c1 += 5) << "\n";
	cout << "c1-=5: " << (c1 -= 5) << "\n";
	cout << "c1*=c2: " << (c1 *= c2) << "\n";
	cout << "c1*=5: " << (c1 *= 5) << "\n";
}