#ifndef GRAPH_INFO_H_
#define GRAPH_INFO_H_

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
using namespace std;

struct Graph_info{
    Graph_info();
    string _equation;
    sf::Vector2f window_dimensions;
    sf::Vector2f _origin;
    sf::Vector2f _scale;
    sf::Vector2f _domain;
    int _num_of_points;
    bool isPolar;

    void set_string ();
    void reset();

    void set_info ();
};



#endif // GRAPH_INFO_H_  