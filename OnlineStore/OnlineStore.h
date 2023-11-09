#ifndef ONLINESTORE_H
#define ONLINESTORE_H
#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"
#include "ShoppingCart.h"
#include "User.h"

using namespace std;

class OnlineStore
{
public:
	Product* products;
	OnlineStore();
	~OnlineStore();
	bool addProductInStore(const Product& product);
	bool removeProductFromStore(string productName);
	void displayAvailableProducts();
	void editProductInStore(string productName);
	void addProductsInCart(ShoppingCart& cart, Product& product);
	void removeProductsFromCart(ShoppingCart& cart, Product& product,int index);
	void displayProductsInCart(ShoppingCart& cart);
	int getNoOfProductsInStore()const;
	void reSize(int s);
	int searchProductByNameInStore(string productName);
private:
	int noOfProductsInStore;
	int size;
};

#endif ONLINESTORE_H
