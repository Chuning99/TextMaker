//
// Created by chuning liu on 4/2/21.
//

#include "TextInput.h"
#include "States.h"

TextInput::TextInput() {

    if (!font.loadFromFile("../ttfFile/arial.ttf")) {
        cout << "animate() CTOR: Fonts failed to load" << endl;
        cin.get();
        exit(-1);
    }
    textInput.setFont(font);
    text_input = "";  //initialization
    is_input = true;
    textInput.setString("");
//    addSnapshotToHistory(text_input);
    snapshotCounter=0;

}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type) {
            // window closed
            case sf::Event::Closed:
                window.close();
                break;
                // key pressed
            case sf::Event::TextEntered:
                cout << "KeyPressed : " << endl;

                inputTextEventHandler(window, event);
                break;


        }
    }
}

void TextInput::inputTextEventHandler(sf::RenderWindow &window, sf::Event event) {
    cout << "TextEntered : " << event.text.unicode << endl;
    if (is_input) {

        if (event.text.unicode < 128) {
            //UNICODE_DELETE = 8
            if ((event.text.unicode == UNICODE_DELETE) &&
                //Delete key
                (text_input.length() > 0)) {
                text_input.pop_back();
            } else {

                text_input += static_cast<char>(event.text.unicode);
                cout << " *** input Text Event: " <<"--"<< text_input<<"--" << endl;
            }
            if(snapshotCounter ==0){
                addSnapshotToHistory("");
                //snapshotCounter++;
            }
            textInput.setString(text_input);
            addSnapshotToHistory(text_input);
           // snapshotCounter++;
            parseStringToSfText(text_input);
        }
    }
}

void TextInput::update(){
    stringlength = TEXTINPUTX;
    stringheight = TEXTINPUTY;
    for (LinkedList<sf::Text>::iterator iter = linkedList.Begin(); iter != linkedList.End();iter++) {
        sf::Text &text = *iter;
        text.setFont(font);
        text.setCharacterSize(40);


        text.setPosition(stringlength, stringheight);

        if(text.getString() == "\n"){
            stringheight += 80;
            stringlength = TEXTINPUTX;

        }
        else{
            stringlength += text.getGlobalBounds().width;
        }
        inputbox.setSize(1000, stringheight + 80 > 100 ? stringheight  + 80 : 100);
//        inputbox.setSize(1000, stringheight  > 100 ? stringheight : 100);


    }

}
void TextInput::textInMemubarupdate(Cursor &cursor) {
    stringlength = 150;
    stringheight = 50;
    for (LinkedList<sf::Text>::iterator iter = linkedList.Begin(); iter != linkedList.End();iter++) {
        sf::Text &text = *iter;
        text.setFont(font);
        text.setCharacterSize(40);


        text.setPosition(stringlength, stringheight);

        if(text.getString() == "\n"){
            stringheight += 40;
            stringlength = 150;
//            cout << "STRINGHEIHGT: " << getTextinputBoundsY() << endl;
//            cursor.update(getTextinputBoundsX(), getTextinputBoundsY());
            cursor.setPosotion(getTextinputBoundsX(),getTextinputBoundsY());
        }
        else{
            stringlength += text.getGlobalBounds().width;
        }
        //inputbox.setSize(1000, stringheight + 40 > 100 ? stringheight  + 40 : 100);
//        inputbox.setSize(1000, stringheight  > 100 ? stringheight : 100);
        //cout << "STRINGHEIHGT: " << getTextinputBoundsY() << endl;
        cursor.update(getTextinputBoundsX(), getTextinputBoundsY());

    }

}

void TextInput::update(Cursor &cursor) {

    stringlength = TEXTINPUTX;
    stringheight = TEXTINPUTY;
    for (LinkedList<sf::Text>::iterator iter = linkedList.Begin(); iter != linkedList.End();iter++) {
       sf::Text &text = *iter;
       text.setFont(font);
       text.setCharacterSize(40);


       text.setPosition(stringlength, stringheight);

        if(text.getString() == "\n"){
            stringheight += 40;
            stringlength = TEXTINPUTX;
//            cout << "STRINGHEIHGT: " << getTextinputBoundsY() << endl;
//            cursor.update(getTextinputBoundsX(), getTextinputBoundsY());
            cursor.setPosotion(stringlength-150, stringheight);
        }
       else{
           stringlength += text.getGlobalBounds().width;
       }
       //inputbox.setSize(1000, stringheight + 40 > 100 ? stringheight  + 40 : 100);
//        inputbox.setSize(1000, stringheight  > 100 ? stringheight : 100);
        //cout << "STRINGHEIHGT: " << getTextinputBoundsY() << endl;
        cursor.update(stringlength-150, stringheight);

    }

}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    inputbox.draw(window, states);
    for (LinkedList<sf::Text>:: iterator iter = linkedList.Begin(); iter != linkedList.End(); iter++) {
        sf::Text text = *iter;
        window.draw(text, states);
    }
    textLabel.draw(window, states);
}


sf::FloatRect TextInput::getobjectGlobalBounds() const {
    return this->inputbox.getInputBoxGlobalBounds();
}

float TextInput::getTextinputBoundsX() const {
    return stringlength - TEXTINPUTX;
}

float TextInput::getTextinputBoundsY() const{
    return stringheight;
}

void TextInput::parseStringToSfText(string input) {
    linkedList.ClearList();

    cout << "Input: " << input << endl;
    if (input.empty()) {
        return;
    }
    size_t found;
    sf::Text parseString;
    string noMatchString = "";
    string MatchString = "";


    while (true) {
        found = containsHightKey(input, MatchString);
        if (found == string::npos) {
            break;
        }
        if (found != 0) {
            noMatchString = input.substr(0, found);
            parseString.setString(noMatchString);
            parseString.setFillColor(sf::Color::White);
          linkedList.Insert_End(parseString);
        }
        parseString.setString(MatchString);
        parseString.setFillColor(COLOR_MAPPER[MatchString]);
        linkedList.Insert_End(parseString);


        input = input.substr(found + MatchString.length());
        noMatchString = "";
        MatchString = "";
    }

    parseString.setString(input);
    parseString.setFillColor(sf::Color::White);
    linkedList.Insert_End(parseString);

}

size_t TextInput::containsHightKey(string str, string &matchedString) {
    size_t minFound = SIZE_MAX;
    size_t found;
    for (string s : HIGHLIGHT) {
        found = str.find(s);
        if (found != string::npos && minFound > found) {
            matchedString = s;
            minFound = found;
        }
    }
    if (minFound != SIZE_MAX) {
        return minFound;
    } else {
        return string::npos;
    }
}

Snapshot &TextInput::getSnapshot() {
    return selfSnapshot;
}

void TextInput::applySnapshot(const Snapshot &snapshot) {
    cout << "TextInput: " << snapshot.getData() << endl;
    selfSnapshot = Snapshot(snapshot);
    text_input = snapshot.getData();
    parseStringToSfText(text_input);

    snapshotCounter--;

}

void TextInput::addSnapshotToHistory(string snapshotString) {
    // add a snapshot
    string componentId = History::addComponent(this);
    Snapshot snapshot(componentId);
    snapshot.setData(snapshotString);
    History::pushHistory(snapshot);
    snapshotCounter++;

}

string TextInput::getTextInputString() {
    return textInput.getString();
}

void TextInput::setReadFileString(string logotext) {
    text_input = logotext;
    textInput.setString(text_input);

    parseStringToSfText(text_input);
}

void TextInput::setTextInputPosition(sf::Vector2f position) {
    inputbox.setPosition(position.x,position.y);
    textLabel.setPosition(sf::Vector2f(inputbox.getInputBoxposition().x,inputbox.getInputBoxposition().y-50));
    textInput.setPosition(sf::Vector2f(inputbox.getInputBoxposition().x+20,inputbox.getPosition().y+10));
}



