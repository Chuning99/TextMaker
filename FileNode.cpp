//
// Created by 刘储宁 on 5/10/21.
//

#include "FileNode.h"

void FileNode::toggleChlidren() {

}

void FileNode::reposition() const {

}

FileNode::FileNode() {

}

FileNode::FileNode(Image::image icon, std::string text, sf::Vector2f size, sf::Vector2f position) {
     data.setIcon(icon);
     data.setString(text);
     data.setSize(size);
     data.setPosition(position);
//    data = FileItem(icon,text,size,position);
//    data.setPosition(position);
}

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(data,states);
//    for(auto iter = children.begin();iter != children.end();iter++){
//         window.draw(*(iter->second),states);
//    }
}
//doing noting
void FileNode::applySnapshot(const Snapshot &snapshot) {

}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
bool checkmousein  = false;
int found = -1;
//    if (event.type == sf::Event::MouseButtonPressed) {
//        if (event.mouseButton.button == sf::Mouse::Left) {
//            bool inFIleNode = MouseEvents<FileNode>::mouseClicked(*this,window,event);
//            if(inFIleNode){
//                return;
//            }
//        }
//    }
}
//doing nothing
void FileNode::update() {

}
//doing nothing
Snapshot &FileNode::getSnapshot() {
}
//doing noting
sf::FloatRect FileNode::getGlobalBounds() {
    return data.getGlobalBounds();
}

bool FileNode::isLeaf() const {
    return children.empty();
}

FileItem &FileNode::getData() {
   return data;
}
void FileNode::setData(const FileItem &data) {
    this->data = data;
}

std::map<std::string, FileNode *> &FileNode::getChildren() {
    return children;
}

typename FileNode::iterator FileNode::begin() {
   return children.begin();
}

typename FileNode::iterator FileNode::end() {
    return children.end();
}

void FileNode::setPosition(sf::Vector2f pos) {
   data.setPosition(pos);
//   cout<<"data's getGlobalBounds width"<<data.getGlobalBounds().width<<endl;
//    cout<<"data's getGlobalBounds height"<<data.getGlobalBounds().height<<endl;



}

void FileNode::setIcon(Image::image icon) {
   data.setIcon(icon);
}

void FileNode::setString(string text) {
   data.setString(text);
}

void FileNode::setSize(sf::Vector2f size) {
    data.setSize(size);
}

sf::Vector2f FileNode::getSize() const {
    return data.getSize();
}

sf::Vector2f FileNode::getPosition() const{
    return data.getPosition();
}

void FileNode::setChildrenPosition() {
    float childrenPositionY = data.getPosition().y+data.getGlobalBounds().height;
    for(auto iter = children.begin();iter != children.end();iter++){
        (iter->second)->setPosition(sf::Vector2f(data.getPosition().x+50,
                                                 childrenPositionY));
         childrenPositionY += data.getGlobalBounds().height;
    }
}

sf::Vector2f FileNode::getChildrenPosition() {
    sf::Vector2f childrenPosition;
    childrenPosition.y = data.getPosition().y+data.getGlobalBounds().height;
    childrenPosition.x = data.getPosition().x;
    for(auto iter = children.begin();iter != children.end();iter++){
        (iter->second)->setPosition(sf::Vector2f(data.getPosition().x+50,
                                                 childrenPosition.y));
        childrenPosition.y += data.getGlobalBounds().height;
    }
    return childrenPosition;
}

void FileNode::setWholeThing(Image::image icon, string text, sf::Vector2f size, sf::Vector2f position) {
    data.setIcon(icon);
    data.setString(text);
    data.setSize(size);
    data.setPosition(position);
}

void FileNode::switchHiddenStates() {
    states.setHidden(!states.getStates()[HIDDEN]);
    for(auto iter = children.begin(); iter != children.end();iter++){
        iter->second->setHidden(data.getHiddenState());
    }


}

sf::FloatRect FileNode::getobjectGlobalBounds() {
    return data.getGlobalBounds();
}





