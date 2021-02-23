8.1 Derived classes {
    *derived class: "a class, or subclass, that is derived from another class, called a 
    base class or superclass"
        - An object of the derived Class type has access to all the public members
        of the derived Class as well as the public members of the base Class.
        - Declared by placing a colon ":" after the derived Class name, followed
        by a member access specifier like public and a base Class name.
            EX: DerivedClass: public BaseClass {...};
    *inheritance: "when the derived class inherits the properties of the base class"
        - Inheritance scenarios:
            - A derived Class can serve as a base Class for another Class.
            EX: class FruitItem: public ProduceItem {...} creates a derived Class 
            FruitItem from ProduceItem, which was derived from GenericItem.
            - A Class can serve as the base Class for multiple derived classes.
            EX: class FrozenFoodItem: public GenericItem {...} creates a derived Class 
            FrozenFoodItem that inherits from GenericItem, just as ProduceItem inherits
            from GenericItem.
            - A Class may be derived from multiple classes.
            EX: class House: public Dwelling, public Property {...} creates a derived 
            Class House that inherits from base classes Dwelling and Property
=======================================================================================
    ```Figure 8. 1. 1: Class ProduceItem is derived from Class GenericItem```
    // Base class
    class GenericItem {
        public:
            void SetName(string newName) { 
                itemName = newName; 
            }
        
            void SetQuantity(int newQty) {
                itemQuantity = newQty; 
            }
        
            void PrintItem() {
                cout << itemName << " " << itemQuantity << endl;
            }
        
        private:
            string itemName;
            int itemQuantity;
    };

    // Derived class inherits from GenericItem 
    class ProduceItem : public GenericItem { 
        public:
            void SetExpiration(string newDate) { 
                expirationDate = newDate; 
            }
        
            string GetExpiration() { 
                return expirationDate; 
            }
        
        private:
            string expirationDate;
    };

}

8.2 Access by members of derived classes {
    *protected: "an access specifier which provides access to derived classes but not
    by anyone else"
        - "public-->protected, protected-->protected -- public and protected members of 
        BaseClass are accessible as protected members of DerivedClass."
    *private: "accessible by self"
        - "public-->private, protected-->private -- public and protected members of 
        BaseClass are accessible as private members of DerivedClass. Incidentally, if the 
        specifier is omitted as in "class DerivedClass: BaseClass {...}", the default is 
        private"
    *public: "accessible by self, derived classes, and everyone else"
        - "public-->public, protected-->protected -- public members of BaseClass are 
        accessible as public members of DerivedClass, and protected members of BaseClass 
        are accessible as protected members of DerivedClass."
=======================================================================================
    ```8. 2. 2: Access specifiers -- Protected allows access by derived classes```
    class Business {   
        protected: // Members accessible by self and derived classes
            string name;
        
        private:   // Members accessible only by self
            string address;

        public:    // Members accessible by anyone
            void PrintMembers();
    };

    class Restaurant : public Business {
        private:
            int rating;

        public:

            ...

            void DisplayRestaurant() {
                // Attempted accesses
                PrintMembers();             // OK
                name = "Gyro Hero";         // OK    ("protected" above made this possible)
                address = "5 Fifth St";     // ERROR
            }

            // Other class members ...

    };

    int main() {
        ...
        
        Business business;
        Restaurant restaurant;
        
        ...
        
        // Attempted accesses
        business.PrintMembers();          // OK
        business.name  = "Gyro Hero";     // ERROR (protected only applies to derived classes)
        business.address = "5 Fifth St";  // ERROR
        
        restaurant.PrintMembers();         // OK
        restaurant.name  = "Gyro Hero";    // ERROR
        restaurant.rating = 5;  // ERROR
        
        return 0;
    }


}

8.3 Overriding Member Functions {
    *override: "when a derived class defines a member function that has the same name
    and parameters as a base class's function"
        - An overriding function can call the overridden function by prepending the base 
        Class name. 
        EX: Business::GetDescription().
        - A common error is to leave off the prepended base name when wanting to call the
        base Class name when wanting to call the base Class function. Without the prepended
        base Class name, the call to GetDescription() refers to itself (a recursive call), 
        so GetDescription() would call itself, which would call itself, etc., never actually
        printing anything.
}

8.4 Is-a versus has-a relationships {
    *Composition: "the idea that one object may be made up of other objects, such as a
    MotherInfo class being made up of objects like firstName, childrenData, etc. 
    Defining that MotherInfo class does not involve inheritance, but rather just composing
    the sub-objects in the class"
============================================================================================
    ```Figure 8. 4. 1: Composition```
    class ChildInfo {
        string firstName;
        string birthDate;
        string schoolName;

        ...
    };
                                            // The 'has-a' relationship.
    class MotherInfo {                      // A MotherInfo object 'has a' string object
        string firstname;                   // and 'has a' vector of ChildInfo objects,
        string birthDate;                   // but no inheritance is involved.
        string spouseName;
        vector<ChildInfo> childrenData;

        ...
    };
--------------------------------------------------------------------------------------------
    /* In contrast, a programmer may note that a mother is a kind of person, and all
    persons have a name and birthdate. So the programmer may decide to better organize
    the program by defining a PersonInfo class, and then by creating the MotherInfo class
    derived from PersonInfo, and likewise for the ChildInfo class. */

    ```Figure 8. 4. 2: Inheritance```
    class PersonInfo {
    string firstName;
    string birthDate;

    ...
    };
                                             // The 'is-a' relationship.
    class ChildInfo : public PersonInfo {    // A MotherInfo object 'is a' kind of PersonInfo
    string schoolName;                       // The MotherInfo object class thus inherits
                                             // from the PersonInfo class. 
    ...                                      // likewise for the ChildInfo class.
    };

    class MotherInfo : public PersonInfo {
    string spouseName;
    vector<ChildInfo> childrenData;

    ...
    };
}