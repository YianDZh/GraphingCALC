#ifndef PLOT_H_
#define PLOT_H_
#include <iostream>
#include <cstring> 
#include "string.h"
#include <cmath>
#include <SFML/Graphics.hpp>
#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/tokenizer/tokenizer.h"

#include "../../includes/rpn/rpn.h"
#include "../../includes/cord_translator/cord_translator.h"
#include "../../includes/vector/vector_class.h"
#include "../../includes/graph_info/graph_info.h"

using namespace std;


class Plot {
    public:
    Plot ();
    Plot (Graph_info* new_info);
    void set_info (Graph_info* newinfo);
    Vector <sf::Vector2f> operator()();
   
    private:
    Graph_info* _info;
    Queue <Token*> _post;
    cord_translator translate;
};


#endif // PLOT_H_