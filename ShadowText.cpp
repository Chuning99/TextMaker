//
// Created by 刘储宁 on 5/22/21.
//

#include "ShadowText.h"

ShadowText::ShadowText() {
//    shadowText.setFont(Fonts::getFont(Fonts::ARIAL));
//    shadowText.setString("");
//    shadowText.setPosition(sf::Vector2f(SHADOWTEXTX,SHADOWTEXTY));
//    shadowText.setColor(sf::Color::White);

}

void ShadowText::setPosition(sf::Vector2f position) {
      shadowText.setPosition(position);
      cout<<"shadow text position : "<<"("<<shadowText.getPosition().x<<","<<shadowText.getPosition().y<<")"<<endl;
}

void ShadowText::setCharacterSize(int size) {
       shadowText.setCharacterSize(size);
}

void ShadowText::setString(string string) {
       shadowText.setString(string);
}

void ShadowText::setFont(sf::Font font) {
     shadowText.setFont(font);
}

void ShadowText::setColor(sf::Color color) {
    shadowText.setColor(color);
}

void ShadowText::setScale(float x, float y) {
      shadowText.setScale(x,y);
}

int ShadowText::getCharacterSize() {
    return shadowText.getCharacterSize();
}

string ShadowText::getString() {
    return shadowText.getString();
}

sf::Font* ShadowText::getFont() {
    //return *(shadowText.getFont());
}

sf::Color ShadowText::getColor() {
    return shadowText.getColor();
}

sf::Vector2f ShadowText::getPosition() {
    return shadowText.getPosition();
}

sf::Vector2f ShadowText::getScale() {
    return shadowText.getScale();
}

void ShadowText::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    window.draw(shadowText,states);
                  std::cout<<"Test shadow text on drow function"<<endl;
}
