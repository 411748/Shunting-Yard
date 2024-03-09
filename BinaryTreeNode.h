//BinaryTreeNode.h

#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

//Class for the treenode
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
