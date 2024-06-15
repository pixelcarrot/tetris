#include "GameScreen.hpp"
#include "StringUtility.hpp"
#include <algorithm>

GameScreen::GameScreen() : Screen()
{
    pauseScreen.SetID(ID);
    isPlaying = false;

    InitializeSound();
    InitializeWall();
    InitializeInfo();
}

void GameScreen::InitializeSound()
{
    sf::SoundBuffer* buffer;
    buffer = GlobalSoundBufferManager.Get(SFX_ROTATE);
    if (buffer)
        sfxRotate.setBuffer(*buffer);
    buffer = GlobalSoundBufferManager.Get(SFX_FILL);
    if (buffer)
        sfxFill.setBuffer(*buffer);
    buffer = GlobalSoundBufferManager.Get(SFX_DELETE);
    if (buffer)
        sfxDelete.setBuffer(*buffer);
    buffer = GlobalSoundBufferManager.Get(SFX_LEVEL_UP);
    if (buffer)
        sfxLevelUp.setBuffer(*buffer);
    buffer = GlobalSoundBufferManager.Get(SFX_GAME_OVER);
    sfxGameOver.setBuffer(*buffer);

    sfxTetris.openFromFile(SFX_TETRIS);
    sfxTetris.setLoop(true);
}

void GameScreen::InitializeWall()
{
    sf::Texture* texture;

    texture = GlobalImageManager.Get(IMAGE_TEXTURE);
    if (texture)
    {
        textureTop.setTexture(*texture);
        textureTop.setTextureRect(sf::IntRect(0, 0, GAME_WIDTH, 50));
        textureBot.setTexture(*texture);
        textureBot.setTextureRect(sf::IntRect(0, 50, GAME_WIDTH, GAME_HEIGHT));
        textureBot.setPosition(0, 50);
    }

    texture = GlobalImageManager.Get(IMAGE_WALL);
    if (texture)
    {
        wallTop.setTexture(*texture);
        wallTop.setTextureRect(sf::IntRect(0, 0, GAME_WIDTH, 50));
        wallBot.setTexture(*texture);
        wallBot.setTextureRect(sf::IntRect(0, 50, GAME_WIDTH, GAME_HEIGHT));
        wallBot.setPosition(0, 50);
    }
}

void GameScreen::InitializeInfo()
{
    for (uint16_t i = 0; i < MaxLevel; ++i)
        delay[i] = (8 - i) * 0.1f;

    level = 1;
    lines = score = land = 0;

    sf::Font* font;

    font = GlobalFontManager.Get(TRANSFORMERS);
    if (font)
    {
        txtLevel.setFont(*font);
        txtLines.setFont(*font);
        txtScore.setFont(*font);
        txtGameOver.setFont(*font);
    }

    font = GlobalFontManager.Get(TRON);
    if (font)
        txtGameOver.setFont(*font);

    txtGameOver.setString("GAME OVER");
    txtGameOver.setFillColor(sf::Color::Black);
    txtGameOver.setPosition(175, 250);
    AlignCenter(txtGameOver);

    txtLevel.setPosition(X_WAIT_PIECE + SIZE_BRICK * 4, Y_WAIT_PIECE + SIZE_BRICK * 4);
    txtLines.setPosition(X_WAIT_PIECE + SIZE_BRICK * 4, Y_WAIT_PIECE + SIZE_BRICK * 7);
    txtScore.setPosition(X_WAIT_PIECE + SIZE_BRICK * 4, Y_WAIT_PIECE + SIZE_BRICK * 10);

    txtLevel.setFillColor(sf::Color::Black);
    txtLines.setFillColor(sf::Color::Black);
    txtScore.setFillColor(sf::Color::Black);

    RefreshLevel();
    RefreshLines();
    RefreshScore();
}

void GameScreen::NewGame()
{
    isPlaying = true;

    board.Reset();
    waitPiece.PosWait();
    waitPiece.SetType(rand() % 7);  // Random piece type
    NextPiece();
    board.Push(actPiece);

    level = 1;
    lines = score = land = 0;

    RefreshLevel();
    RefreshLines();
    RefreshScore();

    clock.restart();
}

Choose GameScreen::Run(sf::RenderWindow& App)
{
    if (sfxTetris.getStatus() == sf::Music::Stopped)
        sfxTetris.play();

    if (!isPlaying)
        NewGame();

    sf::Event e;
    while (true)
    {
        while (App.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                return Choose::Closed;

            if (e.type == sf::Event::KeyPressed)
            {
                if (e.key.code == sf::Keyboard::Escape)
                {
                    sfxTetris.pause();
                    Choose result = pauseScreen.Run(App);
                    if (result == Choose::Closed)
                        return Choose::Closed;
                    if (result == Choose::Quit)
                    {
                        sfxTetris.stop();
                        isPlaying = false;
                        return Choose::Main;
                    }
                    sfxTetris.play();
                }

                Control(e.key);
            }
        }

        actPiece.DelayDrop(delay[level - 1]);

        if (actPiece.IsStop())
        {
            sfxFill.play();
            board.Fill();

            if (board.IsFull())
                return GameOver(App);

            lines += board.GetLineDelete();
            score += 4 + 100 * board.GetLineDelete();

            if (board.GetLineDelete() != 0)
                sfxDelete.play();

            if (land > 50 * level)
            {
                sfxLevelUp.play();
                NextLevel();
                land = 0;
            }

            RefreshLines();
            RefreshScore();

            land++;
            NextPiece();
            board.Push(actPiece);
        }

        App.clear();

        App.draw(wallBot);
        App.draw(textureBot);

        actPiece.Draw(App);

        App.draw(wallTop);
        App.draw(textureTop);

        waitPiece.Draw(App);
        board.Draw(App);

        App.draw(txtLevel);
        App.draw(txtScore);
        App.draw(txtLines);

        App.display();
    }
}

Choose GameScreen::GameOver(sf::RenderWindow& App)
{
    sfxTetris.stop();
    sfxGameOver.play();

    sf::Event e;
    while (true)
    {
        while (App.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                return Choose::Closed;

            if (e.type == sf::Event::KeyPressed)
            {
                isPlaying = false;
                ScoreScreen::NewScore(score, ID);
                return Choose::HighScores;
            }
        }

        App.clear();
        App.draw(txtGameOver);
        App.display();
    }
}

void GameScreen::Control(const sf::Event::KeyEvent& Key)
{
    if (actPiece.IsStop())
        return;

    if (Key.code == sf::Keyboard::Left)
        actPiece.MoveLeft();
    else if (Key.code == sf::Keyboard::Right)
        actPiece.MoveRight();
    else if (Key.code == sf::Keyboard::Down)
        actPiece.SoftDrop();
    else if (Key.code == sf::Keyboard::Z)
    {
        sfxRotate.play();
        actPiece.RotateLeft();
    }
    else if (Key.code == sf::Keyboard::X)
    {
        sfxRotate.play();
        actPiece.RotateRight();
    }
    else if (Key.code == sf::Keyboard::Space)
        actPiece.HardDrop();
}

void GameScreen::NextLevel()
{
    if (level == MaxLevel)
        return;

    level++;
    RefreshLevel();
}

void GameScreen::NextPiece()
{
    actPiece.SetType(waitPiece.GetType());
    while (actPiece.GetType() == waitPiece.GetType())
        waitPiece.SetType(rand() % 7);  // Random piece type
}

void GameScreen::RefreshLevel()
{
    txtLevel.setString(Int2Str(level));
    AlignRight(txtLevel);
}

void GameScreen::RefreshLines()
{
    txtLines.setString(Int2Str(lines));
    AlignRight(txtLines);
}

void GameScreen::RefreshScore()
{
    txtScore.setString(Int2Str(score));
    AlignRight(txtScore);
}
