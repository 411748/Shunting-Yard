#include "Stack.h"
#include "Queue.h"
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
  Queue queue;
  queue.enqueue(5);
  queue.enqueue(10);
  queue.enqueue(15);
  cout << "Dequeued element: " << queue.dequeue() << endl;
  cout << "Dequeued element: " << queue.dequeue() << endl;

  return 0;
}

