#include "ScoreScreen.hpp"

std::vector<std::pair<uint32, int16>> ScoreScreen::v;

ScoreScreen::ScoreScreen() : Screen()
{
	sf::Image* image = GlobalImageManager.Get(IMAGE_WALL);
	if(image)
		wall.SetImage(*image);

	float posY, posX;

	posX = GAME_WIDTH/2.f;

	sf::Font* font;

	font = GlobalFontManager.Get(TRON);
	if(font)
	{
		scoreTitle.SetFont(*font);
		saveTitle.SetFont(*font);
	}

	scoreTitle.SetText("HIGH SCORES");
	scoreTitle.SetColor(sf::Color::Black);
	scoreTitle.SetPosition(posX, 70);
	AlignCenter(scoreTitle);

	saveTitle.SetText("ENTER YOUR NAME");
	saveTitle.SetColor(sf::Color::Black);
	saveTitle.SetPosition(posX, 100);
	AlignCenter(saveTitle);
	
	saveName.SetPosition(posX, 200);
	saveName.SetColor(sf::Color::Black);

	font = GlobalFontManager.Get(TRANSFORMERS);
	if(font)
	{
		for(uint16 i = 0; i < MAX; ++i)
		{
			rank[i].SetFont(*font);
			score[i].SetFont(*font);
			name[i].SetFont(*font);
		}

		saveName.SetFont(*font);
	}

	for(uint16 i = 0; i < MAX; ++i)
	{
		posY = i * 40.f + 150;
		rank[i].SetPosition(60.f, posY);
		rank[i].SetText(Int2Str(i + 1));
		rank[i].SetColor(sf::Color::Black);
		AlignRight(rank[i]);
		score[i].SetPosition(posX - 15, posY);
		score[i].SetColor(sf::Color::Black);
		name[i].SetPosition(posX + 25, posY);
		name[i].SetColor(sf::Color::Black);
	}

	Read();
}

Choose ScoreScreen::Run(sf::RenderWindow& App)
{
	if(IsSave())
		if(SaveScore(App) == -1)
			return Choose::Closed;

	Refresh();

	sf::Event e;
	while(true)
	{
		while(App.GetEvent(e))
		{
			if(e.Type == sf::Event::Closed)
				return Choose::Closed;
			if (e.Type == sf::Event::KeyPressed && e.Key.Code == sf::Key::Escape)
				return Choose::Main;
		}

		App.Clear();

		App.Draw(wall);

		for(uint16 i = 0; i < Size; ++i)
		{
			App.Draw(rank[i]);
			App.Draw(name[i]);
			App.Draw(score[i]);
		}

		App.Draw(scoreTitle);

		App.Display();
	}
}

void ScoreScreen::Read()
{
	std::ifstream iFile(HIGH_SCORES, std::ios::binary);

	if(!iFile || iFile.eof())
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
	for(uint16 i = 0; i < Size; ++i)
	{
		score[i].SetText(Int2Str(scorePacket[i].score));
		AlignRight(score[i]);
		name[i].SetText(scorePacket[i].name);
		AlignLeft(name[i]);
	}
}

bool ScoreScreen::IsSave()
{
	std::vector<ScoreInfo>::iterator v_iter;
	for(v_iter = v.begin(); v_iter != v.end(); ++v_iter)
		if(v_iter->second == this->ID)
			break;

	if(v_iter == v.end())
		return false;

	if(Size == MAX)
	{
		if(scorePacket[Size - 1].score < v_iter->first)
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

int16 ScoreScreen::SaveScore(sf::RenderWindow& App)
{
	std::string yourName = "";

	sf::Event e;
	while(true)
	{
		while(App.GetEvent(e))
		{
			if(e.Type == sf::Event::Closed)
				return -1;
			if(e.Type == sf::Event::KeyPressed)
			{
				if(e.Key.Code == sf::Key::Return)
				{
					scorePacket[Size - 1].name = yourName;
					std::sort(scorePacket, scorePacket + Size, ScoreCompare);
					Write();
					return 0;
				}
				if(e.Key.Code == sf::Key::Back)
					if(!yourName.empty())
						yourName.pop_back();

				if(yourName.length() < 10 && e.Key.Code >= 'a' && e.Key.Code <= 'z')
					yourName.push_back(e.Key.Code & 223);
			}
		}

		saveName.SetText(yourName);
		AlignCenter(saveName);

		App.Clear();

		App.Draw(wall);

		App.Draw(saveTitle);
		App.Draw(saveName);

		App.Display();
	}
}

void ScoreScreen::NewScore(const uint32& Number, const int16& ProID)
{
	v.push_back(ScoreInfo(Number, ProID));
}