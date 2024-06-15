#ifndef PAUSESCREEN_HPP
#define PAUSESCREEN_HPP

#include "MenuScreen.hpp"

class PauseScreen : public MenuScreen
{
public:
    PauseScreen() : MenuScreen()
    {
        SetKeyNext(sf::Keyboard::Down);
        SetKeyPrev(sf::Keyboard::Up);

        SetNormalColor(sf::Color::Black);
        SetChooseColor(sf::Color::Cyan);

        sf::Text *continue_ptr = new sf::Text();
        continue_ptr->setString("Continue");
        sf::Text *quit_ptr = new sf::Text();
        quit_ptr->setString("Quit");
        sf::Text *title = new sf::Text();
        title->setString("PAUSE");

        sf::Font *font = GlobalFontManager.Get(TRON);
        if (font)
        {
            continue_ptr->setFont(*font);
            quit_ptr->setFont(*font);
            title->setFont(*font);
        }

        AlignCenter(*continue_ptr);
        AlignCenter(*quit_ptr);
        AlignCenter(*title);

        float posX = GAME_WIDTH / 2.f;

        continue_ptr->setPosition(posX, 200);
        quit_ptr->setPosition(posX, 270);

        title->setPosition(posX, 100);
        title->setFillColor(sf::Color::Black);

        PushItem(continue_ptr, Choose::Previous);
        PushItem(quit_ptr, Choose::Quit);

        PushTitle(title);

        sf::Texture *texture = GlobalImageManager.Get(IMAGE_WALL);
        if (texture)
        {
            sf::Sprite *wall = new sf::Sprite();
            wall->setTexture(*texture);
            PushSprite(wall);
        }
    }
};

#endif
