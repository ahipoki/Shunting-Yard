#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(char* newValue)
{
  next = NULL;
  //right = newRight;
  //left = newLeft
}

Node::~Node()
{
  next = NULL;
}

Node::setLeft(Node*)
{
  //left = newLeft;
}

Node::getLeft()
{
  //return left;
}

Node::setRight(Node*)
{
  //right = newRight;
}

Node::getRight()
{
  //return right;
}

Node::setNext()
{
  //next = newNext;
}

Node::getNext()
{
  //return next;
}
