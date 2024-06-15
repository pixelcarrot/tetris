#ifndef MENUSCREEN_HPP
#define MENUSCREEN_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Screen.hpp"

class MenuScreen : public Screen
{
public:
    MenuScreen();
    virtual ~MenuScreen();
    virtual Choose Run(sf::RenderWindow& App);

protected:
    void SetKeyNext(const sf::Keyboard::Key& Key);
    void SetKeyPrev(const sf::Keyboard::Key& Key);
    void SetChooseColor(const sf::Color& Color);
    void SetNormalColor(const sf::Color& Color);
    void PushTitle(sf::Text* Title);
    void PushItem(sf::Text* Text, const Choose& Value);
    void PushSprite(sf::Sprite* Sprite);

private:
    void InitializeSound();
    void Next();
    void Previous();
    void Refresh();

private:
    sf::Sound menuChoose, menuEnter;
    std::vector<Choose>::iterator v_iter;
    std::vector<Choose> v;
    std::vector<sf::Text*>::iterator item_iter;
    std::vector<sf::Text*> item;
    std::vector<sf::Sprite*> sprite;
    std::vector<sf::Text*> title;
    sf::Color chooseColor, normalColor;
    sf::Keyboard::Key nextKey, prevKey;
};

#endif
