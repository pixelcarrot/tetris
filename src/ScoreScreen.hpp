#ifndef SCORESCREEN_HPP
#define SCORESCREEN_HPP

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

#include "Screen.hpp"

class ScoreScreen : public Screen
{
public:
	typedef std::pair<uint32, int16> ScoreInfo;

private:
	static const uint16 MAX = 10;
	static std::vector<ScoreInfo> v;

	struct ScorePacket
	{
		uint32 score;
		std::string name;
	} scorePacket[MAX];

	struct myclass {
		bool operator() (const ScorePacket& i, const ScorePacket& j) { return (i.score > j.score);}
	} ScoreCompare;
	
private:
	sf::Sprite wall;
	sf::String saveName, saveTitle, scoreTitle;
	sf::String rank[10], name[10], score[10];
	uint16 Size;

public:
	ScoreScreen();
	virtual Choose Run(sf::RenderWindow& App);
	void Read();
	void Write();

private:
	void Refresh();
	bool IsSave();
	int16 SaveScore(sf::RenderWindow& App);

public:
	static void NewScore(const uint32& Number, const int16& ProID);
};

#endif