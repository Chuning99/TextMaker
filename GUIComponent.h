//
// Created by chuning liu on 4/2/21.
//

#ifndef PROJECT1SFMLTYPE_GUICOMPONENT_H
#define PROJECT1SFMLTYPE_GUICOMPONENT_H

#include <SFML/Graphics.hpp>
#include "SnapshotInterface.h"
#include "EventHandler.h"
#include "States.h"

class GUIComponent
        : public EventHandler, public SnapshotInterface, public sf::Drawable, public States, public sf::Transformable {
public:
    GUIComponent();

    virtual ~GUIComponent() {}

//from the sf::Drawable class
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const = 0;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event) = 0;

    virtual void update() = 0;

//from SnapshotInterface
    virtual Snapshot &getSnapshot() = 0;

    virtual void applySnapshot(const Snapshot &snapshot) = 0;
    //textinpiut
    //

private:

};


#endif //PROJECT1SFMLTYPE_GUICOMPONENT_H
