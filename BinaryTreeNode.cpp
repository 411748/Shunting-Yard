//BinaryTreeNode.cpp

#include "BinaryTreeNode.h"
#include <iostream>

using namespace std;

BinaryTreeNode::BinaryTreeNode(int data) : data(data), op('\0'), left(nullptr),\
 right(nullptr) {}

BinaryTreeNode::BinaryTreeNode(char op, BinaryTreeNode* left, BinaryTreeNode* r\
ight) : data(0), op(op), left(left), right(right) {}

//Function to print infix
void BinaryTreeNode::printInfix() {
  if (left) {
    cout << "(";
    left->printInfix();
  }
  if (op != '\0') //null
    cout << op;
  else
    cout << data;
  if (right) {
    right->printInfix();
    cout << ")";
  }
}

//Function to print prefix
void BinaryTreeNode::printPrefix() {
  if (op != '\0') //null
    cout << op;
  else
    cout << data;
  if (left)
    left->printPrefix();
  if (right)
    right->printPrefix();
}

//Function to print postfix
void BinaryTreeNode::printPostfix() {
  if (left)
    left->printPostfix();
  if (right)
    right->printPostfix();
  if (op != '\0') //null
    cout << op;
  else
    cout << data;
}
