//main.cpp

//Nick Braun
//3/9/2024
//Shunting Yard Algarithm - Takes in two single digit numbers + an opperator and displays infix prefix and postfix algarithms

//Includes
#include "Stack.h"
#include "BinaryTreeNode.h"
#include <iostream>
#include <stack>
#include <cstring>

//https://www.geeksforgeeks.org/stack-in-cpp-stl/

using namespace std;

//Checking to see if what user inputed was one of the allowed opperators
bool isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

//Checking to see the precedence of opperator after finding that its allowed
int precedence(char op) {
  if (op == '^') //Square
    return 3;
  else if (op == '*' || op == '/') //Multiple or divide
    return 2;
  else if (op == '+' || op == '-') //Add or subtract
    return 1;
  else
    return -1; //Not real opperator
}

//Algotrim for postfix 
void infixToPostfix(const char* infix, char* postfix) {
  stack<char> s; //Creating a stack for the equation
  size_t j = 0;
  for (size_t i = 0; infix[i] != '\0'; ++i) { //For loop that runs for equation
    char c = infix[i];
    if (c == ' ')
      continue;
    if (isalnum(c)) {
      postfix[j++] = c;
    } else if (c == '(') { //Finding parenthese around infix equation
      s.push(c);
    } else if (c == ')') {
      while (!s.empty() && s.top() != '(') {
	postfix[j++] = ' ';
        postfix[j++] = s.top();
        s.pop();
      }
      s.pop(); 
      } else {
      while (!s.empty() && precedence(c) <= precedence(s.top())) { //Equation manipulating
	  postfix[j++] = ' ';
          postfix[j++] = s.top();
          s.pop();
         }
        s.push(c);
      }
  }
  while (!s.empty()) { //Adding spaces
    postfix[j++] = ' ';
    postfix[j++] = s.top();
    s.pop();
  }
  postfix[j] = '\0';
}

BinaryTreeNode* buildExpressionTree(const char* postfix) { //Building new expression with postfix
  stack<BinaryTreeNode*> s;
  for (size_t i = 0; postfix[i] != '\0'; ++i) {
    char c = postfix[i];
    if (c == ' ')
      continue;
      if (isalnum(c)) {
	int operand = c - '0'; //Creating new opperator to move
        s.push(new BinaryTreeNode(operand));
      } else if (isOperator(c)) {
        BinaryTreeNode* right = s.top(); //Finding values around opperator
        s.pop();
        BinaryTreeNode* left = s.top();
        s.pop();
        s.push(new BinaryTreeNode(c, left, right)); //Pushing edited expression
      }
  }
  return s.top();
}

void printExpressionTree(BinaryTreeNode* root, const char* expressionType) { //Printing the equations
  if (strcmp(expressionType, "infix") == 0) { //Infix equation
    cout << "Infix expression from expression tree: ";
    root->printInfix();
    cout << endl;
  } else if (strcmp(expressionType, "prefix") == 0) { //Prefix equation
    cout << "Prefix expression from expression tree: ";
    root->printPrefix();
    cout << endl;
  } else if (strcmp(expressionType, "postfix") == 0) { //Postfix equation
    cout << "Postfix expression from expression tree: ";
    root->printPostfix();
    cout << endl;
  }
}

int main() {
  char infixExpression[100]; //User input
  cout << "Enter a mathematical expression in infix notation (single-digit numbers, with spaces between tokens): ";
  cin.getline(infixExpression, 100); //Getting input
  char postfixExpression[200]; //Creating original postfix equation
  infixToPostfix(infixExpression, postfixExpression);
  BinaryTreeNode* root = buildExpressionTree(postfixExpression); //Adding equation
  char expressionType[10];
  while (true) {
    //User input
    cout << "Enter the expression type to output (infix, prefix, or postfix), or 'quit' to exit: ";
    cin >> expressionType;
    if (strcmp(expressionType, "quit") == 0) { //User quits
      break;
    } else {
      printExpressionTree(root, expressionType);
    }
  }
  return 0;
}
