#ifndef CORD_TRANSLATOR_H_
#define CORD_TRANSLATOR_H_
#include <iostream>
#include <cstring> 
#include "string.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include "../../includes/rpn/rpn.h"
#include "../../includes/vector/vector_class.h"
#include "../../includes/graph_info/graph_info.h"


class cord_translator{
    public:
    cord_translator ();
    cord_translator (Graph_info* new_info);
    void set_info (Graph_info * new_info);
    sf::Vector2f operator () (sf::Vector2f sample); 
    private:
    Graph_info* _info;
};

#endif // CORD_TRANSLATOR_H_