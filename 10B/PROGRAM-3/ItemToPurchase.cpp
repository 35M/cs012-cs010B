#include <iostream>
#include "ItemToPurchase.h"
using namespace std;


ItemToPurchase::ItemToPurchase() {
    itemName = "default";
    itemDescription = "default";
    itemPrice = 0;
    itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity) {
    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;
}

void ItemToPurchase::setName(string userName) {
    itemName = userName;
}

string ItemToPurchase::name() {
    return this->itemName;
}

void ItemToPurchase::setPrice(int userPrice) {
    itemPrice = userPrice;
}

int ItemToPurchase::price() {
    return this->itemPrice;
}

void ItemToPurchase::setQuantity(int userQuantity) {
    itemQuantity = userQuantity;
}

int ItemToPurchase::quantity() {
    return this->itemQuantity;
}

void ItemToPurchase::setDescription(string userDescription) {
    itemDescription = userDescription;
}

string ItemToPurchase::description() {
    return this->itemDescription;
}

void ItemToPurchase::printItemCost() {
    int total;
    total = itemQuantity * itemPrice;
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << total << endl;
}

void ItemToPurchase::printItemDescription() {
    cout << itemName << ": " << itemDescription << endl;
}