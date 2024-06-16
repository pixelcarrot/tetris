#include "ImageRect.hpp"
#include <cstdint>

ImageRect GlobalImageRect;

ImageRect::ImageRect()
{
    InitializePieces();
    InitializeBricks();
    InitializeEffect();
}

void ImageRect::InitializePieces()
{
    for (int16_t i = 0; i < 7; ++i)
    {
        for (int16_t j = 0; j < 4; ++j)
        {
            Pieces[i][j].left = i * 4 * SIZE_BRICK;
            Pieces[i][j].top = j * 4 * SIZE_BRICK;
            Pieces[i][j].width = 4 * SIZE_BRICK;  // Calculate width directly
            Pieces[i][j].height = 4 * SIZE_BRICK;  // Calculate height directly
        }
    }
}

void ImageRect::InitializeBricks()
{
    for (int16_t i = 0; i < 7; ++i)
    {
        Bricks[i].left = i * SIZE_BRICK;
        Bricks[i].top = 17 * SIZE_BRICK;
        Bricks[i].width = SIZE_BRICK;  // Calculate width directly
        Bricks[i].height = SIZE_BRICK;  // Calculate height directly
    }
}

void ImageRect::InitializeEffect()
{
    Effect.left = 8 * SIZE_BRICK;
    Effect.top = 17 * SIZE_BRICK;
    Effect.width = 10 * SIZE_BRICK;  // Calculate width directly
    Effect.height = SIZE_BRICK;  // Calculate height directly
}
