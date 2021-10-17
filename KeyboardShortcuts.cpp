#include "KeyboardShortcuts.h"

bool KeyboardShortcuts::isUndo(sf::Event event) {
    if (event.key.code == sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ||
        event.key.code == sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) ||
        event.key.code == sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem)
        || event.key.code == sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem)) {
        cout << "it is Lcontrol" << endl;
        if (event.key.code == sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            cout << "it is  working" << endl;
            return true;
        }
    }

    cout << "it is not working" << endl;
    return false;
}