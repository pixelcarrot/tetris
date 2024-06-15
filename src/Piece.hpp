#ifndef PIECE_HPP
#define PIECE_HPP

#include <SFML/Graphics.hpp>

#include "ImageManager.hpp"
#include "ImageRect.hpp"
#include "Constant.hpp"
#include "Setting.hpp"

class Piece
{
private:
	sf::Clock clock;
	sf::Sprite sprite;
	int16 (*matrix)[COL_MATRIX];
	int16 idAngle, x, y, type;
	bool isStop;
	
public:
	Piece();
	void SetType(int16 Type);
	void LoadMatrix(int16 Matrix[][COL_MATRIX]);
	void Draw(sf::RenderWindow& App);
	void PosAct();
	void PosWait();
	void MoveLeft();
	void MoveRight();
	void RotateLeft();
	void RotateRight();
	void SoftDrop();
	void HardDrop();
	void DelayDrop(float Delay);
	bool IsStop();
	int16 GetX();
	int16 GetY();
	int16 GetType();
	int16 GetIdAngle();

private:
	void InitializeSprite();
	bool IsCollision(int16 X, int16 Y, int16 IdAngle);
	bool IsCollisionLeft();
	bool ISCollisionRight();
	bool IsCollisionDown();
	bool IsCollisionRotateLeft();
	bool IsCollisionRotateRight();
};

#endif