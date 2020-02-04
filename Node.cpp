#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(char* newValue){
  value = newValue;
  right = NULL;
  left = NULL;
  next = NULL;
}

Node::~Node(){//Node destructor
  next = NULL;
}

char* Node::getValue(){//Get value
  return value;
  //Return value
}

Node::setLeft(Node* n){//Set left
  left = n;
}

Node* Node::getLeft(){//Get left
  return left;
  //Return left
}

Node::setRight(Node* n){//Set right
  right = n;
}

Node* Node::getRight(){//Get right
  return right;
  //Return right
}

Node::setNext(Node* n){//Set next
  next = n;
}

Node* Node::getNext(){//Get next
  return next;
  //Return next
}
