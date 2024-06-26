#ifndef STRINGUTILITY_HPP
#define STRINGUTILITY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

#include "Setting.hpp"

//////////////////////////////////////////////////////////////////////////
// TEMPLATE MUST BE IN HEADER
//////////////////////////////////////////////////////////////////////////

template <class T>
std::string Int2Str(T Number)
{
    std::stringstream ss;
    ss << Number;
    return ss.str();
}

template <class T>
T Str2Int(const std::string& Text)
{
    std::stringstream ss(Text);
    T Number;
    return ss >> Number ? Number : 0;
}

//////////////////////////////////////////////////////////////////////////
// DECLARE PROTOTYPE
//////////////////////////////////////////////////////////////////////////

void AlignLeft(sf::Text& Text);   // Use sf::Text instead of sf::String
void AlignRight(sf::Text& Text);  // Use sf::Text instead of sf::String
void AlignCenter(sf::Text& Text); // Use sf::Text instead of sf::String

#endif
