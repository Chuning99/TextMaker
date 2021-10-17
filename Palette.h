//
// Created by 刘储宁 on 5/30/21.
//

#ifndef PROJECT1SFMLTYPE_PALETTE_H
#define PROJECT1SFMLTYPE_PALETTE_H
#include <SFML/Graphics.hpp>
#include "Color.h"
#include "GUIComponent.h"
#include "States.h"
#include <map>
#include "MouseEvents.h"

class Palette : public GUIComponent{
public:
    Palette();

    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
    void setColor(sf::Color color);
    sf::Color getColor();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const ;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event) ;

    virtual void update();

//from SnapshotInterface
    virtual Snapshot &getSnapshot();

    virtual void applySnapshot(const Snapshot &snapshot) ;
    sf::FloatRect getobjectGlobalBounds() const;

    HSVPicker &getHsvPicker();
    void setHsvPicker(const HSVPicker &hsvPicker);

private:
    vector<Color*> COLORLIST ;

    Color red;
    Color white;
    Color yellow;
    Color green;
    Color blue;
    Color pink;
    Color black;
    Color azure;
    sf::RectangleShape palette;
    States states;

    sf::Vector2f position;
//    sf::Color hsvPickedColor = sf::Color::White;
    HSVPicker hsvPicker;
//    double pickedColorHue;
};


#endif //PROJECT1SFMLTYPE_PALETTE_H
