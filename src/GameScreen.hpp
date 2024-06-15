#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include "ScoreScreen.hpp"
#include "PauseScreen.hpp"
#include "Screen.hpp"
#include "Board.hpp"
#include "Piece.hpp"

class GameScreen : public Screen
{
private:
	sf::Music sfxTetris;
	sf::Sound sfxLevelUp, sfxRotate, sfxFill, sfxDelete, sfxGameOver;

private:
	static const uint16 MaxLevel = 8;

private:
	PauseScreen pauseScreen;
	Board board;
	Piece actPiece, waitPiece;
	float delay[MaxLevel];
	uint16 level, lines, land;
	uint32 score;
	bool isPlaying;
	sf::String txtScore, txtLevel, txtLines, txtGameOver;
	sf::Clock clock;
	sf::Sprite textureTop, textureBot, wallTop, wallBot;	

public:
	GameScreen();
	virtual Choose Run(sf::RenderWindow& App);
	void NewGame();

private:
	Choose GameOver(sf::RenderWindow& App);
	void Control(const sf::Event::KeyEvent& Key);
	void InitializeSound();
	void InitializeWall();
	void InitializeInfo();
	void NextPiece();
	void NextLevel();
	void RefreshLevel();
	void RefreshScore();
	void RefreshLines();
};

#endif