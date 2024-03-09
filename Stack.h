//Stack.h

#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

//Very similar to queue, building linked list for tree
class Stack {
private:
  LinkedList list;
public:
  void push(int data);
  int pop();
  bool isEmpty() const;
};

#endif
