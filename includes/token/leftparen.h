#ifndef LEFTPAREN_H_
#define LEFTPAREN_H_
#include <iostream>
#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "integer.h"
#include "operator.h"
#include "token.h"
#include "string.h"
using namespace std;

class LeftParen: public Token{
    public:
    LeftParen ();
    void print ();
    LeftParen (string bug);
    
    private:
    string something;
    char _par;
};

#endif // LEFTPAREN_H_