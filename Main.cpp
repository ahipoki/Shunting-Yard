#include <iostream>
#include <cstring>
#include <vector>
#include "Node.h"
#include "List.h"

using namespace std;

Node* getPostfix(char*);
void enqueue(Node*&, char*);
char* dequeue(Node*&);
void infix();
void prefix();
void postfix();

int main()
{
  char input[80];
  cout << "Enter a mathematical expression" << endl;
  cout << "Do you want to output the expression as infix, prefix, or postfix notation?" << endl;
  cin.getline(input, 80);
  for (int i = 0; i < strlen(input); i++){
    input[i] = toupper(input[i]);
  }
  if (strcmp(input, "INFIX") == 0) {
    infix();
  }
  else if (strcmp(input, "PREFIX") == 0){
    prefix();
  }
  else if (strcmp(input, "POSTFIX") == 0){
    postfix();
  }
}

void shuntingYard(List* newList, Node* &head){
  if (head == NULL){
    head = new Node(newList);
    return;
  }
  if (head->getNext() != NULL){
    //if (newList->qPeek() == number){
      newList->qPush();
      //}
    //else if (newList->qPeek() == function){
      newList->sPush();
      //}
    //else if (newList->qPeek() == operator){
      //while ((there is function at top of operator stack) || (there is operator at top of operator stack w/greater precedence) || (operator at top of operator stack has equal precedence and token is left associative) && (operator at top of operator stack != '(')){
      //pop operators from operator stack onto output queue;
      //}
      newList->sPush();
    //}
    //if (newList->qPeek() == '('){
    //push it onto operator stack
    //}
    //if (newList->qPeek() == ')'){
    //while (operator at top of operator stack != '('){
      //pop operator from operator stack onto output queue
      //}
    //if (there is '(' at top of operator stack){ 
      //pop operator from operator stack and discard it
      //}
      //}
  //if (tokens == 0){
    //while (operator tokens on stack != 0){
      //pop operator from operator stack onto output queue
    //}
  }
  //Exit
}

void infix(){//Infix Traversal
//if (tree not empty){
  //if (tree token is operator){
      cout << "(" << endl;
    }
  //infix (tree left subtree)
  //print (tree token)
  //infix (tree right subtree)
  //if (tree token is operator)
    cout << ")" << endl;
    }
  }
  cout << "Infix" << endl;
}

void postfix(){//Postfix Traversal
//if (tree not empty){
  //postfix (tree left subtree)
  //postfix (tree right subtree)
  //print (tree token)
  }
  cout << "Postfix" << endl;
}

void prefix(){//Prefix Traversal
//if (tree not empty){
  //print (tree token)
  //prefix (tree left subtree)
  //prefix (tree right subtree)
  }
  cout << "Prefix" << endl;
}

