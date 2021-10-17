//
// Created by chuning liu on 4/2/21.
//

#ifndef PROJECT1SFMLTYPE_INPUTBOX_H
#define PROJECT1SFMLTYPE_INPUTBOX_H

#include <SFML/Graphics.hpp>
#include "Constant.h"
#include <iostream>
using namespace std;

class Inputbox : public sf::Drawable, public sf::Transformable{
public:
    Inputbox();//inputbox constructor
    void update(); //update input box
    Inputbox(float height, float weight, float inputBoxX, float inputBoxY);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const; //draw input box
    sf::FloatRect getInputBoxGlobalBounds() const {  //get input box globalbounds
        return this->inputBox.getGlobalBounds();
    }
    Inputbox(float x, float y);
    void setPosition(float x, float y);
    void setSize(float width, float height);
    sf::Vector2f getInputBoxposition();
    sf::Vector2f getSize();
    void setFillColor(sf::Color color);
    void setOutLineColor(sf::Color color);



private:
    sf::RectangleShape inputBox;
};


#endif //PROJECT1SFMLTYPE_INPUTBOX_H
