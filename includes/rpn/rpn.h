#ifndef RPN_H_
#define RPN_H_
#include <iostream>
#include "../../includes/token/integer.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/function.h"
#include "../../includes/token/token.h"
using namespace std;

class RPN {
    public:
    RPN (Queue <Token*> Posfix);
    // RPN (Stack <Token*> Posfix);
    // Stack<Token*> queue_to_stack(Queue <Token*> Sample);
    double operator() ();
    double operator() (int trial);
    double operator() (double trial);
    void set_input (Queue <Token*> newin);
    Queue <Token*> get_fotest() const;
    friend ostream& operator << (ostream& outs, const RPN& printMe);
    private:
    Queue <Token*> _inner;
};


#endif // RPN_H_