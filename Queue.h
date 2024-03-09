#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue {
private:
  Node* front;
  Node* rear;

public:
  Queue();
  void enqueue(int data);
  int dequeue();
  bool isEmpty();
};

#endif 
