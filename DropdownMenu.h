//
// Created by 刘储宁 on 4/30/21.
//

#ifndef PROJECT1SFMLTYPE_DROPDOWNMENU_H
#define PROJECT1SFMLTYPE_DROPDOWNMENU_H
#include "GUIComponent.h"
#include "ItemList.h"
#include "History.h"
#include "TextLabel.h"
const vector<string> LIST = {"Arial", "Agent", "Arcade","OpenSansBold","Supreme"};
class DropdownMenu : public GUIComponent{
public:
    DropdownMenu() ;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void update() override;

    virtual Snapshot& getSnapshot() ; //get snapshot
    virtual void applySnapshot(const Snapshot& snapshot) ;  //to apply snapshot
    virtual void  addSnapshotToHistory(string snapshotString);
    void setItemListPosition(sf::Vector2f position);
    virtual ItemList getItemList();
    bool getHiddenState() {
        return state.getStates()[HIDDEN];
    }

    void refreshItemsStates();
    void replaceTheFirstItem(int index);
    //set hidden
    void setHidden(bool hidden) {
        state.setHidden(hidden);
    }
    int getSnapshotCounter();
    void setSnapshotCounter(int newsnapshotCounter);
    vector<sf::FloatRect> getobjectGlobalBounds() const;
private:
    int snapshotCounter;
    ItemList itemList;
    States state;
    Snapshot selfSnapshot;
    TextLabel fontstyle;

};


#endif //PROJECT1SFMLTYPE_DROPDOWNMENU_H
