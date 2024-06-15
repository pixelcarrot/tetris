#include "ImageManager.hpp"

ImageManager GlobalImageManager;

sf::Texture* ImageManager::Get(const std::string& strId)
{
    auto it = textures.find(strId);
    if (it != textures.end())
    {
        return it->second;
    }
    sf::Texture* texture = new sf::Texture;
    if (!texture->loadFromFile(strId))
    {
        delete texture;
        return nullptr;
    }
    textures[strId] = texture;
    return texture;
}
