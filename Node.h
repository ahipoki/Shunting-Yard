#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node
{
 public:
  Node(char*);
  ~Node();
  char* getValue();
  setLeft(Node*);
  Node* getLeft();
  setRight(Node*);
  Node* getRight();
  setNext(Node*);
  Node* getNext();
 private:
  Node* next;
  Node* right;
  Node* left;
  char* value;
};

#endif
