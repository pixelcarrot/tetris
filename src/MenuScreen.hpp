#ifndef MENUSCREEN_HPP
#define MENUSCREEN_HPP

#include <vector>

#include "Screen.hpp"

class MenuScreen : public Screen
{
private:
	sf::Sound menuChoose, menuEnter;

private:
	std::vector<Choose>::iterator v_iter;
	std::vector<Choose> v;

	std::vector<sf::String*>::iterator item_iter;
	std::vector<sf::String*> item;

	std::vector<sf::Sprite*> sprite;

	std::vector<sf::String*> title;

	sf::Color chooseColor, normalColor;
	sf::Key::Code nextKey, prevKey;

public:
	MenuScreen();
	~MenuScreen();
	virtual Choose Run(sf::RenderWindow& App);

protected:
	void SetKeyNext(const sf::Key::Code& Key);
	void SetKeyPrev(const sf::Key::Code& Key);
	void SetChooseColor(const sf::Color& Color);
	void SetNormalColor(const sf::Color& Color);
	void PushTitle(sf::String* Title);
	void PushItem(sf::String* Text, const Choose& Value);
	void PushSprite(sf::Sprite* Sprite);

private:
	void InitializeSound();
	void Next();
	void Previous();
	void Refresh();
};

#endif