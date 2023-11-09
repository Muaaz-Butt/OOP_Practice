#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"
#include "ShoppingCart.h"

using namespace std;

class User
{
public:
	ShoppingCart userCart;
	User();
	~User();
	string getUserName() const;
	string getUserEmail()const;
	ShoppingCart getUserCart()const;
	void setUserName(string userName);
	void setUserEmail(string userEmail);
	friend istream& operator>>(istream& in, User& user);
private:
	string userName;
	string userEmail;
};

#endif USER_H

