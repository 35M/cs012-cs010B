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
    cout << "List is: ";
    for (unsigned int i = 0; i < test.size(); ++i) 
        { cout << test.at(i) << " ";}
    cout << endl;

    cout << endl;
    cout << "Testing insert function... " << endl;
    cout << "At what index would you like to insert your value?" << endl;
    cin >> ind;
    cout << "What value would you like to insert?" << endl;
    cin >> val;
    test.insert(ind, val);
    cout << "New capacity: " << test.capacity() << endl;
    cout << "List is: ";
    for (unsigned int i = 0; i < test.size(); ++i) {
        cout << test.at(i) << " ";
    }
    cout << endl;

    cout << endl;
    cout << "Testing erase function... " << endl;
    cout << "At what index would you like to erase your value?" << endl;
    cin >> ind;
    cout << "List was: ";
    for (unsigned int i = 0; i < test.size(); ++i) {
        cout << test.at(i) << " ";
    }
    cout << endl;
    test.erase(ind);
    cout << "List is: ";
    for (unsigned int i = 0; i < test.size(); ++i) {
        cout << test.at(i) << " ";
    }
    cout << endl;

    cout << endl;
    cout << "Testing push_back function..." << endl;
    cout << "What value would you like to append?" << endl;
    cin >> val;
    cout << "List was: ";
    for (unsigned int i = 0; i < test.size(); ++i) {
        cout << test.at(i) << " ";
    }
    cout << endl;
    test.push_back(val);
    cout << "List is: ";
    for (unsigned int i = 0; i < test.size(); ++i) {
        cout << test.at(i) << " ";
    }
    cout << endl;

    unsigned newSize = 0;
    cout << endl;
    cout << "Testing resize function..." << endl;
    cout << "What size would you like to resize your vector to?" << endl;
    cin >> newSize;
    cout << "What value would you like to assign?" << endl;
    cin >> val;
    cout << "List was: ";
    for (unsigned int i = 0; i < test.size(); ++i) {
        cout << test.at(i) << " ";
    }
    cout << endl;
    test.resize(newSize, val);
    cout << "List is: ";
    for (unsigned int i = 0; i < test.size(); ++i) {
        cout << test.at(i) << " ";
    }
    cout << endl;

    cout << endl;
    cout << "Testing reserve function..." << endl;
    cout << "To what capacity would you like to increase your vector to?" << endl;
    cin >> val;
    cout << "Previous capacity: " << test.capacity() << endl;
    test.reserve(val);
    cout << "New capacity: " << test.capacity();
    cout << endl;

    cout << endl;
    cout << "Testing assign function..." << endl;
    cout << "What will the new size of your vector be?" << endl;
    cin >> newSize;
    cout << "What would you like all of the values to equal?" << endl;
    cin >> val;
    cout << "List was: ";
    for (unsigned int i = 0; i < test.size(); ++i) {
        cout << test.at(i) << " ";
    }
    cout << endl;
    test.assign(newSize, val); 
    cout << "List is: ";
    for (unsigned int i = 0; i < test.size(); ++i) {
        cout << test.at(i) << " ";
    }
    cout << endl;
    
    cout << endl;
    cout << "Testing pop_back function..." << endl;
    cout << "Initial size: " << test.size() << endl;
    test.pop_back();
    cout << "New size: " << test.size() << endl;
    cout << endl;

    cout << "Testing clear function..." << endl;
    cout << "Initial size: " << test.size() << endl;
    test.clear();
    cout << "New size: " << test.size() << endl;
    cout << endl;
}   