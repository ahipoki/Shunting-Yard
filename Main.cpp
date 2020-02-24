#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Node.h"
#include "List.h"

using namespace std;

vector<char*>* split(char*);
List* shuntingYard(vector<char*>*);
bool checkDigit(char*);
int getPrecedence(char*);
Node* makeTree(List*, List*);
void prefix(Node*);
void m_postfix(Node*);
void infix(Node*);
int main(){
  bool running = true;
  while(run){
    //prompt for input
    cout<<"Enter a mathematical expression separated by spaces"<<endl;
    char* input = new char();
    cin.getline(input, 80);
    //split the input by spaces and put it into a char* vector
    vector<char*>* in = split(input);
    //get the postfix expression using shunting yard
    List* postfix = shuntingYard(in);
    List* stack = new List();
    //make the binary expression tree
    Node* tree = makeTree(postfix, stack);
    while(true){
      cout<<"Type POSTFIX to get the postfix expression, PREFIX to get the prefix expression, and INFIX to get the infix expression, QUIT to quit, and NEW to type a new expression"<<endl;
      char* ex = new char();
      cin.getline(ex, sizeof(ex));
      //make all letters capital
      for(int i = 0; i<sizeof(ex); i++){
	ex[i] = toupper(ex[i]);
      }
      //traverse the binary tree to print the prefix expression
      if(strcmp(ex, "PREFIX") == 0){
	prefix(tree);
	cout<<endl;
      }
      //traverse the binary tree to print the postfix expression
      else if(strcmp(ex, "POSTFIX") == 0){
	m_postfix(tree);
	cout<<endl;
      }
      //traverse the binary tree to print the infix expression
      else if(strcmp(ex, "INFIX") == 0){
	infix(tree);
	cout<<endl;
      }
      //let the user type a new expression
      else if(strcmp(ex, "NEW") == 0){
	break;
      }
      //break out of the code
      else if(strcmp(ex, "QUIT") == 0){
	run = false;
	break;
      }
      else{
	cout<<"That's an invalid option"<<endl;
      }
    }
  }
  return 0;
}

vector <char*>* split (char* in){
  //output vector
  vector<char*>* out = new vector<char*>;
  int counter = 0;
  char* temp = new char[strlen(in)]();
  //loop through input
  for(int i = 0; i<strlen(in); i++){
    //if found a space, push everything from previous space to the current space into the vector
    if(in[i] == ' '){
      out->push_back(temp);
      counter = 0;
      temp = new char[strlen(in)]();
    }
    //add the values between spaces into a temp array
    else{
      temp[counter] = in[i];
      counter++;
    }
    //push the last element
    if(i == strlen(in)-1){
      out->push_back(temp);
    }
  }
  return out;
}

List* shuntingYard(vector<char*>* in){
  //used pseudo code from: https://en.wikipedia.org/wiki/Shunting-yard_algorithm
  List* out_queue = new List();
  List* op_stack = new List();
  vector<char*>::iterator i;
  //iterate through the input
  for(i = in->begin(); i !=in->end();i++){
    char* value = (*i);
    //if val is a digit, push it to the output queue
    if(checkDigit(value)){
      out_queue->push(value);
    }
    //if it is a left bracket, push it to the operator stack
    else if(strcmp(value, "(") == 0){
      op_stack->push(value);
    }
    //if it is a right bracket, push everthing in the operator stack into the output queue until the left bracket is found
    else if(strcmp(value, ")") == 0){
      while(strcmp(op_stack->sPeek(), "(") != 0){
	out_queue->push(op_stack->sPop());
      }
      op_stack->sPop();
    }
    //if it is a operator
    else{
      int c_prec = getPrecedence(val);
      char* next = op_stack->sPeek();
      /*push the values in the operator stack while
	there is a function at the top of the operator stack,
	or there is an operator at the top of the operator stack with greater precedence,
	or the operator at the top of the operator stack has equal precedence and the token is left associative
        and the operator at the top of the operator stack is not a left parenthesis
       */ 
      while(next && (getPrecedence(next)>c_prec || (getPrecedence(next) == c_prec && strcmp(next, "^") != 0)) && strcmp(next, "(") != 0){
	out_queue->push(op_stack->sPop());
	next = op_stack->sPeek();
      }
      op_stack->push(value);
    }
  }
  //push the rest of the values in the operator stack into the output queue
  while(op_stack->sPeek() != NULL){
    out_queue->push(op_stack->sPop());
  }
  return out_queue;
}

bool checkDigit(char* in){
  //if the input is a digit, return true, else return false
  for(int i = 0; i<strlen(in);i++){
    if(!isdigit(in[i])){
	return false;
    }
  }
  return true;
}
//get the precedence of a operator
int getPrecedence(char* in){
  if(strcmp(in, "+") == 0 || strcmp(in, "-") == 0){
    return 1;
  }
  else if(strcmp(in, "*") == 0 || strcmp(in, "/") == 0){
    return 2;
  }
  else if(strcmp(in, "^") == 0){
    return 3;
  }
  return -1;
}
Node* makeTree(List* postfix, List* stack){
  //get the first val in postfix
  char* value = postfix->q_pop();
  if(val != NULL){
    Node* temp = new Node(value);
    //if it is a digit, push it into the stack
    if(checkDigit(value)){
      stack->pushNode(temp);
    }
    //if it is a operator
    else{
      //make the node's val the operator, and set the right val to the first val in the stack and the left val to the next
      temp->setRight(stack->peekNode());
      stack->sPop();
      temp->setLeft(stack->peekNode());
      stack->sPop();
      stack->pushNode(temp);
    }
  }
  //if val is null, return it
  else{
    return stack->peekNode();
  }
  makeTree(postfix, stack);
}

void prefix(Node* tree){
  //traverse the tree to print prefix
  if(tree != NULL){
    cout<<tree->getValue();
    prefix(tree->getLeft());
    prefix(tree->getRight());
  }
}

void m_postfix(Node* tree){
  //traverse the tree to print postfix
  if(tree != NULL){
    m_postfix(tree->getLeft());
    m_postfix(tree->getRight());
    cout<<tree->getValue();
  }
}

void infix(Node* tree){
  //traverse the tree to print infix
  if(tree != NULL){
    if(!checkDigit(tree->getValue())){
      cout<<"(";
    }
    infix(tree->getLeft());
    cout<<tree->getValue();
    infix(tree->getRight());
    if(!checkDigit(tree->getValue())){
      cout<<")";
    }
  }
}
