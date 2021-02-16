7.1 Inline Member Functions {
    *inline member function: "a member function's definition that appears within the class
    definition"
============================================================================================
    ```Inline Member Functions```
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
}

7.2 Constructor Initializer Lists {
    *constructor initializer list: "an alternative approach for initializing data members in
    a constructor, coming after a colon and consisting of a comma-separated list of 
    variableName(initValue) items."
============================================================================================
    ```Using a constructor initializer list```
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
        cout << "Field1: " << field1 << endl;
        cout << "Field2: " << field2 << endl;
    }

    int main() {
        SampleClass myClass;
        myClass.Print();
        return 0;
    }
}

7.3 A First Linked List {
    *list node: "a class defined to represent each list item"
    - comprised of the data to be stored in each list item
============================================================================================
    ```Linked list example```
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
}

7.4 Singly-Linked Lists {
    *singly-linked list: "a structure for implementing a list ADT, where each node has data
    and a pointer to the next node."
        - A singly-linked lists first node is called the HEAD
        - A singly-linked lists last node is called the tail
        - It is a type of positional list; where elements contain pointers to the next
        and/or previous elements in the list.
    *Append: "inserts the new node after the list's tail node"
        - The append algorithm behavior differs if the list is empty versus not empty:
            - *Append to empty list: if the lists head pointer is null, the algorithm
            points the lists head and tail pointers to the new node.
            - *Append to a non-empty list: if the lists head pointer is not null, the 
            algorithm points the tail node's next pointer and the lists tail pointer 
            to the new node
    *Prepend: "inserts the new node before the list's head node"
        - The prepend algorithm behavior differs if the list is empty versus not empty:
            - *Prepend to empty list: if the lists head pointer is null, the algorithm
            points the lists head and tail pointers to the new node.
            - *Prepend to a on-empty list: if the lists head pointer is not null, the 
            algorithm points the new nodes next pointer to the head node, and then points
            the lists head pointer to the new node.
        
}

7.5 Singly-linked lists: Insert {
    *InsertAfter: "inserts the new node after a provided existing list node"
        - The InsertAfter algorithm considers three insertion scenarios:
            - *Insert as lists first node: if the lists head pointer is null, the algorithm
            points the lists head and tail pointers to the new node.
            - *Insert after lists tail node: if the lists head pointer is not null, and 
            curNode points to the lists tail node, the algorithm points the tail nodes
            next pointer and the lists tail pointer to the new node.
            - *Insert in middle of list: if the lists head pointer is not null and curNode
            does not point to the lists tail node, the algorithm points the new nodes
            next pointer to curNodes next node, and then points curNode's next pointer to 
            the new node.
}

7.6 Singly-linked lists: Remove {
    *RemoveAfter: "removes the node after the specified list node"
        - The existing node is specified with the curNode parameter. 
        If curNode is null, RemoveAfter removes the lists first node.
            - *Remove lists head node: if curNode is null, the algorithm points sucNode to
            the head nodes next node, and points the lists head pointer to sucNode. If 
            sucnode is null, the only list node was removed, so the lists tail pointer is
            pointed to null (indicating the list is now empty)
            - *Remove node after curNode: if curNode's next pointer is not null, the 
            algorithm points sucNode to the node after curNode's next node. Then curNode's 
            next pointer is pointed to sucNode. If sucNode is null, the lists tail node was 
            removed, so the algorithm points the lists tail pointer to curNode (the new
            tail node). 
}