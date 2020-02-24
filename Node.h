#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;

class Node{
 public:
  Node(char*);
  ~Node();
  char* getValue();
  void setLeft(Node*);
  Node* getLeft();
  void setRight(Node*);
  Node* getRight();
  void setNext(Node*);
  Node* getNext();
 private:
  Node* next;
  Node* right;
  Node* left;
  char* value;
};

#endif
