#include "token.h"

    Token::Token (){
        _type = 0;
    }
    
    Token::Token (int type){
        _type = type;
    }
    
    Token::Token (string types){
        _types=types;
    }
    
    void Token::print (){

    }

    //?Prob useless
//!
    ostream& operator << (ostream& outs, Token* printMe){
        printMe->print();
        return outs;
    }
    //  ostream& operator << (ostream& outs,Token printMe){
    //     printMe.print();
    //     return outs;
    // }
//!
    int Token::get_type ()const {
        return _type;
    }    



