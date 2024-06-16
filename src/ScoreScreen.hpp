#ifndef SCORESCREEN_HPP
#define SCORESCREEN_HPP

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>

#include <SFML/Graphics.hpp>
#include "Screen.hpp"

class ScoreScreen : public Screen
{
public:
    typedef std::pair<uint32_t, int16_t> ScoreInfo;

private:
    static const uint16_t MAX = 10;
    static std::vector<ScoreInfo> v;

    struct ScorePacket
    {
        uint32_t score;
        std::string name;
    } scorePacket[MAX];

    struct myclass {
        bool operator() (const ScorePacket& i, const ScorePacket& j) { return (i.score > j.score);}
    } ScoreCompare;

private:
    sf::Sprite wall;
    sf::Text saveName, saveTitle, scoreTitle;
    sf::Text rank[10], name[10], score[10];
    uint16_t Size;

public:
    ScoreScreen();
    virtual Choose Run(sf::RenderWindow& App);
    void Read();
    void Write();

private:
    void Refresh();
    bool IsSave();
    int16_t SaveScore(sf::RenderWindow& App);

public:
    static void NewScore(const uint32_t& Number, const int16_t& ProID);
};

#endif
