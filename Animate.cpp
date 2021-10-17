//
// Created by chuning liu on 4/2/21.
//

#include "Animate.h"

Animate::Animate() {

    windows.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Text input");
    windows.setFramerateLimit(60);
    checkmousein = true;
    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);

    //Display box
    DisplayBox.setPosition(sf::Vector2f(DISPLAYBOXPOSITIONX,DISPLAYBOXPOSITIONY));
    DisplayBox.setSize(sf::Vector2f(DISPLAYBOXSIZEWIDTH,DISPLAYBOXSIZEHEIGHT));
    DisplayBox.setFillColor(sf::Color::Black);


    cout<<"Game CTOR. preparing to load the font."<<endl;
    //text set
    TextColor = sf::Color::White;
    ShadowColor = sf::Color::Red;
    background = sf::Color::Black;
    normalText.setFont(Fonts::getFont(Fonts::ARIAL));
    normalText.setCharacterSize(FONTSIZE);
    normalText.setOutlineThickness(5);
    //normalText.setPosition(sf::Vector2f(500,500));
    normalText.setPosition(sf::Vector2f(normalText.getGlobalBounds().width,NORMALTEXTPOSITION_Y));
    normalText.setFillColor(TextColor);


    shadowText.setFont(Fonts::getFont(Fonts::ARIAL));
    shadowText.setCharacterSize(FONTSIZE);
    shadowText.setPosition(sf::Vector2f(normalText.getGlobalBounds().width,NORMALTEXTPOSITION_Y+normalText.getGlobalBounds().height*0.3));
    shadowText.scale(1.f,(normalText.getPosition().y+normalText.getCharacterSize()-shadowText.getPosition().y)/normalText.getCharacterSize());
    shadowText.setFillColor(ShadowColor);

    dropdownMenu.setItemListPosition(sf::Vector2f(1300,950));
    //smallcolorbox.setColor(sf::Color::White);
    smallcolorbox.setPosition(sf::Vector2f(1100,950));
    palette.setPosition(sf::Vector2f(1100,950));
    backgroundColorPicker.setPosition(sf::Vector2f(1750,950));
    backgroundColorText.setFont(Fonts::getFont(Fonts::ARIAL));
    backgroundColorText.setString("BackgroundColor");
    backgroundColorText.setPosition(sf::Vector2f(1900,950));
    backgroundColorText.setCharacterSize(40);



}

void Animate::update() {

    colorPicker.update();
    backgroundColorPicker.update();
    TextColor = colorPicker.getColor();
    ShadowColor = colorPicker.getColor();
    background = backgroundColorPicker.getColor();
    fileTree.update();
    textinput.update(cursor);
    normalText.setString(textinput.getTextInputString());
    shadowText.setString(normalText.getString());
    normalText.setRotation(slider.getTextRotation());
    shadowText.setRotation(slider.getShadowRotation());
    //normalText.setOrigin(sf::Vector2f(SCREEN_WIDTH/2,SCREEN_HEIGHT/2));
    normalText.setPosition(sf::Vector2f(slider.getTextXValue(),slider.getTextYValue()));


    shadowText.setPosition(sf::Vector2f(slider.getShadowXValue(),
                                        slider.getShadowYValue()+normalText.getGlobalBounds().height*((slider.getSkewValue()+50)/100.0+1)));
    shadowText.setOrigin(sf::Vector2f(shadowText.getOrigin().x,shadowText.getGlobalBounds().height/1.5));
    TextColor.a = slider.getTextOpacity();
    normalText.setFillColor(TextColor);
    ShadowColor.a = slider.getShadowOpacity();
    shadowText.setFillColor(ShadowColor);
    normalText.setCharacterSize(slider.getFontSizeValue());
    shadowText.setCharacterSize(slider.getFontShadowSizeValue());

    //menuBar.setPixelColor(background);
    //background = menuBar.getPixelColor();
    background.a = slider.getBackGroundOpacityRedValue();
    DisplayBox.setFillColor(background);
    //DisplayBox.setFillColor(sf::Color(slider.getBackGroundOpacityRedValue(),slider.getBackGroundOpacityGreenValue(),slider.getBackGroundOpacityBlueValue()));
    shadowText.setScale(1.f,(-(slider.getSkewValue()/100.0)));


    menuBar.update();
    dropdownMenu.update();
    if (mousein >= 1) {

        dropdownMenu.getItemList().getItem(mousein)->hoverOnView();

    }

    cursor.update(textinput.getTextinputBoundsX(), textinput.getTextinputBoundsY());

}

void Animate::run() {
    while (windows.isOpen()) {
        sf::Event event;

        ProcessEnevts(windows, event);

        windows.clear();
        update();
        Draw();
        windows.display();
    }
}

void Animate::Draw() {

    windows.draw(DisplayBox);
    windows.draw(textinput);
    windows.draw(normalText);
    windows.draw(shadowText);
    windows.draw(slider);

    if (!cursor.getDisableState() && !cursor.getHiddenState()) {
        windows.draw(cursor);
    }


    if (checkmousein){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(windows).x-5,
                               sf::Mouse::getPosition(windows).y-5);

        //mouse location text for sidebar:



        //draw mouse
        windows.draw(mousePoint);
    }
//}
    //windows.draw(fileNode);
    //windows.draw(fileTree);
    windows.draw(menuBar);
    //windows.draw(colorPicker);
    windows.draw(dropdownMenu);
    //windows.draw(smallcolorbox);
    //windows.draw(palette);
    windows.draw(colorPicker);
    windows.draw(backgroundColorPicker);
    windows.draw(backgroundColorText);


}

void Animate::ProcessEnevts(sf::RenderWindow &window, sf::Event event) {

    while (window.pollEvent((event))) {
        menuBar.addEventHandler(window,event);
        if(!menuBar.getString().empty()){
            cout<<"readfile string"<<menuBar.getString()<<endl;
            textinput.setReadFileString(menuBar.getString());
            menuBar.setString("");

           //textinput.setReadFileString(menuBar.getString());
        }
        menuBar.settoFileString(textinput.getTextInputString());

        fileTree.addEventHandler(window,event);
        sliderBar.addEventHandler(window,event);
        slider.addEventHandler(window,event);

        colorPicker.addEventHandler(window,event);
        backgroundColorPicker.addEventHandler(window,event);
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::TextEntered && !cursor.getDisableState()) {
            //cout << "KeyPressed : " << endl;

            textinput.inputTextEventHandler(window, event);
        } else if (event.type == sf::Event::KeyPressed) {

            if (event.key.code == sf::Keyboard::LControl || event.key.code == sf::Keyboard::RControl) {
               // cout << "control  is press" << endl;
                command = true;
                cursor.setDisableState(true);
            } else if (event.key.code == sf::Keyboard::Z && command) {

                if (History::emptyHistory()) {
                    cout << "No History" << endl;
//                    Snapshot dummySnapshot;
//                    lastComponent->applySnapshot(dummySnapshot);
                    continue;
                }
                Snapshot lastSnapshot = History::topHistory();
                cout << "Data just popped id: " << lastSnapshot.getComponetId() << " " << lastSnapshot.getData()
                     << endl;
                History::popHistory();

                History::Response response = History::getComponent(lastSnapshot.getComponetId());

                if (response.found) {
                    lastComponent = response.component;
                    lastComponent->applySnapshot(lastSnapshot);
                }

//                if (History::getHistorySize() == 1) {
//                    History::popHistory();
//                }

                command = false;
            }
//            if(event.key.code == sf::Keyboard::Return) {
//
//                textinput.inputTextEventHandler(window,event);
//
//            }
//
        } else if (event.type == sf::Event::MouseButtonPressed) {

            //cout<<"Menu add event handerler"<<endl;
            if (event.mouseButton.button == sf::Mouse::Left) {

                //cout << "Mouse clicked" << event.mouseButton.x << ", " << event.mouseButton.y << endl;
                bool inInputBox = MouseEvents<TextInput>::mouseClicked(textinput, window, event);
                int found = -1;
                for (int i = 0; i < dropdownMenu.getobjectGlobalBounds().size(); i++) {
                    Item item = *(dropdownMenu.getItemList().getItem(i));
                    bool inDropDownMenu = MouseEvents<Item>::mouseClicked(item, window, event);
                    if (inDropDownMenu) {
                        found = i;
                        break;
                    }
                }

                if (inInputBox) {
                    //cout << "Mouse clicked in inputbox" << endl;
                    cursor.setDisableState(false);

                    if (cursor.getDisableState()) {
                        cout << "don't show cursor" << endl;
                    } else {
                        cout << "show cursor" << endl;
                    }
                }
                else if (found != -1) {
                   // cout << "found is" << found << endl;
                    if (found >= 1 && !dropdownMenu.getHiddenState()) {
                        if(dropdownMenu.getSnapshotCounter() == 0){
                            dropdownMenu.addSnapshotToHistory(dropdownMenu.getItemList().getItem(0)->getItem());
                        }
                        dropdownMenu.replaceTheFirstItem(found);

                        if(found == 2){
                            normalText.setFont(Fonts::getFont(Fonts::AGENT));
                            shadowText.setFont(Fonts::getFont(Fonts::AGENT));
                        }
                        else if(found == 3){
                            normalText.setFont(Fonts::getFont(Fonts::ARCADE));
                            shadowText.setFont(Fonts::getFont(Fonts::ARCADE));
                        }
                        else if(found ==4){
                            normalText.setFont(Fonts::getFont(Fonts::OPENSANSBOLD));
                            shadowText.setFont(Fonts::getFont(Fonts::OPENSANSBOLD));
                        }
                        else if(found == 5){
                            normalText.setFont(Fonts::getFont(Fonts::SUPREME));
                            shadowText.setFont(Fonts::getFont(Fonts::SUPREME));
                        }
                        else {
                            normalText.setFont(Fonts::getFont(Fonts::ARIAL));
                            shadowText.setFont(Fonts::getFont(Fonts::ARIAL));
                        }



                        dropdownMenu.addSnapshotToHistory(dropdownMenu.getItemList().getItem(found)->getItem());
                    }
                    if ((found == 0 && dropdownMenu.getHiddenState()) || (!dropdownMenu.getHiddenState())) {
                        dropdownMenu.setHidden(!dropdownMenu.getHiddenState());
                        //dropdownMenu.setHidden(true);
                        dropdownMenu.refreshItemsStates();

                    }


                } else {
                    //cout << "Mouse clicked is NOT in inputbox" << endl;
                    cursor.setDisableState(true);
                }
            } else if (event.type == sf::Event::MouseEntered) {

            }

        } else if (event.type == sf::Event::MouseLeft) {
            checkmousein = false;
            mousein = -1;
        } else if (event.type == sf::Event::MouseMoved) {
            checkmousein = true;
//                mousein = -1;
//                cout<<"("<<sf::Mouse::getPosition().x<<","<<sf::Mouse::getPosition().y<<")";
////                mousein = true;
            for (int i = 0; i < dropdownMenu.getobjectGlobalBounds().size(); i++) {
                Item item = *(dropdownMenu.getItemList().getItem(i));
                bool inDropDownMenu = MouseEvents<Item>::mouseHoverOn(item, window);
                if (inDropDownMenu) {
                    mousein = i;
                    break;
                }


            }
            if (mousein >= 1) {
//                    cout<<"mouse is moving"<<endl;
//                    cout<<"Found in mouse moving "<<mousein<<endl;
                dropdownMenu.getItemList().getItem(mousein)->hoverOnView();

            }

        }

    }
}


