//
// Created by chuning liu on 4/2/21.
//

#ifndef PROJECT1SFMLTYPE_EVENTHANDLER_H
#define PROJECT1SFMLTYPE_EVENTHANDLER_H

#include <SFML/Graphics.hpp>

class EventHandler {
public:
    //EventHandler();
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event) = 0;

    virtual void update() = 0;
private:

};


#endif //PROJECT1SFMLTYPE_EVENTHANDLER_H
