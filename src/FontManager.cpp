#include "FontManager.hpp"

FontManager GlobalFontManager;

sf::Font* FontManager::Get(const std::string& strId)
{
    auto it = fonts.find(strId);
    if (it != fonts.end())
    {
        return it->second;
    }
    sf::Font* font = new sf::Font;
    if (!font->loadFromFile(strId))
    {
        delete font;
        return nullptr;
    }
    fonts[strId] = font;
    return font;
}
