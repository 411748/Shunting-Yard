//LinkedList.cpp

#include "LinkedList.h"
#include <cstring>
#include <iostream>

using namespace std;

LinkedList::LinkedList() : head(nullptr) {}

//Functions for shunting yard algorithms
LinkedList::~LinkedList() {
  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

//append function
void LinkedList::append(int data) {
  if (head == nullptr) {
    head = new Node(data);
  } else {
    Node* current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new Node(data);
  }
}
//pop function
int LinkedList::pop() {
  if (isEmpty()) {
    cout << "Error: LinkedList is empty, cannot pop." << endl; //User poped before adding
    return -1; 
  }
  int data = head->data;
  Node* temp = head;
  head = head->next;
  delete temp;
  return data;
}
//isEmpty bool
bool LinkedList::isEmpty() const {
  return head == nullptr;
}
