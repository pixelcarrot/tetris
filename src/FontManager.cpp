#include "FontManager.hpp"

FontManager GlobalFontManager;

sf::Font* FontManager::Load(const std::string& strId)
{
	sf::Font* font = new sf::Font;
	if(!font->LoadFromFile(strId))
	{
		delete font;
		font = NULL;
	}
	return font;
}