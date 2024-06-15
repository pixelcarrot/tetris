#ifndef SOUNDBUFFERMANAGER_HPP
#define SOUNDBUFFERMANAGER_HPP

#include <SFML/Audio.hpp>
#include "ResourceManager.hpp"

class SoundBufferManager : public ResourceManager<sf::SoundBuffer>
{
protected:
    virtual sf::SoundBuffer* Load(const std::string& strId) override;
};

extern SoundBufferManager GlobalSoundBufferManager;

#endif
