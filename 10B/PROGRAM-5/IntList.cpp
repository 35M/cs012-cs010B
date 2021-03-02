#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::IntList(const IntList &cpy) {
    head = nullptr;
    tail = nullptr;
    if (cpy.head == nullptr) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        for (IntNode *curr = cpy.head; curr != nullptr; curr = curr -> next) {
            push_back(curr->value);
        }
    }
}

IntList::~IntList() {
    while (head != nullptr) {
        IntNode *temp = head;
        head = head -> next;
        delete temp;
    }
}

void IntList::push_back(int value) {
    IntNode* temp = new IntNode(value);
    if (empty()) {
        tail = temp;
        head = temp;
    }
    else {
        tail -> next = temp;
        tail = tail -> next;
    }
}

void IntList::push_front(int value) {
    IntNode *temp;
    temp = new IntNode(value);
    temp->next = head;
    head = temp;
    
     if (tail == nullptr) {
        tail = temp;
    }
}

void IntList::pop_front() {
    if (head == nullptr) {
        return;
    }
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        IntNode *temp = head;
        head = head -> next;
        delete temp;
    }
}

void IntList::selection_sort() {
    IntNode *dataVal = nullptr;
    IntNode *succNode = nullptr;
    for (IntNode *curr = head; curr != nullptr; curr = curr -> next) {
        dataVal = curr;
        for (succNode = curr -> next; succNode != nullptr; succNode = succNode -> next) {
            if ((succNode -> value) < dataVal -> value) {
                dataVal = succNode;
            }
        }
        swap(dataVal -> value, curr -> value);
    }
}

void IntList::insert_ordered(int value) {
    IntNode *newVal = new IntNode(value);
    if (head == nullptr) {
        push_front(value);
        return;
    }

    if (newVal -> value <= (head -> value)) {
        push_front(value);
        delete newVal;
        return;
    }

    if (newVal -> value >= (tail -> value)) {
        push_back(value);
        delete newVal;
        return;
    }

    for (IntNode *prev = head; prev != nullptr; prev = prev -> next) {
        IntNode *curr = prev -> next;
        if (value <= (curr -> value) && value >= (prev -> value)) {
            prev -> next = newVal;
            newVal -> next = curr;
            return;
        }
    }
    return;
}

void IntList::remove_duplicates() {
    IntNode *temp = nullptr;
    for (IntNode *i = head; i != nullptr; i = i -> next) {
        IntNode *prev = i;
        for (IntNode *curr = i -> next; curr != nullptr; curr = prev -> next) {
            if (i -> value == curr -> value) {
                if (curr == tail) {
                    temp = curr;
                    tail = prev;
                    tail -> next = nullptr;
                    curr = nullptr;
                    delete temp;
                }
                else {
                    temp = curr;
                    prev -> next = curr -> next;
                    delete temp;
                }
            }
            else {
                prev = prev -> next;
            }
        }
    }
}

void IntList::clear() {
    while (head != nullptr) {
        IntNode *temp = this -> head;
        head = head -> next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

bool IntList::empty() const {
    if (head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

const int & IntList::front() const {
    return head -> value;
}

const int & IntList::back() const {
    return tail -> value;
}

IntList & IntList::operator=(const IntList &rhs) {
    if (this != &rhs) {
        clear();
        if (rhs.head == nullptr) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = nullptr;
            tail = nullptr;
            for (IntNode *curr = rhs.head; curr != nullptr; curr = curr -> next) {
                push_back(curr->value);
            }
        }
    }
    return *this;
}

ostream & operator<<(ostream &out, const IntList &list) {
    IntNode *currNode = list.head;
    while (currNode != nullptr) {
        out << currNode -> value;

        if (currNode -> next != nullptr) {
            out << " ";
        }
        currNode = currNode -> next;
    }
    return out;
}