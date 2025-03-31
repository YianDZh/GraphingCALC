#ifndef ANIMATE_H
#define ANIMATE_H
#include <SFML/Graphics.hpp>
#include "../../includes/system/system.h"
#include <sstream> 
#include <fstream>
#include "../../includes/sidebar/sidebar.h"
#include "../../includes/SMFL_BS/button.h"
#include "../../includes/vector/vector_class.h"
using namespace std;
class animate{
public:
    animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();
    // Vector <Button> group (int size); 
    Vector <string> read();
    void write ();
    Vector <Button> group(Vector <string>arrat , sf::Font font);
    void update_vector();

private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;         //The little red dot
    System system;                      //container for all the animated objects
    int command;                        //command to send to system
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    bool mouseIn;                       //mouse is in the screen
    Sidebar sidebar;     
    Graph_info* _info;               //rectangular message sidebar
    Textbox _textbox;
    sf::Font _font;
    Vector <Button> story; 
    Vector <string> arr;
    Button Polar;
    Button ActualPolar;

    Button eq1;
    Button eq2;
    Button eq3;
    Button eq4;
    Button eq5;

};

string mouse_pos_string(sf::RenderWindow& window);

#endif // GAME_H
