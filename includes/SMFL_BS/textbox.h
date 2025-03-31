#ifndef SIMPLEGAME_TEXTBOX_H
#define SIMPLEGAME_TEXTBOX_H

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox {
public:
    Textbox() {}

    Textbox(int size, sf::Color color, bool sel) {
        textbox.setCharacterSize(size);
        textbox.setFillColor(color);
        isSelected = sel;
        if (sel) {
            textbox.setString("_");
        } else {
            textbox.setString("");
        }
        bg.setFillColor(sf::Color(54,69,79));
        bg.setSize(sf::Vector2f(1115, 90));
        bg.setOutlineThickness (3.0);
        bg.setOutlineColor(sf::Color::Black);
    }

    void setFont(sf::Font &font) {
        textbox.setFont(font);
    }

    void setPosition(sf::Vector2f pos) {
        bg.setPosition(pos);
        textbox.setPosition(pos);
    }

    void setLimit(bool ToF) {
        hasLimit = ToF;
    }

    void setLimit(bool ToF, int lim) {
        hasLimit = ToF;
        limit = lim - 1;
    }

    void setSelected(bool sel) {
        isSelected = sel;
        if (!sel) {
            std::string t = text;
            textbox.setString(t);
            bg.setPosition(sf::Vector2f(2000, 3000));  // Move it out of view
        } else {
            textbox.setString(text + "_");
            // Ensure the bg is positioned correctly if re-selected
            sf::Vector2f pos = textbox.getPosition();
            bg.setPosition(pos);
        }
    }

    std::string getText() {
        return text;
    }

    void drawTo(sf::RenderWindow &window) {
        if (isSelected) {
            window.draw(bg);
            window.draw(textbox);
        }
    }

    void typedOn(sf::Event input) {
        if (isSelected) {
            int charTyped = input.text.unicode;
            if (charTyped < 128) {
                if (hasLimit) {
                    if (text.length() <= limit) {
                        inputLogic(charTyped);
                    } else if (text.length() > limit && charTyped == DELETE_KEY) {
                        deleteLastChar();
                    }
                } else {
                    inputLogic(charTyped);
                }
            }
        }
    }
    bool Selected  ()const {
        return isSelected;
    }
    void clear(){
        text="";
    }
private:
    sf::Text textbox;
    string text;
    bool isSelected = false;
    bool hasLimit = false;
    int limit;
    sf::RectangleShape bg;

    void inputLogic(int charTyped) {
        // cout<<charTyped<<"\n";
        if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
            // cout<<"Fired\n";
            text += static_cast<char>(charTyped);
            // cout<<text<<"\n";
        } else if (charTyped == DELETE_KEY) {
            if (!text.empty()) {
                deleteLastChar();
            }
        } else if (charTyped == ESCAPE_KEY) {
            setSelected(false);
        }
        textbox.setString(text + "_");
    }

    void deleteLastChar() {
        std::string t = text;
        if (!t.empty()) {
            t.pop_back();
            text = "";
            text += t;
            textbox.setString(text + "_");
        }
    }
};

#endif
