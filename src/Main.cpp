#include <vector>

#include "ExitScreen.hpp"
#include "MainScreen.hpp"
#include "GameScreen.hpp"
#include "ControlScreen.hpp"
#include "ScoreScreen.hpp"

int main()
{
	sf::RenderWindow app(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "TETRIS", sf::Style::Close); // Removed the 32-bit depth parameter
	app.setFramerateLimit(60);																  // Use setFramerateLimit instead of SetFramerateLimit

	sf::Image icon;
	if (icon.loadFromFile(ICON))											  // Use loadFromFile instead of LoadFromFile
		app.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr()); // Use getSize instead of GetWidth and GetHeight

	std::vector<Screen *> screen;

	ExitScreen exitScreen;
	MainScreen mainScreen;
	GameScreen gameScreen;
	ControlScreen controlScreen;
	ScoreScreen scoreScreen;

	exitScreen.SetID(0);
	mainScreen.SetID(0);
	gameScreen.SetID(0);
	controlScreen.SetID(0);
	scoreScreen.SetID(0);

	screen.push_back(&exitScreen);
	screen.push_back(&mainScreen);
	screen.push_back(&gameScreen);
	screen.push_back(&controlScreen);
	screen.push_back(&scoreScreen);

	Choose current = Choose::Main;
	Choose next, prev;

	while (true)
	{
		next = screen[current]->Run(app);

		if (next == Choose::Closed)
			return 0;

		if (next != Choose::Previous)
		{
			prev = current;
			current = next;
		}
		else
			current = prev;
	}

	return 0;
}
