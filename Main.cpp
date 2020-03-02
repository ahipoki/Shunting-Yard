/* Finn McKinley
 * Shunting Yard
 * 2/24/20
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Node.h"
#include "List.h"

using namespace std;

void strupper(char* str);
//Make input uppercase function
vector<char*>* split(char*);
//Split function
List* shuntingYard(vector<char*>*);
//Shunting yard function
bool checkDigit(char*);
//Check digit function
int getPrecedence(char*);
//Get precedence
Node* makeTree(List*, List*);
//Make tree function
void prefix(Node*);
//Prefix function
void m_postfix(Node*);
//Postfix function
void infix(Node*);
//Infix function

int main()
{//Main function
  bool running = true;
  //Running bool
  while(running){//While running
    cout<<"Enter a mathematical equation separated by spaces"<<endl;
    //Ask user for mathematical equation
    char* input = new char();
    //Input
    cin.getline(input, 80);
    //Get their input
    vector<char*>* in = split(input);
    //Split it
    List* postfix = shuntingYard(in);
    //New list with shunting yard function
    List* stack = new List();
    //New list
    Node* tree = makeTree(postfix, stack);
    //Make a tree
    while(true){//While true
      cout<<"Type POSTFIX to get the postfix expression, PREFIX to get the prefix expression, and INFIX to get the infix expression, QUIT to quit, and NEW to type a new equation"<<endl;
      //Ask the user if they want postfix, prefix, infix notation, new equation, or quit
      char* ex = new char();
      //ex is new char
      cin.getline(ex, sizeof(ex));
      //Get user input with ex
      strupper(ex);
      //Make input all capital letters
      if(strcmp(ex, "PREFIX") == 0){//If the user said prefix
	prefix(tree);
	//Call prefix function with tree
	cout<<endl;
      }
      else if(strcmp(ex, "POSTFIX") == 0){//Else if they said postfix
	m_postfix(tree);
	//Call postfix function with tree
	cout<<endl;
      }
      else if(strcmp(ex, "INFIX") == 0){//Else if they said infix
	infix(tree);
	//Call infix function with tree
	cout<<endl;
      }
      else if(strcmp(ex, "NEW") == 0){//Else if they said new
	break;
	//Break out so they can enter a new equation
      }
      else if(strcmp(ex, "QUIT") == 0){//Else if they said quit
	running = false;
	//Stop the program
	break;
	//Break out of the loop
      }
      else{//Anything else
	cout<<"That's an invalid option"<<endl;
	//Tell the user that's an invalid option
      }
    }
  }
  return 0;
  //Return 0
}

void strupper(char* str){//Make input uppercase
  int len = strlen(str);
  //Len is the length of the input
  for (int i = 0; i < len; i++){//For loop going through the length of the input
    str[i] = toupper(str[i]);
    //Make all letters of the input uppercase
  }
}

vector <char*>* split (char* in){
  //output vector
  vector<char*>* out = new vector<char*>;
  int counter = 0;
  char* temp = new char[strlen(in)]();
  //loop through input
  for(int i = 0; i<strlen(in); i++){//For loop looping through length of in
    if(in[i] == ' '){//If the char at in is a space
      out->push_back(temp);
      //Push back the temp with out
      counter = 0;
      //Counter equals 0
      temp = new char[strlen(in)]();
      //Temp is a new char of length in
    }
    else{//Anything else
      temp[counter] = in[i];
      //Counter # of temp equals i # of in
      counter++;
      //Add 1 to the counter
    }
    if(i == strlen(in)-1){//If i equals length of in - 1
      out->push_back(temp);
      //Push back temp with out
    }
  }
  return out;
  //Return out
}

List* shuntingYard(vector<char*>* in){//Shunting yard function
  //Used pseudo code from: https://en.wikipedia.org/wiki/Shunting-yard_algorithm
  List* out_queue = new List();
  //New list out_queue
  List* op_stack = new List();
  //New list operator stack
  vector<char*>::iterator it;
  //Iterator it
  for(it = in->begin(); it !=in->end();it++){//Iterate through in
    char* value = (*it);
    //New char* value equals *it
    if(checkDigit(value)){//If the value is a number
      out_queue->push(value);
      //Push value with the out_queue
    }
    else if(strcmp(value, "(") == 0){//Else if value is a left parenthesis
      op_stack->push(value);
      //Push value with operator stack
    }
    else if(strcmp(value, ")") == 0){//Else if value is a right parenthesis
      while(strcmp(op_stack->sPeek(), "(") != 0){//While the next one in the operator stack is not a left parenthesis
	out_queue->push(op_stack->sPop());
	//Pop from the operator stack with out queue
      }
      op_stack->sPop();
      //Pop the next off the operator stack
    }
    else{//Anything else
      int c_prec = getPrecedence(value);
      //C precedence is value of precedence
      char* next = op_stack->sPeek();
      //Next is new char* of next in operator stack
      while(next && (getPrecedence(next)>c_prec || (getPrecedence(next) == c_prec && strcmp(next, "^") != 0)) && strcmp(next, "(") != 0){//While precedence is higher than 2nd precendence or precedence is equal and it's not a ^ and next is not a (
	out_queue->push(op_stack->sPop());
	//Pop off operator stack with pushing command through out_queue
	next = op_stack->sPeek();
	//Next is next of operator stack
      }
      op_stack->push(value);
      //Push value with operator stack
    }
  }
  while(op_stack->sPeek() != NULL){//While next on operator stack is not NULL
    out_queue->push(op_stack->sPop());
    //Pop off operator stack push with out_queue
  }
  return out_queue;
  //Return out_queue
}

bool checkDigit(char* in){//Check digit
  for(int i = 0; i<strlen(in);i++){//For loop through length of in
    if(!isdigit(in[i])){//If i of in is not a number
      return false;
      //Return false
    }
  }
  return true;
  //Return true
}
int getPrecedence(char* in){//Get precedence function
  if(strcmp(in, "+") == 0 || strcmp(in, "-") == 0){//If it's a + or -
    return 1;
    //Return 1
  }
  else if(strcmp(in, "*") == 0 || strcmp(in, "/") == 0){//Else if it's a * or /
    return 2;
    //Return 2
  }
  else if(strcmp(in, "^") == 0){//Else if it's a ^
    return 3;
    //Return 3
  }
  return -1;
  //Return -1
}
Node* makeTree(List* postfix, List* stack){//Make tree function
  char* value = postfix->qPop();
  //Value is pop from postfix
  if(value != NULL){//If value is not NULL
    Node* temp = new Node(value);
    //Temp is new node with value
    if(checkDigit(value)){//If value is a number
      stack->pushNode(temp);
      //Push temp node onto stack
    }
    else{//Anything else
      temp->setRight(stack->peekNode());
      //Set right node with next in stack
      stack->sPop();
      //Pop next off stack
      temp->setLeft(stack->peekNode());
      //Set left node with next in stack
      stack->sPop();
      //Pop next off stack
      stack->pushNode(temp);
      //Push node temp onto stack
    }
  }
  else{//Anything else
    return stack->peekNode();
    //Return next in stack
  }
  makeTree(postfix, stack);
  //Make tree with postix + stack
}

void prefix(Node* tree){//Prefix function
  if(tree != NULL){//If tree is not NULL
    cout<<tree->getValue();
    //Print value of tree
    prefix(tree->getLeft());
    //Get left of tree
    prefix(tree->getRight());
    //Get right of tree
  }
}

void m_postfix(Node* tree){//Postfix function
  if(tree != NULL){//If tree isn't NULL
    m_postfix(tree->getLeft());
    //Get left of tree
    m_postfix(tree->getRight());
    //Get right of tree
    cout<<tree->getValue();
    //Print value of tree
  }
}

void infix(Node* tree){//Infix function
  if(tree != NULL){//If tree is not NULL
    if(!checkDigit(tree->getValue())){//If value of tree is not a number
      cout<<"(";
      //Print a left parenthesis
    }
    infix(tree->getLeft());
    //Get left of tree
    cout<<tree->getValue();
    //Print value of tree
    infix(tree->getRight());
    //Get right of tree
    if(!checkDigit(tree->getValue())){//If value of tree is not a number
      cout<<")";
      //Print out a left parenthesis
    }
  }
}
