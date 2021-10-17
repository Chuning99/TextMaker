//
// Created by 刘储宁 on 5/22/21.
//

#ifndef PROJECT1SFMLTYPE_FONTS_H
#define PROJECT1SFMLTYPE_FONTS_H
#include <SFML/Graphics.hpp>

class Fonts {
public:
    enum fonts{OPENSANSBOLD, ARIAL, ARCADE, AGENT,SUPREME,LASTFONT};
    static sf::Font& getFont(fonts font);

private:
    static std::vector<sf::Font> _fonts;
    static std::vector<bool> loaded;
    static std::string mapFont(fonts font);
    static void loadFont(fonts font);
};


#endif //PROJECT1SFMLTYPE_FONTS_H
