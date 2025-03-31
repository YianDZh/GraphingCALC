#include "shunting_yard.h"
    ShuntingYard::ShuntingYard ():_inner (){

    }

    ShuntingYard::ShuntingYard (Queue <Token*> Sample){
        _inner = Sample;
    }
    Queue <Token*> ShuntingYard::postfix(){
        Queue <Token*> postfix;
        Stack <Token *> op_hold;
        for (Queue<Token*>::Iterator test= _inner.begin();test!=_inner.end();test++){
            Token* temp = *test;
            // cout<<temp->get_type()<<"\n";
            //left = 5
            //right =6
            //operator = 3
            //int =2
            //function = 10
            if (temp->get_type()==2){
                postfix.push (temp);
            }

            else if (temp->get_type ()==3){
                if (op_hold.empty()||op_hold.top()->get_type()==5){
                    op_hold.push (temp);
                }          
                else{  

                    Operator* holder= static_cast <Operator*> (op_hold.top());
                    Operator* actual = static_cast <Operator*> (temp);
                    if (op_hold.top()->get_type()==10||holder->get_pred()>=actual->get_pred()){
                        Token* a = op_hold.pop ();
                        postfix.push (a);
                        op_hold.push (temp);
                    }
                    else{
                        // Token* temporal = op_hold.top();
                        // Operator* a = static_cast <Operator *> (temp);
                        // Operator* b = static_cast <Operator *> (temporal);
                        op_hold.push (temp);
    
                    }
                }
            }

            else if (temp->get_type ()==5){
                op_hold.push (temp);
            }

            else if (temp->get_type()==6){
                //  cout<<"Currently here\n";
                    while (op_hold.top()->get_type()!=5){
                        Token* a = op_hold.pop ();
                        // cout<<"Current Stack"<<op_hold<<"\n";    
                        postfix.push (a);
                    }
                    op_hold.pop();
            }
            else if (temp->get_type()==10){
                // cout<<"HERE\n";
                if (op_hold.empty()||op_hold.top()->get_type()!=10){
                op_hold.push (temp);

                }
                else{
                Token* a = op_hold.pop ();
                postfix.push (a);
                op_hold.push (temp);
                }
            }

            // cout<<"Current Queue"<<postfix<<"\n";    
            // cout<<"Current Stack"<<op_hold<<"\n";    

        }
        //!Can break
        if (!op_hold.empty()){
        for (Stack<Token*>::Iterator test= op_hold.begin();test!=op_hold.end();test++){
            Token* a = *test;
            postfix.push (a);
            }
        }
        // cout<<"Current Stack"<<op_hold<<"\n";    

        // cout<<postfix<<"\n";    
        return postfix;
    }
//TODO
        void ShuntingYard::infix(Queue <Token*> Sample){
            _inner = Sample;
        }
        Queue <Token*> ShuntingYard::postfix(Queue <Token*> Sample){
            _inner = Sample;
            return postfix ();
        }
//!
       Queue <Token*> ShuntingYard::get_fotest() const{
            return _inner;
        }

        ostream& operator << (ostream& outs, const ShuntingYard& printMe){
            for (Queue<Token*>::Iterator test= printMe.get_fotest().begin();test!=printMe.get_fotest().end();test++){
                cout<<*test<<"\t";
            }
            return outs;
        }
 