//
// Created by 刘储宁 on 5/6/21.
//

#ifndef PROJECT1SFMLTYPE_MENU_H
#define PROJECT1SFMLTYPE_MENU_H
#include "GUIComponent.h"
#include "ItemList.h"
#include "States.h"
#include "MouseEvents.h"

class Menu : public GUIComponent{
public:
    Menu();

    Menu(vector<string> itemnames);

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void update() override;

    virtual Snapshot& getSnapshot() ; //get snapshot
    virtual void applySnapshot(const Snapshot& snapshot) ;  //to apply snapshot
    virtual void  addSnapshotToHistory(string snapshotString);
    virtual ItemList getItemList();
    bool getHiddenState() {
        return state.getStates()[HIDDEN];
    }

    void refreshItemsStates();
    void replaceTheFirstItem(int index);
    void setPosition(float x, float y);
    //set hidden
    void setHidden(bool hidden) {
        state.setHidden(hidden);
    }
    void swithcHiddenState();
//    int getSnapshotCounter();
//    void setSnapshotCounter(int newsnapshotCounter);
    vector<sf::FloatRect> getobjectGlobalBounds() const;
private:
    ItemList itemList;
    States state;
    sf::Vector2f menuPosition;
public:
    void setItemList(const ItemList &itemList);

    const States &getState() const;

    void setState(const bool hidden);

    const sf::Vector2f &getMenuPosition() const;

    void setMenuPosition(const sf::Vector2f &menuPosition);


};


#endif //PROJECT1SFMLTYPE_MENU_H
