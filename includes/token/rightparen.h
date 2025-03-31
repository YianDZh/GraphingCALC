#ifndef RIGHTPAREN_H_
#define RIGHTPAREN_H_
#include <iostream>
#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "integer.h"
#include "operator.h"
#include "token.h"
#include "string.h"
using namespace std;

class RightParen:public Token{
    public:
    RightParen ();
    RightParen (string newset);
    void print ();
    private:
    string _string;
    char _par;
};

#endif // RIGHTPAREN_H_