//
// Created by 刘储宁 on 5/6/21.
//

#ifndef PROJECT1SFMLTYPE_MENUBAR_H
#define PROJECT1SFMLTYPE_MENUBAR_H
#include "ItemList.h"
#include "GUIComponent.h"
#include "States.h"
#include "Menu.h"
#include "FileTree.h"
#include "Button.h"
#include <fstream>
#include "TextInput.h"
#include <filesystem>
#include <fstream>
#include <iostream>
using namespace std;
const vector<vector<string>> LISTS = {{"File", "Close Project", "New Project","Open Project","Quit","Save Project"},
                                      {"Render", "Export image"}
                                      };
class MenuBar: public GUIComponent{
public:
    MenuBar();

    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    Snapshot &getSnapshot() override;

    void applySnapshot(const Snapshot &snapshot) override;

    vector<vector<sf::FloatRect>> getobjectGlobalBounds() const;

    void setPosition(float x, float y);
    void takeScreenshoot(const sf::RenderWindow& window, const std::string& filename);
    string getString();
    void setString(string s);
    void settoFileString(string filetext);
    string gettoFileStirng();
    string CreatTxtFile(string newfileName);
    void createtxtfile(string filename);

private:

    vector<Menu> menus;
    States state;
    sf::Vector2f menuBarPosition;
    int mouseHoverinx ;
    int mouseHoveriny ;
    sf::Image image;
    FileTree fileTree;
    Button open;
    Button cancel;
    Button save;
    Button notsave;
    string fromFile = "";
    string toFile = "";
    string newfilename = "";
    TextInput filename;
    Cursor cursor;
    vector<string> readFilename;
    sf::Color color = sf::Color::White;

public:
    const vector<Menu> &getMenus() const;

    void setMenus(const vector<Menu> &menus);

    const States &getState() const;

    void setState(const States &state);

    const sf::Vector2f &getMenuBarPosition() const;

    void setMenuBarPosition(const sf::Vector2f &menuBarPosition);
    string readFile(string filename);
    void saveFile(string textinput);
    void setPixelColor(sf::Color pixelcolor);
    sf::Color& getPixelColor();




};


#endif //PROJECT1SFMLTYPE_MENUBAR_H
