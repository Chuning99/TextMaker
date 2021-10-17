#include <iostream>
#include "Animate.h"
#include "Fonts.h"
#include <SFML/Graphics/Color.hpp>
#include <tuple>
#include <algorithm> // min, max
/**
 * name: chuning liu
 * Professor: Dave Smith
 * project: Logo Maker
 * version: 2.0
 * Function:
 * cursor
 * inputbox
 * textinput
 * label
 * text change color
 * undo
 * delete
 */
std::stack<Snapshot> History::stack;
std::map<std::string, GUIComponent*> History::components;
int History::globalComponentID = 1;
std::map<Image::image, sf::Texture> Image::images;
std::map<Image::image,bool> Image::loaded;
int main() {
  Animate animate;
  animate.run();

    return 0;



}
