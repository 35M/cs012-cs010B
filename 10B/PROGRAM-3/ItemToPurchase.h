#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
#include <string>

using namespace std;

class ItemToPurchase {
    public:
        ItemToPurchase();
        ItemToPurchase(string name, string description, int price, int quantity);
        void setName(string userName);
        string name();
        void setPrice(int userPrice);
        int price();
        void setQuantity(int userQuantity);
        int quantity();
        void setDescription(string userDescription);
        string description();
        void printItemCost();
        void printItemDescription();
    private:
        string itemName;
        string itemDescription;
        int itemPrice;
        int itemQuantity;
};

#endif