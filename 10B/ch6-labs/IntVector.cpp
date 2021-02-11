#include "IntVector.h"
#include <iostream> 
#include <vector>
#include <stdexcept>
using namespace std;

IntVector::IntVector(unsigned capacity, int value) {
    _size = capacity;
    _capacity = capacity;
    _data = nullptr;
    if (capacity > 0) {
        _data = new int[capacity];
        for (unsigned int i = 0; i < _size; i++) {
            _data[i] = value; 
        }
    }
}

IntVector::~IntVector() {
    delete[] _data;
}

unsigned IntVector::size() const {
    return _size;
}

unsigned IntVector::capacity() const {
    return _capacity;
}

bool IntVector::empty() const {
    bool empty = true;

    if (_size != 0) {
        empty = false;
    }
    else {
        empty = true;
    }
    return empty;
}

const int & IntVector::at(unsigned index) const {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return _data[index];
    }
}

const int & IntVector::front() const {
    return _data[0];
}

const int & IntVector::back() const {
    return _data[_size - 1];
}