#include <iostream>
#include "SortedSet.h"

using namespace std;

SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet &copySet) : IntList(copySet) {}

SortedSet::SortedSet(const IntList &otherSet) : IntList(otherSet) {
    this->selection_sort();
    this->remove_duplicates();
}

SortedSet::~SortedSet() {
    clear();
}

bool SortedSet::in(int value) {
    IntNode* i = head;
    while (i != nullptr) {
        if (i -> value == value) {
            return true;
        }
        i = i -> next;
    }
    return false;
}

SortedSet SortedSet::operator|(const SortedSet &set) {
    SortedSet temp = *this;
    IntNode* i = set.head;
    while (i != nullptr) {
        temp.insert_ordered(i -> value);
        i = i -> next;
    }
    return temp;
}

SortedSet SortedSet::operator&(const SortedSet &set) {
    SortedSet temp;
    IntNode* i = set.head;
    while (i != nullptr) {
        if (in(i -> value) == true) {
            temp.push_back(i -> value);
        }
        i = i -> next;
    }
    return temp;
}

void SortedSet::add(int value) {
    if (!in(value)) {
        IntList::insert_ordered(value);
    }
}

void SortedSet::push_front(int value) {
    add(value);
}

void SortedSet::push_back(int value) {
    add(value);
}

void SortedSet::insert_ordered(int value) {
    add(value);
}

SortedSet& SortedSet::operator|=(const SortedSet &temp) {
    *this = *this | temp;
    return *this;
}

SortedSet& SortedSet::operator&=(const SortedSet &temp) {
    *this = *this & temp;
    return *this;
}

