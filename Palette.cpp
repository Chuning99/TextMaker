//
// Created by 刘储宁 on 5/30/21.
//

#include "Palette.h"

Palette::Palette() {
    red.setColor(sf::Color::Red, 0);
    yellow.setColor(sf::Color::Yellow, 0.1666667);
    green.setColor(sf::Color::Green, 0.333333334);
    azure.setColor(sf::Color::Cyan, 0.5000001);
    blue.setColor(sf::Color::Blue, 0.6666668);
    pink.setColor(sf::Color::Magenta, 0.8333335);
    black.setColor(sf::Color::Black,-1);
    white.setColor(sf::Color::White,-2);
    palette.setSize(sf::Vector2f(240, 120));
    palette.setFillColor(sf::Color::White);

    COLORLIST.push_back(&red);
    COLORLIST.push_back(&yellow);
    COLORLIST.push_back(&green);
    COLORLIST.push_back(&azure);
    COLORLIST.push_back(&blue);
    COLORLIST.push_back(&pink);
    COLORLIST.push_back(&black);
    COLORLIST.push_back(&white);

    hsvPicker.setHidden(true);
}

void Palette::setPosition(sf::Vector2f position) {
    this->position = position;
    palette.setPosition(position.x - 5, position.y - 5);
    red.setPosition(position);
    yellow.setPosition(sf::Vector2f(red.getPosition().x + red.getobjectGlobalBounds().width + 5, position.y));
    green.setPosition(sf::Vector2f(yellow.getPosition().x + yellow.getobjectGlobalBounds().width + 5, position.y));
    azure.setPosition(sf::Vector2f(green.getPosition().x + azure.getobjectGlobalBounds().width + 5, position.y));
    blue.setPosition(sf::Vector2f(position.x, position.y + red.getobjectGlobalBounds().height + 5));
    pink.setPosition(sf::Vector2f(blue.getPosition().x + blue.getobjectGlobalBounds().width + 5, blue.getPosition().y));
    black.setPosition(
            sf::Vector2f(pink.getPosition().x + pink.getobjectGlobalBounds().width + 5, pink.getPosition().y));
    white.setPosition(
            sf::Vector2f(black.getPosition().x + black.getobjectGlobalBounds().width + 5, pink.getPosition().y));

    hsvPicker.setPosition(sf::Vector2f(this->position.x, this->position.y + palette.getGlobalBounds().height));
    cout << hsvPicker.getPosition().x << " ----- " << hsvPicker.getPosition().y << endl;
}

sf::Vector2f Palette::getPosition() {
    return this->palette.getPosition();
}

void Palette::setColor(sf::Color color) {

}


void Palette::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(palette, states);
    for(int i = 0; i < COLORLIST.size();i++){
        window.draw(*COLORLIST[i],states);
    }
    if(!hsvPicker.getStates()[HIDDEN]){
        window.draw(hsvPicker,states);
    }
}

void Palette::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            for(int i = 0; i < COLORLIST.size();i++) {
                bool inColorBox = MouseEvents<Color>::mouseClicked(*COLORLIST[i], window, event);
//               COLORLIST[i]->setHidden(true);
                if (inColorBox) {
                    hsvPicker.setColor(COLORLIST[i]->getColor());
//                    cout << "the hue picked: " << this->pickedColorHue << endl;
                    hsvPicker.setHidden(!hsvPicker.getHiddenState());
//                    this->pickedColorHue = -1;
                }
            }
        }
    }
    if(!hsvPicker.getHiddenState()){
        hsvPicker.addEventHandler(window, event);
    }
}

void Palette::update() {

}

Snapshot &Palette::getSnapshot() {

}

void Palette::applySnapshot(const Snapshot &snapshot) {

}

sf::FloatRect Palette::getobjectGlobalBounds() const {
    return this->palette.getGlobalBounds();
}

HSVPicker &Palette::getHsvPicker() {
    return hsvPicker;
}

void Palette::setHsvPicker(const HSVPicker &hsvPicker) {
    Palette::hsvPicker = hsvPicker;
}
