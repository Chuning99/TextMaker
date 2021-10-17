//
// Created by 刘储宁 on 5/23/21.
//

#ifndef PROJECT1SFMLTYPE_SLIDERBAR_H
#define PROJECT1SFMLTYPE_SLIDERBAR_H
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "Fonts.h"
#include "TextLabel.h"
#include "MouseEvents.h"
class SliderBar : public GUIComponent {
public:
SliderBar();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const ;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event) ;

    virtual void update() ;

//from SnapshotInterface
    virtual Snapshot &getSnapshot() ;

    virtual void applySnapshot(const Snapshot &snapshot) ;
void setPosition(sf::Vector2f position);
void setCirclePosition(int value);
void setValue(int value);
void setFont(sf::Font font);
int getValue();
void setString(string string);
string getString();

void setMaxnumber(int number);

void setLineLength(float length);
    int getMaxnumber();
    float getLineLength();
sf::Vector2f getCirclePosition();
sf::Vector2f getPosition();
sf::FloatRect getobjectGlobalBounds();
sf::FloatRect getGlobalBounds();







private:
    int Maxnumber;
    TextLabel textLabel;
    TextLabel number;
    //sf::Text text;
    //sf::Text number;
    sf::CircleShape circle;
    sf::RectangleShape line;
    bool mouseClick = false;
    bool dragging = false;
    sf::Vector2f Mouseoffset;
    int MouseX, MouseY = 0;
};


#endif //PROJECT1SFMLTYPE_SLIDERBAR_H
