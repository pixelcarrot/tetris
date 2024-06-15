#ifndef IMAGERECT_HPP
#define IMAGERECT_HPP

#include <SFML/Graphics.hpp>
#include "Constant.hpp"
#include "Setting.hpp"

class ImageRect
{
public:
	ImageRect();
	sf::IntRect Effect;
	sf::IntRect Bricks[7];
	sf::IntRect Pieces[7][4];
private:
	void InitializePieces();
	void InitializeBricks();
	void InitializeEffect();
};

extern ImageRect GlobalImageRect;

#endif