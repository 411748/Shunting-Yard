#include "BinaryTreeNode.h"
#include <iostream>

using namespace std;

BinaryTreeNode::BinaryTreeNode(int data) : data(data), op('\0'), left(nullptr),\
 right(nullptr) {}

BinaryTreeNode::BinaryTreeNode(char op, BinaryTreeNode* left, BinaryTreeNode* r\
ight) : data(0), op(op), left(left), right(right) {}

void BinaryTreeNode::printInfix() {
  if (left) {
    cout << "(";
    left->printInfix();
  }
  if (op != '\0')
    cout << op;
  else
    cout << data;
  if (right) {
    right->printInfix();
    cout << ")";
  }
}

void BinaryTreeNode::printPrefix() {
  if (op != '\0')
    cout << op;
  else
    cout << data;
  if (left)
    left->printPrefix();
  if (right)
    right->printPrefix();
}

void BinaryTreeNode::printPostfix() {
  if (left)
    left->printPostfix();
  if (right)
    right->printPostfix();
  if (op != '\0')
    cout << op;
  else
    cout << data;
}
