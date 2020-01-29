#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node
{
 public:
  Node(char*);
  ~Node();
  setLeft(Node*);
  getLeft();
  setRight(Node*);
  getRight();
  setNext();
  getNext();
 private:
  Node* next;
  Node* right;
  Node* left;
  char* value;
};

#endif
