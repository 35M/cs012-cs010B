#ifndef SORTEDSET_H
#define SORTEDSET_H

#include <iostream>
#include "IntList.h"

using namespace std;

class SortedSet : public IntList {

public:
    SortedSet();
    SortedSet(const SortedSet &);
    SortedSet(const IntList &);
    ~SortedSet();

    bool in(int value);
    SortedSet operator|(const SortedSet &);
    SortedSet operator&(const SortedSet &);
    
    void add(int value);
    void push_front(int value);
    void push_back(int value);
    void insert_ordered(int value);
    SortedSet& operator|=(const SortedSet &);
    SortedSet& operator&=(const SortedSet &);

};

#endif