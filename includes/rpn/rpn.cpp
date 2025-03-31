#include  "rpn.h"
    RPN::RPN (Queue <Token*> Posfix){
        _inner= Posfix;
    }
    // RPN::RPN (Stack <Token*> Posfix){
    //     _inner=Posfix;
    // }
    //Queue<Token*>::Iterator 
    //Stack<Token*>::Iterator 

    // Stack<Token*> RPN::queue_to_stack(Queue<Token*> Sample){
    //     Stack <Token*> solver;
    //     for (Queue<Token*>::Iterator test= Sample.begin();test!=Sample.end();test++){
    //         Token *p=*test;
    //         solver.push (p);
    //     }
    //     return solver;
    // }

    double RPN::operator()(){
        double res;
        Stack <Token *> stack_t;
        for (Queue<Token*>::Iterator test= _inner.begin();test!=_inner.end();test++){
            Token* temp = *test;
            // cout<<"Current item: "<<temp<<"\n";
            // cout<<temp->get_type()<<"\n";
            if (temp->get_type()==2){
                Integer* plchldr = static_cast<Integer*> (temp);
                temp=plchldr;
            }
            else if (temp->get_type()==3){
                Operator* op = static_cast <Operator*>(temp);
                //cout<<"In here\n";
                Integer* top= static_cast <Integer*> (stack_t.pop());
                Integer* bot= static_cast <Integer*> (stack_t.pop());
                // cout<<top<<"\t"<<bot<<"\n";
                res = op->eval (*bot,*top);
                // cout<<*a<<"\t"<<*b<<"\n";
                // cout<<res<<"\n";
                Integer* plchldr = new Integer (res);
                // Integer* tempo = plchldr;
                temp =  plchldr;
                // stack_t.push (final);
            }
            stack_t.push(temp);
            // cout<<"Current Stack "<<stack_t<<"\n";
        }
        Integer* a= static_cast <Integer*> (stack_t.pop());
        res=a->get_Value();
        return res;
    }

    void RPN::set_input (Queue <Token*> newin){
        _inner=newin;
        // cout<<"Setting input\n";
        // cout<<"==============================================\n";
        // cout<<"New Queue: "<<newin<<"\n";
        // cout<<"==============================================\n";
        // cout<<"Renewd Queue: "<<_inner<<"\n";

    }
    
    double RPN::operator() (int trial){
        double actual = trial*1.00;
        return (*this)(actual);
    }



//!!!!!!!!!!!!!!!!!!!!!!!
    double RPN::operator() (double trial){
    // cout<<"==============================================\n";
    // cout<<_inner<<"\n";
    double res;
    Stack <Token *> stack_t;
        for (Queue<Token*>::Iterator test= _inner.begin();test!=_inner.end();test++){
            Token* temp = *test;

            //*
            //?operator = 3
            //*int =2
            //*function = 10
            //*
            if (temp->get_type()==2){
                Integer* plchldr = static_cast<Integer*> (temp);
                temp=plchldr;
            }

            else if (temp->get_type()==3){
                Operator* op = static_cast <Operator*>(temp);
                //cout<<"In here\n";
                Integer* top= static_cast <Integer*> (stack_t.pop());
                Integer* bot= static_cast <Integer*> (stack_t.pop());
                // cout<<top<<"\t"<<bot<<"\n";
                res = op->eval (*bot,*top);
                // cout<<*a<<"\t"<<*b<<"\n";
                // cout<<res<<"\n";
                Integer* plchldr = new Integer (res);
                // Integer* tempo = plchldr;
                temp =  plchldr;
                // stack_t.push (final);
            }
             else if (temp->get_type ()==10){
                Function* fofx= static_cast <Function*>(temp);
                if (fofx->not_x()){
                    Integer* top= static_cast <Integer*> (stack_t.pop());
                    Integer * plachld = new Integer (fofx->eval (top->get_Value()));
                    temp = plachld;
                }
                    //TODO remember to  use EVAL later
                else{
                Integer * plchldr = new Integer (fofx->eval(trial));
                temp =  plchldr;
                }
            }
            stack_t.push(temp);
            // cout<<"Current result"<<res<<"\n";
        }
        Integer* a= static_cast <Integer*> (stack_t.top());
        res=a->get_Value();
        return res;    
    }

    
    Queue <Token*> RPN::get_fotest() const{
        return _inner;
    }

    ostream& operator << (ostream& outs, const RPN& printMe){
            for (Queue<Token*>::Iterator test= printMe.get_fotest().begin();test!=printMe.get_fotest().end();test++){
                cout<<*test<<"\t";
            }
            return outs;
    }
    //!!!!!!!!!!!!!!!!!!!!!!!
