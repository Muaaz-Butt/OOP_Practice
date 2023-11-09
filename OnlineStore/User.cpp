#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"
#include "ShoppingCart.h"
#include "User.h"

using namespace std;

User::User()
{
	userName = "";
	userEmail = "";
}

User::~User()
{
}

string User::getUserName()const {
	return userName;
}

string User::getUserEmail()const {
	return userEmail;
}

ShoppingCart User::getUserCart()const {
	return userCart;
}

void User::setUserName(string userName) {
	this->userName = userName;
}

void User::setUserEmail(string userEmail) {
	this->userEmail = userEmail;
}

istream& operator>>(istream& in, User& user) {
	cin.ignore();
	cout << "Enter your name:";
	getline(in, user.userName);
	cout << "Enter your email: ";
	getline(in, user.userEmail);
	return in;
}