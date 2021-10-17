//
// Created by 刘储宁 on 4/30/21.
//

#include "Item.h"

Item::Item() {
    if (!font.loadFromFile("../ttfFile/arial.ttf")){
        cout<<"animate() CTOR: Fonts failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    itemname = sf::Text("Help", font);
    itemname.setCharacterSize(40);
    itemname.setStyle(sf::Text::Bold);
    itemname.setColor(sf::Color::White);
//    itemname.setPosition(sf::Vector2f(MYTEXTLABLEX, MYTEXTLABLEY));
    inputbox.setPosition(MYTEXTLABLEX,MYTEXTLABLEY);
    inputbox.setSize(MENUBARWIDTH,MENUBARHEIGHT);
    inputbox.setOutLineColor(sf::Color::Black);
    //inputbox.setFillColor(sf::Color::Blue);
    state.setStates(HIDDEN,true);
}
Item::Item(float height, float weight,float ItemX,float ItemY,const string text){
//    inputbox.setSize(height,weight);
//    inputbox.setPosition(ItemX,ItemY);
////    if (!font.loadFromFile("../ttfFile/arial.ttf")) {
////            cout << "animate() CTOR: Fonts failed to load" << endl;
////            cin.get();
////            exit(-1);
////        }
//        //itemname.setFont(font);
//        //itemname.setString(text);
//
//
////    itemname.setString(text);
////    itemname.setCharacterSize(40);
////    itemname.setStyle(sf::Text::Bold);
////    itemname.setFillColor(sf::Color::White);
//    cout<<"before set font"<<endl;
//    //itemname.setPosition(sf::Vector2f(inputbox.getInputBoxposition().x+(weight/2)-(itemname.getGlobalBounds().width/2),inputbox.getInputBoxposition().y));
//    //itemname.setColor(sf::Color::White);
//    cout<<"after set font"<<endl;
}
Item::Item(string itemname) {
    this->itemname.setString(itemname);
}

string Item::getItem() {
    return itemname.getString();
}

void Item::setItem(string itemname) {
  this->itemname.setString(itemname);
}

void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const {
  window.draw(inputbox,states);
  window.draw(itemname,states);

}

void Item::update() {

}

void Item::setPostion(float positionx, float positiony) {
     inputbox.setPosition(positionx,positiony);
    cout << "inputbox: position -> " <<  inputbox.getInputBoxposition().x << endl;
    cout << "inputbox: size -> " <<  inputbox.getSize().x << endl;
    cout << "itemname: size -> " <<  itemname.getGlobalBounds().width << endl;
     itemname.setPosition(sf::Vector2f((inputbox.getSize().x/2.0
                                    -itemname.getGlobalBounds().width/2.0+inputbox.getInputBoxposition().x),inputbox.getInputBoxposition().y));
    // cout<<"itemname position: "<<itemname.getPosition().x<<itemname.getPosition().y<<
//    itemname.setPosition(sf::Vector2f(inputbox.getInputBoxposition().x
//                                      +(inputbox.getSize().x/2.0)
//                                      - itemname.getGlobalBounds().width/2.0,
//                                      inputbox.getInputBoxposition().y));
}

void Item::setSize(sf::Vector2f position) {
    inputbox.setSize(position.x, position.y);
}

Item::~Item() {

}

sf::FloatRect Item::getobjectGlobalBounds() const {
    return inputbox.getInputBoxGlobalBounds();
}

void Item::hoverOnView() {
  inputbox.setFillColor(sf::Color::Blue);
    itemname.setCharacterSize(45);
}

void Item::outLineView() {
inputbox.setOutLineColor(sf::Color::White);
}

void Item::defaultView() {
    inputbox.setOutLineColor(sf::Color::Black);
    inputbox.setFillColor(sf::Color::Black);
    itemname.setCharacterSize(40);
}


//void Item::setSize(float wight, float height) {
//      inputbox.setSize(wight,height);
//
//
//}
