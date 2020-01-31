#include <iostream>
#include <cstring>
#include "Node.h"
#include "List.h"

using namespace std;

void infix();
void prefix();
void postfix();

int main()
{
  char input[80];
  cout << "Enter a mathematical expression" << endl;
  cout << "Do you want to output the expression as infix, prefix, or postfix notation?" << endl;
  cin.getline(input, 80);
  for (int i = 0; i < strlen(input); i++)
  {
    input[i] = toupper(input[i]);
  }
  if (strcmp(input, "INFIX") == 0)
  {
    infix();
  }
  else if (strcmp(input, "PREFIX") == 0)
  {
    prefix();
  }
  else if (strcmp(input, "POSTFIX") == 0)
  {
    postfix();
  }
   *       push it onto the operator stack.
   *    if the token is a right paren (i.e. ")"), then:
   *       while the operator at the top of the operator stack is not a left paren:
   *         pop the operator from the operator stack onto the output queue.
   *       if there is a left paren at the top of the operator stack, then:
   *          pop the operator from the operator stack and discard it
   * if there are no more tokens to read then:
   *    while there are still operator tokens on the stack:
   *       pop the operator from the operator stack onto the output queue.
   *exit.
   */
}

void shuntingYard()
{
  //While (there are tokens to be read)
  //  read a token;
  //  if (token == number){
  //    push it to output queue;
  //  else if (token == function){
  //    push it onto operator stack;
  //  if (token == operator){
  //    while ((there is function at top of operator stack) || (there is operator at top of operator stack w/greater precedence) || (operator at top of operator stack has equal precedence and token is left associative) && (operator at top of operator stack != '(')){
  //      pop operators from operator stack onto output queue;
  //    }
  //    push it onto operator stack;
  //  }
  //  if (token == '('){
}

void infix()
{//Infix Traversal
  //if (tree not empty)
  //  if (tree token is operator)
  //  print (open parenthesis)
  cout << "(" << endl;
  //  end if
  //  infix (tree left subtree)
  //  print (tree token)
  //  infix (tree right subtree)
  //  if (tree token is operator)
  //    print (close parenthesis)
  cout << ")" << endl;
  //  end if
  //end if
  cout << "Infix" << endl;
}

void postfix()
{//Postfix Traversal
  //if (tree not empty)
  //  postfix (tree left subtree)
  //  postfix (tree right subtree)
  //  print (tree token)
  //end if
  cout << "Postfix" << endl;
}

void prefix()
{//Prefix Traversal
  //if (tree not empty)
  //  print (tree token)
  //  prefix (tree left subtree)
  //  prefix (tree right subtree)
  //end if
  cout << "Prefix" << endl;
}
