#ifndef FONTMANAGER_HPP
#define FONTMANAGER_HPP

#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"

class FontManager : public ResourceManager<sf::Font>
{
protected:
	virtual sf::Font* Load(const std::string& strId);
};

extern FontManager GlobalFontManager;

#endif