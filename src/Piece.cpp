#include "Piece.hpp"

Piece::Piece()
{
    InitializeSprite();
    isStop = true;
}

void Piece::SetType(int16_t Type)
{
    type = Type;
    sprite.setTextureRect(GlobalImageRect.Pieces[type][0]);
}

void Piece::LoadMatrix(int16_t Matrix[][COL_MATRIX])
{
    matrix = Matrix;
}

void Piece::Draw(sf::RenderWindow& App)
{
    App.draw(sprite);
}

void Piece::PosAct()
{
    isStop = false;
    idAngle = 0;
    x = COL_ACT_PIECE;
    y = ROW_ACT_PIECE;
    sprite.setPosition(X_ACT_PIECE, Y_ACT_PIECE);
}

void Piece::PosWait()
{
    sprite.setPosition(X_WAIT_PIECE, Y_WAIT_PIECE);
}

void Piece::MoveLeft()
{
    if (!IsCollisionLeft())
    {
        x = x - 1;
        sprite.move(-SIZE_BRICK, 0);
    }
}

void Piece::MoveRight()
{
    if (!IsCollisionRight())
    {
        x = x + 1;
        sprite.move(SIZE_BRICK, 0);
    }
}

void Piece::RotateLeft()
{
    if (!IsCollisionRotateLeft())
    {
        idAngle = idAngle + 1;
        if (idAngle > 3)
            idAngle = 0;
        sprite.setTextureRect(GlobalImageRect.Pieces[type][idAngle]);
    }
}

void Piece::RotateRight()
{
    if (!IsCollisionRotateRight())
    {
        idAngle = idAngle - 1;
        if (idAngle < 0)
            idAngle = 3;
        sprite.setTextureRect(GlobalImageRect.Pieces[type][idAngle]);
    }
}

void Piece::SoftDrop()
{
    if (!IsCollisionDown())
    {
        y = y - 1;
        sprite.move(0, SIZE_BRICK);
    }
    else
    {
        isStop = true;
    }
}

void Piece::HardDrop()
{
    while (!IsCollisionDown())
    {
        y = y - 1;
    }
    isStop = true;
}

void Piece::DelayDrop(float Delay)
{
    if (clock.getElapsedTime().asSeconds() > Delay)
    {
        SoftDrop();
        clock.restart();
    }
}

bool Piece::IsStop()
{
    return isStop;
}

int16_t Piece::GetX()
{
    return x;
}

int16_t Piece::GetY()
{
    return y;
}

int16_t Piece::GetIdAngle()
{
    return idAngle;
}

int16_t Piece::GetType()
{
    return type;
}

bool Piece::IsCollision(int16_t X, int16_t Y, int16_t IdAngle)
{
    int16_t row, col;
    for (int16_t i = 0; i < 4; ++i)
    {
        row = y + Y + GlobalCheck[type][IdAngle][i].y;
        col = x + X + GlobalCheck[type][IdAngle][i].x;
        if (matrix[row][col])
            return true;
    }
    return false;
}

bool Piece::IsCollisionLeft()
{
    return IsCollision(-1, 0, idAngle);
}

bool Piece::IsCollisionRight()
{
    return IsCollision(1, 0, idAngle);
}

bool Piece::IsCollisionDown()
{
    return IsCollision(0, -1, idAngle);
}

bool Piece::IsCollisionRotateLeft()
{
    if (idAngle + 1 > 3)
        return IsCollision(0, 0, 0);
    return IsCollision(0, 0, idAngle + 1);
}

bool Piece::IsCollisionRotateRight()
{
    if (idAngle - 1 < 0)
        return IsCollision(0, 0, 3);
    return IsCollision(0, 0, idAngle - 1);
}

void Piece::InitializeSprite()
{
    sf::Texture* texture = GlobalImageManager.Get(IMAGE_PIECE);
    if (texture != nullptr)
    {
        sprite.setTexture(*texture);
        sprite.setOrigin(SIZE_BRICK, SIZE_BRICK * 2);
    }
}
