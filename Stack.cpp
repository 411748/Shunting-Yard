//Stack.cpp

#include "Stack.h"
#include <iostream>
#include <cstring>

using namespace std;

//Push function
void Stack::push(int data) {
  list.append(data);
}
//Pop function
int Stack::pop() {
  return list.pop();
}
//isEmpty bool
bool Stack::isEmpty() const {
  return list.isEmpty();
}
