#include "system.h"
#include "../../includes/random/random.h"
#include "../../includes/constants.h"
#include <iostream>

System::System(){

}
System::System(Graph_info* info)
{


    _info=info;
    tempo = Graph (_info);


    Random r;
    int xpos = 100;
    int ypos = 100;
    //the shape of the object, along  with its velocity, acceleration,
    //position, etc. should be part of the individual object.
    shape = sf::CircleShape(10);
    
    shape.setPosition(sf::Vector2f(xpos, ypos));
    vel = sf::Vector2f(r.Next(-5,5), r.Next(-5,5)); //random velocity
    int r_ = r.Next(0,255);
    int g_ = r.Next(0,255);
    int b_ = r.Next(0,255);
    shape.setFillColor(sf::Color(r_, g_, b_));

    x_axis.setSize (sf::Vector2f(1120,4));
    x_axis.setFillColor (sf::Color(0,110,51));
    x_axis.setPosition (sf::Vector2f (0,_info->_origin.y));
    y_axis.setSize (sf::Vector2f(1120,4));
    y_axis.setFillColor (sf::Color(203,96,21));
    y_axis.setPosition (sf::Vector2f (_info->_origin.x,0));
    y_axis.setRotation (90);
    tempo.update();

    
}


//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Step(int command){
        //all this is the responsibility of the
        // individual object:
        shape.move(vel);
        sf::Vector2f pos = shape.getPosition();
        if ((pos.x)>=WORK_PANEL-20)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if (pos.x<=0)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if ((pos.y)>=SCREEN_HEIGHT-20)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);
        if (pos.y<=0)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);
        
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        if (command == 6){
            //*Right
            _info->_domain.x += (1/_info->_scale.x);
            _info->_domain.y += (1/_info->_scale.x);

            // double smth = (_info->_domain.y*_info->_scale.y)-(_info->_domain.x*_info->_scale.x);  
            double smth = (_info->_domain.y)-(_info->_domain.x);  
            float change_x = (_info->window_dimensions.x / (smth));
    
            _info->_origin.x -=change_x/_info->_scale.x;
            // _info->_origin.y + change_y;
            
            y_axis.setPosition (_info->_origin.x,0);
            


        }
        if (command ==4){
            //*LEFT
            _info->_domain.x -= (1/_info->_scale.x);
            _info->_domain.y -=(1/_info->_scale.x);
            // cout<<"Current Domain: "<<_info->_domain.x<<"\t"<<_info->_domain.y<<"\n";
            double smth = (_info->_domain.y)-(_info->_domain.x);  
            // double smth = (_info->_domain.y)-(_info->_domain.x);  
            float change_x =(_info->window_dimensions.x / (smth));

            _info->_origin.x += change_x/_info->_scale.x;

            y_axis.setPosition (_info->_origin.x,0);
            // cout<<"Current Origin (x): "<<_info->_origin.x<<"\n";
            // cout<<"Current Origin (y): "<<_info->_origin.y<<"\n";
        }
        if (command == 9){
             //*Zoomout
            //    cout<<"Current Scale: "<<_info->_scale.x<<"\t"<<_info->_scale.y<<"\n";
            // cout<<"Current Domain: "<<_info->_domain.x<<"\t"<<_info->_domain.y<<"\n";

            //  cout<<"Current Scale: "<<_info->_scale.x<<"\t"<<_info->_scale.y<<"\n";
            // cout<<"Current Domain: "<<_info->_domain.x<<"\t"<<_info->_domain.y<<"\n";

            _info->_scale.x*=0.9;
            _info->_scale.y*=0.9;
            _info->_domain.x/=0.9;
            _info->_domain.y/=0.9;
        }
        if (command==1){
            //*Zoomin
            //   cout<<"Current Scale: "<<_info->_scale.x<<"\t"<<_info->_scale.y<<"\n";
            // cout<<"Current Domain: "<<_info->_domain.x<<"\t"<<_info->_domain.y<<"\n";


            
            _info->_scale.x/=0.9;
            _info->_scale.y/=0.9;
            _info->_domain.x*=0.9;
            _info->_domain.y*=0.9;
            //   cout<<"Current Scale: "<<_info->_scale.x<<"\t"<<_info->_scale.y<<"\n";
            // cout<<"Current Domain: "<<_info->_domain.x<<"\t"<<_info->_domain.y<<"\n";

        }        
        if (command==8){

            // cout<<"Current Domain: "<<_info->_domain.x<<"\t"<<_info->_domain.y<<"\n";
            // double smth = (_info->_domain.y*_info->_scale.y)-(_info->_domain.x*_info->_scale.x);  
            double smth = (_info->_domain.y)-(_info->_domain.x);  
            float change_y =(_info->window_dimensions.y / (smth));

            _info->_origin.y -= change_y/_info->_scale.x;

            x_axis.setPosition (0,_info->_origin.y);
            // cout<<"Current Origin (x): "<<_info->_origin.x<<"\n";
            // cout<<"Current Origin (y): "<<_info->_origin.y<<"\n";
        }        
        if (command==7){

            // cout<<"Current Domain: "<<_info->_domain.x<<"\t"<<_info->_domain.y<<"\n";
            // double smth = (_info->_domain.y*_info->_scale.y)-(_info->_domain.x*_info->_scale.x);  
            double smth = (_info->_domain.y)-(_info->_domain.x);  
            float change_y =(_info->window_dimensions.y / (smth));

            _info->_origin.y += change_y/_info->_scale.x;

            x_axis.setPosition (0,_info->_origin.y);
            // cout<<"Current Origin (x): "<<_info->_origin.x<<"\n";
            // cout<<"Current Origin (y): "<<_info->_origin.y<<"\n";

        }
        if (command==99){
            _info->reset();
            x_axis.setPosition (0,_info->_origin.y);
            y_axis.setPosition (_info->_origin.x,0);

        }
        if (command ==77){
            
        }
        if(command != 0){
        tempo.update();
        }
}


void System::Draw(sf::RenderWindow& window){
    // window.clear();
    window.clear(sf::Color(215,210,203));
    window.draw(x_axis);
    window.draw(y_axis);
    tempo.draw(window);
}
    void System::update (Graph_info* info){
        try{
        _info=info;
        tempo.set_info(_info);
        }
        catch (int fail){
            throw int (4);
        }
        // tempo.update();
    }
