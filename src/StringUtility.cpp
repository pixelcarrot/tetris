#include "StringUtility.hpp"

void AlignLeft(sf::Text& Text)
{
    sf::FloatRect textRect = Text.getLocalBounds();  // Get the local bounds of the text
    Text.setOrigin(0, textRect.top);  // Align left by setting the origin to the top-left corner
}

void AlignRight(sf::Text& Text)
{
    sf::FloatRect textRect = Text.getLocalBounds();  // Get the local bounds of the text
    Text.setOrigin(textRect.width, textRect.top);  // Align right by setting the origin to the top-right corner
}

void AlignCenter(sf::Text& Text)
{
    sf::FloatRect textRect = Text.getLocalBounds();  // Get the local bounds of the text
    Text.setOrigin(textRect.width / 2.f, textRect.top);  // Align center by setting the origin to the top-center
}
