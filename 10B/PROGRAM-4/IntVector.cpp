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
        _data = new int[_capacity];
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

void IntVector::expand() {
    int *temp = _data;

    if (_capacity > 0) {
        _capacity = _capacity * 2;
        _data = new int[_capacity];
        for (unsigned int i = 0; i < _size; i++) {
            _data[i] = temp[i];
        }
    }
    if (_capacity == 0) {
        _capacity = 1;
        _data = new int[_capacity];
    }
    delete[] temp;
}

void IntVector::expand(unsigned amount) {
    int *temp = _data;

    _capacity = _capacity + amount;
    _data = new int [_capacity];
    for (unsigned int i = 0; i < _size; i++) {
        _data[i] = temp[i];
    }
    delete[] temp;
}

void IntVector::insert(unsigned index, int value) {
    _size = _size + 1;
    
    if (_size > _capacity) {
        expand();
    }

    for (unsigned int i = index; i < _size; i++) {
        _data[i + 1] = _data[i];
    }

    if (index >= _size) {
        throw out_of_range("IntVector::insert_range_check");
    }
    _data[index] = value;
}

void IntVector::erase(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned int i = index + 1; i < _size; i++) {
        _data[i - 1] = _data[i];
    }
    _size = _size - 1;
}

void IntVector::push_back(int value) {
    if (_size + 1 >= _capacity) {
        expand();
    }
    _size = _size + 1;

    _data[_size - 1] = value;
}

void IntVector::pop_back() {
    _size = _size - 1;
}

void IntVector::clear() {
    _size = 0;
}

void IntVector::resize(unsigned size, int value) {
    if (size < _size) {
        _size = size;
    }
    else {
        if (size > _capacity * 2) {
            expand(size - _capacity);
        }
        if (size > _capacity) {
            expand();
        }
        for (unsigned int i = _size; i < size; ++i) {
            _size = size;
            _data[i] = value;
        }
    }
}

void IntVector::reserve(unsigned n) {
    if (n > _capacity) {
        expand(n - _capacity);
    }
}

void IntVector::assign(unsigned n, int value) {
    if (n > _capacity) {
        if (n > _capacity * 2) {
            expand(n - _capacity);
        }
        else {
            expand();
        }
    }
    _size = n;
    for (unsigned int i = 0; i < _size; ++i) {
        _data[i] = value;
    }
}

int & IntVector::at(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return _data[index];
    }
}

int & IntVector::front() {
    return _data[0];
}

int & IntVector::back() {
    return _data[_size - 1];
}