#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <SFML/Graphics.hpp>

//////////////////////////////////////////////////////////////////////////
// APP SIZE
//////////////////////////////////////////////////////////////////////////

#define GAME_WIDTH 550
#define GAME_HEIGHT 600

//////////////////////////////////////////////////////////////////////////
// POSITION IN MATRIX
//////////////////////////////////////////////////////////////////////////

#define ROW_MATRIX 22
#define COL_MATRIX 12

#define ROW_GRAPH 20
#define COL_GRAPH 10

#define COL_ACT_PIECE 5
#define ROW_ACT_PIECE 21

//////////////////////////////////////////////////////////////////////////
// COORDINATE IN SCREEN
//////////////////////////////////////////////////////////////////////////

#define SIZE_BRICK 25

#define X_ORGIN 50
#define Y_ORGIN 50

#define X_ACT_PIECE 100 + X_ORGIN
#define Y_ACT_PIECE 0 + Y_ORGIN

#define X_WAIT_PIECE 350 + X_ORGIN
#define Y_WAIT_PIECE 100 + Y_ORGIN

#define X_BOARD 180 + X_ORGIN
#define Y_BOARD 30 + Y_ORGIN

//////////////////////////////////////////////////////////////////////////
// FILE LOCATION
//////////////////////////////////////////////////////////////////////////
// ICON
#define ICON "data\\image\\logo.png"
// IMAGE
#define IMAGE_TETRIS "data\\image\\tetris.png"
#define IMAGE_PIECE "data\\image\\piece.png"
#define IMAGE_TEXTURE "data\\image\\wall.png"
#define IMAGE_WALL "data\\image\\blank_wall.png"
// HIGH SCORES
#define HIGH_SCORES "data\\highscores.ngn"
// FONT
#define TRON "data\\font\\tron.ttf"
#define TRANSFORMERS "data\\font\\transformers.ttf"
// SFX TRACK
#define SFX_TETRIS "data\\sfx\\tracks\\game.ogg"
// SFX SOUND
#define SFX_MENU_CHOOSE "data\\sfx\\sounds\\menu_choose.ogg"
#define SFX_MENU_ENTER "data\\sfx\\sounds\\menu_enter.ogg"
#define SFX_ROTATE "data\\sfx\\sounds\\rotate.ogg"
#define SFX_FILL "data\\sfx\\sounds\\fill.ogg"
#define SFX_DELETE "data\\sfx\\sounds\\delete.ogg"
#define SFX_LEVEL_UP "data\\sfx\\sounds\\level_up.ogg"
#define SFX_GAME_OVER "data\\sfx\\sounds\\game_over.ogg"
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// POSITION CHECK PIECE COLLISION
//////////////////////////////////////////////////////////////////////////

extern sf::Vector2i GlobalCheck[7][4][4];

#endif