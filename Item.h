//
// Created by 刘储宁 on 4/30/21.
//

#ifndef PROJECT1SFMLTYPE_ITEM_H
#define PROJECT1SFMLTYPE_ITEM_H
#include "Inputbox.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "States.h"
#include "MouseEvents.h"
#include "Image.h"
using namespace std;
class Item : public sf::Drawable, public sf::Transformable, public MouseEvents<Item>{
public:
Item();
Item(string itemname);
~Item();
Item(float height, float weight,float ItemX,float ItemY,const string text);
string getItem();
void setItem(string itemname);


virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
void update();
void setPostion(float positionx, float positiony);
void hoverOnView();
void outLineView();
void defaultView();
sf::FloatRect getobjectGlobalBounds() const;
void setSize(sf::Vector2f position);
    bool getHiddenState() const{
        return state.getStates()[HIDDEN];
    }

    //set hidden
    void setHidden(bool hidden) {
        state.setHidden(hidden);
    }
private:
    Inputbox inputbox;
    sf::Text itemname;
    sf::Font font;
    States state;

};


#endif //PROJECT1SFMLTYPE_ITEM_H
