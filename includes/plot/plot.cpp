#include "plot.h"
#include "../../includes/constants.h"

    Plot::Plot (Graph_info* new_info){
        _info = new_info;
        Tokenizer t (_info->_equation);
        // cout<<t.equ()<<"\n";
        // cout<<"Process done\n";
        translate = cord_translator (_info);
        try{
        _post = t.equ();
        }
        catch (int num){
            cout<<"FATAL FAILURE"<<"\n";
            throw int (4);
        }
    }
    Plot::Plot (){  
        _info = new Graph_info();
        translate = cord_translator (_info);
        Tokenizer t (_info->_equation);
        try{
        _post = t.equ();
        }
        catch (int num){
            cout<<"FATAL FAILURE"<<"\n";
            throw int (4);
        }
    }

    void Plot::set_info (Graph_info* newinfo){
        // cout<<"FIRED\n";
        _info = newinfo;
        translate.set_info (newinfo);
    }


    Vector <sf::Vector2f> Plot::operator()(){
    RPN rpn (_post);
    Vector <sf::Vector2f> tempo;
    double ratio = (_info->_domain.y-_info->_domain.x)/(_info->_num_of_points);
    // cout<<ratio<<"\n";
     for (double i=0;i<= _info->_num_of_points; i+=1){
        double x =  _info->_domain.x + i*ratio;
        double y = rpn (x);
        // cout<<x<<"\t"<<y<<"\n";
        if (_info->isPolar==true){
            double r = sqrt(pow(x,2)+pow(y,2));
            double theta = atan2(y, x);
            tempo.push_back (translate(sf::Vector2f (r,theta))); 
        }
        else{
            tempo.push_back (translate(sf::Vector2f (x,y))); 

        }
    }
    // cout << "domain lmao: " << _info->_domain.x << endl;
    // for (double x = _info->_domain.x; x <=_info->_domain.y; x += 0.025){
    //     double y = rpn (x);
    //     tempo.push_back (translate(sf::Vector2f (x,y)));
    //     cout <<"x: " <<x << endl;
    //     cout << "y:" <<y << endl;
    //     }
            return tempo;
    }
