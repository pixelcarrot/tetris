#ifndef CONTROLSCREEN_HPP
#define CONTROLSCREEN_HPP

#include "Screen.hpp"

class ControlScreen : public Screen
{
private:
	sf::Sprite wall;
	sf::String left[7], right[7], title;
public:
	ControlScreen() : Screen()
	{
		sf::Image* image = GlobalImageManager.Get(IMAGE_WALL);
		if(image)
			wall.SetImage(*image);

		title.SetText("CONTROL KEYS");

		left[0].SetText("Left arrow");
		left[1].SetText("Right arrow");
		left[2].SetText("Down arrow");
		left[3].SetText("Z");
		left[4].SetText("X");
		left[5].SetText("Space");
		left[6].SetText("ESC");

		right[0].SetText("- Move left");
		right[1].SetText("- Move right");
		right[2].SetText("- Soft drop");
		right[3].SetText("- Rotate left");
		right[4].SetText("- Rotate right");
		right[5].SetText("- Hard drop");
		right[6].SetText("- Escape / Pause");

		float posX = GAME_WIDTH/2.f;
		float posY;

		sf::Font* font = GlobalFontManager.Get(TRON);
		if(font)
			title.SetFont(*font);

		AlignCenter(title);
		title.SetPosition(posX, 100);
		title.SetColor(sf::Color::Black);

		for(int16 i = 0; i < 7; ++i)
		{
			posY = i * 50 + 200;
			AlignRight(left[i]);
			AlignLeft(right[i]);
			left[i].SetPosition(posX - 15, posY);
			right[i].SetPosition(posX, posY);
			left[i].SetColor(sf::Color::Black);
			right[i].SetColor(sf::Color::Black);
		}
	}

	virtual Choose Run(sf::RenderWindow& App)
	{
		sf::Event e;
		while(true)
		{
			while(App.GetEvent(e))
			{
				if(e.Type == sf::Event::Closed)
					return Choose::Closed;

				if(e.Type == sf::Event::KeyPressed && e.Key.Code == sf::Key::Escape)
					return Choose::Previous;
			}

			App.Clear();

			App.Draw(wall);

			App.Draw(title);

			for(int16 i = 0; i < 7; ++i)
			{
				App.Draw(left[i]);
				App.Draw(right[i]);
			}

			App.Display();
		}
	}
};

#endif