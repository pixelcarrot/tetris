#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Constant.hpp"
#include "Setting.hpp"
#include "StringUtility.hpp"
#include "SoundBufferManager.hpp"
#include "ImageManager.hpp"
#include "FontManager.hpp"

enum Choose
{
	Closed = -1, Exit, Main, NewGame, Control, HighScores, Pause, Previous, Quit
};

class Screen
{
protected:
	int16 ID;
public:
	Screen()
	{
		ID = 0;
	}
	void SetID(const int16& ProID)
	{
		ID = ProID;
	}
	virtual Choose Run(sf::RenderWindow& App) = 0;
};

#endif