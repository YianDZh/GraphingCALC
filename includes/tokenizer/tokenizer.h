#ifndef TOKENIZER_H_
#define TOKENIZER_H_
#include <string>
#include <cstring>
#include <iostream>
#include "assert.h"
#include <SFML/Graphics.hpp>
#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/token/token.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/vector/vector_class.h"
#include "../../includes/graph_info/graph_info.h"

using namespace std; 
// const  string outcs [11]={"sin","cos","tan","ln","+","-","*","/","^","(",")"};

class Tokenizer{
    public:
    // Tokenizer ();
    Tokenizer (string neo);
    Queue <Token*> equ();
    
    private:
    string _eq;
    Vector <string> _options;
    ShuntingYard _postfix;
};

#endif // TOKENIZER_H_