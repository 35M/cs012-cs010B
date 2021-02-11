#include "IntVector.h"
#include <iostream>

using namespace std;

int main() {
    unsigned cap;
    int val;

    cout << "Enter your vector capacity: " << endl;
    cin >> cap;
    cout << endl;

    cout << "Enter your value: " << endl;
    cin >> val;
    cout << endl;

    IntVector test(cap, val);
    
    cout << "Size: " << test.size() << endl;

    cout << "Capacity: " << test.capacity() << endl;

    if (test.empty()) {
        cout << "Status: empty" << endl;
    }
    else {
        cout << "Status: not empty" << endl;
    }

    cout << endl;
    unsigned ind;

    cout << "Enter index: " << endl;
    cin >> ind;
    cout << endl;
    
    cout << "Value at index: " << test.at(ind) << endl; 
    cout << "Front is: " << test.front() << endl;
    cout << "Back is: " << test.back() << endl;
}   