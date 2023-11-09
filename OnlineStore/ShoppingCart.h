#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"

using namespace std;

class ShoppingCart
{
public:
	Product* cart;
	ShoppingCart();
	~ShoppingCart();
	bool addProductToCart(Product& product);
	bool removeProductFromCart(Product& product, string productName,int index);
	int searchProductByName(string productName);
	void displayContentOfCart();
	void reSize(int s);
	Product* getCart()const;
	int getNoOfProductsInCart() const;
	int getSize() const;
	const long double getTotalPrice()const;
private:
    int size;
	static int noOfProductsInCart;
};

#endif SHOPPINGCART_H
