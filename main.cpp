#include "Stack.h"
#include <cstring>
#include <iostream>

using namespace std;

int main() {
  Stack stack;
  stack.push(5);
  stack.push(10);
  stack.push(15);
  cout << "Top element: " << stack.peek() << endl;
  cout << "Popped element: " << stack.pop() << endl;
  cout << "Popped element: " << stack.pop() << endl;
  return 0;
}

