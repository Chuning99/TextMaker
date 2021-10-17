//
// Created by 刘储宁 on 5/10/21.
//

#include "FileTree.h"

void FileTree::push(FileNode *&root, std::string parent, std::string item,Image::image type) {

        FileNode* parentNode;
        parentNode = search(root,parent);
        if(parentNode == nullptr){

            parentNode= new FileNode(Image::FOLDER,parent,sf::Vector2f(MENUBARINPUTBOX_WIDTH,MENUBERINPUTBOX_HEIGHT),sf::Vector2f(5,50));
            if(root == nullptr){
                root = parentNode;
                root->setHidden(false);
                //root->setDisable(true);

                //parentNode = new FileNode(Image::FOLDER,parent,sf::Vector2f(MENUBARINPUTBOX_WIDTH,MENUBERINPUTBOX_HEIGHT),parentNode->getPosition());
            }
            else{
                 parentNode->setHidden(true);
                root->getChildren()[parent] = parentNode;


            }
        }



            parentNode->getChildren()[item] = new FileNode(type,item,
                                  sf::Vector2f(MENUBARINPUTBOX_WIDTH,MENUBERINPUTBOX_HEIGHT),parentNode->getPosition());
    parentNode->getChildren()[item]->setHidden(true);

             setChildrenPosition(root,0);


}
//use pre order
FileNode* FileTree::traverse(FileNode *&node, sf::RenderWindow &window, sf::Event event) {

      if(node == nullptr){
          return nullptr;
      }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            bool inFIleNode = MouseEvents<FileNode>::mouseClicked(*node,window,event);
            if(inFIleNode){
                return node;
            }

        }
    }

    for(auto iter = node->getChildren().begin(); iter != node->getChildren().end(); iter++){
        FileNode* checkNode = traverse(iter->second, window,event);
       if(checkNode != nullptr){
           filename = checkNode->getData().getString();
           cout<<"check node name"<<checkNode->getData().getString()<<endl;
           return checkNode;
       }

    }

        return nullptr;
}

FileTree::FileTree() {
   defaultView(root);

}

void FileTree::push(std::string parent, std::string item,Image::image type) {
  push(root,parent,item,type);
}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
   //window.draw(*root,states);
   traverseDraw(root,window,states);
//    for(auto iter = root->getChildren().begin();iter != root->getChildren().end();iter++){
//        window.draw(*(iter->second),states);
//    }
}

void FileTree::applySnapshot(const Snapshot &snapshot) {

}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    FileNode *newClickNode = traverse(root, window, event);
    if (newClickNode == nullptr) {
        return;
    }
    if (newClickNode != clickNode) {
        clickNode = newClickNode;


    }

    if (!clickNode->getChildren().empty()) {
        if (clickNode->getChildren().begin()->second->getHiddenState()) {
            for (auto iter = clickNode->getChildren().begin(); iter != clickNode->getChildren().end(); iter++) {
                iter->second->setHidden(!iter->second->getHiddenState());
            }
        } else {
            for (auto iter = clickNode->getChildren().begin(); iter != clickNode->getChildren().end(); iter++) {
                recursiveChangeStates(iter->second);
            }

        }

    }

    this->setChildrenPosition(root, 0);

}

void FileTree::update() {
    defaultView(root);
    if(clickNode != nullptr){

        clickNode->getData().hoverOnView();
    }
    //defaultView(root);
}

Snapshot &FileTree::getSnapshot() {

}

sf::FloatRect FileTree::getGlobalBounds() {

}

FileNode *FileTree::search(FileNode* parent,std::string ParentFilename) {
    if(parent == nullptr){
        return nullptr;
    }
    if(parent->getData().getString() == ParentFilename){
        return parent;
    }
    FileNode* searchResult = nullptr;
    std::map<std::string, FileNode*>::iterator iter;
    for(iter = parent->getChildren().begin();iter != parent->getChildren().end(); iter++){
        searchResult = search(iter->second,ParentFilename);
        if(searchResult){
            return searchResult;
        }

    }
    return nullptr;
}

void FileTree::setFileNodePosition(FileNode *root) {
    if(root == nullptr){
        return;
    }
    std::map<std::string, FileNode*>::iterator iter;
    sf::Vector2f newPosition;
    for(iter = root->getChildren().begin();iter != root->getChildren().end();iter++){

        newPosition.x = root->getPosition().x+70;
        newPosition.y = (iter->second->getPosition().y+iter->second->getGlobalBounds().height);
        iter->second->setPosition(newPosition);
        setFileNodePosition(iter->second);
        //(root->getPosition().x+70,(root->getPosition().y+root->getGlobalBounds().height));
        cout<<"children position :"<<"("<<iter->second->getChildrenPosition().x<<","<<iter->second->getChildrenPosition().y<<")"<<endl;
    }



}

int FileTree::setChildrenPosition(FileNode *&node, int level) {
   if(node==nullptr){
       return level;
   }
   if(node->getChildren().empty()){
       return level;
   }
//   if(node->getHiddenState()){
//       cout<<"Hidden node no position set "<<node->getData().getString()<<endl;
//       return level;
//   }

   for(auto iter = node->getChildren().begin();iter != node->getChildren().end(); iter++){
       if(iter->second->getHiddenState()){
           continue;
       }
       iter->second->setPosition(sf::Vector2f(node->getPosition().x+70, root->getPosition().y+(level+1)*node->getGlobalBounds().height));
       level = setChildrenPosition(iter->second,level+1);
   }

   return level;
}

void FileTree::traverseDraw(FileNode *node, sf::RenderTarget &window, sf::RenderStates states) const {
    if(!node->getHiddenState()){
        window.draw(*node);
    }
   //window.draw(*node);
    std::map<std::string, FileNode*>::iterator iter;
    for(auto iter = node->getChildren().begin(); iter != node->getChildren().end();iter++){
        //window.draw(*(iter->second));
        traverseDraw(iter->second,window,states);
    }


}

void FileTree::defaultView(FileNode* node) {
    if(node == nullptr){
        return;
    }
    node->getData().defaultView();
    for(auto iter = node->getChildren().begin(); iter != node->getChildren().end();iter++){
             defaultView(iter->second);
            //cout<<"default View name"<<iter->second->getData().getString()<<endl;
    }


}

void FileTree::recursiveChangeStates(FileNode *node) {
    if(node == nullptr){
        return;
    }
    node->setHidden(true);
    for(auto iter = node->getChildren().begin(); iter != node->getChildren().end();iter++){
        recursiveChangeStates(iter->second);
    }
}

string FileTree::getfilename() {
    return filename;
}

