#ifndef OPERATOR_H_
#define OPERATOR_H_
#include "token.h"
#include <iostream>
#include "string.h"
#include <cassert>
#include "assert.h"
#include "integer.h"
using namespace std;

class Operator: public Token{
    public:
    Operator (string operato);
    Operator (string operato,int prec);
    int get_type ();
    // string get_this ();    
    string type () const;
    void print ();
    double eval (const Integer a,const Integer b);
    friend bool operator > (const Operator a, const Operator b);
    friend bool operator < (const Operator a, const Operator b);
    friend ostream& operator << (ostream& outs, const Operator& printMe);
    int get_pred ()const;
    private:
    string _op;
    int _prec;
};

#endif // OPERATOR_H_