#include "operator.h"
#include "assert.h"
#include <cmath>
#include <cassert>
 Operator::Operator (string operato):Token (3){
    _op=operato;
    if (operato == "+"||operato=="-")
        _prec=1;
    else if (operato == "*"||operato=="/")
        _prec=2;
    else if (operato == "^")
        _prec=3;
 }
    Operator::Operator (string operato,int prec){
        _op=operato;
        
     }
int Operator::get_type (){
    return this->get_type();
}    
string Operator::type () const{
    return _op;
}
void Operator::print (){
    cout<<_op;
}
int Operator::get_pred ()const{
    return _prec;
}

double Operator::eval (const Integer a,const Integer b){
    double res = 0;
    if (_op=="+"){
        res=a.get_Value()+b.get_Value();
    }
    else if (_op=="-"){
        res=a.get_Value()-b.get_Value();

   }
    else if (_op=="*"){
        // cout<< a<< "\t"<<b<<"\n";
        // cout<< a.get_Value()<< "\t"<<b.get_Value()<<"\n";
        // cout<<a.get_Value()*b.get_Value()<<"\n";
        res=a.get_Value()*b.get_Value();

    }
    else if (_op=="/"){
        //!assert(!(b.get_Value()==0.00));
        res=a.get_Value()/b.get_Value();
    }
    else if (_op=="^"){
        // assert(!(b.get_Value()==0.00));
        //TODO::
        res = pow (a.get_Value(),b.get_Value());
    }
    else{
        assert(0);
    }
    return res;
}

    bool  operator > (const Operator a, const Operator b){
        return a._prec > b._prec;
    }
    bool  operator < (const Operator a, const Operator b){
            return a._prec < b._prec;
    }

    // ostream& operator << (ostream& outs, const Operator& printMe){
    //     cout<<printMe.type();
    //     return outs;
    // }