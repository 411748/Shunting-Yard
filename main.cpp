#include "Stack.h"
#include "BinaryTreeNode.h"
#include <iostream>
#include <stack>
#include <cstring>

//https://www.geeksforgeeks.org/stack-in-cpp-stl/

using namespace std;

bool isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
  if (op == '^')
    return 3;
  else if (op == '*' || op == '/')
    return 2;
  else if (op == '+' || op == '-')
    return 1;
  else
    return -1;
}

void infixToPostfix(const char* infix, char* postfix) {
  stack<char> s;
  size_t j = 0;
  for (size_t i = 0; infix[i] != '\0'; ++i) {
    char c = infix[i];
    if (c == ' ')
      continue;
    if (isalnum(c)) {
      postfix[j++] = c;
    } else if (c == '(') {
      s.push(c);
    } else if (c == ')') {
      while (!s.empty() && s.top() != '(') {
	postfix[j++] = ' ';
        postfix[j++] = s.top();
        s.pop();
      }
      s.pop(); 
      } else {
        while (!s.empty() && precedence(c) <= precedence(s.top())) {
	  postfix[j++] = ' ';
          postfix[j++] = s.top();
          s.pop();
         }
        s.push(c);
      }
  }
  while (!s.empty()) {
    postfix[j++] = ' ';
    postfix[j++] = s.top();
    s.pop();
  }
  postfix[j] = '\0';
}

BinaryTreeNode* buildExpressionTree(const char* postfix) {
  stack<BinaryTreeNode*> s;
  for (size_t i = 0; postfix[i] != '\0'; ++i) {
    char c = postfix[i];
    if (c == ' ')
      continue;
      if (isalnum(c)) {
	int operand = c - '0';
        s.push(new BinaryTreeNode(operand));
      } else if (isOperator(c)) {
        BinaryTreeNode* right = s.top();
        s.pop();
        BinaryTreeNode* left = s.top();
        s.pop();
        s.push(new BinaryTreeNode(c, left, right));
      }
  }
  return s.top();
}

void printExpressionTree(BinaryTreeNode* root, const char* expressionType) {
  if (strcmp(expressionType, "infix") == 0) {
    cout << "Infix expression from expression tree: ";
    root->printInfix();
    cout << endl;
  } else if (strcmp(expressionType, "prefix") == 0) {
    cout << "Prefix expression from expression tree: ";
    root->printPrefix();
    cout << endl;
  } else if (strcmp(expressionType, "postfix") == 0) {
    cout << "Postfix expression from expression tree: ";
    root->printPostfix();
    cout << endl;
  }
}

int main() {
  char infixExpression[100];
  cout << "Enter a mathematical expression in infix notation (single-digit numbers, with spaces between tokens): ";
  cin.getline(infixExpression, 100);
  char postfixExpression[200]; 
  infixToPostfix(infixExpression, postfixExpression);
  BinaryTreeNode* root = buildExpressionTree(postfixExpression);
  char expressionType[10];
  while (true) {
    cout << "Enter the expression type to output (infix, prefix, or postfix), or 'quit' to exit: ";
    cin >> expressionType;
    if (strcmp(expressionType, "quit") == 0) {
      break;
    } else {
      printExpressionTree(root, expressionType);
    }
  }
  return 0;
}
