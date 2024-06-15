#ifndef IMAGEMANAGER_HPP
#define IMAGEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

class ImageManager
{
public:
    sf::Texture* Get(const std::string& strId);
    // Other existing methods...

private:
    std::unordered_map<std::string, sf::Texture*> textures;
};

extern ImageManager GlobalImageManager;

#endif
