#ifndef FONTMANAGER_HPP
#define FONTMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

class FontManager
{
public:
    sf::Font* Get(const std::string& strId);
    // Other existing methods...

private:
    std::unordered_map<std::string, sf::Font*> fonts;
};

extern FontManager GlobalFontManager;

#endif
