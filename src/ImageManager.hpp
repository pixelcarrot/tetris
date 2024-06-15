#ifndef IMAGEMANAGER_HPP
#define IMAGEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"

class ImageManager : public ResourceManager<sf::Image>
{
protected:
	virtual sf::Image* Load(const std::string& strId);
};

extern ImageManager GlobalImageManager;

#endif