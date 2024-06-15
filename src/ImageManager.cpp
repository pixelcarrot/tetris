#include "ImageManager.hpp"

ImageManager GlobalImageManager;

sf::Image* ImageManager::Load(const std::string& strId)
{
	sf::Image* image = new sf::Image;
	if(!image->LoadFromFile(strId))
	{
		delete image;
		image = NULL;
	}
	if(image != NULL)
		image->SetSmooth(false);
	return image;
}