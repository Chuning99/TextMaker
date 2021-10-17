//
// Created by 刘储宁 on 6/1/21.
//

#ifndef PROJECT1SFMLTYPE_COLORPICKER_H
#define PROJECT1SFMLTYPE_COLORPICKER_H
#include <SFML/Graphics.hpp>
#include "Palette.h"
#include "GUIComponent.h"
#include "MouseEvents.h"
#include "States.h"
class ColorPicker : public GUIComponent{
public:
    ColorPicker();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const ;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event) ;

    virtual void update();
    void setColor(sf::Color color);
    void setPosition(sf::Vector2f position);
    sf::Color getColor();
    sf::FloatRect getobjectGlobalBounds();

//from SnapshotInterface
    virtual Snapshot &getSnapshot() ;

    virtual void applySnapshot(const Snapshot &snapshot) ;

private:
    Palette palette;
    sf::RectangleShape box;
    sf::Color color;
    States states;
};


#endif //PROJECT1SFMLTYPE_COLORPICKER_H
