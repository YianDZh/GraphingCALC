#include "animate.h"
#include "../../includes/constants.h"
#include <iostream>
using namespace std;
#include "../../includes/system/system.h"
#include "../../includes/SMFL_BS/button.h"
#include "../../includes/SMFL_BS/textbox.h"

animate::animate():sidebar(WORK_PANEL, SIDE_BAR)

{
        
    if (!_font.loadFromFile("ToThePointRegular.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    if (!font.loadFromFile("Roboto-Thin.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will
    _info = new Graph_info();
    window.setFramerateLimit(60);
    
    mouseIn = true;


    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color (150,55,238));

    cout<<"Geme CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration

    // myTextLabel = sf::Text("Initial String for myTextLabel", font);
    // myTextLabel.setCharacterSize(20);
    // myTextLabel.setStyle(sf::Text::Bold);
    // myTextLabel.setColor(sf::Color(225,6,0));
    // myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));
    arr = read ();
    _textbox = Textbox (40, sf::Color(155,211,221),false);
    _textbox.setFont (font);
    _textbox.setPosition (sf::Vector2f(5,0));
    _textbox.setLimit(true, 50);
    Polar=Button ("Reset",{100,30},15,sf::Color::White,sf::Color::Black);
    Polar.setFont (font);
    Polar.setPosition ({1200,700});

    ActualPolar=Button ("Polar",{100,30},15,sf::Color::White,sf::Color::Black);
    ActualPolar.setFont (font);
    ActualPolar.setPosition ({1200,600});

     eq1=Button (arr.at(0), {250,45},20,sf::Color (0,255,123),sf::Color::Black);
    eq1.setFont (font);
    eq1.setPosition ({1140,150});

     eq2=Button (arr.at(1), {250,45},20,sf::Color (0,255,123),sf::Color::Black);
    eq2.setFont (font);
    eq2.setPosition ({1140,195});
    
     eq3=Button (arr.at(2), {250,45},20,sf::Color (0,255,123),sf::Color::Black);
    eq3.setFont (font);
    eq3.setPosition ({1140,240});
    
     eq4=Button (arr.at(3), {250,45},20,sf::Color (0,255,123),sf::Color::Black);

    eq4.setFont (font);
    eq4.setPosition ({1140,285});
   
    eq5=Button (arr.at(4), {250,45},20,sf::Color (0,255,123),sf::Color::Black);

    eq5.setFont (font);
    eq5.setPosition ({1140,330});

    _info->_equation=eq1.getString();
    system = System(_info);

    cout<<"animate instantiated successfully."<<endl;

}

void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);
    if (mouseIn){
        window.draw(mousePoint);
    }

    sidebar.draw(window);

    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)
    window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .
    _textbox.drawTo (window);
    eq1.drawTo (window);
    eq2.drawTo (window);
    eq3.drawTo (window);
    eq4.drawTo (window);
    eq5.drawTo (window);   
    Polar.drawTo (window);
    ActualPolar.drawTo (window);


}

void animate::update(){
    //cause changes to the data for the next frame
    system.Step(command);
    command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

        //mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);




    }
}
void animate::render(){
    window.clear();
    //    window.clear(sf::Color (215,210,203));
       Draw();
       window.display();
}



void animate::processEvents()
{
   sf::Event event;
   float mouseX, mouseY;


   while (window.pollEvent(event))//or waitEvent
       
       {
//!!BIG BLOCK OF JUNK

        if (Polar.isMouseOver(window)){
            Polar.setBackColor(sf::Color(255,222,0));
            if (event.mouseButton.button == sf::Mouse::Left){
                command=99;
            }
        } 
        else {
            Polar.setBackColor(sf::Color::White);
        }
        if (ActualPolar.isMouseOver(window)){
            ActualPolar.setBackColor(sf::Color(255,222,0));
            if (event.mouseButton.button == sf::Mouse::Left){
                _info->isPolar= !_info->isPolar;
                system=System (_info);
            }
        } 
        else {
            ActualPolar.setBackColor(sf::Color::White);
        }
        if (eq1.isMouseOver(window)){
            eq1.setBackColor(sf::Color(255,222,0));
            if (event.mouseButton.button == sf::Mouse::Left){
                
                _info->_equation =  eq1.getString();
                system=System (_info);
            }
        } 
        else {
            eq1.setBackColor(sf::Color::White);
        }
        if (eq2.isMouseOver(window)){
            eq2.setBackColor(sf::Color(255,222,0));
            if (event.mouseButton.button == sf::Mouse::Left){
                _info->_equation =  eq2.getString();
                system=System (_info);            }
        } 
        else {
            eq2.setBackColor(sf::Color::White);
        }
        if (eq3.isMouseOver(window)){
            eq3.setBackColor(sf::Color(255,222,0));
            if (event.mouseButton.button == sf::Mouse::Left){
                _info->_equation =  eq3.getString();
                system=System (_info);            }
        } 
        else {
            eq3.setBackColor(sf::Color::White);
        }
        if (eq4.isMouseOver(window)){
            eq4.setBackColor(sf::Color(255,222,0));
            if (event.mouseButton.button == sf::Mouse::Left){
                _info->_equation =  eq4.getString();
                system=System (_info);            }
        } 
        else {
            eq4.setBackColor(sf::Color::White);
        }
        if (eq5.isMouseOver(window)){
            eq5.setBackColor(sf::Color(255,222,0));
            if (event.mouseButton.button == sf::Mouse::Left){
                _info->_equation =  eq5.getString();
                system=System (_info);            }
        } 
        else {
            eq5.setBackColor(sf::Color::White);
        }
//!!big block of JHuksoka

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            _textbox.setSelected(true);
            
            return;
        } 
        if (event.type == sf::Event::TextEntered) {
            _textbox.typedOn(event);
            // cout<<_textbox.getText()<<"\n";
            
            return;

        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)&&_textbox.Selected()) {
            bool empt = false;
            try{
            string store =  _info->_equation;
            _textbox.setSelected(false);
            // cout<<_info->_equation<<"\n";
            if (_textbox.getText().length()==0){
                throw int (9);
            }
            // else{
                // write (store);
                _info->_equation = _textbox.getText();

                // cout<<_info->_equation<<"\n";
                _textbox.clear();
            // system.update (_info);
            // command =77;
                system=System (_info);
                update_vector();
                empt=!empt;
            // }
            }
            catch (int fail){
                 myTextLabel = sf::Text("INVALID INPUT", font);
                 myTextLabel.setColor(sf::Color(225,6,0));
                myTextLabel.setCharacterSize(30);
                myTextLabel.setStyle(sf::Text::Bold);
            }
            if (empt==true){
                myTextLabel = sf::Text("", font);
            }
            // return;
   
        }  

        
        if (!_textbox.Selected()) {
       // check the type of the event...
           switch (event.type)
           {
           // window closed
           case sf::Event::Closed:
               window.close();
               break;

           // key pressed
           case sf::Event::KeyPressed:
               switch(event.key.code){


                case sf::Keyboard::Left:
                   sidebar[SB_KEY_PRESSED] = "LEFT ARROW";
                   command = 4;
                   break;
               case sf::Keyboard::Right:
                   sidebar[SB_KEY_PRESSED] = "RIGHT ARROW";
                   command = 6;
                   break;
                case sf::Keyboard::Up:
                   sidebar[SB_KEY_PRESSED] = "UP";
                   command =7;
                   break;
                case sf::Keyboard::Down:
                   sidebar[SB_KEY_PRESSED] = "DOWN";
                   command =8;
                   break;
               case sf::Keyboard::Escape:
                   sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                   window.close();
                break;
                case sf::Keyboard::O:
                    sidebar[SB_KEY_PRESSED] = "O: ZOOOOM";
                    command = 1;
                    break;
                case sf::Keyboard::P:
                    sidebar[SB_KEY_PRESSED] = "P: Outs";
                    command = 9;
                    break;
                case sf::Keyboard::Comma:
                  sidebar[SB_KEY_PRESSED] = "Reset";
                    command = 99;
                    break;
           case sf::Event::MouseEntered:
               mouseIn = true;
               break;

           case sf::Event::MouseLeft:
               mouseIn = false;
               break;

           case sf::Event::MouseMoved:
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                //Do something with it if you need to...

               break;
           case sf::Event::MouseButtonReleased:
                   if (event.mouseButton.button == sf::Mouse::Right)
                   {
                       sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
                               mouse_pos_string(window);

                   }

                   else{
                       sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                               mouse_pos_string(window);
                   }
                  
                   break;

               default:
                   break;
            }
           }
       }
    }
}
void animate::run()
{
   while (window.isOpen())
   {

       processEvents();
       update();
       window.clear();
    //    window.clear(sf::Color (215,210,203));
       render(); //clear/draw/display
   }
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
   write();
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}

// Vector <Button> animate::group(int size){
//     Vector <Button> temp;
//     for (int i=0;i<size;i++){
//         temp [i]= Button ("sex",sf::Vector2f (200,30),16,sf::Color::White,sf::Color::Green);
//     }
//     return temp;
// } 

    void animate::write(){
        ofstream myfile;
        myfile.open("read.txt",ofstream::out|ofstream::trunc);
        if (!myfile.is_open()) { 
        cerr << "Error opening the file!" << endl; 
        exit; 
        }
        cout << arr.size() << endl;
        if (myfile.is_open()){
            for(int i =0;i<arr.size();i++){
            myfile << arr.at(i) << "\n";
            }
        myfile.close();
        }
        else 
        cout<<"This shit is bad\n";

    }



    Vector <string> animate::read (){
        Vector <string> line;
        string temp;
        ifstream myfile ("read.txt");
        if (!myfile.is_open()) { 
        cerr << "Error opening the file!" << endl; 
        exit; 
        }
        if (myfile.is_open()){
            while ( getline (myfile,temp) )
            {
                line.push_back(temp);
                cout << temp << '\n';
        }
        myfile.close();
        }

        else 
            cout << "BROKEN"; 
        return line;
    }
    

    Vector <Button> animate::group(Vector <string> arrat , sf::Font font){
        Vector <Button> a;
        for (int i=0;i<arrat.size();i++){
            a.at(i)=Button (arrat[i],{100,30},20,sf::Color::Black,sf::Color::White);
            a.at(i).setFont (font);
            a.at(i).setPosition ({1200.0f,(300.0f+(100.0f*i))});
        }
        return a;
    }

    void animate::update_vector(){
        if (arr.size()==5){
            arr.pop_back();
        }
        arr.insert(0,_info->_equation);
            eq5.change (eq4.getString());
            eq4.change (eq3.getString());
            eq3.change (eq2.getString());
            eq2.change (eq1.getString());
            eq1.change(_info->_equation);
        
    }
