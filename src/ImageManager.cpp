#include "ImageManager.hpp"

ImageManager GlobalImageManager;

sf::Texture *ImageManager::Get(const std::string &strId)
{
    auto it = textures.find(strId);
    if (it != textures.end())
    {
        return it->second;
    }

    sf::Image image;
    if (!image.loadFromFile(strId))
    {
        return nullptr;
    }

    // Apply a color mask (e.g., make green color transparent)
    image.createMaskFromColor(sf::Color::Green);

    sf::Texture *texture = new sf::Texture;
    if (!texture->loadFromImage(image))
    {
        delete texture;
        return nullptr;
    }

    textures[strId] = texture;
    return texture;
}
