//
// Created by 刘储宁 on 5/10/21.
//

#include "FileItem.h"
FileItem::FileItem() {
    if (!font.loadFromFile("../ttfFile/arial.ttf")){
        cout<<"animate() CTOR: Fonts failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    this->text = sf::Text("Help",font);
    this->text.setFont(font);

    this->text.setStyle(sf::Text::Bold);
    this->text.setCharacterSize(40);

    this->text.setFillColor(sf::Color::White);
    inputbox.setSize(MENUBARINPUTBOX_WIDTH,MENUBERINPUTBOX_HEIGHT);
    inputbox.setOutLineColor(sf::Color::White);

}

FileItem::FileItem(Image::image icon, std::string text, sf::Vector2f size, sf::Vector2f position) {
//   this->icon.setPosition(position);
//   this->icon.setTexture(Image::getImage(icon));




//
//    inputbox.setPosition(position.x,position.y);
//
//    string getstring = this->text.getString();
//    cout<<"FIle item text string"<<getstring<<endl;

}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(inputbox,states);
     window.draw(icon,states);
    window.draw(this->text,states);

    string getstring = this->text.getString();
   // cout<<"FIle item text in draw`"<<getstring<<endl;

//    this->text.draw(window,states);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

sf::FloatRect FileItem::getGlobalBounds() const {
   return inputbox.getInputBoxGlobalBounds();
}

sf::Vector2f FileItem::getSize() const {
   return icon.getScale();
}

sf::Vector2f FileItem::getPosition() const {
   return icon.getPosition();
}

void FileItem::setPosition(sf::Vector2f pos) {
   icon.setPosition(pos);
   inputbox.setPosition(pos.x,pos.y);
   this->text.setPosition(sf::Vector2f(pos.x+70,pos.y));
}

void FileItem::update() {

    if (!font.loadFromFile("../ttfFile/arial.ttf")){
        cout<<"animate() CTOR: Fonts failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    this->text = sf::Text("Help",font);
    this->text.setCharacterSize(40);
    this->text.setStyle(sf::Text::Bold);
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(sf::Vector2f(300,500));
    this->text.setString("folder");
}

void FileItem::setIcon(Image::image icon) {
    this->icon.setTexture(Image::getImage(icon));
    this->icon.setScale(sf::Vector2f(0.1f,0.1f));
}

void FileItem::setString(string text) {
    this->text.setString(text);
}

void FileItem::setSize(sf::Vector2f size) {
    inputbox.setSize(size.x,size.y);


}

void FileItem::hoverOnView() {
    inputbox.setFillColor(sf::Color::Blue);
    text.setCharacterSize(45);
}

void FileItem::outLineView() {
    inputbox.setOutLineColor(sf::Color::Black);
}

void FileItem::defaultView() {
    inputbox.setOutLineColor(sf::Color::Black);
    inputbox.setFillColor(sf::Color::Black);
    text.setCharacterSize(40);
}

sf::FloatRect FileItem::getobjectGlobalBounds() const {
    return inputbox.getInputBoxGlobalBounds();
}

string FileItem::getString() {
    return text.getString();
}
