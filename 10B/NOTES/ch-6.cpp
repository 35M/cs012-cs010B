6.7 Vector ADT {
    *standard template library (STL): "defines classes for common Abstract Data Types (ADTs)."
    *vector: "an ADT of an ordered, indexable list of items"
        - The vector ADT is implemented as a "class" which supports different types, such as:
            vector<int> or vector<string>
=========================================================================================================
    For the commonly-used vector member functions below, assume a vector is declared as:
    vector<T> vectorName();
        where T represents the vectors element type, such as:
    vector<int> teamNums(5);

    ```VECTOR ADT FUNCTIONS``` {
        at()
            at(size_type n)
            Accesses element n.
            -----------
            teamNums.at(3) = 99;    // Assigns 99 to element 3 
            x = teamNums.at(3);     // Assigns element 3's value 99 to x
            
        size()
            size_type size() const;
            Returns vector size.
            -----------
            if (teamNums.size() > 0) {  // Size is 5 so condition is true
            ...
            }

        empty()
            bool empty() const;
            Returns true if size is 0.
            -----------
            if (teamNums.empty()) {  // Size is 5 so condition is false
            ...
            }

        clear()
            Removes all elements. Vector size becomes 0.
            -----------
            teamNums.clear();         // Vector now has no elements
            cout << teamNums.size();  // Prints 0
            teamNums.at(3) = 88;      // Error; element 3 does not exist

        push_back()
            void push_back(const T& x);
            Copies x to new element at vectors end, increasing size by 1.
            Parameter is pass by reference to avoid making local copy, but 
            const to make clear not changed.
            -----------
            // Assume vector is empty
            teamNums.push_back(77);  // Vector is: 77 
            teamNums.push_back(88);  // Vector is: 77, 88
            cout << teamNums.size(); // Prints 2

        erase()
            iterator erase (iteratorPosition);
            Removes element from position. Elements from higher positions
            are shifted back to fill gap. Vector size decrements.
            -----------
            // Assume vector is 77, 33, 88
            teamNums.erase(teamNums.begin() + 1); // Now 77, 88
            // (Strange position indication explained below)

        insert()
            iterator insert(iteratorPosition, const T& x);
            Copies x to element at position. Items at that position and
            higher are shifted over to make room. Vector size increments.
            -----------
            // Assume vector is 77, 88
            teamNums.insert(teamNums.begin() + 1, 33); // Now 77, 33, 88
    }

    ```6. 7. 4: Insert() and Erase() vector member functions```
        int main() {
            unsigned int i;
            vector<int> vctr;

            vctr.push_back(27);
            vctr.push_back(44);
            vctr.push_back(9);
            vctr.push_back(17);                                    // List is: 27, 44, 9, 17
            vctr.erase(vctr.begin() + 1);                          // List is: 27, 9, 17
            vctr.insert(vctr.begin() + 0, 88);                     // List is: 88, 27, 9, 17
            vctr.erase(vctr.begin() + 3);                          // List is: 88, 27, 9

            cout << "Contents:" << endl;                           // Output:
            for (i = 0; i < vctr.size(); ++i) {                    // Contents:
                cout << " " << vctr.at(i) << endl;                 // 88
            }                                                      // 27
            cin >> i;                                              // 9 
            return 0;
        }
}