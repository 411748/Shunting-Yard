#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() : front(nullptr), rear(nullptr) {}

void Queue::enqueue(int data) {
  Node* newNode = new Node(data);
  if (isEmpty()) {
    front = newNode;
  } else {
    rear->next = newNode;
  }
  rear = newNode;
}

int Queue::dequeue() {
  if (isEmpty()) {
    cout << "Queue empty" << endl;
    return -1; 
  }
  int dequeued = front->data;
  Node* temp = front;
  front = front->next;
  delete temp;
  if (front == nullptr) {
    rear = nullptr;
  }
  return dequeued;
}

bool Queue::isEmpty() {
  return front == nullptr;
}
