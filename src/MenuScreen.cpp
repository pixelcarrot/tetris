#include "MenuScreen.hpp"

MenuScreen::MenuScreen() : Screen() 
{
	InitializeSound();
}

void MenuScreen::InitializeSound()
{
	sf::SoundBuffer* buffer;
	buffer = GlobalSoundBufferManager.Get(SFX_MENU_CHOOSE);
	if(buffer)
		menuChoose.SetBuffer(*buffer);
	buffer = GlobalSoundBufferManager.Get(SFX_MENU_ENTER);
	if(buffer)
		menuEnter.SetBuffer(*buffer);
}

MenuScreen::~MenuScreen()
{
	std::vector<sf::String*>::reverse_iterator ret_it;
	for(ret_it = item.rbegin(); ret_it != item.rend(); ++ret_it)
	{
		delete *ret_it;
		item.pop_back();
	}

	std::vector<sf::Sprite*>::reverse_iterator ret_sprite;
	for(ret_sprite = sprite.rbegin(); ret_sprite != sprite.rend(); ++ret_sprite)
	{
		delete *ret_sprite;
		sprite.pop_back();
	}

	std::vector<sf::String*>::reverse_iterator ret_title;
	for(ret_title = title.rbegin(); ret_title != title.rend(); ++ret_title)
	{
		delete *ret_title;
		title.pop_back();
	}
}

Choose MenuScreen::Run(sf::RenderWindow& App)
{
	std::vector<sf::String*>::iterator item_it, title_it;
	std::vector<sf::Sprite*>::iterator sprite_it;

	Refresh();

	sf::Event e;
	while(true)
	{
		while(App.GetEvent(e))
		{
			if(e.Type == sf::Event::Closed)
				return Choose::Closed;

			if(e.Type == sf::Event::KeyPressed)
			{
				if(e.Key.Code == sf::Key::Return)
				{
					menuEnter.Play();
					return (*v_iter);
				}
				if(e.Key.Code == nextKey)
				{
					menuChoose.Play();
					Next();
				}
				if(e.Key.Code == prevKey)
				{
					menuChoose.Play();
					Previous();
				}
			}
		}
		App.Clear();

		for(sprite_it = sprite.begin(); sprite_it != sprite.end(); ++sprite_it)
			App.Draw(**sprite_it);

		for(item_it = item.begin(); item_it != item.end(); ++item_it)
			App.Draw(**item_it);

		for(title_it = title.begin(); title_it != title.end(); ++title_it)
			App.Draw(**title_it);

		App.Display();
	}
}

void MenuScreen::Next()
{
	if(item_iter + 1 < item.end())
	{
		(**item_iter).SetColor(normalColor);
		item_iter++;
		v_iter++;
		(**item_iter).SetColor(chooseColor);
	}
}

void MenuScreen::Previous()
{
	if(item_iter - 1 >= item.begin())
	{
		(**item_iter).SetColor(normalColor);
		item_iter--;
		v_iter--;
		(**item_iter).SetColor(chooseColor);
	}
}

void MenuScreen::Refresh()
{
	v_iter = v.end() - 1;
	item_iter = item.end() - 1;
	while(v_iter != v.begin())
		Previous();
}

void MenuScreen::SetKeyNext(const sf::Key::Code& Key)
{
	nextKey = Key;
}

void MenuScreen::SetKeyPrev(const sf::Key::Code& Key)
{
	prevKey = Key;
}

void MenuScreen::SetChooseColor(const sf::Color& Color)
{
	chooseColor = Color;
}

void MenuScreen::SetNormalColor(const sf::Color& Color)
{
	normalColor = Color;
}

void MenuScreen::PushItem(sf::String* Text, const Choose& Value)
{
	v.push_back(Value);
	item.push_back(Text);
}

void MenuScreen::PushSprite(sf::Sprite* Sprite)
{
	sprite.push_back(Sprite);
}

void MenuScreen::PushTitle(sf::String* Title)
{
	title.push_back(Title);
}