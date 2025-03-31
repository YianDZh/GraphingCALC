#include "cord_translator.h"
using namespace std;


    cord_translator::cord_translator (){
        _info = new Graph_info;
    }
    cord_translator::cord_translator (Graph_info* new_info) {
        _info = new_info;
    }
    void cord_translator::set_info (Graph_info * new_info){
        _info = new_info;
    }


//void cord_translator::set_info () {

//}

sf::Vector2f cord_translator::operator () (sf::Vector2f sample) {  
    // double smth = (_info->_domain.y*_info->_scale.y)-(_info->_domain.x*_info->_scale.x);  
     double smth = ((_info->_domain.y)-(_info->_domain.x));  
    float effective =  (_info->window_dimensions.x / (smth));
    float effective_y =  (_info->window_dimensions.y / (smth));

    float effx = _info->_origin.x + (effective*sample.x);
    float effy = _info->_origin.y + (sample.y*-effective_y);


    sf::Vector2f tempo (effx, effy);
    return tempo;
}

// sf::Vector2f cord_translator::operator()(sf::Vector2f sample) {
//     double smth = ((_info->_domain.y) - (_info->_domain.x));
//         // cout<<"SOMETHING : "<<smth<<"\n";

//     float effective = (_info->window_dimensions.x / smth);
//     float effective_y = (_info->window_dimensions.y / smth);
//         // cout << "Current Scale: " << _info->_scale.x << endl;
//         // cout<<"Current Domain: "<<_info->_domain.x<<"\t"<<_info->_domain.y<<"\n";
//         // cout<<"Current Origin (x): "<<_info->_origin.x<<"\n";
//         // cout<<"Current Origin (y): "<<_info->_origin.y<<"\n";
//         // cout<<"Current x: "<<sample.x<<"\n"<<"Current y:"<<sample.y<<"\n";
//     float x, y;

//     if (_info->isPolar) {
//         // Convert polar to Cartesian coordinates
//         double r = sample.x;
//         double theta = sample.y;
//         x = r * cos(theta);
//         y = r * sin(theta);
//     } else {
//         // Use provided Cartesian coordinates directly
//         x = sample.x;
//         y = sample.y;
//     }

//     float effx = _info->_origin.x + (effective * x);
//     float effy = _info->_origin.y + (y * -effective_y);
//     // cout<<"Current x: "<<sample.x<<"\n"<<"Current y:"<<sample.y<<"\n";
//     // cout<<"new x: "<<effx<<"\n"<<"New y:"<<effy<<"\n";
//     sf::Vector2f tempo(effx, effy);
//         //    cout << effx << "\t" << effy << "\n";

//     return tempo;
// }