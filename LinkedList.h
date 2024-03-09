#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class Node {
public:
  int data;
  Node* next;
  Node(int data);
};
class LinkedList {
private:
  Node* head;
public:
  LinkedList();
  ~LinkedList();
  void append(int data);
  int pop();
  bool isEmpty() const;
};

#endif 
