#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"
#include "ShoppingCart.h"

using namespace std;

int ShoppingCart::noOfProductsInCart = 0;


ShoppingCart::ShoppingCart() {
	cart = nullptr;
	size = 1;
}

ShoppingCart::~ShoppingCart() {
	if (!cart) {
		return;
	}
	delete[] cart;
	cart = nullptr;
}

Product* ShoppingCart::getCart()const {
	return cart;
}

int ShoppingCart::getNoOfProductsInCart() const {
	return noOfProductsInCart;
}

int ShoppingCart::getSize()const {
	return size;
}


void ShoppingCart::reSize(int s) {
	//int length = size;
	//cout << "in reszie\n";
	//cout << s<<"\n";
	if (s <= 0) {
		this->~ShoppingCart();
		return; 
	}
	Product* p = new Product[s];
	int i = 0;
	//cout << size << "\n";
	//size = s;
	while (i < (s > (size - 1) ? (size - 1) : s - 1)) {
		//cout <<"sizeeeeee "<< size << endl;
		//cout << "i" << "\n";
		//cout << this->cart[i];
		p[i] = this->cart[i];
		//cout << p[i];
		i++;
		//cout << p[i]<<endl;
	}
	this->~ShoppingCart();
	cart = p;
	size = s;
	//cout <<"size "<< size << endl;
}

bool ShoppingCart::addProductToCart(Product& product) {
	//cout << "in add\n";
	//cout <<"size "<< size << endl;
	//cout << "cart" << cart[noOfProductsInCart] << endl;
	if (size == noOfProductsInCart+1) {
		reSize((size * 2));
	}
	if (product.getProductQuantity() != 0) {
		this->cart[noOfProductsInCart] = product;
		//cout << "cart" << cart[noOfProductsInCart]<<endl;
		noOfProductsInCart++;
		//cout << cart[noOfProductsInCart]<<endl;
		//cout << noOfProductsInCart<<endl;
		cout << "\n\n------------Product is added successfully to your cart------------\n\n";
		product.setProductQuantity(product.getProductQuantity() - 1);
		//cout << product.getProductQuantity()<<endl;
		//cout << noOfProductsInCart<<endl;
		return true;
	}
	else {
		cout << "\n\n------------Product sold out--------------\n\n";
		return false;
	}
}

bool ShoppingCart::removeProductFromCart(Product& product , string productName, int index){
	if (noOfProductsInCart == 0) {
		cout << "\n\n-----------No product in the cart------------\n\n";
		return false;
	}
	else {
		//int index = searchProductByName(product.getProductName());
		//cout << "size " << size << endl;
		//cout << "index " << index<<endl;
		Product* temp = new Product[size];
		int i = 0, j = 0;
		while (j < noOfProductsInCart-1) {
			if (i == index) {
				i++;
			}
			else {
				temp[j] = cart[i];
		//		cout << temp[j]<<endl;
				i++;
				j++;
			}
		}
		this->~ShoppingCart();
		this->cart = temp;
		//cout << cart[0]<<endl;
		cout << "\n\n--------------Product has been removed successfully--------------\n\n";
		noOfProductsInCart--;
		product.setProductQuantity(product.getProductQuantity() + 1);
		//cout << product.getProductQuantity()<<endl;
		return true;
	}

}

int ShoppingCart::searchProductByName(string productName) {
	int i = 0;
	while (i < this->noOfProductsInCart) {
		if (productName == this->cart[i].getProductName()) {
			return i;
		}
		i++;
	}
	return -1;
}

void ShoppingCart::displayContentOfCart() {
	//cout << noOfProductsInCart<<endl;
	int i = 0;
	if (noOfProductsInCart == 0) {
		cout << "\n\n-----------No product in the cart------------\n\n";
		return;
	}
	while (i < noOfProductsInCart) {
		cart[i].display();
		i++;
	}
}

const long double ShoppingCart::getTotalPrice()const {
	int i = 0;
	long double totalPrice = 0;
	while (i < noOfProductsInCart) {
		totalPrice += cart[i].getProductPrice();
		i++;
	}
	return totalPrice;
}