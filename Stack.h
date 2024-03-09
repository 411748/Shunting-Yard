#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <cstring>

class Stack {
private:
  Node* top;
public:
  Stack();
  void push(int data);
  int pop();
  int peek();
  bool isEmpty();
};

#endif 
