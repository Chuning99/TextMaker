//
// Created by 刘储宁 on 4/30/21.
//

#include "DropdownMenu.h"

DropdownMenu::DropdownMenu() {
    fontstyle.setString("Font Style");
    fontstyle.setCharacterSize(40);
    fontstyle.setPosition(sf::Vector2f(1300,880));
    itemList.addItem(LIST.at(0));
    itemList.getItem(0)->setHidden(false);
    itemList.getItem(0)->outLineView();
    for(int i = 0; i < LIST.size();i++){
        itemList.addItem(LIST[i]);
        itemList.getItem(i + 1)->setHidden(true);
    }
    itemList.setItemSize(sf::Vector2f(300,50));
    itemList.setPosition(1300,950);


    state.setStates(HIDDEN, true);
    snapshotCounter = 0;
}

void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {


}

void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    //window.draw(*(itemList.getItem(0)),states);
//    if(itemList.getItem(0)->getHiddenState()){
//        cout << "item hidden" << endl;
//    }
//    else{
//        cout << "item is NOT hidden" << endl;
//    }
    for(int i = 0; i < itemList.getItemList().size();i++){
        if(!itemList.getItemList()[i]->getHiddenState()){
            window.draw(*(itemList.getItem(i)),states);
        }

    }
    fontstyle.draw(window,states);
  // window.draw(itemList,states);
}

Snapshot &DropdownMenu::getSnapshot() {
    return selfSnapshot;
}

void DropdownMenu::applySnapshot(const Snapshot &snapshot) {
    cout << "Dropdown: " << snapshot.getData() << endl;
    selfSnapshot = Snapshot(snapshot);
    this->itemList.getItemList()[0]->setItem(snapshot.getData());
    snapshotCounter--;
    cout<<"SnapshotCounter-- is :"<<snapshotCounter<<endl;
}

void DropdownMenu::update() {
    for(int i = 1; i <itemList.getItemList().size();i++){
        itemList.getItem(i)->defaultView();
    }
}

vector<sf::FloatRect> DropdownMenu::getobjectGlobalBounds() const {
    return itemList.getGlobalBounds();
}

ItemList DropdownMenu::getItemList() {
    return itemList;
}

void DropdownMenu::refreshItemsStates() {
    for(int i = 1;i<itemList.getItemList().size();i++){
        itemList.getItem(i)->setHidden(getHiddenState());
       }


}

void DropdownMenu::replaceTheFirstItem(int index) {
//    if(index >= itemList.getItemList().size()){
//        return;
//    }
    string itemname =  itemList.getItem(index)->getItem();
    cout<<"Item name is "<<itemname<<endl;
//   Item* item = new Item();
//   item->setItem(itemname);
   itemList.getItemList()[0]->setItem(itemname);
   cout<<"itemlist first itme position: )"<<itemList.getItemList()[0]->getPosition().x<<","<<itemList.getItemList()[0]->getPosition().y<<")"<<endl;
    itemList.getItemList()[0]->setPostion(1300,950);

}

void DropdownMenu::addSnapshotToHistory(string snapshotString) {
    string componentId = History::addComponent(this);
    Snapshot snapshot(componentId);
    snapshot.setData(snapshotString);
    cout << "History in: " << snapshot.getComponetId() << " " << snapshot.getData() << endl;
    History::pushHistory(snapshot);
    snapshotCounter++;
    cout<<"SnapshotCounter++ is :"<<snapshotCounter<<endl;
}

int DropdownMenu::getSnapshotCounter() {
    return snapshotCounter;
}

void DropdownMenu::setSnapshotCounter(int newsnapshotCounter) {
     snapshotCounter = newsnapshotCounter;
}

void DropdownMenu::setItemListPosition(sf::Vector2f position) {

    itemList.setPosition(position.x,position.y);
}

