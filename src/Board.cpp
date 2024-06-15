#include "Board.hpp"

bool IsGreater(int16 i, int16 j)
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
	memset(matrix, 0, sizeof(int16) * ROW_MATRIX * COL_MATRIX);
	memset(&matrix[0], -1, sizeof(int16) * COL_MATRIX);
	for(int16 i = 1, j = ROW_MATRIX - 1; i <= j; ++i, --j)
	{
		matrix[i][0] = matrix[i][COL_MATRIX - 1] = -1;
		matrix[j][0] = matrix[j][COL_MATRIX - 1] = -1;
	}
}

void Board::Draw(sf::RenderWindow& App)
{
	for(int16 i = 0; i < ROW_GRAPH; ++i)
	{
		for(int16 j = 0; j < COL_GRAPH; ++j)
			if(matrix[i + 1][j + 1])
			{
				App.Draw(sprite[i][j]);
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
	int16 x = piece->GetX();
	int16 y = piece->GetY();
	int16 type = piece->GetType();
	int16 idAngle = piece->GetIdAngle();

	int16 row, col;

	for(int16 i = 0; i < 4; ++i)
	{
		row = GlobalCheck[type][idAngle][i].y + y;
		col = GlobalCheck[type][idAngle][i].x + x;
		matrix[row][col] = type + 1;
		SetLineDelete(row);
	}

	DeleteLine();
	Refresh();
}

void Board::SetLineDelete(int16 Row)
{
	if(binary_search(v.begin(), v.end(), Row, IsGreater) == false && IsFullLine(Row) == true)
	{
		std::vector<int16>::iterator it = v.begin(); 
		while(it != v.end() && *it > Row)
			++it;
		v.insert(it, Row);
	}
}

void Board::Refresh()
{
	for(int16 i = 0; i < ROW_GRAPH; ++i)
		for(int16 j = 0; j < COL_GRAPH; ++j)
			if(matrix[i + 1][j + 1])
				sprite[i][j].SetSubRect(GlobalImageRect.Bricks[matrix[i+1][j+1] - 1]);
}

void Board::DeleteLine(int16 Row)
{
	while(Row <= ROW_GRAPH)
	{
		memmove(&matrix[Row][1], &matrix[Row + 1][1], sizeof(int16) * COL_GRAPH);
		Row++;
	}
}

void Board::DeleteLine()
{
	if(v.empty())
		return;

	std::vector<int16>::iterator it;
	for(it = v.begin(); it != v.end(); ++it)
		DeleteLine(*it);
}

bool Board::IsFullLine(int16 Row)
{
	for(int16 i = 1, j = COL_GRAPH; i < j; ++i, --j)
		if(matrix[Row][i] == 0 || matrix[Row][j] == 0)
			return false;
	return true;
}

bool Board::IsFull()
{
	for(int16 i = 1, j = COL_GRAPH; i < j; ++i, --j)
		if(matrix[ROW_MATRIX - 1][i] || matrix[ROW_MATRIX - 1][j] )
			return true;
	return false;
}

int16 Board::GetLineDelete()
{
	return v.size();
}

void Board::InitializeSprite()
{
	sf::Image* image = GlobalImageManager.Get(IMAGE_PIECE);
	if(image != NULL)
	{
		(*image).CreateMaskFromColor(sf::Color::Black);
		for(int16 i = 0; i < ROW_GRAPH; ++i)
		{
			for(int16 j = 0; j < COL_GRAPH; ++j)
			{
				sprite[i][j].SetImage(*image);
				sprite[i][j].SetPosition(j * SIZE_BRICK + X_ORGIN, (ROW_GRAPH-1-i) * SIZE_BRICK + Y_ORGIN);
			}
		}
	}
}