#include "rightparen.h"

 RightParen::RightParen ():Token (6){
    _string = " ";
    _par = ')';
 }
    RightParen::RightParen (string newset):Token(6){
        _string = newset;
        _par = ')';
    }
   void RightParen::print (){
      cout<<_par;
   }

    