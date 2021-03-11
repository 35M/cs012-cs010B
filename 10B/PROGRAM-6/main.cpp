#include <iostream>

using namespace std;

#include "SortedSet.h"

int main() {
    cout << endl;
    cout << "Declaring empty SortedSets" << endl;
    SortedSet list1 = SortedSet();
    SortedSet list2 = SortedSet();
    SortedSet list3 = SortedSet();
    cout << endl;

    cout << "Testing add()" << endl;
    cout << "List 1 before:" << endl;
    if (list1.empty()) {
        cout << "empty";
    }
    cout << list1 << endl;
    list1.add(1);
    list1.add(5);
    list1.add(9);
    list1.add(25);
    list1.add(42);
    cout << "List 1 after:" << endl;
    cout << list1 << endl;
    cout << endl;

    list1.clear();
    cout << "Testing push_back()" << endl;
    cout << "List 1 before:" << endl;
    if (list1.empty()) {
        cout << "empty";
    }
    cout << list1 << endl;
    list1.push_back(1);
    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(25);
    list1.push_back(42);
    cout << "List 1 after:" << endl;
    cout << list1 << endl;
    cout << endl;

    cout << "Testing push_front()" << endl;
    cout << "List 2 before:" << endl;
    if (list2.empty()) {
        cout << "empty";
    }
    cout << list2 << endl;
    list2.push_front(2);
    list2.push_front(6);
    list2.push_front(10);
    list2.push_front(26);
    list2.push_front(43);
    cout << "List 2 after:" << endl;
    cout << list2 << endl;
    cout << endl;

    cout << "Testing insert_ordered()" << endl;
    cout << "List 2 before:" << endl;
    cout << list2 << endl;
    list2.insert_ordered(3);
    list2.insert_ordered(7);
    list2.insert_ordered(21);
    list2.insert_ordered(34);
    list2.insert_ordered(68);
    cout << "List 2 after:" << endl;
    cout << list2 << endl;
    cout << endl;

    cout << "Testing operator | function" << endl;
    cout << "List 3 before:" << endl;
    if (list3.empty()) {
        cout << "empty";
    }
    cout << list3 << endl;
    cout << "List 3 after:" << endl;
    list3 = list1 | list2;
    cout << list3 << endl;
    cout << endl;

    cout << "Testing operator |= function" << endl;
    cout << "List 3 before:" << endl;
    if (list3.empty()) {
        cout << "empty";
    }
    cout << list3 << endl;
    cout << "List 3 after:" << endl;
    list3 |= list1;
    cout << list3 << endl;
    list3.clear();

    cout << endl;
    cout << "Testing operator & function" << endl;
    cout << "List 3 before:" << endl;
    if (list3.empty()) {
        cout << "empty";
    }
    cout << list3 << endl;
    cout << "List 3 after:" << endl;
    list3 = list1 & list2;
    cout << list3 << endl;

    cout << endl;
    cout << "Testing operator &= function" << endl;
    list3 = list1 | list2;
    cout << "List 3 before:" << endl;
    if (list3.empty()) {
        cout << "empty";
    }
    cout << list3 << endl;
    cout << "List 3 after:" << endl;
    list3 &= list2;
    cout << list3 << endl;

    return 0;
}