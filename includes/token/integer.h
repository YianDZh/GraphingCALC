#ifndef INTEGER_H_
#define INTEGER_H_
#include "string.h"
#include <cstring>
#include "token.h"

class Integer: public Token{
    public:
    Integer (double value);
    Integer (int value);
    Integer (string value);
    Integer (char value);

    int get_type ();    
    double get_Value () const;
    // friend ostream& operator << (ostream& outs, const Integer& printMe);
    void print () ;
    
    private:
    double _val;
    // int _int;
    // string _value;
    // char _char;
};

#endif // INTEGER_H_