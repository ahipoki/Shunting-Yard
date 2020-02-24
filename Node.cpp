#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(char* newValue){
  value = new char[strlen(newValue)+1];
  //Value new char
  strcpy(value,newValue);
  //Copy newValue onto value
  right = NULL;
  //Right is NULL
  left = NULL;
  //Left is NULL
  next = NULL;
  //Next is NULL
}

void Node::setNext(Node* newNext){//Set next
  next = newNext;
  //Set next equal to newNext
}

Node* Node::getNext(){//Get next
  return next;
  //Return next
}

Node::~Node(){//Node destructor
  delete[] value;
  //Delete value
  next = NULL;
  //Next equals NULL
}

char* Node::getValue(){//Get value
  return value;
  //Return value
}

void Node::setLeft(Node* newLeft){//Set left
  left = newLeft;
  //Left is equal to newLeft
}

Node* Node::getLeft(){//Get left
  return left;
  //Return left
}

void Node::setRight(Node* newRight){//Set right
  right = newRight;
  //Right is equal to newRight
}

Node* Node::getRight(){//Get right
  return right;
  //Return right
}
