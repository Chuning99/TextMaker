//
// Created by 刘储宁 on 5/22/21.
//

#ifndef PROJECT1SFMLTYPE_SHADOWTEXT_H
#define PROJECT1SFMLTYPE_SHADOWTEXT_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "Constant.h"
#include <iostream>
using namespace std;
class ShadowText : public sf::Transformable, public sf::Drawable{
public:
    ShadowText();
    void setPosition(sf::Vector2f position);
    void setCharacterSize(int size);
    void setString(string string);
    void setFont(sf::Font font);
    void setColor(sf::Color color);
    void setScale(float x, float y);
    int getCharacterSize();
    string getString();
    sf::Font* getFont();
    sf::Color getColor();
    sf::Vector2f getPosition();
    sf::Vector2f getScale();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
private:
    sf::Text normalText;
    sf::Text shadowText;


};


#endif //PROJECT1SFMLTYPE_SHADOWTEXT_H
