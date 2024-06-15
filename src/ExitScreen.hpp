#ifndef EXITSCREEN_HPP
#define EXITSCREEN_HPP

#include "MenuScreen.hpp"

class ExitScreen : public MenuScreen
{
public:
    ExitScreen() : MenuScreen()
    {
        SetKeyNext(sf::Keyboard::Left);
        SetKeyPrev(sf::Keyboard::Right);

        SetNormalColor(sf::Color::Black);
        SetChooseColor(sf::Color::Cyan);

        sf::Text* yes = new sf::Text();
        yes->setString("YES");
        sf::Text* no = new sf::Text();
        no->setString("NO");
        sf::Text* title = new sf::Text();
        title->setString("EXIT GAME");

        sf::Font* font = GlobalFontManager.Get(TRON);
        if (font)
        {
            yes->setFont(*font);
            no->setFont(*font);
            title->setFont(*font);
        }

        AlignRight(*yes);
        AlignLeft(*no);
        AlignCenter(*title);

        float posX = GAME_WIDTH / 2.f, posY = GAME_HEIGHT / 2.f;

        yes->setPosition(posX - 20, posY - 100);
        no->setPosition(posX + 20, posY - 100);

        title->setPosition(posX, 100);
        title->setFillColor(sf::Color::Black);

        PushItem(no, Choose::Previous);
        PushItem(yes, Choose::Closed);

        PushTitle(title);

        sf::Texture* texture = GlobalImageManager.Get(IMAGE_WALL);
        if (texture)
        {
            sf::Sprite* wall = new sf::Sprite();
            wall->setTexture(*texture);
            PushSprite(wall);
        }
    }
};

#endif
