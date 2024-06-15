#ifndef EXITSCREEN_HPP
#define EXITSCREEN_HPP

#include "MenuScreen.hpp"

class ExitScreen : public MenuScreen
{
public:
	ExitScreen() : MenuScreen()
	{
		SetKeyNext(sf::Key::Left);
		SetKeyPrev(sf::Key::Right);

		SetNormalColor(sf::Color::Black);
		SetChooseColor(sf::Color::Cyan);

		sf::String* yes = new sf::String("YES");
		sf::String* no = new sf::String("NO");
		sf::String* title = new sf::String("EXIT GAME");

		sf::Font* font = GlobalFontManager.Get(TRON);
		if(font)
		{
			yes->SetFont(*font);
			no->SetFont(*font);
			title->SetFont(*font);
		}
		
		AlignRight(*yes);
		AlignLeft(*no);
		AlignCenter(*title);

		float posX = GAME_WIDTH/2.f, posY = GAME_HEIGHT/2.f;

		yes->SetPosition(posX - 20, posY - 100);
		no->SetPosition(posX + 20, posY - 100);

		title->SetPosition(posX, 100);
		title->SetColor(sf::Color::Black);

		PushItem(no, Choose::Previous);
		PushItem(yes, Choose::Closed);

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