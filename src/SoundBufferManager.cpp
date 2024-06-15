#include "SoundBufferManager.hpp"

SoundBufferManager GlobalSoundBufferManager;

sf::SoundBuffer* SoundBufferManager::Load(const std::string& strId)
{
    sf::SoundBuffer* soundBuffer = new sf::SoundBuffer;
    if (!soundBuffer->loadFromFile(strId))  // Use loadFromFile instead of LoadFromFile
    {
        delete soundBuffer;
        soundBuffer = nullptr;  // Use nullptr instead of NULL
    }
    return soundBuffer;
}
