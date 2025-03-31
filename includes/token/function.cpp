#include "function.h"

    Function::Function (string type):Token (10){
        _func =type;
    }
    
    bool Function::not_x (){
        return !(_func=="x"||_func=="X");
    }

    double Function::eval (double num){
        if (_func=="x"||_func=="X"){
            return num;
        }
        else if (_func == "sin"){
            return sin (num);

        }
        else if (_func == "cos"){
            return cos (num);
        }
        else if (_func == "tan"){
            return tan (num);
        }
        else if (_func == "e"){
            return EULER;
        }
        else if (_func=="ln"){
            return log10 (num);
        }
        return 0.00;
    }
    
    void Function::print (){
        cout<<_func;
    }  
