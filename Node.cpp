#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(char* newValue)
{
  value = newValue;
  right = NULL;
  left = NULL;
  next = NULL;
}

Node::~Node()
{
  next = NULL;
}

char* Node::getValue()
{
  return value;
}

Node::setLeft(Node* n)
{
  left = n;
}

Node* Node::getLeft()
{
  return left;
}

Node::setRight(Node* n)
{
  right = n;
}

Node* Node::getRight()
{
  return right;
}

Node::setNext(Node* n)
{
  next = n;
}

Node* Node::getNext()
{
  return next;
}
