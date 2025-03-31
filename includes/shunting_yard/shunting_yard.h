#ifndef SHUNTING_YARD_H_
#define SHUNTING_YARD_H_

#include <iostream>
#include "../../includes/token/integer.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/function.h"
#include "../../includes/token/token.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"


using namespace std;

class ShuntingYard{
    public:
    ShuntingYard ();
    ShuntingYard (Queue <Token*> Sample);
    Queue <Token*> postfix();
    friend ostream& operator << (ostream& outs, const ShuntingYard& printMe);
    Queue <Token*> postfix(Queue <Token*> Sample);
    void infix(Queue <Token*> Sample);
    Queue <Token*> get_fotest() const;


    private:
    Queue <Token*> _inner;
};


#endif // SHUNTING_YARD_H_