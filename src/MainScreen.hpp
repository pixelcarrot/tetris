#ifndef MAINSCREEN_HPP
#define MAINSCREEN_HPP

#include "StringUtility.hpp"
#include "ImageManager.hpp"
#include "FontManager.hpp"
#include "MenuScreen.hpp"
#include "Constant.hpp"

class MainScreen : public MenuScreen
{
public:
    MainScreen() : MenuScreen()
    {
        SetKeyNext(sf::Keyboard::Down);
        SetKeyPrev(sf::Keyboard::Up);

        SetNormalColor(sf::Color::Black);
        SetChooseColor(sf::Color::Cyan);

        sf::Text *play = new sf::Text();
        play->setString("New Game");
        sf::Text *control = new sf::Text();
        control->setString("Control");
        sf::Text *highscores = new sf::Text();
        highscores->setString("High Scores");
        sf::Text *exit = new sf::Text();
        exit->setString("Exit");

        sf::Font *font = GlobalFontManager.Get(TRON);
        if (font)
        {
            play->setFont(*font);
            control->setFont(*font);
            highscores->setFont(*font);
            exit->setFont(*font);
        }

        AlignCenter(*play);
        AlignCenter(*control);
        AlignCenter(*highscores);
        AlignCenter(*exit);

        float posX = GAME_WIDTH / 2.f;

        play->setPosition(posX, 290);
        control->setPosition(posX, 360);
        highscores->setPosition(posX, 430);
        exit->setPosition(posX, 500);

        PushItem(play, Choose::NewGame);
        PushItem(control, Choose::Control);
        PushItem(highscores, Choose::HighScores);
        PushItem(exit, Choose::Exit);

        sf::Texture *texture;

        texture = GlobalImageManager.Get(IMAGE_WALL);
        if (texture)
        {
            sf::Sprite *wall = new sf::Sprite();
            wall->setTexture(*texture);
            PushSprite(wall);
        }

        texture = GlobalImageManager.Get(IMAGE_TETRIS);
        if (texture)
        {
            texture->setSmooth(false);
            sf::Sprite *tetris = new sf::Sprite();
            tetris->setTexture(*texture);
            tetris->setTextureRect(sf::IntRect(0, 0, texture->getSize().x, texture->getSize().y));
            tetris->setOrigin(tetris->getLocalBounds().width / 2.f, 0);
            tetris->setPosition(posX, 100);
            PushSprite(tetris);
        }

        sf::Font *arial = GlobalFontManager.Get(ARIAL);
        if (arial)
        {
            sf::Text *author = new sf::Text();
            author->setFont(*arial);
            author->setString("Copyright 2011 Nguyen. All rights reserved.");
            author->setCharacterSize(14);
            author->setFillColor(sf::Color::Black);
            author->setPosition(GAME_WIDTH - 2, GAME_HEIGHT - 22);
            AlignRight(*author);
            PushTitle(author);
        }
    }
};

#endif
