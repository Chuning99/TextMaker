//
// Created by 刘储宁 on 5/22/21.
//

#ifndef PROJECT1SFMLTYPE_SLIDER_H
#define PROJECT1SFMLTYPE_SLIDER_H
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "MouseEvents.h"
#include "SliderBar.h"
class Slider : public GUIComponent{
public:
    Slider();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);

    virtual void update();

//from SnapshotInterface
    virtual Snapshot &getSnapshot() ;

    virtual void applySnapshot(const Snapshot &snapshot) ;
    void setPosition(sf::Vector2f position);

    void setColor(sf::Color color);
    void setScale(float x, float y);
    float getTextXPosition();
    float getTextYPosition();
    float getShadowTextXPosition();
    float getShadowTextYPosition();
    int getTextXValue();
    int getTextYValue();
    int getShadowXValue();
    int getShadowYValue();
    int getTextOpacity();
    int getShadowOpacity();
    int getRotation();
    int getSkewValue();
    int getBackGroundOpacityRedValue();
    int getBackGroundOpacityBlueValue();
    int getBackGroundOpacityGreenValue();

    int getFontShadowSizeValue();
    int getFontSizeValue();
    float getTextRotation();
    float getShadowRotation();
    sf::Color getColor();
    sf::FloatRect getobjectGlobalBounds();





private:
SliderBar textOpacity;
SliderBar shadowOpacity;
SliderBar TextX_axis;
SliderBar TextY_axis;
SliderBar shadowX_axis;
SliderBar shadowY_axis;
SliderBar Fontsize;
SliderBar FontShadowSize;
SliderBar Skew;
SliderBar BackgroundOpacityRed;
SliderBar BackgroundOpacityBlue;
SliderBar BackgroundOpacityGreen;
SliderBar TextRotation;
SliderBar ShadowTextRotation;
};


#endif //PROJECT1SFMLTYPE_SLIDER_H
