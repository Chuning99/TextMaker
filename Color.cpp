//
// Created by 刘储宁 on 5/30/21.
//

#include "Color.h"
Color::Color() {
    box.setSize(sf::Vector2f(COLORBOXSIZE_WIDTH,COLORBOXSIZE_HEIGHT));
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(2);
//    hsvPicker.setHidden(true);

}
Color::Color(sf::Color color) {
    this->fillColor = color;
    box.setSize(sf::Vector2f(COLORBOXSIZE_WIDTH,COLORBOXSIZE_HEIGHT));
    box.setFillColor(color);

}

void Color::setColor(sf::Color color,double hue, double s, double v) {
    fillColor = color;
    box.setFillColor(color);
}

sf::Color Color::getColor() {
    return fillColor;
}

void Color::setPosition(sf::Vector2f position) {
    box.setPosition(position);
//   hsvPicker.setPosition(sf::Vector2f (position.x,box.getPosition().y+150));
}

sf::Vector2f Color::getPosition() {
    return box.getPosition();
}

sf::FloatRect Color::getobjectGlobalBounds() {
    return box.getGlobalBounds();
}

void Color::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(box,states);

}

void Color::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Color::update() {

}

Snapshot &Color::getSnapshot() {

}

void Color::applySnapshot(const Snapshot &snapshot) {

}

void Color::printHSV() {
//   hsvPicker.RGBtoHSV(sf::Color::Red);

}

sf::Color &Color::getFillColor() {
    return fillColor;
}

void Color::setFillColor(const sf::Color &fillColor) {
    Color::fillColor = fillColor;
}
