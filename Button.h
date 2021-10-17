//
// Created by 刘储宁 on 6/1/21.
//

#ifndef PROJECT1SFMLTYPE_BUTTON_H
#define PROJECT1SFMLTYPE_BUTTON_H

#include "GUIComponent.h"
#include "MouseEvents.h"
#include "Fonts.h"
class Button: public GUIComponent {
public:
    Button();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const ;
    void setPosition(sf::Vector2f position);
    void setString(string name);
    sf::FloatRect getobjectGlobalBounds();
    string getString();
    sf::Vector2f getPosition();
    void setInButton(bool isClick);
    bool getInButton();


// from EventHandler
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);

    virtual void update();

//from SnapshotInterface
    virtual Snapshot &getSnapshot();

    virtual void applySnapshot(const Snapshot &snapshot);

private:
    sf::RectangleShape button;
    sf::Text buttonName;
    bool inButton;



};


#endif //PROJECT1SFMLTYPE_BUTTON_H
