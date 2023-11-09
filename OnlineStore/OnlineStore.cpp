#include <iostream>
#include <string>
#include <sstream>
#include "OnlineStore.h"
#include "Product.h"
#include "ShoppingCart.h"
#include "User.h"

using namespace std;

OnlineStore::OnlineStore()
{
	products = nullptr;
	noOfProductsInStore = 0;
	size = 1;
}

OnlineStore::~OnlineStore()
{
	if (!products) {
		return;
	}
	delete[]products;
	products = nullptr;
}

int OnlineStore::getNoOfProductsInStore()const {
	return noOfProductsInStore;
}

void OnlineStore::reSize(int s) {
	//cout << "in resize\n";
	if (s <= 0) {
		this->~OnlineStore();
		return;
	}
	int i = 0;
	Product* p = new Product[s];
	//cout << "j\n";
	while (i <(s > (size - 1) ? (size - 1) : s - 1)) {
		p[i] = products[i];
		i++;
	}
	//cout << "k\n";
	this->~OnlineStore();
	products = p;
	size = s;
}

int OnlineStore::searchProductByNameInStore(string productName) {
	int i = 0;
	while (i < noOfProductsInStore) {
		if (productName == products[i].getProductName()) {
			return i;
		}
		i++;
	}
	return -1;
}

bool OnlineStore::addProductInStore(const Product& product) {
	//cout << "in add"<<endl;
	if (size == noOfProductsInStore + 1) {
		reSize(size * 2);
	}
	//cout << "ii\n";
	this->products[noOfProductsInStore] = product;
	noOfProductsInStore++;
	//cout << "\n\n-----------Your product is added in the store-------------\n\n";
	return true;
}

void OnlineStore::editProductInStore(string productName){
	int index = searchProductByNameInStore(productName);
	cout << products[index];
	cout << "\n\n---------You can only edit price and quantity----------\n\n";
	int newPrice, newQuantity;
	cout << "Enter new price: ";
	cin >> newPrice;
	//newPrice = (newPrice - product.getProductPrice()) + product.getProductPrice();
	products[index].setProductPrice(newPrice);
	cout << "Enter new quantity: ";
	cin >> newQuantity;
	products[index].setProductQuantity(newQuantity);
	cout << "\n---------Updated information of product---------\n";
	cout << products[index];
}

bool OnlineStore::removeProductFromStore(string productName) {
	int index = searchProductByNameInStore(productName);
	Product* temp = new Product[size];
	int i = 0, j = 0;
	while (j < noOfProductsInStore - 1) {
		if (i == index) {
			i++;
		}
		else {
			temp[j] = products[i];
			i++;
			j++;
		}
	}
	this->~OnlineStore();
	this->products = temp;
	cout << "\n\n----------Product has been removed successfully from store----------\n\n";
	noOfProductsInStore--;
	return true;
}

void OnlineStore::addProductsInCart(ShoppingCart& cart, Product& product) {
	//cout << "In add store in cart\n";
	cart.addProductToCart(product);
}

void OnlineStore::removeProductsFromCart(ShoppingCart& cart, Product& product, int index) {
	cart.removeProductFromCart(product,product.getProductName(),index);
}

void OnlineStore::displayProductsInCart(ShoppingCart& cart) {
	cart.displayContentOfCart();
}

void OnlineStore::displayAvailableProducts() {
	if (noOfProductsInStore == 0) {
		cout << "\n\n-------------No available products-------------\n\n";
		return;
	}
	int i = 0;
	while (i < noOfProductsInStore) {
		cout << products[i];
		i++;
	}

}