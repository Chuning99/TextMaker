//
// Created by Chuning Liu on 6/1/21.
//

#include "ColorPicker.h"

ColorPicker::ColorPicker() {
    box.setSize(sf::Vector2f(50,50));
    setPosition(sf::Vector2f(1100,950));
    setColor(sf::Color::Red);
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(2);
    palette.setHidden(true);
}

void ColorPicker::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box,states);
    if(!palette.getStates()[HIDDEN]){
        palette.draw(window,states);
    }

}

void ColorPicker::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            bool inColorBox = MouseEvents<ColorPicker>::mouseClicked(*this,window,event);

            if(inColorBox){
                palette.setHidden(!palette.getHiddenState());
            }
            if(!palette.getHiddenState()){
                palette.addEventHandler(window,event);
            }
        }
    }
}

void ColorPicker::update() {
    if(this->palette.getHsvPicker().isColorPicked()){
        setColor(this->palette.getHsvPicker().getPickedColor());
        this->palette.setHidden(true);
        this->palette.getHsvPicker().setColorPicked(false);
    }
}

Snapshot &ColorPicker::getSnapshot() {

}

void ColorPicker::applySnapshot(const Snapshot &snapshot) {

}

void ColorPicker::setColor(sf::Color color) {
    this->color = color;
    box.setFillColor(color);
}

void ColorPicker::setPosition(sf::Vector2f position) {
    box.setPosition(position);
    palette.setPosition(sf::Vector2f(position.x,position.y+box.getGlobalBounds().height+10));
}

sf::Color ColorPicker::getColor() {
    return box.getFillColor();
}

sf::FloatRect ColorPicker::getobjectGlobalBounds() {
    return box.getGlobalBounds();
}