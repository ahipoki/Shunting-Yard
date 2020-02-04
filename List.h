#include <iostream>
#include <cstring>
#include "Node.h"

#ifndef LIST_H
#define LIST_H

using namespace std;

class List{
 public:
  List(Node*);
  Node* qPop();
  Node* sPop();
  Node* qPeek();
  Node* sPeek();
  Node* qPush();
  Node* sPush();
  Node* enqueue();
  Node* dequeue();
 private:
};

#endif
