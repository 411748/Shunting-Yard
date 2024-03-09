#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

class BinaryTreeNode {
public:
  int data;
  char op;
  BinaryTreeNode* left;
  BinaryTreeNode* right;
  BinaryTreeNode(int data);
  BinaryTreeNode(char op, BinaryTreeNode* left, BinaryTreeNode* right);
  void printInfix();
  void printPrefix();
  void printPostfix();
};

#endif
