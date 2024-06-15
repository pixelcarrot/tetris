#include "ScoreScreen.hpp"

std::vector<std::pair<uint32_t, int16_t>> ScoreScreen::v;

ScoreScreen::ScoreScreen() : Screen()
{
    sf::Texture* texture = GlobalImageManager.Get(IMAGE_WALL);
    if (texture)
        wall.setTexture(*texture);  // Use setTexture instead of SetImage

    float posY, posX;
    posX = GAME_WIDTH / 2.f;

    sf::Font* font;
    font = GlobalFontManager.Get(TRON);
    if (font)
    {
        scoreTitle.setFont(*font);  // Use setFont instead of SetFont
        saveTitle.setFont(*font);
    }

    scoreTitle.setString("HIGH SCORES");  // Use setString instead of SetText
    scoreTitle.setFillColor(sf::Color::Black);  // Use setFillColor instead of SetColor
    scoreTitle.setPosition(posX, 70);  // Use setPosition instead of SetPosition
    AlignCenter(scoreTitle);

    saveTitle.setString("ENTER YOUR NAME");
    saveTitle.setFillColor(sf::Color::Black);
    saveTitle.setPosition(posX, 100);
    AlignCenter(saveTitle);

    saveName.setPosition(posX, 200);
    saveName.setFillColor(sf::Color::Black);

    font = GlobalFontManager.Get(TRANSFORMERS);
    if (font)
    {
        for (uint16_t i = 0; i < MAX; ++i)
        {
            rank[i].setFont(*font);
            score[i].setFont(*font);
            name[i].setFont(*font);
        }
        saveName.setFont(*font);
    }

    for (uint16_t i = 0; i < MAX; ++i)
    {
        posY = i * 40.f + 150;
        rank[i].setPosition(60.f, posY);
        rank[i].setString(Int2Str(i + 1));
        rank[i].setFillColor(sf::Color::Black);
        AlignRight(rank[i]);
        score[i].setPosition(posX - 15, posY);
        score[i].setFillColor(sf::Color::Black);
        name[i].setPosition(posX + 25, posY);
        name[i].setFillColor(sf::Color::Black);
    }

    Read();
}

Choose ScoreScreen::Run(sf::RenderWindow& App)
{
    if (IsSave())
        if (SaveScore(App) == -1)
            return Choose::Closed;

    Refresh();

    sf::Event e;
    while (true)
    {
        while (App.pollEvent(e))  // Use pollEvent instead of GetEvent
        {
            if (e.type == sf::Event::Closed)
                return Choose::Closed;
            if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)  // Use sf::Keyboard instead of sf::Key
                return Choose::Main;
        }

        App.clear();  // Use clear instead of Clear

        App.draw(wall);  // Use draw instead of Draw

        for (uint16_t i = 0; i < Size; ++i)
        {
            App.draw(rank[i]);
            App.draw(name[i]);
            App.draw(score[i]);
        }

        App.draw(scoreTitle);
        App.display();  // Use display instead of Display
    }
}

void ScoreScreen::Read()
{
    std::ifstream iFile(HIGH_SCORES, std::ios::binary);

    if (!iFile || iFile.eof())
    {
        Size = 0;
        return;
    }

    iFile.read(reinterpret_cast<char*>(&Size), sizeof(Size));
    iFile.read(reinterpret_cast<char*>(&scorePacket), sizeof(scorePacket));
    iFile.close();
}

void ScoreScreen::Write()
{
    std::ofstream oFile(HIGH_SCORES, std::ios::binary);
    oFile.write(reinterpret_cast<char*>(&Size), sizeof(Size));
    oFile.write(reinterpret_cast<char*>(&scorePacket), sizeof(scorePacket));
    oFile.close();
}

void ScoreScreen::Refresh()
{
    for (uint16_t i = 0; i < Size; ++i)
    {
        score[i].setString(Int2Str(scorePacket[i].score));  // Use setString instead of SetText
        AlignRight(score[i]);
        name[i].setString(scorePacket[i].name);  // Use setString instead of SetText
        AlignLeft(name[i]);
    }
}

bool ScoreScreen::IsSave()
{
    std::vector<ScoreInfo>::iterator v_iter;
    for (v_iter = v.begin(); v_iter != v.end(); ++v_iter)
        if (v_iter->second == this->ID)
            break;

    if (v_iter == v.end())
        return false;

    if (Size == MAX)
    {
        if (scorePacket[Size - 1].score < v_iter->first)
            scorePacket[Size - 1].score = v_iter->first;
        else
        {
            v.erase(v_iter);
            return false;
        }
    }
    else
        scorePacket[Size++].score = v_iter->first;

    v.erase(v_iter);
    return true;
}

int16_t ScoreScreen::SaveScore(sf::RenderWindow& App)
{
    std::string yourName = "";

    sf::Event e;
    while (true)
    {
        while (App.pollEvent(e))  // Use pollEvent instead of GetEvent
        {
            if (e.type == sf::Event::Closed)
                return -1;
            if (e.type == sf::Event::KeyPressed)
            {
                if (e.key.code == sf::Keyboard::Return)  // Use sf::Keyboard instead of sf::Key
                {
                    scorePacket[Size - 1].name = yourName;
                    std::sort(scorePacket, scorePacket + Size, ScoreCompare);
                    Write();
                    return 0;
                }
                if (e.key.code == sf::Keyboard::BackSpace && !yourName.empty())  // Use sf::Keyboard instead of sf::Key
                    yourName.pop_back();

                if (yourName.length() < 10 && e.key.code >= sf::Keyboard::A && e.key.code <= sf::Keyboard::Z)
                    yourName.push_back(static_cast<char>(e.key.code + ('a' - sf::Keyboard::A)));  // Convert to lowercase
            }
        }

        saveName.setString(yourName);  // Use setString instead of SetText
        AlignCenter(saveName);

        App.clear();

        App.draw(wall);
        App.draw(saveTitle);
        App.draw(saveName);

        App.display();
    }
}

void ScoreScreen::NewScore(const uint32_t& Number, const int16_t& ProID)
{
    v.push_back(ScoreInfo(Number, ProID));
}
