#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <vector>

#include "ImageManager.hpp"
#include "ImageRect.hpp"
#include "Constant.hpp"
#include "Piece.hpp"

class Board
{
private:
	sf::Sprite sprite[ROW_GRAPH][COL_GRAPH];
	int16 matrix[ROW_MATRIX][COL_MATRIX];
	std::vector<int16> v;
	Piece * piece;
	bool isPushed;

public:
	Board();
	void Draw(sf::RenderWindow& App);
	void Push(Piece& actPiece);
	void Fill();
	void Reset();
	void Refresh();
	bool IsFull();
	int16 GetLineDelete();

private:
	void InitializeSprite();
	void SetLineDelete(int16 Row);
	void DeleteLine();
	void DeleteLine(int16 Row);
	bool IsFullLine(int16 Row);
};

#endif