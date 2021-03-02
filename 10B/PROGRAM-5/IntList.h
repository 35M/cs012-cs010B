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

	/* the copy constructor. Make sure this performs deep copy. */
	IntList(const IntList &cpy);

	/* the overloaded assignment operator. Make sure this performs deep copy. */
	IntList & operator=(const IntList &rhs);

	/* Inserts a data value (within a new node) at the back end of the list. */
	void push_back(int value);

	/* Removes (deallocates) all IntNodes in the IntList. Don't forget to set both head 
	and tail to appropriate values for an empty list. DO NOT leave them dangling! */
	void clear();

	/* Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers. */
	void selection_sort();

	/* Inserts a data value (within a new node) in an ordered list. Assumes the list is already sorted 
	in ascending order (i.e., Do not sort the list first, assume the list is already is sorted.) 
	This function loops through the list until if finds the correct position for the new data value and 
	then inserts the new IntNode in that location. This function may NOT ever sort the list. */
	void insert_ordered(int value);

	/* Removes all duplicate data values (actually removes the nodes that contain the values) within the list. 
	Always remove just the later value within the list when a duplicate is found. This function may NOT ever 
	sort the list. */
	void remove_duplicates();
};

#endif
