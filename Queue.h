#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

class Queue {
private:
  LinkedList list;
public:
  void enqueue(int data);
  int dequeue();
  bool isEmpty() const;
};

#endif 

