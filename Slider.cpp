//
// Created by Chuning Liu on 5/22/21.
//

#include "Slider.h"

Slider::Slider() {
textOpacity.setString("Text Opacity:");
textOpacity.setMaxnumber(255);
textOpacity.setLineLength(255);
textOpacity.setPosition(sf::Vector2f(10,1100));
textOpacity.setCirclePosition(255);
shadowOpacity.setString("Shadow Opacity:");
shadowOpacity.setMaxnumber(255);
shadowOpacity.setLineLength(255);
shadowOpacity.setPosition(sf::Vector2f(10,1200));
shadowOpacity.setCirclePosition(100);
TextX_axis.setString("Text X-Axis:");
    TextX_axis.setMaxnumber(2000);
    TextX_axis.setLineLength(2000);
    TextX_axis.setPosition(sf::Vector2f(10,1300));
    TextX_axis.setCirclePosition(1000);
TextY_axis.setString("Text Y-Axis");
    TextY_axis.setMaxnumber(2000);
    TextY_axis.setLineLength(2000);
    TextY_axis.setPosition(sf::Vector2f(10,1400));
    TextY_axis.setCirclePosition(400);
shadowX_axis.setString("Shadow X-Axis:");
    shadowX_axis.setMaxnumber(2000);
    shadowX_axis.setLineLength(2000);
    shadowX_axis.setPosition(sf::Vector2f(10,1500));
    shadowX_axis.setCirclePosition(1000);
shadowY_axis.setString("Shadow Y-Axis");
    shadowY_axis.setMaxnumber(2000);
    shadowY_axis.setLineLength(2000);
    shadowY_axis.setPosition(sf::Vector2f(10,1600));
    shadowY_axis.setCirclePosition(400);
Fontsize.setString("Normal Text Size:");
    Fontsize.setMaxnumber(300);
    Fontsize.setLineLength(300);
    Fontsize.setPosition(sf::Vector2f(620,1100));
    Fontsize.setCirclePosition(200);
    FontShadowSize.setString("Shadow Text Size");
    FontShadowSize.setMaxnumber(300);
    FontShadowSize.setLineLength(300);
    FontShadowSize.setPosition(sf::Vector2f(1370,1100));
    FontShadowSize.setCirclePosition(200);
Skew.setString("Skew:");
    Skew.setMaxnumber(100);
    Skew.setLineLength(100);
    Skew.setPosition(sf::Vector2f(2100,1100));
    Skew.setCirclePosition(0);
BackgroundOpacityRed.setString("BackgroundOpacity:");
    BackgroundOpacityRed.setMaxnumber(255);
    BackgroundOpacityRed.setLineLength(255);
    BackgroundOpacityRed.setPosition(sf::Vector2f(1300,1200));
    BackgroundOpacityRed.setCirclePosition(0);
BackgroundOpacityBlue.setString("BackgroundOpacityBlue:");
    BackgroundOpacityBlue.setMaxnumber(255);
    BackgroundOpacityBlue.setLineLength(255);
    BackgroundOpacityBlue.setPosition(sf::Vector2f(1300,1300));
    BackgroundOpacityBlue.setCirclePosition(0);
BackgroundOpacityGreen.setString("BackgroundOpacityGreen:");
    BackgroundOpacityGreen.setMaxnumber(255);
    BackgroundOpacityGreen.setLineLength(255);
    BackgroundOpacityGreen.setPosition(sf::Vector2f(1300,1400));
    BackgroundOpacityGreen.setCirclePosition(0);
TextRotation.setString("TextRotation:");
    TextRotation.setMaxnumber(360);
    TextRotation.setLineLength(360);
    TextRotation.setPosition(sf::Vector2f(10,1700));
    TextRotation.setCirclePosition(0);
ShadowTextRotation.setString("ShadowTextRotation");
    ShadowTextRotation.setMaxnumber(360);
    ShadowTextRotation.setLineLength(360);
    ShadowTextRotation.setPosition(sf::Vector2f(10,1800));
    ShadowTextRotation.setCirclePosition(0);

}

void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    textOpacity.draw(window,states);
shadowOpacity.draw(window,states);
TextX_axis.draw(window,states);
TextY_axis.draw(window,states);
shadowX_axis.draw(window,states);
shadowY_axis.draw(window,states);
TextRotation.draw(window,states);
Fontsize.draw(window,states);
FontShadowSize.draw(window,states);
Skew.draw(window,states);
BackgroundOpacityRed.draw(window,states);
ShadowTextRotation.draw(window,states);

}

void Slider::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    textOpacity.addEventHandler(window,event);
    shadowOpacity.addEventHandler(window,event);
    TextX_axis.addEventHandler(window,event);
    TextY_axis.addEventHandler(window,event);
    shadowX_axis.addEventHandler(window,event);
    shadowY_axis.addEventHandler(window,event);
    TextRotation.addEventHandler(window,event);
    Fontsize.addEventHandler(window,event);
    FontShadowSize.addEventHandler(window,event);
    Skew.addEventHandler(window,event);
    BackgroundOpacityRed.addEventHandler(window,event);
    BackgroundOpacityBlue.addEventHandler(window,event);
    BackgroundOpacityGreen.addEventHandler(window,event);
    ShadowTextRotation.addEventHandler(window,event);

}

void Slider::update() {

}

void Slider::setPosition(sf::Vector2f position) {

}

void Slider::setColor(sf::Color color) {

}

void Slider::setScale(float x, float y) {

}

sf::Color Slider::getColor() {
    return sf::Color();
}

sf::FloatRect Slider::getobjectGlobalBounds() {
    return sf::FloatRect();
}

Snapshot &Slider::getSnapshot() {

}

void Slider::applySnapshot(const Snapshot &snapshot) {

}

float Slider::getTextXPosition() {
    return TextX_axis.getPosition().x;
}


int Slider::getFontSizeValue() {
    return Fontsize.getValue();
}

float Slider::getTextRotation() {
    return TextRotation.getValue();
}

float Slider::getShadowRotation() {
    return ShadowTextRotation.getValue();
}

float Slider::getTextYPosition() {
    return TextY_axis.getPosition().y;
}

float Slider::getShadowTextXPosition() {
    return shadowX_axis.getPosition().x;
}

float Slider::getShadowTextYPosition() {
    return shadowY_axis.getPosition().y;
}

int Slider::getTextXValue() {
    return TextX_axis.getValue();
}

int Slider::getTextYValue() {
    return TextY_axis.getValue();
}

int Slider::getShadowXValue() {
    return shadowX_axis.getValue();
}

int Slider::getShadowYValue() {
    return shadowY_axis.getValue();
}

int Slider::getTextOpacity() {
    return textOpacity.getValue();
}

int Slider::getShadowOpacity() {
    return shadowOpacity.getValue();
}

int Slider::getRotation() {
    return 0;
}

int Slider::getSkewValue() {
    return Skew.getValue();
}


int Slider::getFontShadowSizeValue() {
    return FontShadowSize.getValue();
}

int Slider::getBackGroundOpacityRedValue() {
    return BackgroundOpacityRed.getValue();
}

int Slider::getBackGroundOpacityBlueValue() {
    return BackgroundOpacityBlue.getValue();
}

int Slider::getBackGroundOpacityGreenValue() {
    return BackgroundOpacityGreen.getValue();
}
