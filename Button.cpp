//
// Created by 刘储宁 on 6/1/21.
//

#include "Button.h"

Button::Button() {
button.setSize(sf::Vector2f(200,80));
setPosition(sf::Vector2f(600,750));

button.setFillColor(sf::Color(120,120,120));
    buttonName.setFont(Fonts::getFont(Fonts::ARIAL));
    buttonName.setCharacterSize(50);
    buttonName.setFillColor(sf::Color::White);
}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const {
 window.draw(button,states);
 window.draw(buttonName,states);
}

void Button::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left){
        inButton = MouseEvents<Button>::mouseClicked(*this,window,event);
        if(inButton){
            setInButton(true);
        }
        }
    }
}

void Button::update() {

}

Snapshot &Button::getSnapshot() {

}

void Button::applySnapshot(const Snapshot &snapshot) {

}

void Button::setPosition(sf::Vector2f position) {
    button.setPosition(position);
    //(inputbox.getSize().x/2.0
    //-itemname.getGlobalBounds().width/2.0+inputbox.getInputBoxposition().x),inputbox.getInputBoxposition().y)
    buttonName.setPosition(sf::Vector2f((button.getSize().x/2.0-buttonName.getGlobalBounds().width/2.0+button.getPosition().x),
                                        button.getSize().y/2.0-buttonName.getGlobalBounds().height/1.5+button.getPosition().y));
}

void Button::setString(string name) {
  buttonName.setString(name);
}

sf::FloatRect Button::getobjectGlobalBounds() {
    return button.getGlobalBounds();
}

string Button::getString() {
    return std::string();
}

sf::Vector2f Button::getPosition() {
    return sf::Vector2f();
}

void Button::setInButton(bool isClick) {
      inButton = isClick;
}

bool Button::getInButton() {
    return inButton;
}
