//
// Created by chuning liu on 4/2/21.
//

#include "Inputbox.h"

Inputbox::Inputbox() {
    inputBox.setSize(sf::Vector2f(1000, 100));
    inputBox.setPosition(sf::Vector2f(INPUTBOX_X, INPUTBOX_Y));
    inputBox.setFillColor(sf::Color::Black);
    inputBox.setOutlineThickness(5);
    inputBox.setOutlineColor(sf::Color::White);

}

void Inputbox::update() {

}

void Inputbox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(inputBox, states);
}

void Inputbox::setPosition(float x, float y){
    inputBox.setPosition(x,y);
}

void Inputbox::setSize(float width, float height){
    inputBox.setSize(sf::Vector2f(width, height));
}

Inputbox::Inputbox(float height, float weight, float inputBoxX, float inputBoxY) {
   inputBox.setSize(sf::Vector2f(height,weight));
   inputBox.setPosition(inputBoxX,inputBoxY);
   inputBox.setFillColor(sf::Color::Blue);
   inputBox.setOutlineThickness(5);

}

Inputbox::Inputbox(float x, float y) {

}

sf::Vector2f Inputbox::getInputBoxposition() {
    return sf::Vector2f(inputBox.getPosition().x,inputBox.getPosition().y);
}

sf::Vector2f Inputbox::getSize() {
    return inputBox.getSize();
}

void Inputbox::setFillColor(sf::Color color) {
   inputBox.setFillColor(color);
   //inputBox.setOutlineColor(sf::Color::Black);
}

void Inputbox::setOutLineColor(sf::Color color) {
inputBox.setOutlineColor(color);
}


