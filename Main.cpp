#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Node.h"
#include "List.h"

using namespace std;

void strupper(char* str);
vector<char*>* split(char*);
List* shuntingYard(vector<char*>*);
bool checkDigit(char*);
int getPrecedence(char*);
Node* makeTree(List*, List*);
void prefix(Node*);
void infix(Node*);
void m_postfix(Node*);

int main()
{
    bool running = true;
    while (running){
        cout<<"Enter a mathematical expression separated by spaces"<<endl;
        char* input = new char();
        cin.getline(input,80);
	cout<<"Test1"<<endl;
        vector<char*>* in = split(input);
	cout<<"Test2"<<endl;
        List* postfix = shuntingYard(in);
	cout<<"test3"<<endl;
        List* stack = new List();
	cout<<"test4"<<endl;
        Node* tree = makeTree(postfix,stack);
	cout<<"Test5"<<endl;
        while (true){
            cout<<"Do you want to output the expression as INFIX, PREFIX, or POSTFIX notation, or do you want to QUIT, or type a NEW expression?"<<endl;
            char* ex = new char();
            cin.getline(ex, sizeof(ex));
            strupper(ex);
            if (strcmp(ex,"INFIX") == 0) {
                infix(tree);
                cout<<endl;
            }
            else if (strcmp(ex,"PREFIX") == 0){
                prefix(tree);
                cout<<endl;
            }
            else if (strcmp(ex,"POSTFIX") == 0){
                m_postfix(tree);
                cout<<endl;
            }
            else if (strcmp(ex,"NEW") == 0){
                break;
            }
            else if (strcmp(ex,"QUIT") == 0){
                running = false;
                break;
            }
            else{
                cout<<"That's an invalid input"<<endl;
            }
        }
    }
    return 0;
}

void strupper(char* str){
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        str[i] = toupper(str[i]);
    }
}

vector<char*>* split(char* in){
    vector<char*>* out = new vector<char*>;
    int counter = 0;
    char* temp = new char[strlen(in)]();
    for (int i = 0; i < strlen(in); i++){
        if (in[i] == ' '){
            out->push_back(temp);
            counter = 0;
            temp = new char[strlen(in)]();
        }
        else{
            temp[counter] = in[i];
            counter++;
        }
        if (i == strlen(in)-1){
            out->push_back(temp);
        }
    }
    return out;
}    

List* shuntingYard(vector<char*>* in){//Used pseudocode from https://en.wikipedia.org/wiki/Shunting-yard_algorithm
  cout<<"testing"<<endl;
    List* outQueue = new List();
    List* opStack = new List();
    vector<char*>::iterator it = in->begin();
    while (it != in->end()){
        char* value = (*it);
        if (checkDigit(value)){
            outQueue->push(value);
	    cout<<"Number"<<endl;
        }
        else if (strcmp(value,"(") == 0){
            opStack->push(value);
	    cout<<"Number2"<<endl;
        }
        else if (strcmp(value,")") == 0){
            while (strcmp(opStack->sPeek(),"(") != 0){
                outQueue->push(opStack->sPop());
            }
            opStack->sPop();
        }
        else{
            int cPrecedence = getPrecedence(value);
            char* next = opStack->sPeek();
            while (next && (getPrecedence(next) > cPrecedence || (getPrecedence(next) == cPrecedence && strcmp(next, "^") != 0)) && strcmp(next,"(") != 0){
                outQueue->push(opStack->sPop());
                next = opStack->sPeek();
            }
            opStack->push(value);
        }
    }
    while (opStack->sPeek() != NULL){
        outQueue->push(opStack->sPop());
    }
    return outQueue;
}

bool checkDigit(char* in){
    for (int i = 0; i < strlen(in); i++){
        if (!isdigit(in[i])){
            return false;
        }
    }
    return true;
}

int getPrecedence(char* in){
    if (strcmp(in,"+") == 0 || strcmp(in,"-") == 0){
        return 1;
    }
    else if (strcmp(in,"*") == 0 || strcmp(in,"/") == 0){
        return 2;
    }
    else if (strcmp(in,"^") == 0){
        return 3;
    }
    return -1;
}

Node* makeTree(List* postfix, List* stack){
    char* value = postfix->qPop();
    if (value != NULL){
        Node* temp = new Node(value);
        if (checkDigit(value)){
            stack->pushNode(temp);
        }
        else{
            temp->setRight(stack->peekNode());
            stack->sPop();
            temp->setLeft(stack->peekNode());
            stack->sPop();
            stack->pushNode(temp);
        }
    }
    else{
        return stack->peekNode();
    }
    makeTree(postfix, stack);
}

void infix(Node* tree){//Infix Traversal
    if (tree != NULL){
        if (!checkDigit(tree->getValue())){
            cout<<"(";
        }
        infix(tree->getLeft());
        cout<<tree->getValue();
        infix(tree->getRight());
        if (!checkDigit(tree->getValue())){
            cout<<")";
        }
    }
}

void m_postfix(Node* tree){//Postfix Traversal
    if (tree != NULL){
        m_postfix(tree->getLeft());
        m_postfix(tree->getRight());
        cout<<tree->getValue();
    }
}

void prefix(Node* tree){//Prefix Traversal
    if (tree != NULL){
        cout<<tree->getValue();
        prefix(tree->getLeft());
        prefix (tree->getRight());
    }
}
