//
// Created by 刘储宁 on 5/10/21.
//

#ifndef PROJECT1SFMLTYPE_FILENODE_H
#define PROJECT1SFMLTYPE_FILENODE_H

#include "FileItem.h"
#include "GUIComponent.h"
#include "Inputbox.h"

class FileNode : public GUIComponent, public MouseEvents<FileNode>
{
private:
    //This is the data represented in the tree
    FileItem data;

    //= FileItem(Image::FOLDER,"Directory 3",sf::Vector2f(0.1f,0.1f),sf::Vector2f(250,500));
    //this is all the child nodes in the tree, a vector would also work just fine
    std::map<std::string, FileNode*> children;
    States states;

    //this tells the draw function whether or not to show the node's children
    //this is done by toggling a state on and off
    void toggleChlidren();

    //this is called in the draw function to reposition the children so they
    //are indented and below the parent
    void reposition() const;
    int mouseHoverinx ;
    int mouseHoveriny ;

public:
    // this is so I can use the iterator for the children map publicly
    typedef typename std::map<std::string, FileNode*>::iterator iterator;
    FileNode();
    FileNode(Image::image icon, std::string text, sf::Vector2f size, sf::Vector2f position);
    void setPosition(sf::Vector2f pos);
    void setIcon(Image::image icon);
    void setString(string text);
    void setSize(sf::Vector2f size);
    void setChildrenPosition();
    void setWholeThing(Image::image icon, string text, sf::Vector2f size, sf::Vector2f position);
    void switchHiddenStates();

    //this draws the node. This is a recursive function to draw all the children nodes as well
    // this will only draw the node's children when it is in the proper state
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //This is not currently used
    virtual void applySnapshot(const Snapshot& snapshot);

    //This calls the addEventHandler for all the children. It calls the toggleChildren function
    // when the node's data (FileItem) is clicked on
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //does nothing now
    virtual void update();
    //does nothing now
    virtual Snapshot& getSnapshot();
    //does nothing now
    sf::FloatRect getGlobalBounds();
    sf::FloatRect getobjectGlobalBounds();
    //returns true if the node has no children, otherwise false
    bool isLeaf() const;
    //getters and setters
    FileItem &getData();
    void setData(const FileItem &data);
    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;
    sf::Vector2f getChildrenPosition();
    std::map<std::string, FileNode*>& getChildren();

    //iterators
    iterator begin() ;
    iterator end() ;

    bool getHiddenState() const{
        return states.getStates()[HIDDEN];
    }

    //set hidden
    void setHidden(bool hidden) {
        states.setHidden(hidden);
    }
    bool getDisableStates()const{
        return  states.getStates()[DISABLED];
    }
    void setDisable(bool Disable){
        states.getStates()[DISABLED] = Disable;
    }



};





#endif //PROJECT1SFMLTYPE_FILENODE_H
