#include "Board.hpp"
#include <algorithm>
#include <cstring>
#include <cstdint>

bool IsGreater(int16_t i, int16_t j)
{
    return i > j;
}

Board::Board()
{
    InitializeSprite();
}

void Board::Reset()
{
    isPushed = false;
    memset(matrix, 0, sizeof(int16_t) * ROW_MATRIX * COL_MATRIX);
    memset(&matrix[0], -1, sizeof(int16_t) * COL_MATRIX);
    for(int16_t i = 1, j = ROW_MATRIX - 1; i <= j; ++i, --j)
    {
        matrix[i][0] = matrix[i][COL_MATRIX - 1] = -1;
        matrix[j][0] = matrix[j][COL_MATRIX - 1] = -1;
    }
}

void Board::Draw(sf::RenderWindow& App)
{
    for(int16_t i = 0; i < ROW_GRAPH; ++i)
    {
        for(int16_t j = 0; j < COL_GRAPH; ++j)
            if(matrix[i + 1][j + 1])
            {
                App.draw(sprite[i][j]);
            }
    }
}

void Board::Push(Piece& actPiece)
{
    isPushed = true;
    piece = &actPiece;
    piece->PosAct();
    piece->LoadMatrix(matrix);
}

void Board::Fill()
{
    if(isPushed == false)
        return;

    v.clear();

    isPushed = false;
    int16_t x = piece->GetX();
    int16_t y = piece->GetY();
    int16_t type = piece->GetType();
    int16_t idAngle = piece->GetIdAngle();

    int16_t row, col;

    for(int16_t i = 0; i < 4; ++i)
    {
        row = GlobalCheck[type][idAngle][i].y + y;
        col = GlobalCheck[type][idAngle][i].x + x;
        matrix[row][col] = type + 1;
        SetLineDelete(row);
    }

    DeleteLine();
    Refresh();
}

void Board::SetLineDelete(int16_t Row)
{
    if(std::binary_search(v.begin(), v.end(), Row, IsGreater) == false && IsFullLine(Row) == true)
    {
        std::vector<int16_t>::iterator it = v.begin(); 
        while(it != v.end() && *it > Row)
            ++it;
        v.insert(it, Row);
    }
}

void Board::Refresh()
{
    for(int16_t i = 0; i < ROW_GRAPH; ++i)
        for(int16_t j = 0; j < COL_GRAPH; ++j)
            if(matrix[i + 1][j + 1])
                sprite[i][j].setTextureRect(GlobalImageRect.Bricks[matrix[i+1][j+1] - 1]);
}

void Board::DeleteLine(int16_t Row)
{
    while(Row <= ROW_GRAPH)
    {
        memmove(&matrix[Row][1], &matrix[Row + 1][1], sizeof(int16_t) * COL_GRAPH);
        Row++;
    }
}

void Board::DeleteLine()
{
    if(v.empty())
        return;

    std::vector<int16_t>::iterator it;
    for(it = v.begin(); it != v.end(); ++it)
        DeleteLine(*it);
}

bool Board::IsFullLine(int16_t Row)
{
    for(int16_t i = 1, j = COL_GRAPH; i < j; ++i, --j)
        if(matrix[Row][i] == 0 || matrix[Row][j] == 0)
            return false;
    return true;
}

bool Board::IsFull()
{
    for(int16_t i = 1, j = COL_GRAPH; i < j; ++i, --j)
        if(matrix[ROW_MATRIX - 1][i] || matrix[ROW_MATRIX - 1][j] )
            return true;
    return false;
}

int16_t Board::GetLineDelete()
{
    return v.size();
}

void Board::InitializeSprite()
{
    sf::Texture* texture = GlobalImageManager.Get(IMAGE_PIECE);  // Use sf::Texture
    if(texture != nullptr)
    {
        for(int16_t i = 0; i < ROW_GRAPH; ++i)
        {
            for(int16_t j = 0; j < COL_GRAPH; ++j)
            {
                sprite[i][j].setTexture(*texture);
                sprite[i][j].setPosition(j * SIZE_BRICK + X_ORGIN, (ROW_GRAPH - 1 - i) * SIZE_BRICK + Y_ORGIN);
            }
        }
    }
}
