//
// Created by 刘储宁 on 5/10/21.
//

#ifndef PROJECT1SFMLTYPE_FILEITEM_H
#define PROJECT1SFMLTYPE_FILEITEM_H

#include "Item.h"
#include "Image.h"


class FileItem : public Item{
public:
    //Constructors
    FileItem();
    FileItem(Image::image icon, std::string text, sf::Vector2f size, sf::Vector2f position);

    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    //Returns the bounds of the item
    sf::FloatRect getGlobalBounds() const;
    //returns the size of the item
    sf::Vector2f getSize() const;
    //returns the size of the item
    sf::Vector2f getPosition() const;
    //sets the position of the item
    void setPosition(sf::Vector2f pos);
    void setIcon(Image::image icon);
    void setString(string text);
    void setSize(sf::Vector2f size);
    string getString();



    void hoverOnView();
    void outLineView();
    void defaultView();
    void switchHidden();
    sf::FloatRect getobjectGlobalBounds() const;
    //void setSize(sf::Vector2f position);
    bool getHiddenState() const{
        return state.getStates()[HIDDEN];
    }

    //set hidden
    void setHidden(bool hidden) {
        state.setHidden(hidden);
    }
    //uses an enum to change the icon to a folder or file
    // void setIcon(Image::image icon);

private:
    //this is the folder or file icon
    sf::Sprite icon;
    float padding = 5;
     sf::Text text;
     sf::Font font;
     Inputbox inputbox;
     States state;



};


#endif //PROJECT1SFMLTYPE_FILEITEM_H
