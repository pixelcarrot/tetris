#include "ImageRect.hpp"

ImageRect GlobalImageRect;

ImageRect::ImageRect()
{
	InitializePieces();
	InitializeBricks();
	InitializeEffect();
}

void ImageRect::InitializePieces()
{
	for(int16 i = 0; i < 7; ++i)
	{
		for(int16 j = 0; j < 4; ++j)
		{
			Pieces[i][j].Left = i * 4 * SIZE_BRICK;
			Pieces[i][j].Top = j * 4 * SIZE_BRICK;
			Pieces[i][j].Right = (i+1) * 4 * SIZE_BRICK;
			Pieces[i][j].Bottom = (j+1) * 4 * SIZE_BRICK;
		}
	}
}

void ImageRect::InitializeBricks()
{
	for(int16 i = 0; i < 7; ++i)
	{
		Bricks[i].Left = i * SIZE_BRICK;
		Bricks[i].Top = 17 * SIZE_BRICK;
		Bricks[i].Right = (i+1) * SIZE_BRICK;
		Bricks[i].Bottom = 18 * SIZE_BRICK;
	}
}

void ImageRect::InitializeEffect()
{
	Effect.Left = 8 * SIZE_BRICK;
	Effect.Top = 17 * SIZE_BRICK;
	Effect.Right = 18 * SIZE_BRICK;
	Effect.Bottom = 18 * SIZE_BRICK;
}