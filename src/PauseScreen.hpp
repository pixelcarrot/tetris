#ifndef PAUSESCREEN_HPP
#define PAUSESCREEN_HPP

#include "MenuScreen.hpp"

class PauseScreen : public MenuScreen
{
public:
	PauseScreen() : MenuScreen()
	{
		SetKeyNext(sf::Key::Down);
		SetKeyPrev(sf::Key::Up);

		SetNormalColor(sf::Color::Black);
		SetChooseColor(sf::Color::Cyan);
		
		sf::String* continue_ptr = new sf::String("Continue");
		sf::String* quit_ptr = new sf::String("Quit");
		sf::String* title = new sf::String("PAUSE");

		sf::Font* font = GlobalFontManager.Get(TRON);
		if(font)
		{
			continue_ptr->SetFont(*font);
			quit_ptr->SetFont(*font);
			title->SetFont(*font);
		}

		AlignCenter(*continue_ptr);
		AlignCenter(*quit_ptr);
		AlignCenter(*title);

		float posX = GAME_WIDTH/2.f;

		continue_ptr->SetPosition(posX, 200);
		quit_ptr->SetPosition(posX, 270);

		title->SetPosition(posX, 100);
		title->SetColor(sf::Color::Black);

		PushItem(continue_ptr, Choose::Previous);
		PushItem(quit_ptr, Choose::Quit);

		PushTitle(title);

		sf::Image* image = GlobalImageManager.Get(IMAGE_WALL);
		if(image)
		{
			sf::Sprite* wall = new sf::Sprite(*image);
			PushSprite(wall);
		}
	}
};

#endif