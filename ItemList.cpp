//
// Created by 刘储宁 on 4/30/21.
//

#include "ItemList.h"

ItemList::ItemList() {

}

vector<Item*> ItemList::getItemList() const{
    return itemlist;
}

void ItemList::addItem(string itemname) {
    Item *item = new Item();
    item->setItem(itemname);
   itemlist.push_back(item);
}

Item* ItemList::getItem(int index) const {
    return itemlist.at(index);
}

void ItemList::removeItem(int index) {
     itemlist.erase(itemlist.begin()+index);
}

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for(int i = 0; i < itemlist.size();i++){
        window.draw(*itemlist[i],states);
    }

}

void ItemList::update() {

}

void ItemList::setItemSize(sf::Vector2f size) {
    this->itemSize = sf::Vector2f(size.x,size.y);
      for(int i = 0; i <itemlist.size();i++){
        itemlist[i]->setSize(itemSize);
    }
}

sf::Vector2f ItemList::getSize() {
    return itemSize;
}

void ItemList::setPosition(float x, float y) {

    itemListPosition.x = x;
    itemListPosition.y = y;
    float tempy = itemListPosition.y;
    for(int i = 0; i < itemlist.size(); i++){
        itemlist[i]->setPostion(itemListPosition.x,tempy);
        cout<<"tempy is :"<<tempy<<endl;
        cout<<"itemSize is :"<<itemSize.y<<endl;
        tempy+= itemSize.y+10;
    }

}

vector<sf::FloatRect> ItemList::getGlobalBounds() const {
    vector<sf::FloatRect> itemlistGlobalBounds;
   for(int i = 0; i< itemlist.size();i++){
       itemlistGlobalBounds.push_back(itemlist[i]->getobjectGlobalBounds());
   }
   return itemlistGlobalBounds;
}


