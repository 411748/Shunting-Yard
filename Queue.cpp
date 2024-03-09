#include <iostream>
#include "Queue.h"

void Queue::enqueue(int data) {
  list.append(data);
}

int Queue::dequeue() {
  return list.pop();
}

bool Queue::isEmpty() const {
  return list.isEmpty();
}
