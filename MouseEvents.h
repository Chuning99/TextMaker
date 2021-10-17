//
// Created by chuning liu on 4/2/21.
//

#ifndef PROJECT1SFMLTYPE_MOUSEEVENTS_H
#define PROJECT1SFMLTYPE_MOUSEEVENTS_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

template<class T>
class MouseEvents {
public:
    // returns true if the mouse clicks on the object
    static bool mouseClicked(T &object, sf::RenderWindow &window, sf::Event event);

    // returns true if the mouse clicks anywhere in the window
    static bool mouseClicked(sf::RenderWindow &window, sf::Event event);
    static bool mouseHoverOn(T &object, sf::RenderWindow &window);

};

template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {
    if (event.type == event.MouseButtonPressed) {
        return true;
    }
}

template<class T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window, sf::Event event) {

    if (event.mouseButton.button != sf::Mouse::Left) {
        return false;
    }
    bool inObject = object.getobjectGlobalBounds().contains(window.mapPixelToCoords(
            sf::Vector2i(event.mouseButton.x, event.mouseButton.y)
    ));
    cout << "Mouse clicked" << "(" << event.mouseButton.x << ", " << event.mouseButton.y << ")" << endl;
    return inObject;
}

template<class T>
bool MouseEvents<T>::mouseHoverOn(T &object, sf::RenderWindow &window) {
    sf::Vector2i mouseposition = sf::Mouse::getPosition(window);

    bool inObject = object.getobjectGlobalBounds().contains(window.mapPixelToCoords(
            mouseposition));
   return inObject;

}

#endif //PROJECT1SFMLTYPE_MOUSEEVENTS_H
