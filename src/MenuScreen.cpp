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
        menuChoose.setBuffer(*buffer);
    buffer = GlobalSoundBufferManager.Get(SFX_MENU_ENTER);
    if(buffer)
        menuEnter.setBuffer(*buffer);
}

MenuScreen::~MenuScreen()
{
    std::vector<sf::Text*>::reverse_iterator ret_it;
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

    std::vector<sf::Text*>::reverse_iterator ret_title;
    for(ret_title = title.rbegin(); ret_title != title.rend(); ++ret_title)
    {
        delete *ret_title;
        title.pop_back();
    }
}

Choose MenuScreen::Run(sf::RenderWindow& App)
{
    std::vector<sf::Text*>::iterator item_it, title_it;
    std::vector<sf::Sprite*>::iterator sprite_it;

    Refresh();

    sf::Event e;
    while(true)
    {
        while(App.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
                return Choose::Closed;

            if(e.type == sf::Event::KeyPressed)
            {
                if(e.key.code == sf::Keyboard::Return)
                {
                    menuEnter.play();
                    return (*v_iter);
                }
                if(e.key.code == nextKey)
                {
                    menuChoose.play();
                    Next();
                }
                if(e.key.code == prevKey)
                {
                    menuChoose.play();
                    Previous();
                }
            }
        }
        App.clear();

        for(sprite_it = sprite.begin(); sprite_it != sprite.end(); ++sprite_it)
            App.draw(**sprite_it);

        for(item_it = item.begin(); item_it != item.end(); ++item_it)
            App.draw(**item_it);

        for(title_it = title.begin(); title_it != title.end(); ++title_it)
            App.draw(**title_it);

        App.display();
    }
}

void MenuScreen::Next()
{
    if(item_iter + 1 < item.end())
    {
        (**item_iter).setFillColor(normalColor);
        item_iter++;
        v_iter++;
        (**item_iter).setFillColor(chooseColor);
    }
}

void MenuScreen::Previous()
{
    if(item_iter - 1 >= item.begin())
    {
        (**item_iter).setFillColor(normalColor);
        item_iter--;
        v_iter--;
        (**item_iter).setFillColor(chooseColor);
    }
}

void MenuScreen::Refresh()
{
    v_iter = v.end() - 1;
    item_iter = item.end() - 1;
    while(v_iter != v.begin())
        Previous();
}

void MenuScreen::SetKeyNext(const sf::Keyboard::Key& Key)
{
    nextKey = Key;
}

void MenuScreen::SetKeyPrev(const sf::Keyboard::Key& Key)
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

void MenuScreen::PushItem(sf::Text* Text, const Choose& Value)
{
    v.push_back(Value);
    item.push_back(Text);
}

void MenuScreen::PushSprite(sf::Sprite* Sprite)
{
    sprite.push_back(Sprite);
}

void MenuScreen::PushTitle(sf::Text* Title)
{
    title.push_back(Title);
}
