#include "Constant.hpp"

using namespace std;

sf::Vector2i GlobalCheck[7][4][4];

class Constant
{
public:
	Constant()
	{
		// GlobalCheckCoord[Type][Rotate][Cell]

		//////////////////////////////////////////////////////////////////////////
		//	TYPE O
		//////////////////////////////////////////////////////////////////////////

		// Rotate 0
		GlobalCheck[0][0][0].x = 0;
		GlobalCheck[0][0][1].x = 0;
		GlobalCheck[0][0][2].x = -1;
		GlobalCheck[0][0][3].x = -1;

		GlobalCheck[0][0][0].y = 0;
		GlobalCheck[0][0][1].y = -1;
		GlobalCheck[0][0][2].y = -1;
		GlobalCheck[0][0][3].y = 0;

		// Rotate 1
		GlobalCheck[0][1][0].x = 0;
		GlobalCheck[0][1][1].x = 0;
		GlobalCheck[0][1][2].x = -1;
		GlobalCheck[0][1][3].x = -1;

		GlobalCheck[0][1][0].y = 0;
		GlobalCheck[0][1][1].y = -1;
		GlobalCheck[0][1][2].y = -1;
		GlobalCheck[0][1][3].y = 0;

		// Rotate 2
		GlobalCheck[0][2][0].x = 0;
		GlobalCheck[0][2][1].x = 0;
		GlobalCheck[0][2][2].x = -1;
		GlobalCheck[0][2][3].x = -1;

		GlobalCheck[0][2][0].y = 0;
		GlobalCheck[0][2][1].y = -1;
		GlobalCheck[0][2][2].y = -1;
		GlobalCheck[0][2][3].y = 0;

		// Rotate 3
		GlobalCheck[0][3][0].x = 0;
		GlobalCheck[0][3][1].x = 0;
		GlobalCheck[0][3][2].x = -1;
		GlobalCheck[0][3][3].x = -1;

		GlobalCheck[0][3][0].y = 0;
		GlobalCheck[0][3][1].y = -1;
		GlobalCheck[0][3][2].y = -1;
		GlobalCheck[0][3][3].y = 0;

		//////////////////////////////////////////////////////////////////////////
		// TYPE I
		//////////////////////////////////////////////////////////////////////////

		// Rotate 0
		GlobalCheck[1][0][0].x = 0;
		GlobalCheck[1][0][1].x = -1;
		GlobalCheck[1][0][2].x = 2;
		GlobalCheck[1][0][3].x = 1;

		GlobalCheck[1][0][0].y = 0;
		GlobalCheck[1][0][1].y = 0;
		GlobalCheck[1][0][2].y = 0;
		GlobalCheck[1][0][3].y = 0;

		// Rotate 1
		GlobalCheck[1][1][0].x = 0;
		GlobalCheck[1][1][1].x = 0;
		GlobalCheck[1][1][2].x = 0;
		GlobalCheck[1][1][3].x = 0;

		GlobalCheck[1][1][0].y = 0;
		GlobalCheck[1][1][1].y = -2;
		GlobalCheck[1][1][2].y = -1;
		GlobalCheck[1][1][3].y = 1;

		// Rotate 2
		GlobalCheck[1][2][0].x = 0;
		GlobalCheck[1][2][1].x = -1;
		GlobalCheck[1][2][2].x = 2;
		GlobalCheck[1][2][3].x = 1;

		GlobalCheck[1][2][0].y = 0;
		GlobalCheck[1][2][1].y = 0;
		GlobalCheck[1][2][2].y = 0;
		GlobalCheck[1][2][3].y = 0;

		// Rotate 3
		GlobalCheck[1][3][0].x = 0;
		GlobalCheck[1][3][1].x = 0;
		GlobalCheck[1][3][2].x = 0;
		GlobalCheck[1][3][3].x = 0;

		GlobalCheck[1][3][0].y = 0;
		GlobalCheck[1][3][1].y = -2;
		GlobalCheck[1][3][2].y = -1;
		GlobalCheck[1][3][3].y = 1;

		//////////////////////////////////////////////////////////////////////////
		// TYPE S
		//////////////////////////////////////////////////////////////////////////

		// Rotate 0
		GlobalCheck[2][0][0].x = 0;
		GlobalCheck[2][0][1].x = -1;
		GlobalCheck[2][0][2].x = 0;
		GlobalCheck[2][0][3].x = 1;

		GlobalCheck[2][0][0].y = 0;
		GlobalCheck[2][0][1].y = -1;
		GlobalCheck[2][0][2].y = -1;
		GlobalCheck[2][0][3].y = 0;

		// Rotate 1
		GlobalCheck[2][1][0].x = 0;
		GlobalCheck[2][1][1].x = 1;
		GlobalCheck[2][1][2].x = 1;
		GlobalCheck[2][1][3].x = 0;

		GlobalCheck[2][1][0].y = 0;
		GlobalCheck[2][1][1].y = -1;
		GlobalCheck[2][1][2].y = 0;
		GlobalCheck[2][1][3].y = 1;

		// Rotate 2
		GlobalCheck[2][2][0].x = 0;
		GlobalCheck[2][2][1].x = -1;
		GlobalCheck[2][2][2].x = 0;
		GlobalCheck[2][2][3].x = 1;

		GlobalCheck[2][2][0].y = 0;
		GlobalCheck[2][2][1].y = -1;
		GlobalCheck[2][2][2].y = -1;
		GlobalCheck[2][2][3].y = 0;

		// Rotate 3
		GlobalCheck[2][3][0].x = 0;
		GlobalCheck[2][3][1].x = 1;
		GlobalCheck[2][3][2].x = 1;
		GlobalCheck[2][3][3].x = 0;

		GlobalCheck[2][3][0].y = 0;
		GlobalCheck[2][3][1].y = -1;
		GlobalCheck[2][3][2].y = 0;
		GlobalCheck[2][3][3].y = 1;

		//////////////////////////////////////////////////////////////////////////
		// TYPE Z
		//////////////////////////////////////////////////////////////////////////

		// Rotate 0
		GlobalCheck[3][0][0].x = 0;
		GlobalCheck[3][0][1].x = 0;
		GlobalCheck[3][0][2].x = -1;
		GlobalCheck[3][0][3].x = 1;

		GlobalCheck[3][0][0].y = 0;
		GlobalCheck[3][0][1].y = -1;
		GlobalCheck[3][0][2].y = 0;
		GlobalCheck[3][0][3].y = -1;

		// Rotate 1
		GlobalCheck[3][1][0].x = 0;
		GlobalCheck[3][1][1].x = 0;
		GlobalCheck[3][1][2].x = 1;
		GlobalCheck[3][1][3].x = 1;

		GlobalCheck[3][1][0].y = 0;
		GlobalCheck[3][1][1].y = -1;
		GlobalCheck[3][1][2].y = 0;
		GlobalCheck[3][1][3].y = 1;

		// Rotate 2
		GlobalCheck[3][2][0].x = 0;
		GlobalCheck[3][2][1].x = 0;
		GlobalCheck[3][2][2].x = -1;
		GlobalCheck[3][2][3].x = 1;

		GlobalCheck[3][2][0].y = 0;
		GlobalCheck[3][2][1].y = -1;
		GlobalCheck[3][2][2].y = 0;
		GlobalCheck[3][2][3].y = -1;

		// Rotate 3
		GlobalCheck[3][3][0].x = 0;
		GlobalCheck[3][3][1].x = 0;
		GlobalCheck[3][3][2].x = 1;
		GlobalCheck[3][3][3].x = 1;

		GlobalCheck[3][3][0].y = 0;
		GlobalCheck[3][3][1].y = -1;
		GlobalCheck[3][3][2].y = 0;
		GlobalCheck[3][3][3].y = 1;

		//////////////////////////////////////////////////////////////////////////
		// TYPE L
		//////////////////////////////////////////////////////////////////////////


		// Rotate 0
		GlobalCheck[4][0][0].x = 0;
		GlobalCheck[4][0][1].x = -1;
		GlobalCheck[4][0][2].x = 1;
		GlobalCheck[4][0][3].x = -1;

		GlobalCheck[4][0][0].y = 0;
		GlobalCheck[4][0][1].y = -1;
		GlobalCheck[4][0][2].y = 0;
		GlobalCheck[4][0][3].y = 0;

		// Rotate 1
		GlobalCheck[4][1][0].x = 0;
		GlobalCheck[4][1][1].x = 0;
		GlobalCheck[4][1][2].x = 1;
		GlobalCheck[4][1][3].x = 0;

		GlobalCheck[4][1][0].y = 0;
		GlobalCheck[4][1][1].y = -1;
		GlobalCheck[4][1][2].y = -1;
		GlobalCheck[4][1][3].y = 1;

		// Rotate 2
		GlobalCheck[4][2][0].x = 0;
		GlobalCheck[4][2][1].x = -1;
		GlobalCheck[4][2][2].x = 1;
		GlobalCheck[4][2][3].x = 1;

		GlobalCheck[4][2][0].y = 0;
		GlobalCheck[4][2][1].y = 0;
		GlobalCheck[4][2][2].y = 0;
		GlobalCheck[4][2][3].y = 1;

		// Rotate 3
		GlobalCheck[4][3][0].x = 0;
		GlobalCheck[4][3][1].x = 0;
		GlobalCheck[4][3][2].x = -1;
		GlobalCheck[4][3][3].x = 0;

		GlobalCheck[4][3][0].y = 0;
		GlobalCheck[4][3][1].y = -2;
		GlobalCheck[4][3][2].y = 0;
		GlobalCheck[4][3][3].y = -1;

		//////////////////////////////////////////////////////////////////////////
		// TYPE J
		//////////////////////////////////////////////////////////////////////////


		// Rotate 0
		GlobalCheck[5][0][0].x = 0;
		GlobalCheck[5][0][1].x = 1;
		GlobalCheck[5][0][2].x = -1;
		GlobalCheck[5][0][3].x = 1;

		GlobalCheck[5][0][0].y = 0;
		GlobalCheck[5][0][1].y = -1;
		GlobalCheck[5][0][2].y = 0;
		GlobalCheck[5][0][3].y = 0;

		// Rotate 1
		GlobalCheck[5][1][0].x = 0;
		GlobalCheck[5][1][1].x = 0;
		GlobalCheck[5][1][2].x = 1;
		GlobalCheck[5][1][3].x = 0;

		GlobalCheck[5][1][0].y = 0;
		GlobalCheck[5][1][1].y = -2;
		GlobalCheck[5][1][2].y = 0;
		GlobalCheck[5][1][3].y = -1;

		// Rotate 2
		GlobalCheck[5][2][0].x = 0;
		GlobalCheck[5][2][1].x = -1;
		GlobalCheck[5][2][2].x = 1;
		GlobalCheck[5][2][3].x = -1;

		GlobalCheck[5][2][0].y = 0;
		GlobalCheck[5][2][1].y = 0;
		GlobalCheck[5][2][2].y = 0;
		GlobalCheck[5][2][3].y = 1;

		// Rotate 3
		GlobalCheck[5][3][0].x = 0;
		GlobalCheck[5][3][1].x = -1;
		GlobalCheck[5][3][2].x = 0;
		GlobalCheck[5][3][3].x = 0;

		GlobalCheck[5][3][0].y = 0;
		GlobalCheck[5][3][1].y = -1;
		GlobalCheck[5][3][2].y = -1;
		GlobalCheck[5][3][3].y = 1;

		//////////////////////////////////////////////////////////////////////////
		// Type T
		//////////////////////////////////////////////////////////////////////////


		// Rotate 0
		GlobalCheck[6][0][0].x = 0;
		GlobalCheck[6][0][1].x = 0;
		GlobalCheck[6][0][2].x = -1;
		GlobalCheck[6][0][3].x = 1;

		GlobalCheck[6][0][0].y = 0;
		GlobalCheck[6][0][1].y = -1;
		GlobalCheck[6][0][2].y = 0;
		GlobalCheck[6][0][3].y = 0;

		// Rotate 1
		GlobalCheck[6][1][0].x = 0;
		GlobalCheck[6][1][1].x = 0;
		GlobalCheck[6][1][2].x = 1;
		GlobalCheck[6][1][3].x = 0;

		GlobalCheck[6][1][0].y = 0;
		GlobalCheck[6][1][1].y = -1;
		GlobalCheck[6][1][2].y = 0;
		GlobalCheck[6][1][3].y = 1;

		// Rotate 2
		GlobalCheck[6][2][0].x = 0;
		GlobalCheck[6][2][1].x = -1;
		GlobalCheck[6][2][2].x = 1;
		GlobalCheck[6][2][3].x = 0;

		GlobalCheck[6][2][0].y = 0;
		GlobalCheck[6][2][1].y = 0;
		GlobalCheck[6][2][2].y = 0;
		GlobalCheck[6][2][3].y = 1;

		// Rotate 3
		GlobalCheck[6][3][0].x = 0;
		GlobalCheck[6][3][1].x = 0;
		GlobalCheck[6][3][2].x = -1;
		GlobalCheck[6][3][3].x = 0;

		GlobalCheck[6][3][0].y = 0;
		GlobalCheck[6][3][1].y = -1;
		GlobalCheck[6][3][2].y = 0;
		GlobalCheck[6][3][3].y = 1;
	}
};

Constant slientInit;