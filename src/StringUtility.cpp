#include "StringUtility.hpp"

void AlignLeft(sf::String& Text)
{
	Text.SetCenter(0, 0);
}

void AlignRight(sf::String& Text)
{
	Text.SetCenter(Text.GetRect().GetWidth(), 0);
}

void AlignCenter(sf::String& Text)
{
	Text.SetCenter(Text.GetRect().GetWidth()/2.f, 0);
}