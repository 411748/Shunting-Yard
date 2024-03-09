//Queue.cpp
#include <iostream>
#include "Queue.h"

//Functions for queue
//Enqueue function
void Queue::enqueue(int data) {
  list.append(data);
}
//Dequeue function
int Queue::dequeue() {
  return list.pop();
}
//isEmpty bool
bool Queue::isEmpty() const {
  return list.isEmpty();
}
