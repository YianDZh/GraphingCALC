#ifndef FUNCTION_H_
#define FUNCTION_H_
#include <iostream>
#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "integer.h"
#include "operator.h"
#include "token.h"
#include <cmath>
#include "string.h"
using namespace std;
const double EULER = 2.71828182845904523536;

class Function: public Token {
    public:
    Function (string type);
    bool not_x ();
    void print ();  
    double eval (double num);
    private:
    string _func;
};

#endif // FUNCTION_H_