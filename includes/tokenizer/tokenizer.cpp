#include "tokenizer.h"
using namespace std;

    Tokenizer::Tokenizer (string neo){
        string outcs [14]={"sin","cos","tan","ln","x","X","+","-","*","/","^","(",")"," "};
        _eq=neo;
        _options= Vector <string>(outcs,13);
    }
    
    Queue <Token*> Tokenizer::equ(){
            //left = 5
            //right =6
            //operator = 3
            //int =2
            //function = 10
        Queue <Token*> res;
        string test = "";
        bool cond=true;
        try{
            for (int i=0;i<_eq.size();i++){
                test+=((_eq.at(i)));
                // cout<<"Current string: "<<test<<"\n";
                if (i==0){
                    if (_eq.at(i)=='-'){
                    res.push (new Integer (-1));
                    res.push (new Operator ("*"));
                    test="";
                    }
                }
                if (_eq.at(i)=='-'){
                    if ((i+1!=_eq.length()) && isdigit(_eq.at (i+1))&&res.back()->get_type()==3){
                        res.push (new Integer (-1));
                        res.push (new Operator ("*"));
                        test="";
                    }
                }
                int a = _options.index_of(test);
                // cout<<"Current array elem: "<<a<<"\n";
                if (a!=-1){
                    Token *ans;
                    if (a>=0&&a<=5){
                        ans= new Function (test);
                        // res.push (ans);
                    }
                    else if (a>=6&&a<=10){
                        ans= new Operator (test);
                    }
                    else if (a==11){
                        ans = new LeftParen;
                        cond=false;
                    }
                    else if (a==12){
                        ans = new RightParen;
                        cond = true;
                    }
                    else if (a==13){
                        test = "";
                        continue;
                    }
                    else {
                        assert (a);
                    }
                    res.push (ans);
                    test ="";
                }
                else if (isdigit (test.front())){
                    // cout<<"ISDIGIT\n";
                    // cout<<(i+1) <<"\t"<<_eq.length()<<"\n";
                    if ((i+1!=_eq.length()) && isdigit(_eq.at (i+1))){
                        continue;
                    }
                    else {
                        // cout<<"Pushing int\n";
                        res.push (new Integer (test));
                        test="";
                    }
                }
                else {
                    continue;
                }
            }
            int wea = res.back()->get_type();
            
            if (test!= ""||cond==false||wea==3){
                int fail = 9;
                throw fail;
            }
        }
        catch (int fail){
            cout<<"FATAL FAILURE"<<test<<"\n";
            throw int (3);
        }
        // cout<<res<<"\n";
        return _postfix.postfix (res);    
    }