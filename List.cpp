#include <iostream>
#include <cstring>
#include "Node.h"
#include "List.h"

using namespace std;

List::List(){//List function
  head = NULL;
  //Head is NULL
}

void List::push(char* newValue){//Push
  pushEnd(head,newValue,NULL,true);
  //Push end
  return;
  //Return
}

void List::pushNode(Node* newValue){//Push node
  pushEnd(head,NULL,newValue,false);
  //Push end
}

char* List::qPop(){//Queue pop
  if (head == NULL){//If head is NULL
    return NULL;
    //Return NULL
  }
  char* value = copy(head->getValue());
  Node* temp = head->getNext();
  delete head;
  head = temp;
  return value;
}

char* List::sPop(){//Stack pop
  return getEnd(head,true);
  //Return getEnd
}

char* List::qPeek(){//Queue peek
  if (head == NULL){//If head is NULL
    return NULL;
    //Return NULL
  }
  return head->getValue();
  //Return value of head
}

char* List::sPeek(){//Stack peek
  return getEnd(head,false);
  //Return end
}

Node* List::peekNode(){//Peek node
  return getEndNode(head);
  //Return end node
}

char* List::getEnd(Node* &current,bool de){//Get end
  if (current == NULL){//If current is not NULL
    return NULL;
    //Return NULL
  }
  if (current->getNext() == NULL){//If next node is not NULL
    char* value = copy(current->getValue());
    //Copy next value
    if (de){//If delete
      current = NULL;
      //Current is NULL
      delete current;
      //Delete current
    }
    return value;
    //Return value
  }
  if (current->getNext()->getNext() == NULL){//If next's next is NULL
    char* value = copy(current->getNext()->getValue());
    //Copy next's value
    if (de){//If delete
      current->setNext(NULL);
      //Next is NULL
      delete current->getNext();
      //Delete next
    }
    return value;
    //Return value
  }
  Node* next = current->getNext();
  //Next is next node
  getEnd(next,de);
  //Get end
}

Node* List::getEndNode(Node* &current){//Get end node
  if (current == NULL){//If current is NULL
    return NULL;
    //Return NULL
  }
  else if (current->getNext() == NULL){//Else if next is NULL
    return current;
    //Return current
  }
  Node* next = current->getNext();
  //Next is next node
  getEndNode(next);
  //Get end node
}

void List::pushEnd(Node* &current, char* charIn, Node* nodeIn, bool type){//Push end
  if (current == NULL){//If current is NULL
    if (type){//If type
      current = new Node(charIn);
      //Current is new char in
    }
    else{//Anything else
      current = nodeIn;
      //Current is node in
    }
    return;
    //Return
  }
  if (current->getNext() == NULL){//If next is NULL
    if (type){//If type
      current->setNext(new Node(charIn));
      //Next is new node char in
    }
    else{//Anything else
      current->setNext(nodeIn);
      //Next is node in
    }
    return;
    //Return
  }
  Node* next = current->getNext();
  //Next is next node
  pushEnd(next,charIn,nodeIn,type);
  //Push end
}

char* List::copy(char* in){//Copy function
  char* out = new char[strlen(in)+1];
  //Out is new char*
  strcpy(out,in);
  //Copy in to out
  return out;
  //Return out
}

List::~List(){//Destructor
  delete head;
  //Delete head
}
