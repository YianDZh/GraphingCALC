#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include "../../includes/graph/graph.h"
#include <SFML/Graphics.hpp>
#include "../../includes/SMFL_BS/button.h"
#include "../../includes/SMFL_BS/textbox.h"

using namespace std;
class System
{
public:
    System();
    System(Graph_info* info);

    void Step(int command);
    int Size();
    void Draw(sf::RenderWindow& window);
    void update (Graph_info* info);
private:
//    vector<Particle> system;
    sf::CircleShape shape;
    Graph_info* _info;
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    sf::RectangleShape x_axis;
    sf::RectangleShape y_axis;
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    Graph tempo ;
    sf::Vector2f vel;


};

#endif // SYSTEM_H
