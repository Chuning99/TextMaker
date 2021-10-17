//
// Created by chuning liu on 4/2/21.
//

#ifndef PROJECT1SFMLTYPE_CURSOR_H
#define PROJECT1SFMLTYPE_CURSOR_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SnapshotInterface.h"
#include "States.h"
#include "GUIComponent.h"
#include "Constant.h"

using namespace std;

class Cursor : public GUIComponent {

private:
    void toggleBlinkState();

private:
    sf::RectangleShape cursor;
    sf::Clock clock;
    int blinkSpeed = 500;
    States state;

public:

    Cursor();//default constructor
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const; //draw  cursor
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event); //addeventhandler function
    virtual void update(); //update cursor
    virtual void update(float x_position, float y_position); //update cursor with position
    virtual Snapshot &getSnapshot();   //get snapshot
    virtual void applySnapshot(const Snapshot &snapshot); //applysnapshot
    virtual void setPosotion(float x, float y);

    //get hiddenstate
    bool getHiddenState() {
        return state.getStates()[HIDDEN];
    }

    //set hidden
    void setHidden(bool hidden) {
        state.setHidden(hidden);
    }

    //get disable state
    bool getDisableState() {
        return state.getStates()[DISABLED];
    }

    //set disable state
    void setDisableState(bool disable) {
        state.setStates(DISABLED, disable);
    }
};


#endif //PROJECT1SFMLTYPE_CURSOR_H
