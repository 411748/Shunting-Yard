#include "Stack.h"
#include <iostream>
#include <cstring>

using namespace std;

void Stack::push(int data) {
  list.append(data);
}

int Stack::pop() {
  return list.pop();
}

bool Stack::isEmpty() const {
  return list.isEmpty();
}
