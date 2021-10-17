//
// Created by chuning liu on 4/2/21.
//

#ifndef PROJECT1SFMLTYPE_ANIMATE_H
#define PROJECT1SFMLTYPE_ANIMATE_H

#include "Constant.h"
#include "TextInput.h"
#include "Cursor.h"
#include "MouseEvents.h"
#include "History.h"
#include "KeyboardShortcuts.h"
#include <SFML/Graphics.hpp>
#include "Item.h"
#include "ItemList.h"
#include "DropdownMenu.h"
#include "MenuBar.h"
#include "FileTree.h"
#include "Image.h"
#include "Fonts.h"
#include "ShadowText.h"
#include "Slider.h"
#include "SliderBar.h"
#include "HSVPicker.h"
#include "Color.h"
#include "Palette.h"
#include "ColorPicker.h"
class Animate {
public:
    Animate(); //default constructor
    void update(); //update
    void run(); //run my function in main
    void Draw(); //draw my function
    void ProcessEnevts(sf::RenderWindow &window, sf::Event event);  //process event

private:
    sf::RenderWindow windows;
    //sf::RenderTarget& window;
    GUIComponent *lastComponent;
    TextInput textinput;
    sf::RectangleShape DisplayBox;

    Cursor cursor;
    Inputbox inputbox;
    int mousein = -1;
    bool checkmousein;
    bool command = false;
    DropdownMenu dropdownMenu;
    sf::CircleShape mousePoint;
    MenuBar menuBar;



    FileTree fileTree;


    //test font class
    sf::Text normalText;
    sf::Text shadowText;
    sf::Text backgroundColorText;

    SliderBar sliderBar;
   Slider slider;
   sf::Color TextColor;
   sf::Color ShadowColor;
   Color smallcolorbox;
   sf::Color background;
   Palette palette;
   ColorPicker colorPicker;
   ColorPicker backgroundColorPicker;



};
string mouse_pos_string(sf::RenderWindow& window);

#endif //PROJECT1SFMLTYPE_ANIMATE_H
