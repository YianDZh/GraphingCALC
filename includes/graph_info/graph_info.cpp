#include "graph_info.h"
#include "../../includes/constants.h"
    // void Graph_info::set_info(){
    //     _num_of_points=1000;
    //     _equation = "x^2";
    //     window_dimensions = sf::Vector2f (1120,800);
    //     _origin = sf::Vector2f(556,400);
    //     _scale = sf::Vector2f (1,1);
    //     _domain= sf::Vector2f (-5,5);   
    // }
    Graph_info::Graph_info(){
        _num_of_points=3000;

        _equation = "x^2";
        window_dimensions = sf::Vector2f (SCREEN_WIDTH-SIDE_BAR,SCREEN_HEIGHT);
        _origin = sf::Vector2f(556,400);
        _scale = sf::Vector2f (1,1);
        bool isPolar=false;
        _domain= sf::Vector2f (-5,5);  
    }
    void Graph_info::reset(){
        _num_of_points=3000;
        // _equation = "x^2";
        window_dimensions = sf::Vector2f (SCREEN_WIDTH-SIDE_BAR,SCREEN_HEIGHT);
        _origin = sf::Vector2f(556,400);
        _scale = sf::Vector2f (1,1);
        _domain= sf::Vector2f (-5,5);  
        // bool isPolar=false;

    }

