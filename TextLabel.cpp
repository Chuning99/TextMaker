//
// Created by chuning liu on 4/2/21.
//

#include "TextLabel.h"
#include "Constant.h"
TextLabel::TextLabel(){
    if (!font.loadFromFile("../ttfFile/arial.ttf")){
        cout<<"animate() CTOR: Fonts failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    myTextLabel = sf::Text("TextInput :", font);
    myTextLabel.setCharacterSize(40);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setColor(sf::Color::White);
    myTextLabel.setPosition(sf::Vector2f(MYTEXTLABLEX, MYTEXTLABLEY));
}
void TextLabel::update(){

}
void TextLabel::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(myTextLabel,states);
}

void TextLabel::setPosition(sf::Vector2f position) {
myTextLabel.setPosition(position);
}

void TextLabel::setString(string name) {
myTextLabel.setString(name);
}

void TextLabel::setCharacterSize(int size) {
  myTextLabel.setCharacterSize(size);
}

string TextLabel::getString() {
    return myTextLabel.getString();
}

sf::Vector2f TextLabel::getPosition() {
    return myTextLabel.getPosition();
}

int TextLabel::getCharacterSize() {
    return myTextLabel.getCharacterSize();
}

sf::FloatRect TextLabel::getGlobalBounds() {
    return myTextLabel.getGlobalBounds();
}
