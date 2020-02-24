#include <iostream>
#include <cstring>
#include "Node.h"
#include "List.h"

using namespace std;

List::List(){
    head = NULL;
}

void List::push(char* newValue){
    pushEnd(head,newValue,NULL,true);
    return;
}

void List::pushNode(Node* newValue){
    pushEnd(head,NULL,newValue,false);
}

char* List::qPop(){
    if (head == NULL){
        return NULL;
    }
    char* value = copy(head->getValue());
    Node* temp = head->getNext();
    delete head;
    head = temp;
    return value;
}

char* List::sPop(){
    return getEnd(head,true);
}

char* List::qPeek(){
    if (head == NULL){
        return NULL;
    }
    return head->getValue();
}

char* List::sPeek(){
    return getEnd(head,false);
}

Node* List::peekNode(){
    return getEndNode(head);
}

char* List::getEnd(Node* &current,bool de){
    if (current = NULL){
        return NULL;
    }
    if (current->getNext() == NULL){
        char* value = copy(current->getValue());
        if (de){
            current = NULL;
            delete current;
        }
        return value;
    }
    if (current->getNext()->getNext() == NULL){
        char* value = copy(current->getNext()->getValue());
        if (de){
            current->setNext(NULL);
            delete current->getNext();
        }
        return value;
    }
    Node* next = current->getNext();
    getEnd(next,de);
}

Node* List::getEndNode(Node* &current){
    if (current == NULL){
        retun NULL;
    }
    else if (current->getNext() == NULL){
        return current;
    }
    Node* next = current->getNext();
    getEndNode(next);
}

void List::pushEnd(Node* &current, char* charIn, Node* nodeIn, bool type){
    if (current == NULL){
        if (type){
            current = new Node(charIn);
        }
        else{
            current = nodeIn;
        }
        return;
    }
    if (current->getNext() == NULL){
        if (type){
            current->setNext(new Node(charIn));
        }
        else{
            current->setNext(nodeIn);
        }
        return;
    }
    Node* next = current->getNext();
    pushEnd(next,charIn,nodeIn,type);
}

char* List::copy(char* in){
    char* out = new char[strlen(in)+1];
    strcpy(out,in);
    return out;
}

List::~List(){
    delete head;
}
