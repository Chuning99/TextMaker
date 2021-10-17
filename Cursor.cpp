//
// Created by chuning liu on 4/2/21.
//

#include "Cursor.h"

Cursor::Cursor() : GUIComponent() {
    cursor.setSize(sf::Vector2f(CURSORHEIGHT, CURSORLENGTH));
    cursor.setPosition(sf::Vector2f(CURSORPOSITIONX, CURSORPOSITIONY));
    //cursor.move(sf::Vector2f(200,10));
    cursor.setFillColor(sf::Color::White);
    state.setStates(DISABLED, true);

}
void Cursor::setPosotion(float x, float y){
    cursor.setPosition(sf::Vector2f(x,y));
}
void Cursor::applySnapshot(const Snapshot &snapshot) {

}

void Cursor::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Cursor::update() {

}


void Cursor::update(float x_position, float  y_position) {
    if (x_position > 0) {
        cursor.setPosition(CURSORPOSITIONX + x_position, y_position);
    } else {
        cursor.setPosition(CURSORPOSITIONX, cursor.getPosition().y);
    }
    if (clock.getElapsedTime().asMilliseconds() > blinkSpeed) {
        setHidden(!getHiddenState());
        clock.restart();
    }
}

Snapshot &Cursor::getSnapshot() {

}

void Cursor::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(cursor, states);
}
