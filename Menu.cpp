//
// Created by 刘储宁 on 5/6/21.
//

#include "Menu.h"
Menu::Menu(vector<string> itemnames){

//itemLists.
//at(LISTS[0].at(0));
//      for(int i = 0; i < LISTS.size();i++){
//          //j [0,4)
//          ItemList itemList;
//          itemLists.push_back(itemList);
        state.setHidden(true);
          for(int j = 0; j <itemnames.size();j++){
              this->itemList.addItem(itemnames.at(j));
              if(j == 0){
                  this->itemList.getItem(j)->setHidden(false);
                  this->itemList.setItemSize(sf::Vector2f(200,5));
              }
              else{
                  this->itemList.getItem(j)->setHidden(true);
                  this->itemList.setItemSize(sf::Vector2f(300,50));
              }


              //itemLists[i].setPosition(10,400);
          }

}
 void Menu::addEventHandler(sf::RenderWindow& window, sf::Event event){
//      if(event.type == sf::Event::MouseButtonPressed){
//          if(event.mouseButton.button == sf::Mouse::Left){
//              int foundi = -1;
//              int foundj = -1;
//              for(int i = 0; i < itemLists.size();i++){
//                  for(int j = 0; j < itemLists[i].getItemList().size();j++){
//                      Item item = *(itemLists[i].getItem(j));
//                      bool inMenu = MouseEvents<Item>::mouseClicked(item,window,event);
//                      if(inMenu){
//                         foundi = i;
//                         foundj = j;
//                         break;
//                      }
//
//                  }
//              }
//              cout<<"found i = "<<foundi<<endl;
//              cout<<"found j = "<<foundj<<endl;
//              if(foundj >0 && !itemLists[foundi].getItem(foundj)->getHiddenState()){
//                  for( int j = 1; j<itemLists[foundi].getItemList().size();j++){
//                      itemLists[foundi].getItem(j)->setHidden(true);
//
//                  }
//
//              }
//
//              if(foundj == 0){
//                  for( int j = 1; j<itemLists[foundi].getItemList().size();j++){
//                      itemLists[foundi].getItem(j)->setHidden(!itemLists[foundi].getItem(j)->getHiddenState());
//                  }
//
//              }
//
//         }



//          else if (event.type == sf::Event::MouseLeft) {
//              checkmousein = false;
//              mousein = -1;
//          } else if (event.type == sf::Event::MouseMoved) {
//              checkmousein = true;
////                mousein = -1;
////                cout<<"("<<sf::Mouse::getPosition().x<<","<<sf::Mouse::getPosition().y<<")";
//////                mousein = true;
//
//
//
//              }
//              if (mousein >= 1) {
////                    cout<<"mouse is moving"<<endl;
////                    cout<<"Found in mouse moving "<<mousein<<endl;
//                  dropdownMenu.getItemList().getItem(mousein)->hoverOnView();
//
//              }
//
//          }

//      }


//      }
}
 void Menu::draw(sf::RenderTarget& window, sf::RenderStates states) const{

     for(int j = 0; j < itemList.getItemList().size();j++){
         if(!itemList.getItemList()[j]->getHiddenState()){
             window.draw(*(itemList.getItem(j)),states);
         }
     }

 }

void Menu::update() {
for(int i = 0; i < itemList.getItemList().size();i++){
    itemList.getItem(i)->defaultView();
    if(!state.getHiddenState()){
        itemList.getItem(0)->hoverOnView();
    }
}
}

 Snapshot& Menu::getSnapshot()  //get snapshot
 {

 }
 void Menu::applySnapshot(const Snapshot& snapshot) //to apply snapshot
 {

 }
 void Menu::addSnapshotToHistory(string snapshotString){

}
 ItemList Menu::getItemList(){
     return itemList;
}


void Menu::refreshItemsStates(){

}
void Menu::replaceTheFirstItem(int index){

}
//set hidden

vector<sf::FloatRect>Menu:: getobjectGlobalBounds() const{
   return itemList.getGlobalBounds();
}
void Menu::setPosition(float x, float y){
//    itemListPosition.x = x;
//    itemListPosition.y = y;
//    float tempx = itemListPosition.x;
//    for(int i = 0; i < itemLists.size();i++){
//       itemLists[i].setPosition(tempx,y);
//       tempx += itemLists[i].getGlobalBounds().at(0).width;
//    }

    itemList.setPosition(x,y);

}

void Menu::setItemList(const ItemList &itemList) {
    Menu::itemList = itemList;
}

const States &Menu::getState() const {
    return state;
}

void Menu::setState(const bool hidden) {
    state.setHidden(hidden);
    for(int j = 0; j <itemList.getItemList().size();j++){
        if(j == 0){
            this->itemList.getItem(j)->setHidden(false);
        }
        else{
            this->itemList.getItem(j)->setHidden(true);
        }
        //itemLists[i].setPosition(10,400);
    }
}

const sf::Vector2f &Menu::getMenuPosition() const {
    return menuPosition;
}

void Menu::setMenuPosition(const sf::Vector2f &menuPosition) {
    Menu::menuPosition = menuPosition;
}

Menu::Menu() {

}

void Menu::swithcHiddenState() {
    state.setHidden(!state.getStates()[HIDDEN]);
    for( int j = 1; j < itemList.getItemList().size();j++){
        itemList.getItem(j)->setHidden(!itemList.getItem(j)->getHiddenState());
    }
}




