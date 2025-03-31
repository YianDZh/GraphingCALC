#include "integer.h"

    Integer::Integer (double value): Token (2){
        _val=value;
    }
    Integer::Integer (int value): Token (2){
        _val = value * 1.00;
    }
    Integer::Integer (string value):Token (2){
        _val = stod (value);
    }
    Integer::Integer (char value):Token (2){
        _val= static_cast<double>(value - '0');
    }

    int Integer::get_type (){
        return this->get_type();
    }   
    double Integer::get_Value () const{
        double temp=_val;
        return temp;
    }
    void Integer::print () {
        cout<<_val;
    }
    // ostream& operator << (ostream& outs, const Integer& printMe){
    //     cout<<printMe.get_Value();
    //     return outs;
    // }