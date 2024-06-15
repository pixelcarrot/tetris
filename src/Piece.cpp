#include "Piece.hpp"

Piece::Piece()
{
	InitializeSprite();
	isStop = true;
}

void Piece::SetType(int16 Type)
{
	type = Type;
	sprite.SetSubRect(GlobalImageRect.Pieces[type][0]);
}

void Piece::LoadMatrix(int16 Matrix[][COL_MATRIX])
{
	matrix = Matrix;
}

void Piece::Draw(sf::RenderWindow& App)
{
	App.Draw(sprite);
}

void Piece::PosAct()
{
	isStop = false;
	idAngle = 0;
	x = COL_ACT_PIECE;
	y = ROW_ACT_PIECE;
	sprite.SetX(X_ACT_PIECE);
	sprite.SetY(Y_ACT_PIECE);
}

void Piece::PosWait()
{
	sprite.SetX(X_WAIT_PIECE);
	sprite.SetY(Y_WAIT_PIECE);
}

void Piece::MoveLeft()
{
	if(IsCollisionLeft() == false)
	{
		x = x - 1;
		sprite.Move(-SIZE_BRICK,0);
	}
}

void Piece::MoveRight()
{
	if(ISCollisionRight() == false)
	{
		x = x + 1;
		sprite.Move(SIZE_BRICK,0);
	}
}

void Piece::RotateLeft()
{
	if(IsCollisionRotateLeft() == false)
	{
		idAngle = idAngle + 1;
		if(idAngle > 3)
			idAngle = 0;
		sprite.SetSubRect(GlobalImageRect.Pieces[type][idAngle]);
	}
}

void Piece::RotateRight()
{
	if(IsCollisionRotateRight() == false)
	{
		idAngle = idAngle - 1;
		if(idAngle < 0)
			idAngle = 3;
		sprite.SetSubRect(GlobalImageRect.Pieces[type][idAngle]);
	}
}

void Piece::SoftDrop()
{
	if(IsCollisionDown() == false)
	{
		y = y - 1;
		sprite.Move(0, SIZE_BRICK);
	}
	else
		isStop = true;
}

void Piece::HardDrop()
{
	while(IsCollisionDown() == false)
	{
		y = y - 1;
	}
	isStop = true;
}

void Piece::DelayDrop(float Delay)
{
	if(clock.GetElapsedTime() > Delay)
	{
		SoftDrop();
		clock.Reset();
	}
}

bool Piece::IsStop()
{
	return isStop;
}

int16 Piece::GetX()
{
	return x;
}

int16 Piece::GetY()
{
	return y;
}

int16 Piece::GetIdAngle()
{
	return idAngle;
}

int16 Piece::GetType()
{
	return type;
}

bool Piece::IsCollision(int16 X, int16 Y, int16 IdAngle)
{
	int16 row, col;
	for(int16 i = 0; i < 4; ++i)
	{
		row = y + Y + GlobalCheck[type][IdAngle][i].y;
		col = x + X + GlobalCheck[type][IdAngle][i].x;
		if(matrix[row][col])
			return true;
	}
	return false;
}

bool Piece::IsCollisionLeft()
{
	return IsCollision(-1, 0, idAngle);
}

bool Piece::ISCollisionRight()
{
	return IsCollision(1, 0, idAngle);
}

bool Piece::IsCollisionDown()
{
	return IsCollision(0, -1, idAngle);
}

bool Piece::IsCollisionRotateLeft()
{
	if(idAngle + 1 > 3)
		return IsCollision(0, 0, 0);
	return IsCollision(0, 0, idAngle + 1);
}

bool Piece::IsCollisionRotateRight()
{
	if(idAngle - 1 < 0)
		return IsCollision(0, 0, 3);
	return IsCollision(0, 0, idAngle - 1);
}

void Piece::InitializeSprite()
{
	sf::Image* image = GlobalImageManager.Get(IMAGE_PIECE);
	if(image != NULL)
	{
		(*image).CreateMaskFromColor(sf::Color::Black);
		sprite.SetImage(*image);
		sprite.SetCenter(SIZE_BRICK, SIZE_BRICK * 2);
	}
}