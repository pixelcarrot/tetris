#include <vector>

#include "ExitScreen.hpp"
#include "MainScreen.hpp"
#include "GameScreen.hpp"
#include "ControlScreen.hpp"
#include "ScoreScreen.hpp"

int main()
{
	sf::RenderWindow app(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT, 32), "TETRIS", sf::Style::Close);
	app.SetFramerateLimit(60);

	sf::Image icon;
	if(icon.LoadFromFile(ICON))
		app.SetIcon(icon.GetWidth(), icon.GetHeight(), icon.GetPixelsPtr());

	std::vector<Screen*> screen;

	ExitScreen exitScreen;
	MainScreen mainScreen;
	GameScreen gameScreen;
	ControlScreen controlscreen;
	ScoreScreen scoreScreen;

	exitScreen.SetID(0);
	mainScreen.SetID(0);
	gameScreen.SetID(0);
	controlscreen.SetID(0);
	scoreScreen.SetID(0);

	screen.push_back(&exitScreen);
	screen.push_back(&mainScreen);
	screen.push_back(&gameScreen);
	screen.push_back(&controlscreen);
	screen.push_back(&scoreScreen);

	Choose current = Choose::Main;
	Choose next, prev;

	while(true)
	{
		next = screen[current]->Run(app);

		if(next == Choose::Closed)
			return 0;

		if(next != Choose::Previous)
		{
			prev = current;
			current = next;
		}
		else
			current = prev;
	}

	return 0;
}