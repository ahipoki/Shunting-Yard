#include <iostream>
#include <cstring>
#include "Node.h"

#ifndef LIST_H
#define LIST_H

using namespace std;

class List
{
 public:
  List(Node*);
  Node* qPop();
  Node* sPop();
 private:
};

#endif
