# CHAPTER 7

## SECTIONS:
- [CHAPTER 7](#chapter-7)
  - [SECTIONS:](#sections)
  - [7.1 Inline Member Functions](#71-inline-member-functions)
  - [7.3 A First Linked List](#73-a-first-linked-list)
  - [7.4 Singly-Linked Lists](#74-singly-linked-lists)
  - [7.5 Singly-linked lists: Insert](#75-singly-linked-lists-insert)
  - [7.6 Singly-linked lists: Remove](#76-singly-linked-lists-remove)
  - [7.7 Copy Constructors](#77-copy-constructors)
  - [7.8 Copy Assignment Operator](#78-copy-assignment-operator)
  - [7.9 Rule of Three](#79-rule-of-three)

## 7.1 Inline Member Functions
> **inline member function:** a member function's definition that appears within the class definition
---
### Inline Member Functions
```cpp
    #include <iostream>
    #include <string>
    using namespace std;

    class Restaurant {                        // Info about a restaurant
    public:
        void SetName(string restaurantName) { // Sets the restuarant's name
            name = restaurantName;
        }
        void SetRating(int userRating) {      // Sets the rating (1-5, with 5 best)
            rating = userRating;
        }
        void Print();                         // Prints name and rating on one line
    
    private:
        string name;
        int rating;
    };
```
### Constructor Initializer Lists
> **constructor initializer list:** an alternative approach for initializing data members in
a constructor, coming after a colon and consisting of a comma-separated list of 
`variableName(initValue)` items.
---
Using a constructor initializer list
```cpp
    #include <iostream>
    using namespace std;

    class SampleClass {
    public:
        SampleClass();
        void Print() const;

    private:
        int field1;
        int field2;
    };

    SampleClass::SampleClass() : field1(100), field2(200) {
    }

    void SampleClass::Print() const {
        cout << Field1:  << field1 << endl;
        cout << Field2:  << field2 << endl;
    }

    int main() {
        SampleClass myClass;
        myClass.Print();
        return 0;
    }
```

## 7.3 A First Linked List
> **list node:** a class defined to represent each list item
> - is comprised of the data to be stored in each list item  
---
### Linked list example
```c++
    #include <iostream>
    using namespace std;

    class IntNode {
        public:
            IntNode(int dataInit = 0, IntNode* nextLoc = nullptr);
            void InsertAfter(IntNode* nodeLoc);
            IntNode* GetNext();
            void PrintNodeData();
        private:
            int dataVal;
            IntNode* nextNodePtr;
    };

    // Constructor
    IntNode::IntNode(int dataInit, IntNode* nextLoc) {
        this->dataVal = dataInit;
        this->nextNodePtr = nextLoc;
    }

    /* Insert node after this node.
    * Before: this -- next
    * After:  this -- node -- next
    */
    void IntNode::InsertAfter(IntNode* nodeLoc) {
        IntNode* tmpNext = nullptr;
        
        tmpNext = this->nextNodePtr;    // Remember next
        this->nextNodePtr = nodeLoc;    // this -- node -- ?
        nodeLoc->nextNodePtr = tmpNext; // this -- node -- next
    }

    // Print dataVal
    void IntNode::PrintNodeData() {
        cout << this->dataVal << endl;
    }

    // Grab location pointed by nextNodePtr
    IntNode* IntNode::GetNext() {
        return this->nextNodePtr;
    }

    int main() {
        IntNode* headObj  = nullptr; // Create IntNode objects
        IntNode* nodeObj1 = nullptr;
        IntNode* nodeObj2 = nullptr;
        IntNode* nodeObj3 = nullptr;
        IntNode* currObj  = nullptr;
        
        // Front of nodes list
        headObj = new IntNode(-1);
        
        // Insert nodes
        nodeObj1 = new IntNode(555);
        headObj->InsertAfter(nodeObj1);
        
        nodeObj2 = new IntNode(999);
        nodeObj1->InsertAfter(nodeObj2);
        
        nodeObj3 = new IntNode(777);
        nodeObj1->InsertAfter(nodeObj3);
        
        // Print linked list
        currObj = headObj;
        while (currObj != nullptr) {
            currObj->PrintNodeData();
            currObj = currObj->GetNext();
        }
        
        return 0;
    }
```

## 7.4 Singly-Linked Lists 
> **singly-linked list:** a structure for implementing a list ADT, where each node has data and a pointer to the next node.
> - A singly-linked lists first node is called the head
> - A singly-linked lists last node is called the tail
> - It is a type of positional list; where elements contain pointers to the next and/or previous elements in the list.  

> **Append:** inserts the new node after the list's tail node
> - The append algorithm behavior differs if the list is empty versus not empty:
>   - *Append to empty list:* if the lists head pointer is null, the algorithm points the lists head and tail pointers to the new node.
>   - *Append to a non-empty list:* if the lists head pointer is not null, the algorithm points the tail node's next pointer and the lists tail pointer to the new node  

> **Prepend:** inserts the new node before the list's head node
> - The prepend algorithm behavior differs if the list is empty versus not empty:  
>   - *Prepend to empty list:* if the lists head pointer is null, the algorithm points the lists head and tail pointers to the new node.
>   - *Prepend to a on-empty list:* if the lists head pointer is not null, the algorithm points the new nodes next pointer to the head node, and then points the lists head pointer to the new node.
      
## 7.5 Singly-linked lists: Insert
> **InsertAfter:** inserts the new node after a provided existing list node
> - The InsertAfter algorithm considers three insertion scenarios:
>   - *Insert as lists first node:* if the lists head pointer is null, the algorithm points the lists head and tail pointers to the new node.
>   - *Insert after lists tail node:* if the lists head pointer is not null, and curNode points to the lists tail node, the algorithm points the tail nodes next pointer and the lists tail pointer to the new node.
>   - *Insert in middle of list:* if the lists head pointer is not null and curNode does not point to the lists tail node, the algorithm points the new nodes next pointer to curNodes next node, and then points curNode's next pointer to the new node.

## 7.6 Singly-linked lists: Remove
> **RemoveAfter:** removes the node after the specified list node
>   - The existing node is specified with the curNode parameter. 
>   - If curNode is null, RemoveAfter removes the lists first node.
>   - Remove lists head node: if curNode is null, the algorithm points sucNode to the head nodes next node, and points the lists head pointer to sucNode. If sucnode is null, the only list node was removed, so the lists tail pointer is pointed to null (indicating the list is now empty)
>   - Remove node after curNode: if curNode's next pointer is not null, the algorithm points sucNode to the node after curNode's next node. Then curNode's next pointer is pointed to sucNode. If sucNode is null, the lists tail node was removed, so the algorithm points the lists tail pointer to curNode (the new tail node). 

## 7.7 Copy Constructors
> **Copy constructor:** constructor that is automatically called when an object of the class type is passed by value to a function and when an object is initialized by copying another object during declaration

> **deep copy:** when a copy constructor makes a new copy of all data members (including
    pointers)

> **shallow copy:** creating a copy of an object by copying only the data members' values
---
### 7. 2. 2: Write a Copy Constructor
Write a copy constructor for CarCounter that assigns origCarCounter.carCount to the constructed object's carCount. Sample output for the given program:  

Cars counted: 5
``` c++
      #include <iostream>
      using namespace std;

      class CarCounter {
      public:
         CarCounter();
         CarCounter(const CarCounter& origCarCounter);
         void SetCarCount(const int count) {
            carCount = count;
         }
         int GetCarCount() const {
            return carCount;
         }
      private:
         int carCount;
      };

      CarCounter::CarCounter() {
         carCount = 0;
      }

      // copy constructor below

       CarCounter::CarCounter(const CarCounter& origCarCounter) {
         carCount = (origCarCounter.carCount);
      }

      void CountPrinter(CarCounter carCntr) {
         cout << Cars counted:  << carCntr.GetCarCount();
      }

      int main() {
         CarCounter parkingLot;
         int count;

         cin >> count;

         parkingLot.SetCarCount(count);
         CountPrinter(parkingLot);

         return 0;
      }
```

## 7.8 Copy Assignment Operator 
### Assignment Operator Performs a Deep Copy
```c++
    #include <iostream>
    using namespace std;

    class MyClass {
        public:
            MyClass();
            ~MyClass();
            MyClass& operator=(const MyClass& objToCopy);
            
            // Set member value dataObject
            void SetDataObject(const int setVal) {
                *dataObject = setVal;
            }
            
            // Return member value dataObject
            int GetDataObject() const {
                return *dataObject;
            }
        private:
            int* dataObject;// Data member
    };

    // Default constructor
    MyClass::MyClass() {
        cout << Constructor called. << endl;
        dataObject = new int; // Allocate mem for data
        *dataObject = 0;
    }

    // Destructor
    MyClass::~MyClass() {
        cout << Destructor called. << endl;
        delete dataObject;
    }

    MyClass& MyClass::operator=(const MyClass& objToCopy) {
        cout << Assignment op called. << endl;
    
        if (this != &objToCopy) {                   // 1. Don't self-assign
            delete dataObject;                      // 2. Delete old dataObject
            dataObject = new int;                   // 3. Allocate new dataObject
            *dataObject = *(objToCopy.dataObject);  // 4. Copy dataObject
        }
    
        return *this;
    }

    int main() {
        MyClass classObj1; // Create object of type MyClass
        MyClass classObj2; // Create object of type MyClass
        
        // Set and print object 1 data member value
        classObj1.SetDataObject(9);
        
        // Copy class object using copy assignment operator
        classObj2 = classObj1;
        
        // Set object 1 data member value
        classObj1.SetDataObject(1);
        
        // Print data values for each object
        cout << classObj1: << classObj1.GetDataObject() << endl;
        cout << classObj2: << classObj2.GetDataObject() << endl;
        
        return 0;
    }

    //OUTPUTS ARE AS FOLLOWS:
        // Constructor called.
        // Constructor called.
        // Assignment op called.
        // obj1:1
        // obj2:9
        // Destructor called.
        // Destructor called.
```
---
### 7. 8. 2: Write a Copy Assignment
Write a copy assignment operator for CarCounter that assigns objToCopy.carCount to the new objects's 
    carCount, then returns *this. Sample output for the given program:  
    Cars counted: 12
```c++
    #include <iostream>
    using namespace std;

    class CarCounter {
    public:
        CarCounter();
        ~CarCounter();
        CarCounter& operator=(const CarCounter& objToCopy);
        void SetCarCount(const int setVal) {
            *carCount = setVal;
        }
        int GetCarCount() const {
            return *carCount;
        }
    private:
        int* carCount;
    };

    CarCounter::CarCounter() {
        carCount = new int;
        *carCount = 0;
    }

    CarCounter::~CarCounter() {
        delete carCount;
    }

    // copy assignment operator below

    CarCounter& CarCounter::operator=(const CarCounter& objToCopy) {
        delete carCount;
        carCount = new int;
        *carCount = *(objToCopy.carCount);
    }

    int main() {
        CarCounter frontParkingLot;
        CarCounter backParkingLot;
        int count;

        cin >> count;

        frontParkingLot.SetCarCount(count);
        backParkingLot = frontParkingLot;

        cout << Cars counted:  << backParkingLot.GetCarCount();

        return 0;
    }
```

## 7.9 Rule of Three 
> **Destructor:** A destructor is a class member function that is automatically called when an object of the class is destroyed, such as when the object goes out of scope or is explicitly destroyed as in delete someObject;.
    
> **Copy constructor:** A copy constructor is another version of a constructor that can be called with a single pass by reference argument. The copy constructor is automatically called when an object is passed by value to a function, such as for the function SomeFunction(MyClass localObject) and the call SomeFunction(anotherObject), when an object is initialized when declared such as MyClass classObject1 = classObject2;, or when an object is initialized when allocated via new as in newObjectPtr = new MyClass(classObject2);
    
> **Copy assignment operator:** The assignment operator = can be overloaded for a class via a member function, known as the copy assignment operator, that overloads the built-in function operator=, the member function having a reference parameter of the class type and returning a reference to the class type.
    
> **Rule of three:** describes a practice that if a programmer explicitly defines any one of those three special member functions (destructor, copy constructor, copy assignment operator), then the programmer should explicitly define all three.
