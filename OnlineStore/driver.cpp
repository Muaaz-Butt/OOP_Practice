#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"
#include "ShoppingCart.h"
#include "User.h"
#include "OnlineStore.h"

using namespace std;

void seller(OnlineStore& store,User& user) {
	int choice;
	string productName;
	do {
		cout << "Enter 1 if you want to add product in store\nEnter 2 to edit your product in store\nEnter 3 to delete your product in store\n"
			<<"Enter 4 to exit\n\n Which task you want to perform ? ";
		cin >> choice;
		if (choice == 1) {
			Product* product = new Product;
			cin >> *product;
			if (store.searchProductByNameInStore(product->getProductName()) == -1) {
				store.addProductInStore(*product);
				char choiceForDisplay;
				cout << "Do you want to see your product? (y/n): ";
				cin >> choiceForDisplay;
				if (choiceForDisplay == 'y') {
					cout << *product;
				}
			}
			else {
				cout << "\n\n------------Product already exist in store------------\n\n";
			}
			delete product;
		}
		else if (choice == 2) {
			cin.ignore();
			cout << "Enter name of your product: ";
			getline(cin, productName);
			if (store.searchProductByNameInStore(productName) != -1) {
				store.editProductInStore(productName);
			}
			else {
				cout << "\n--------Product does not exist in store---------\n";
			}
		}
		else if (choice == 3) {
			cin.ignore();
			cout << "Enter name of your product in store: ";
			getline(cin, productName);
			if (store.searchProductByNameInStore(productName) != -1) {
				store.removeProductFromStore(productName);
			}
			else {
				cout << "\n\n-----------Your Product does not exist in store------------\n\n";
			}
		}
	} while (choice != 4);
}

void buyer(OnlineStore& store,User& user,ShoppingCart& cart) {
	string productName;
	int index;
	cout << "\n-------------Available products are given-------------\n";
	store.displayAvailableProducts();
	int choice;
	do {
		cout << "Enter 1 if you want to add product in your cart\nEnter 2 to remove product from cart\nEnter 3 to display your cart\n"
			<< "Enter 4 to check number of products in your cart\nEnter 5 to proceed to checkout\nEnter 6 to if you don't want to buy anything\n\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1) {
			cin.ignore();
			cout << "Which product you want to buy: ";
			getline(cin, productName);
			if (store.searchProductByNameInStore(productName) != -1) {
				index = store.searchProductByNameInStore(productName);
				//cout << index << endl;
				store.addProductsInCart(cart, store.products[index]);
			}
			else {
				cout << "\n\n-----------Product does not exist in store-------------\n\n";
			}
		}
		else if (choice == 2) {
			cin.ignore();
			cout << "Which product do you want to remove from the cart: ";
			getline(cin, productName);
			if (cart.searchProductByName(productName) != -1) {
				int index = cart.searchProductByName(productName);
				cout << index;
				store.removeProductsFromCart(cart,store.products[index],index);
			}
			else {
				cout << "\n\n------------Product does not exist in the cart-------------\n\n";
			}
		}

		else if (choice == 3) {
			store.displayProductsInCart(cart);
		}

		else if (choice == 4) {
			cout << "\nNo of products in cart are: ";
			cout<<cart.getNoOfProductsInCart();
			cout << "\n\n";
		}

		else if (choice == 5) {
			cout << "Total price is: " << cart.getTotalPrice();
			char confirmation;
			cout << "\nDo you want to confirm your order? (y,n): ";
			cin >> confirmation;
			if (confirmation == 'y') {
				cout << "\n\n----------Thank you so much for your shopping you will recieve your order soon----------\n\n";
				return;
			}
			cout << "\n\n";
		}
	} while (choice != 6);
}

int main() {
	OnlineStore store;
	ShoppingCart cart;
	Product rolexWatch("Rolex Watch", 100000.0, 10),iphone("Iphone X",80000.0,5);
	Product airpods("airpods pro6", 2000, 50);
	store.addProductInStore(rolexWatch);
	store.addProductInStore(iphone);
	store.addProductInStore(airpods);
	cout << "-----------Welcome to our Online store-----------\n\n";
	//store.displayAvailableProducts();
	int choice;
	cout << "Are you a buyer or seller?\n";
	cout << "Enter 1 if you are seller\n";
	cout << "Enter 2 if you are buyer\n";
	cin >> choice;
	User user;
	cin >> user;
	if (choice == 1) {
		seller(store,user);
	}
	else if (choice == 2) {
		buyer(store,user,cart);
	}
	return 0;
}
