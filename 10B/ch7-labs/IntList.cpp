#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {
    while (head != nullptr) {
        IntNode *temp = head;
        head = head -> next;
        delete temp;
    }
}

void IntList::push_front(int value) {
    if (tail == nullptr) {
        tail = head;
    }
    IntNode *temp = new IntNode(value);
    temp -> next = head;
    head = temp;
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

bool IntList::empty() const {
    bool list;
    if (head == nullptr && tail == nullptr) {
        list = true;
    }
    else {
        list = false;
    }
    return list;
}

const int & IntList::front() const {
    return head -> value;
}

const int & IntList::back() const {
    return tail -> value;
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