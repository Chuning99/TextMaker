//
// Created by 刘储宁 on 5/22/21.
//

#ifndef PROJECT1SFMLTYPE_HSVPICKER_H
#define PROJECT1SFMLTYPE_HSVPICKER_H
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "States.h"
#include "Constant.h"
#include <tuple>
#include <algorithm>
#include <iostream>
#include "MouseEvents.h"

using namespace std;
class HSVPicker : public GUIComponent{
public:
    HSVPicker();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);

    virtual void update();
    void setColorPoint();
    sf::FloatRect getobjectGlobalBounds();
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f position);
    void setColor(sf::Color color);
    std::tuple<float, float, float> RGBtoHSV(const sf::Color& color);
    sf::Color HSVtoColor(double h, double s, double v);


//from SnapshotInterface
    virtual Snapshot &getSnapshot();

    virtual void applySnapshot(const Snapshot &snapshot);

    const sf::Color &getPickedColor() const;
    void setPickedColor(sf::Vector2f pickedPosition);
    bool isColorPicked() const;
    void setColorPicked(bool colorPicked);
private:
    sf::VertexArray colors;
    States HSVstates;
    sf::Vector2f position;

private:
    sf::Color pickedColor;
    bool colorPicked = false;
    float hueValue;
    float sValue;
    float vValue;
    bool stable;
};


#endif //PROJECT1SFMLTYPE_HSVPICKER_H