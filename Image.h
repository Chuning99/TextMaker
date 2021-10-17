//
// Created by 刘储宁 on 5/13/21.
//

#ifndef PROJECT1SFMLTYPE_IMAGE_H
#define PROJECT1SFMLTYPE_IMAGE_H
#include <map>
#include <SFML/Graphics.hpp>
#include <string>

class Image {
public:
    enum image{FOLDER, FILE};
    static std::map<image, sf::Texture> images;
    static std::map<image,bool> loaded;
public:

    static sf::Texture& getImage(image image){
        if(!loaded[image]){

            loadImage(image);
        }

        return images[image];
    }
    static void loadImage(image image){

//        if(!loaded[image]){
//
//        }sf::IntRect(10,10,32,32)
//        if(!loaded[image]){
//            if(!images[image].loadFromFile("images/"+getImagePath(image)))
//                  exit(128);
//                loaded[image]=true;
//
//
//        }
        if(!loaded[image]){
            if(!images[image].loadFromFile("../images/"+getImagePath(image)))
               loaded[image] = true;
        }
    }
    static std::string getImagePath(image image){
        switch (image) {
            case FOLDER: return "folder.png";
            case FILE: return "file.png";
        }
    }
};


#endif //PROJECT1SFMLTYPE_IMAGE_H
