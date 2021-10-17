//
// Created by chuning liuon 4/10/21.
//

#ifndef PROJECT1SFMLTYPE_TEXTLABEL_H
#define PROJECT1SFMLTYPE_TEXTLABEL_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class TextLabel {
public:
    TextLabel();//TextLabel constructor
    void update(); //update function
    void draw(sf::RenderTarget& window, sf::RenderStates states) const; //draw Textlabel
    void setPosition(sf::Vector2f position);
    void setString(string name);
    void setCharacterSize(int size);
    sf::FloatRect getGlobalBounds();
    string getString();
    sf::Vector2f getPosition();
    int getCharacterSize();

private:
    sf::Text  myTextLabel;
    sf::Font font;
};


#endif //PROJECT1SFMLTYPE_TEXTLABEL_H
