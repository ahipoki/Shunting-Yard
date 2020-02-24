#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;

class Node{
 public:
  Node(char*);
  ~Node();
  //Destructor
  char* getValue();
  //Get value
  void setNext(Node*);
  //Set next
  Node* getNext();
  //Get next
  void setLeft(Node*);
  //Set left
  Node* getLeft();
  //Get left
  void setRight(Node*);
  //Set right
  Node* getRight();
  //Get right
 private:
  Node* next;
  //Next
  Node* right;
  //Right
  Node* left;
  //Left
  char* value;
  //Value
};

#endif
