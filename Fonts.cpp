//
// Created by 刘储宁 on 5/22/21.
//

#include "Fonts.h"
#include <iostream>
 std::vector<sf::Font>Fonts:: _fonts(LASTFONT,sf::Font());
 std::vector<bool> Fonts::loaded(LASTFONT,false);
sf::Font &Fonts::getFont(Fonts::fonts font) {
    loadFont(font);
    return _fonts[font];
}

std::string Fonts::mapFont(Fonts::fonts font) {
    switch(font){
        std::cout<<"check load font";
        case OPENSANSBOLD: return "../ttfFile/OpenSans-Bold.ttf";
        case ARIAL: return "../ttfFile/arial.ttf";
        case ARCADE: return "../ttfFile/Arcade.ttf";
        case AGENT: return "../ttfFile/Agent.ttf";
        case SUPREME:return "../ttfFile/futur.ttf";

    }
}

void Fonts::loadFont(Fonts::fonts font) {

    if (!loaded[font]) {
        _fonts[font].loadFromFile(mapFont(font));
        loaded[font] = true;
    }
}
