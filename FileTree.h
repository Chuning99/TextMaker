//
// Created by 刘储宁 on 5/10/21.
//

#ifndef PROJECT1SFMLTYPE_FILETREE_H
#define PROJECT1SFMLTYPE_FILETREE_H
#include "GUIComponent.h"
#include "FileNode.h"

class FileTree : public GUIComponent
{
private:
    //the root node of the tree
    FileNode* root = nullptr;
    FileNode* clickNode = nullptr;

    //finds the parent and add the item to the parent.
    // If the parent isn't found, a new parent is created
    void push(FileNode*& root, std::string parent, std::string item, Image::image type);

    //traverses the tree ad adds the evenhandlers for each of the nodes
    FileNode* traverse(FileNode* &node, sf::RenderWindow& window, sf::Event event);
    sf::Vector2f initPosition = {0, 0};
    FileNode* search(FileNode* parent,std::string ParentFilename);
    string filename;
public:
    //constructors
    FileTree();


    //this is the public version of push
    void push(std::string parent, std::string item = "NULL", Image::image type = Image::FOLDER);

    //draws the root node of the tree
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void traverseDraw(FileNode* node, sf::RenderTarget& window, sf::RenderStates states) const;

    void setFileNodePosition(FileNode* root);

    //does nothing now
    virtual void applySnapshot(const Snapshot& snapshot);

    //calls the traverse function to add the event handlers to each node
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    //does nothing now
    virtual void update();
    //does nothing now
    virtual Snapshot& getSnapshot();
    //does nothing now
    virtual sf::FloatRect getGlobalBounds();

    int setChildrenPosition(FileNode* &node, int level);
    void defaultView(FileNode* node);
    void recursiveChangeStates(FileNode* node);
    string getfilename();

};


#endif //PROJECT1SFMLTYPE_FILETREE_H
