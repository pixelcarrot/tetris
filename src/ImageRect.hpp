#ifndef IMAGERECT_HPP
#define IMAGERECT_HPP

#include <SFML/Graphics.hpp>
#include "Constant.hpp"  // Ensure Constant.hpp is included to use SIZE_BRICK
#include <array>

// Comment out this line if SIZE_BRICK is already defined in Constant.hpp
// const int SIZE_BRICK = 32;

class ImageRect
{
public:
    ImageRect();

    std::array<std::array<sf::IntRect, 4>, 7> Pieces;
    std::array<sf::IntRect, 7> Bricks;
    sf::IntRect Effect;

private:
    void InitializePieces();
    void InitializeBricks();
    void InitializeEffect();
};

extern ImageRect GlobalImageRect;

#endif
