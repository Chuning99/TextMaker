//
// Created by 刘储宁 on 5/30/21.
//

#ifndef PROJECT1SFMLTYPE_COLOR_H
#define PROJECT1SFMLTYPE_COLOR_H

#include <SFML/Graphics.hpp>
#include "Constant.h"
#include "GUIComponent.h"
#include "MouseEvents.h"
#include "HSVPicker.h"
class Color : public GUIComponent {
public:
    Color();
    Color(sf::Color color);
    void setColor(sf::Color color,double hue, double s = 255, double v = 255);
    sf::Color getColor();
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
    sf::FloatRect getobjectGlobalBounds();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);

    virtual void update();

    //from SnapshotInterface
    virtual Snapshot &getSnapshot();

    virtual void applySnapshot(const Snapshot &snapshot) ;
    //textinpiut
    sf::Color &getFillColor();

    void setFillColor(const sf::Color &fillColor);

    bool getHiddenState(){
        return states.getStates()[HIDDEN];
    }
    void setHidden(bool hidden){
//       hsvPicker.setHidden(hidden);
        states.setHidden(hidden);
    }
    void printHSV();

private:
    sf::RectangleShape box;
    sf::Color fillColor;
    States states;
    //double colorHue;
    //HSVPicker hsvPicker;
};


#endif //PROJECT1SFMLTYPE_COLOR_H
