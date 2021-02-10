#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include "ItemToPurchase.h"
#include <string>
#include <vector>

using namespace std;

class ShoppingCart {
    public:
        ShoppingCart();
        ShoppingCart(string custName, string currDate);
        string customerName();
        string date();
        void addItem(ItemToPurchase item);
        void removeItem(string itemName);
        void modifyItem(ItemToPurchase item);
        int numItemsInCart();
        int costOfCart();
        void printTotal();
        void printDescriptions();
    private:
        string usercustomerName;
        string userCurrentDate;
        vector <ItemToPurchase> CartItems;
};

#endif