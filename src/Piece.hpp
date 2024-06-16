#ifndef PIECE_HPP
#define PIECE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>  // Include this for sf::Clock
#include <cstdint>
#include "ImageManager.hpp"
#include "ImageRect.hpp"
#include "Constant.hpp"
#include "Setting.hpp"

class Piece
{
private:
    sf::Clock clock;
    sf::Sprite sprite;
    int16_t (*matrix)[COL_MATRIX];
    int16_t idAngle, x, y, type;
    bool isStop;

public:
    Piece();
    void SetType(int16_t Type);
    void LoadMatrix(int16_t Matrix[][COL_MATRIX]);
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
    int16_t GetX();
    int16_t GetY();
    int16_t GetType();
    int16_t GetIdAngle();

private:
    void InitializeSprite();
    bool IsCollision(int16_t X, int16_t Y, int16_t IdAngle);
    bool IsCollisionLeft();
    bool IsCollisionRight();
    bool IsCollisionDown();
    bool IsCollisionRotateLeft();
    bool IsCollisionRotateRight();
};

#endif
