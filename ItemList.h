//
// Created by 刘储宁 on 4/30/21.
//

#ifndef PROJECT1SFMLTYPE_ITEMLIST_H
#define PROJECT1SFMLTYPE_ITEMLIST_H
#include "Item.h"
#include <vector>
class ItemList : public sf::Drawable, sf::Transformable{
public:

    ItemList();
    vector<Item*> getItemList() const;
    void addItem(string itemname);
    Item* getItem(int index) const;
    void removeItem(int index);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void update();
    void setItemSize(sf::Vector2f size);
    sf::Vector2f getSize();
    void setPosition(float x, float y);
    vector<sf::FloatRect>getGlobalBounds() const;







private:
    vector<Item*> itemlist;
    sf::Vector2f itemSize;
    sf::Vector2f itemListPosition;



};


#endif //PROJECT1SFMLTYPE_ITEMLIST_H
