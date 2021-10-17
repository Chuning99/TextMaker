//
// Created by 刘储宁 on 5/23/21.
//

#include "SliderBar.h"

SliderBar::SliderBar() {
    cout<<"Test SliderBar Top"<<endl;
    setFont(Fonts::getFont(Fonts::ARIAL));
//    text.setCharacterSize(40);
//    text.setStyle(sf::Text::Bold);
//    text.setColor(sf::Color::White);
    textLabel.setString("name");
    textLabel.setCharacterSize(40);
    number.setCharacterSize(40);
    //textLabel.setPosition(sf::Vector2f(100,1000));
    setString("");
    number.setString(to_string(100));
    setMaxnumber(255);
    setLineLength(255);
    circle.setRadius(10);
    circle.setFillColor(sf::Color::White);
    setPosition(sf::Vector2f(10,1100));
    setCirclePosition(100);
    cout<<"Test SliderBar Tail"<<endl;

}

void SliderBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    //cout<<"Test SliderBar draw Top"<<endl;
    //string textstring = text.getString();
    //cout<<"text string :"<<textstring<<endl;
    //cout<<"text position :"<<"("<<text.getPosition().x<<","<<text.getPosition().y<<")"<<endl;
    //window.draw(text,states);
    textLabel.draw(window,states);
    window.draw(line,states);

    window.draw(circle,states);

    number.draw(window,states);

}

void SliderBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        mouseClick = true;

        if ( circle.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) )
        {
            dragging = true ;
            Mouseoffset.x = event.mouseButton.x - circle.getGlobalBounds().left - circle.getOrigin().x;
            Mouseoffset.y = event.mouseButton.y - circle.getGlobalBounds().top - circle.getOrigin().y ;
        }
    }

    //LMB released
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        mouseClick = false;
        dragging = false ;
    }

    //Mouse Moved in window
    if (event.type == sf::Event::MouseMoved)
    {
       MouseX = event.mouseMove.x;
        MouseY = event.mouseMove.y;
    }
    if (dragging == true)
    {
        int newXPosition = MouseX-Mouseoffset.x;
        if(newXPosition <= line.getPosition().x){
            setValue(0);
            //number.setString(to_string(getValue()));
        }
        else if(newXPosition > line.getPosition().x + line.getGlobalBounds().width){
           setValue(Maxnumber);
            //number.setString(to_string(getValue()));
        }
        else{
            circle.setPosition(MouseX - Mouseoffset.x, line.getPosition().y-circle.getRadius());

        }
        number.setString(to_string(getValue()));
    }

}

void SliderBar::update() {

}

void SliderBar::setPosition(sf::Vector2f position) {
    textLabel.setPosition(position);
     line.setPosition(textLabel.getPosition().x+textLabel.getGlobalBounds().width+10,position.y+textLabel.getGlobalBounds().height);
     number.setPosition(sf::Vector2f(line.getPosition().x+line.getGlobalBounds().width+20,position.y+5));

}

void SliderBar::setCirclePosition(int value) {

    circle.setPosition(sf::Vector2f(line.getPosition().x+value*1.0/Maxnumber*line.getGlobalBounds().width,line.getPosition().y-circle.getRadius()));
}

void SliderBar::setMaxnumber(int number) {
   Maxnumber = number;
}

void SliderBar::setLineLength(float length) {
   line.setSize(sf::Vector2f(length,3));
}

int SliderBar::getMaxnumber() {
    return Maxnumber;
}

float SliderBar::getLineLength() {
    return line.getSize().x;
}

sf::Vector2f SliderBar::getCirclePosition() {
    return circle.getPosition();
}

sf::Vector2f SliderBar::getPosition() {
    return  textLabel.getPosition();
}

sf::FloatRect SliderBar::getobjectGlobalBounds() {
    return circle.getGlobalBounds();
}

sf::FloatRect SliderBar::getGlobalBounds() {
    //sf::FloatRect total(text.getPosition().x,text.getPosition().y,(text.getPosition().x+line.getPosition().x+number.getPosition().x),text.getGlobalBounds().height)
    sf::FloatRect total(textLabel.getPosition().x,textLabel.getPosition().y,(textLabel.getPosition().x+line.getPosition().x+number.getPosition().x),textLabel.getGlobalBounds().height);
    return total;
}

void SliderBar::setString(string string) {
   textLabel.setString(string);
}

string SliderBar::getString() {
    return textLabel.getString();
}

void SliderBar::setValue(int value) {
   setCirclePosition(value);
}

int SliderBar::getValue() {

    return ((circle.getPosition().x-line.getPosition().x)*Maxnumber)/line.getGlobalBounds().width;
}

void SliderBar::setFont(sf::Font font) {
//      textLabel.setFont(font);
//      number.setFont(font);
}

Snapshot &SliderBar::getSnapshot() {

}

void SliderBar::applySnapshot(const Snapshot &snapshot) {

}
