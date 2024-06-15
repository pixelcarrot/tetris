#ifndef MAINSCREEN_HPP
#define MAINSCREEN_HPP

#include "StringUtility.hpp"
#include "ImageManager.hpp"
#include "FontManager.hpp"
#include "MenuScreen.hpp"
#include "Constant.hpp"

class MainScreen : public MenuScreen
{
public:
	MainScreen() : MenuScreen()
	{
		SetKeyNext(sf::Key::Down);
		SetKeyPrev(sf::Key::Up);

		SetNormalColor(sf::Color::Black);
		SetChooseColor(sf::Color::Cyan);

		sf::String* play = new sf::String("New Game");
		sf::String* control = new sf::String("Control");
		sf::String* highscores = new sf::String("High Scores");
		sf::String* exit = new sf::String("Exit");

		sf::Font* font = GlobalFontManager.Get(TRON);
		if(font)
		{
			play->SetFont(*font);
			control->SetFont(*font);
			highscores->SetFont(*font);
			exit->SetFont(*font);
		}

		AlignCenter(*play);
		AlignCenter(*control);
		AlignCenter(*highscores);
		AlignCenter(*exit);

		float posX = GAME_WIDTH/2.f;

		play->SetPosition(posX, 290);
		control->SetPosition(posX, 360);
		highscores->SetPosition(posX, 430);
		exit->SetPosition(posX, 500);

		PushItem(play, Choose::NewGame);
		PushItem(control, Choose::Control);
		PushItem(highscores, Choose::HighScores);
		PushItem(exit, Choose::Exit);

		sf::Image* image;

		image = GlobalImageManager.Get(IMAGE_WALL);
		if(image)
		{
			sf::Sprite* wall = new sf::Sprite(*image);
			PushSprite(wall);
		}

		image = GlobalImageManager.Get(IMAGE_TETRIS);
		if(image)
		{
			image->CreateMaskFromColor(sf::Color::Black);
			sf::Sprite* tetris = new sf::Sprite(*image);
			tetris->SetCenter(tetris->GetSubRect().GetWidth()/2.f, 0);
			tetris->SetPosition(posX, 100);
			PushSprite(tetris);
		}

		sf::String* author = new sf::String("Programmed by Nguyen");
		author->SetSize(16);
		author->SetColor(sf::Color::Black);
		author->SetPosition(GAME_WIDTH - 2, GAME_HEIGHT - 22);
		AlignRight(*author);

		PushTitle(author);
	}
};

#endif