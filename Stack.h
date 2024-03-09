#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

class Stack {
private:
  LinkedList list;
public:
  void push(int data);
  int pop();
  bool isEmpty() const;
};

#endif
