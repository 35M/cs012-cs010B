#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
	int value;
	IntNode *next;
	IntNode(int value) : value(value), next(nullptr) { }
};

class IntList {
 private:
	IntNode *head;
	IntNode *tail;
 public:
	//Initializes an empty list.
	IntList();

	//Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
	~IntList();

	//Inserts a data value (within a new node) at the front end of the list.
	void push_front(int value);

	/*Removes the value (actually removes the node that contains the value) at the front 
	end of the list. Does nothing if the list is already empty.*/
	void pop_front();

	/* Returns true if the list does not store any data values (does not have any nodes), 
	otherwise returns false. */
	bool empty() const;

	/* Returns a reference to the first value in the list. Calling this on an empty list 
	causes undefined behavior.*/
	const int & front() const;

	/* Returns a reference to the last value in the list. Calling this on an empty list 
	causes undefined behavior. */
	const int & back() const;

	/* Overloads the insertion operator (<<) so that it sends to the output stream 
	(ostream) a single line all of the int values stored in the list, each separated by 
	a space. This function does NOT send a newline or space at the end of the line. */
	friend ostream & operator<<(ostream &out, const IntList &list);
};

#endif
