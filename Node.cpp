#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(char* newValue){
  value = new char[strlen(newValue)+1];
  strcpy(value,newValue);
  right = NULL;
  left = NULL;
  next = NULL;
}

Node::~Node(){//Node destructor
    delete[] value;
    next = NULL;
}

char* Node::getValue(){//Get value
  return value;
  //Return value
}

void Node::setLeft(Node* newLeft){//Set left
  left = newLeft;
}

Node* Node::getLeft(){//Get left
  return left;
  //Return left
}

void Node::setRight(Node* newRight){//Set right
  right = newRight;
}

Node* Node::getRight(){//Get right
  return right;
  //Return right
}

void Node::setNext(Node* newNext){//Set next
  next = newNext;
}

Node* Node::getNext(){//Get next
  return next;
  //Return next
}
