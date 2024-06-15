#ifndef CONTROLSCREEN_HPP
#define CONTROLSCREEN_HPP

#include "Screen.hpp"

class ControlScreen : public Screen
{
private:
    sf::Sprite wall;
    sf::Text left[7], right[7], title;

public:
    ControlScreen() : Screen()
    {
        sf::Texture* texture = GlobalImageManager.Get(IMAGE_WALL);  // Use sf::Texture
        if (texture)
            wall.setTexture(*texture);

        title.setString("CONTROL KEYS");

        left[0].setString("Left arrow");
        left[1].setString("Right arrow");
        left[2].setString("Down arrow");
        left[3].setString("Z");
        left[4].setString("X");
        left[5].setString("Space");
        left[6].setString("ESC");

        right[0].setString("- Move left");
        right[1].setString("- Move right");
        right[2].setString("- Soft drop");
        right[3].setString("- Rotate left");
        right[4].setString("- Rotate right");
        right[5].setString("- Hard drop");
        right[6].setString("- Escape / Pause");

        float posX = GAME_WIDTH / 2.f;
        float posY;

        sf::Font* font = GlobalFontManager.Get(TRON);
        if (font)
            title.setFont(*font);

        AlignCenter(title);
        title.setPosition(posX, 100);
        title.setFillColor(sf::Color::Black);

        for (int16_t i = 0; i < 7; ++i)
        {
            posY = i * 50 + 200;
            AlignRight(left[i]);
            AlignLeft(right[i]);
            left[i].setPosition(posX - 15, posY);
            right[i].setPosition(posX, posY);
            left[i].setFillColor(sf::Color::Black);
            right[i].setFillColor(sf::Color::Black);
        }
    }

    virtual Choose Run(sf::RenderWindow& App)
    {
        sf::Event e;
        while (true)
        {
            while (App.pollEvent(e))
            {
                if (e.type == sf::Event::Closed)
                    return Choose::Closed;

                if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
                    return Choose::Previous;
            }

            App.clear();

            App.draw(wall);

            App.draw(title);

            for (int16_t i = 0; i < 7; ++i)
            {
                App.draw(left[i]);
                App.draw(right[i]);
            }

            App.display();
        }
    }
};

#endif
