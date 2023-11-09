#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"

using namespace std;

Product::Product() {
	productName = " ";
	productPrice = 0;
	productQuantity = 0;
}

Product::Product(string productName, double productPrice, int productQuantity) {
	this->productName = productName;
	this->productPrice = productPrice;
	this->productQuantity = productQuantity;
}

Product::~Product() {

}

string Product::getProductName() const {
	return productName;
}

double Product::getProductPrice() const {
	return productPrice;
}

int Product::getProductQuantity()const {
	return productQuantity;
}

void Product::setProductName(string productName) {
	this->productName = productName;
}

void Product::setProductPrice(double productPrice) {
	this->productPrice = productPrice;
}

void Product::setProductQuantity(int productQuantity) {
	this->productQuantity = productQuantity;
}

istream& operator>>(istream& in, Product& product) {
	cout << "----------Enter your product info-----------\n";
	cin.ignore();
	cout << "Enter Name of your product: ";
	getline(in, product.productName);
	cout << "Enter price of your product: ";
	in >> product.productPrice;
	cout << "Enter quantity of your product: ";
	in >> product.productQuantity;
	return in;
}

ostream& operator<<(ostream& out, const Product& product) {
	out << "----------------------------------------\n\n\n";
	out << "Product Name: " << product.productName << "\n";
	out << "Product Price: " << product.productPrice << "\n";
	out << "Product Quantity: " << product.productQuantity << "\n\n\n";
	return out;
}

void Product::display() {
	cout << "----------------------------------------\n\n\n";
	cout << "Product Name: " << productName << "\n";
	cout << "Product Price: " << productPrice << "\n\n\n";
	//cout << "Product Quantity: " << productQuantity << "\n";
}