#include "Stack.h"
#include <iostream>
#include <cstring>

using namespace std;

Stack::Stack() : top(nullptr) {}

void Stack::push(int data) {
  Node* newNode = new Node(data);
  newNode->next = top;
  top = newNode;
}

int Stack::pop() {
  if (isEmpty()) {
    cout << "Stack empty" << endl;
    return -1; 
  }
  int popped = top->data;
  Node* temp = top;
  top = top->next;
  delete temp;
  return popped;
}

int Stack::peek() {
  if (isEmpty()) {
    cout << "Stack empty" << endl;
    return -1; 
  }
  return top->data;
}

bool Stack::isEmpty() {
  return top == nullptr;
}
