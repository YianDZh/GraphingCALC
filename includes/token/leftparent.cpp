#include "leftparen.h"

    LeftParen::LeftParen ():Token (5){
        something ="";
        _par = '(';
    }
    LeftParen::LeftParen (string bug):Token (5){
        something=bug;
        _par = '(';
    }
        void LeftParen::print (){
            cout<<_par<<"\t";
        }

