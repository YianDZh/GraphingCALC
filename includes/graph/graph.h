#ifndef GRAPH_H_
#define GRAPH_H_
#include <SFML/Graphics.hpp>
#include "../../includes/graph_info/graph_info.h"
#include <iostream>
#include "../../includes/plot/plot.h"
#include "../../includes/cord_translator/cord_translator.h"

#include "../../includes/vector/vector_class.h"
class Graph {
    public:
    Graph ();
    Graph (Graph_info* new_info);

    // ~Graph ();
    void set_info(Graph_info* info);
    void draw(sf::RenderWindow& Window);
    void update();
    private:
    Graph_info* _info;
    Plot plotter;
    Vector <sf::Vector2f> _points;
};

#endif // GRAPH_H_