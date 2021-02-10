#include <iostream>
#include <vector>
#include <string>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"

using namespace std;

ShoppingCart::ShoppingCart() {
    usercustomerName = "none";
    userCurrentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string custName, string currDate) {
    usercustomerName = custName;
    userCurrentDate = currDate;
}

string ShoppingCart::customerName() {
    return this->usercustomerName;
}

string ShoppingCart::date() {
    return this->userCurrentDate;
}

void ShoppingCart::addItem(ItemToPurchase item) {
    CartItems.push_back(item);
}

void ShoppingCart::removeItem(string itemName) {
    bool itemExists = false;
    for (unsigned int i = 0; i < CartItems.size(); ++i) {
        if (CartItems.at(i).name() == itemName) {
            CartItems.erase(CartItems.begin() + i);
            //CartItems.erase(CartItems.at(i)); //fix?
            itemExists = true;
            break;
        }
        // else {
        //     cout << "Item not found in cart. Nothing removed." << endl;
        // }
    }
    if (!itemExists) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
    cout << endl;
}

void ShoppingCart::modifyItem(ItemToPurchase item) {
    bool itemExists = false;
    for (unsigned int i = 0; i < CartItems.size(); ++i) {
        if (CartItems.at(i).name() == item.name()) {
            if (CartItems.at(i).description() != "default" && CartItems.at(i).quantity() != 0 && CartItems.at(i).price() != 0) {
                CartItems.at(i).setQuantity(item.quantity());
                itemExists = true;
                break;
            }
        }
        // else {
        //     cout << "Item not found in cart. Nothing modified." << endl;
        // }
    }
    if (!itemExists) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
    cout << endl;
}

int ShoppingCart::numItemsInCart() {
    int total = 0;
	for (unsigned int i = 0; i < CartItems.size(); ++i) {
		total += CartItems.at(i).quantity();
	}
	return total;
}

int ShoppingCart::costOfCart() {
    int totalPrice = 0;
    for (unsigned i = 0; i < CartItems.size(); ++i) {
        totalPrice += CartItems.at(i).price() * CartItems.at(i).quantity();
    }
    return totalPrice; 
}

void ShoppingCart::printTotal() {
    cout << usercustomerName << "'s Shopping Cart - " << userCurrentDate << endl;
    cout << "Number of Items: " << numItemsInCart() << endl;
    cout << endl;
    if (CartItems.size() > 0) {
        for (unsigned int i = 0; i < CartItems.size(); ++i) {
            CartItems.at(i).printItemCost();
            //cout << endl;
        }
    }
    else {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    cout << endl;
    cout << "Total: $" << costOfCart() << endl;
    cout << endl;
}

void ShoppingCart::printDescriptions() {
    cout << usercustomerName << "'s Shopping Cart - " << userCurrentDate << endl;
    cout << endl;
    cout << "Item Descriptions" << endl;
    for (unsigned int i = 0; i < CartItems.size(); ++i) {
        CartItems.at(i).printItemDescription();
    }
    cout << endl;
}