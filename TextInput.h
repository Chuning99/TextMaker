//
// Created by chuning liu on 4/2/21.
//

#ifndef PROJECT1SFMLTYPE_TEXTINPUT_H
#define PROJECT1SFMLTYPE_TEXTINPUT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constant.h"
#include "EventHandler.h"
#include "MouseEvents.h"
#include "GUIComponent.h"
#include "History.h"
#include "TextLabel.h"
#include "Inputbox.h"
#include "linkedlist.h"
#include "Cursor.h"


using namespace std;
const string HIGHLIGHT [] = {"int", "char", "double", "float",
                             "+","-","*","/","=","%","0", "1",
                             "2", "3", "4", "5", "6", "7", "8", "9", "\n"};
class TextInput : public GUIComponent{

public:
    TextInput();
   virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);//add event Handler
    void inputTextEventHandler(sf::RenderWindow& window, sf::Event event); // input text and do event
     void update(); //update my text
    void update(Cursor& cursor); //update my text
    void textInMemubarupdate(Cursor& cursor);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const; //draw my text and other staff

    //sf::FloatRect getGlobalBounds () const;
    sf::FloatRect getobjectGlobalBounds() const; //to get my inputbox
    float getTextinputBoundsX() const; //to get textinput weight
    float getTextinputBoundsY() const;
    void parseStringToSfText(string input); //to parseString and change color
    size_t containsHightKey(string str, string& matchedString);   //to check the text we need to change color
    void addSnapshotToHistory(string snapshotString);  //to add snapshot to History

    //from SnapshotInterface
    virtual Snapshot& getSnapshot() ; //get snapshot
    virtual void applySnapshot(const Snapshot& snapshot) ;  //to apply snapshot
    string getTextInputString();
    void setReadFileString(string logotext);
    void setTextInputPosition(sf::Vector2f position);


private:
    int snapshotCounter;
    sf::Font font;
    bool is_input = false;
    float stringlength;
    float stringheight;
    Snapshot selfSnapshot;
    string text_input;
    Inputbox inputbox;
    TextLabel textLabel;
    sf::Text textInput;

    LinkedList<sf::Text> linkedList;
    map<string,sf::Color> COLOR_MAPPER{
            {"int", sf::Color::Blue},
            {"char",sf::Color::Blue},
            {"double",sf::Color::Blue},
            {"float",sf::Color::Blue},
            {"+",sf::Color::Green},
            {"-",sf::Color::Green},
            {"*",sf::Color::Green},
            {"/",sf::Color::Green},
            {"%",sf::Color::Green},
            {"=",sf::Color::Green},
            {"0",sf::Color::Red},
            {"1",sf::Color::Red},
            {"2",sf::Color::Red},
            {"3",sf::Color::Red},
            {"4",sf::Color::Red},
            {"5",sf::Color::Red},
            {"6",sf::Color::Red},
            {"7",sf::Color::Red},
            {"8",sf::Color::Red},
            {"9",sf::Color::Red},
//            {"\n", sf::Color::White}
            };

};


#endif //PROJECT1SFMLTYPE_TEXTINPUT_H
