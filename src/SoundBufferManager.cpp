#include "SoundBufferManager.hpp"

SoundBufferManager GlobalSoundBufferManager;

sf::SoundBuffer* SoundBufferManager::Load(const std::string& strId)
{
	sf::SoundBuffer* soundBuffer = new sf::SoundBuffer;
	if(!soundBuffer->LoadFromFile(strId))
	{
		delete soundBuffer;
		soundBuffer = NULL;
	}
	return soundBuffer;
}