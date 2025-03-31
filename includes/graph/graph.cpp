#include "graph.h"

    Graph::Graph (){
    _info = new Graph_info;
    }
    // Graph:: ~Graph (){
    //     delete _info;
    // }
    Graph::Graph (Graph_info* new_info){
        _info = new_info;
        try{
        plotter= Plot (_info);
        }
        catch (int fail){
            throw int (4);
        }
    }
    void Graph::set_info(Graph_info* info){
        try{
        _info =info;
        update();
        }
        catch (int fail){
            throw int (4);
        }

    }

    void Graph::draw(sf::RenderWindow& Window){
        for (int i =0 ;i<_points.size();i++){
            sf::CircleShape circle;
            circle.setFillColor (sf::Color (0,68,129));
            circle.setRadius(2);
            circle.setPosition (_points.at(i));
            Window.draw(circle);
        }
    
    }
    void Graph::update(){
        try{
        plotter.set_info(_info);
        _points = plotter();
        }
        catch (int fail){
            throw int (4);
        }
    }