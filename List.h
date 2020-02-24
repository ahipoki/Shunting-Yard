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
  //Push function
  char* qPop();
  //Queue pop
  char* sPop();
  //Stack pop
  char* qPeek();
  //Queue peek
  char* sPeek();
  //Stack peek
  void pushNode(Node*);
  //Push node
  Node* peekNode();
  //Peek next node
  char* getEnd(Node*&, bool);
  //Get end
  void pushEnd(Node*&, char*, Node*, bool);
  //Push to end
  Node* getEndNode(Node*&);
  //Get end node
  char* copy(char*);
  //Copy
  ~List();
  //Destructor
 private:
  Node* head;
  //Head
};

#endif
