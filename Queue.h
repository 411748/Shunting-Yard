//Queue.h

#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

//Class using linkedlist for queue
class Queue {
private:
  LinkedList list;
public:
  void enqueue(int data);
  int dequeue();
  bool isEmpty() const;
};

#endif 

