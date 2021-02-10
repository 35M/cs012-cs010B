#include <iostream>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

void printMenu(ShoppingCart &uCart, bool menu);
void userSelection(ShoppingCart &uCart, bool menu);

void printMenu(ShoppingCart &uCart, bool menu) {
    cout << "MENU" << endl;
	cout << "a - Add item to cart" << endl;
	cout << "d - Remove item from cart" << endl;
	cout << "c - Change item quantity" << endl;
	cout << "i - Output items' descriptions" << endl;
	cout << "o - Output shopping cart" << endl;
	cout << "q - Quit" << endl;
	cout << endl;
    userSelection(uCart, menu);
}

void userSelection(ShoppingCart &uCart, bool menu) {
    char userChoice;

    cout << "Choose an option: " << endl;
    cin >> userChoice;
    cin.ignore();
    
    if (menu && userChoice != 'q') {
        cout << endl;
    }

    while (userChoice != 'a' && userChoice != 'd' && userChoice != 'c' && 
           userChoice != 'i' && userChoice != 'o' && userChoice != 'q') {
        cout << "Choose an option: " << endl;
        cin >> userChoice;
        cin.ignore();
    }

    if (userChoice == 'q') {
        return;
    }
    if (userChoice == 'a') {
        string itemName;
        string itemDescription;
        int itemPrice;
        int itemQuantity;

        cout << "ADD ITEM TO CART" << endl;
        cout << "Enter the item name: " << endl;
        getline(cin, itemName);
        cout << "Enter the item description: " << endl;
        getline(cin, itemDescription);
        cout << "Enter the item price: " << endl;
        cin >> itemPrice;
        cout << "Enter the item quantity: " << endl;
        cin >> itemQuantity;
        cout << endl;
        ItemToPurchase itemAdd(itemName, itemDescription, itemPrice, itemQuantity);
        uCart.addItem(itemAdd);
            
        menu = true;
        printMenu(uCart, menu);
    }
    if (userChoice == 'd') {
        string itemName;

        cout << "REMOVE ITEM FROM CART" << endl;
        cout << "Enter name of item to remove: " << endl;
        getline(cin, itemName);
        uCart.removeItem(itemName);

        menu = true;
        printMenu(uCart, menu);
    }
    if (userChoice == 'c') {
        string itemName;
        int itemQuantity;

        cout << "CHANGE ITEM QUANTITY" << endl;
        cout << "Enter the item name: " << endl;
        getline(cin, itemName);
        cout << "Enter the new quantity: " << endl;
        cin >> itemQuantity;
        ItemToPurchase itemMod;
        itemMod.setName(itemName); 
        itemMod.setQuantity(itemQuantity);
        uCart.modifyItem(itemMod);

        menu = true;
        printMenu(uCart, menu);
    }
    if (userChoice == 'i') {
        cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
        uCart.printDescriptions();

        menu = true;
        printMenu(uCart, menu);
    }
    if (userChoice == 'o') {
        cout << "OUTPUT SHOPPING CART" << endl;
        uCart.printTotal();

        menu = true;
        printMenu(uCart, menu);
    }
    // else {
    //     printMenu(uCart);
    // }
}
 
int main() {
    string userName;
    string userDate;
    ShoppingCart userCart;
    bool menu = false;

    cout << "Enter customer's name: " << endl;
    getline(cin, userName);
    cout << "Enter today's date: " << endl;
    getline(cin, userDate);
    cout << endl;

    userCart = ShoppingCart(userName, userDate);
    cout << "Customer name: " << userCart.customerName() << endl;
    cout << "Today's date: " << userCart.date() << endl;
    cout << endl;

    printMenu(userCart, menu);

    return 0;
}