# CHAPTER 8
## SECTIONS:
- [CHAPTER 8](#chapter-8)
  - [SECTIONS:](#sections)
  - [8.1 Derived classes](#81-derived-classes)
    - [Figure 8. 1. 1: Class ProduceItem is derived from Class GenericItem](#figure-8-1-1-class-produceitem-is-derived-from-class-genericitem)
  - [8.2 Access by members of derived classes](#82-access-by-members-of-derived-classes)
    - [8. 2. 2: Access specifiers -- Protected allows access by derived classes](#8-2-2-access-specifiers----protected-allows-access-by-derived-classes)
  - [8.3 Overriding Member Functions](#83-overriding-member-functions)
  - [8.4 Is-a versus has-a relationships](#84-is-a-versus-has-a-relationships)
    - [Figure 8. 4. 1: Composition](#figure-8-4-1-composition)
    - [Figure 8. 4. 2: Inheritance](#figure-8-4-2-inheritance)
  - [8.5 Polymorphism and virtual member functions](#85-polymorphism-and-virtual-member-functions)
    - [Adding a virtual function to the base class](#adding-a-virtual-function-to-the-base-class)
    - [Runtime Polymorphism via a virtual function](#runtime-polymorphism-via-a-virtual-function)

## 8.1 Derived classes
> **derived class:** a class, or subclass, that is derived from another class, called a base class or superclass  
- An object of the derived class type has access to all the public members of the derived class as well as the public members of the base class.
- Declared by placing a colon ":" after the derived class name, followed by a member access specifier like public and a base class name.
    - EX: `DerivedClass: public BaseClass {...};`
> **inheritance:** when the derived class inherits the properties of the base class  
- Inheritance scenarios:
    - A derived class can serve as a base class for another class.
        - EX: `class FruitItem: public ProduceItem {...}` creates a derived class FruitItem from ProduceItem, which was derived from GenericItem.
    - A Class can serve as the base Class for multiple derived classes.
        - EX: `class FrozenFoodItem: public GenericItem {...}` creates a derived class FrozenFoodItem that inherits from GenericItem, just as ProduceItem inherits from GenericItem.
    - A Class may be derived from multiple classes. 
      - EX: `class House: public Dwelling, public Property {...}` creates a derived class House that inherits from base classes Dwelling and Property
---
### Figure 8. 1. 1: Class ProduceItem is derived from Class GenericItem
```c++
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
```

## 8.2 Access by members of derived classes
> **protected:** an access specifier which provides access to derived classes but not by anyone else
- public-->protected, protected-->protected -- public and protected members of BaseClass are accessible as protected members of DerivedClass.
> **private:** accessible by self
- public-->private, protected-->private -- public and protected members of BaseClass are accessible as private members of DerivedClass. Incidentally, if the specifier is omitted as in "class DerivedClass: BaseClass {...}", the default is private
> **public:** accessible by self, derived classes, and everyone else
- public-->public, protected-->protected -- public members of BaseClass are accessible as public members of DerivedClass, and protected members of BaseClass are accessible as protected members of DerivedClass.
---
### 8. 2. 2: Access specifiers -- Protected allows access by derived classes
```c++
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
```
## 8.3 Overriding Member Functions
> **override:** when a derived class defines a member function that has the same name and parameters as a base class's function
- An overriding function can call the overridden function by prepending the base class name. 
    - EX: `Business::GetDescription().`
- A common error is to leave off the prepended base name when wanting to call the base Class name when wanting to call the base Class function. Without the prepended base Class name, the call to GetDescription() refers to itself (a recursive call), so GetDescription() would call itself, which would call itself, etc., never actually printing anything.

## 8.4 Is-a versus has-a relationships
> **Composition:** the idea that one object may be made up of other objects, such as a MotherInfo class being made up of objects like firstName, childrenData, etc. Defining that MotherInfo class does not involve inheritance, but rather just composing the sub-objects in the class
---
### Figure 8. 4. 1: Composition 
```c++
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
```
---
In contrast, a programmer may note that a mother is a kind of person, and all persons have a name and birthdate. So the programmer may decide to better organize the program by defining a PersonInfo class, and then by creating the MotherInfo class derived from PersonInfo, and likewise for the ChildInfo class.

### Figure 8. 4. 2: Inheritance
```C++
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
```
## 8.5 Polymorphism and virtual member functions
> **Polymorphism:** determining which program behavior to execute depending on data types  

> **Compile-time polymorphism:** when the compiler determines which function to call at compile time  
- EX: function overloading

> **Runtime polymorphism:** when the compiler is unable to determine which function to call at compile-time, so the determination is made while the program is running  

> **Derived/base class pointer conversion:** where a pointer to a derived class is converted to a pointer to the base class without explicit casting  

> **Virtual function:** member function that may be overridden in a derived class and is used for runtime polymorphism
- Declared by prepending the word 'virtual'
    - EX: `virtual string GetDescription() const`
> **Override:** "an optional keyword used to indicate that a virtual function is overridden in a derived class. Use it when overriding a virtual function to avoid accidentally misspelling the function name or typing the wrong parameters"  

> **Virtual table:** table that contains an entry for each virtual function with a function pointer that points to the most-derived function that is accessible to each class; allows computer to lookup which function to call at runtime

> **pure virtual function:** function that provides no definition in the base class abd all derived classes must override the function  
   
> **abstract base class:** a class that has at least one pure virtual function; cannot be declared
---
### Adding a virtual function to the base class
```c++
    class Business {
        public:
        virtual string GetDescription() const {
            return name + " -- " + address;
        }
        ...
    };

    class Restaurant : public Business {
        public:
        string GetDescription() const override {
            return name + " -- " + address +
                "\n  Rating: " + to_string(rating);
        }
        ...                                             // Output with NO virtual function:
    };                                                  // Friends Cafe -- 500 2nd Ave
                                                        // Output with virtual function:
    int main() {                                        // Friends Cafe -- 500 2nd Ave
        Business* businessPtr;                          //    Rating: 5  
        Restaurant favoriteCafe;
        favoriteCafe.SetName("Friends Cafe");
        favoriteCafe.SetAddress("500 2nd Ave");
        favoriteCafe.SetRating(5);

        // Point to favoriteCafe
        businessPtr = &favoriteCafe;

        cout << businessPtr->GetDescription();
    }
    
    /*
        1. Restaurant overrides GetDescription() from the base class Business without using the 
        "override" keyword.
        2. businessPtr points to favoriteCafe. businessPtr->GetDesciption() calls Business 
        GetDescription() instead of Restaurant GetDescription() because runtime polymorphism 
        does not work without virtual functions.
        3. The "virtual" keyword makes GetDescription() a virtual function. The "override" 
        keyword indicates that Restaurant GetDescription() overrides the base class 
        GetDescription().
        4. Running the program with an overridden virtual function causes runtime polymorphism 
        to call Restaurant GetDescription().
    */
```
---
### Runtime Polymorphism via a virtual function
```c++
    #include <iostream>
    #include <string>
    #include <vector>
    using namespace std;

    class Business {
        public:
        void SetName(string busName) {
            name = busName;
        }

        void SetAddress(string busAddress) {
            address = busAddress;
        }

        virtual string GetDescription() const {
            return name + " -- " + address;
        }

        protected:
        string name;
        string address;
    };

    class Restaurant : public Business {
        public:
        void SetRating(int userRating) {
            rating = userRating;
        }

        int GetRating() const {
            return rating;
        }

        string GetDescription() const override {
            return name + " -- " + address +
                "\n  Rating: " + to_string(rating);
        }

        private:
        int rating;
    };

    int main() {
        unsigned int i;
        vector<Business*> businessList;
        Business* businessPtr;
        Restaurant* restaurantPtr;

        businessPtr = new Business;
        businessPtr->SetName("ACME");
        businessPtr->SetAddress("4 Main St");

        restaurantPtr = new Restaurant;
        restaurantPtr->SetName("Friends Cafe");
        restaurantPtr->SetAddress("500 2nd Ave");
        restaurantPtr->SetRating(5);

        businessList.push_back(businessPtr);
        businessList.push_back(restaurantPtr);

        for (i = 0; i < businessList.size(); ++i) {
            cout << businessList.at(i)->GetDescription() << endl;
        }

        return 0;
    }

    //OUTPUTS:
    //ACME -- 4 Main St
    //Friends Cafe -- 500 2nd Ave
    //  Rating: 5
```
