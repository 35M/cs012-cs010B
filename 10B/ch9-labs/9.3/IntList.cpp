#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator<<(ostream &out, const IntList &list) {
   if (list.head) {
      out << list.head -> value << list.head -> next;
   }
   return out;
}
  
bool IntList::exists(int temp) const {
   return exists(head, temp);
}

bool IntList::exists(IntNode *node, int temp) const {
   if (node == nullptr) {
      return false;
   }

   if (temp == node -> value) {
      return true;
   }

   else {
      return exists(node -> next, temp);
   }
}

ostream & operator<<(ostream & out, IntNode *node) {
   if (node) {
      out << " " << node -> value << node -> next;
   }
   return out;
}