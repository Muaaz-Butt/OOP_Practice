#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Product {
private:
	string productName;
	double productPrice;
	int productQuantity;
public:
	Product();
	Product(string productName, double productPrice, int productQuantity);
	~Product();
	string getProductName() const;
	double getProductPrice() const;
	int getProductQuantity() const;
	void setProductName(string productName);
	void setProductPrice(double productPrice);
	void setProductQuantity(int productQuantity);
	void display();
	friend ostream& operator<<(ostream& out, const Product& product);
	friend istream& operator>>(istream& in, Product& product);
};

#endif PRODUCT_H
