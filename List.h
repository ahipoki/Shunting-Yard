#include <iostream>
#include <cstring>
#include "Node.h"

#ifndef LIST_H
#define LIST_H

using namespace std;

class List{
 public:
  List();
  void push(char*);
  char* qPop();
  char* sPop();
  char* qPeek();
  char* sPeek();
  void pushNode(Node*);
  Node* peekNode();
  char* getEnd(Node*&, bool);
  void pushEnd(Node*&, char*, Node*, bool);
  Node* getEndNode(Node*&);
  char* copy(char*);
  ~List();
 private:
  Node* head;
};

#endif
