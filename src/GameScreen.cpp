#include "GameScreen.hpp"

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
	if(buffer)
		sfxRotate.SetBuffer(*buffer);
	buffer = GlobalSoundBufferManager.Get(SFX_FILL);
	if(buffer)
		sfxFill.SetBuffer(*buffer);
	buffer = GlobalSoundBufferManager.Get(SFX_DELETE);
	if(buffer)
		sfxDelete.SetBuffer(*buffer);
	buffer = GlobalSoundBufferManager.Get(SFX_LEVEL_UP);
	if(buffer)
		sfxLevelUp.SetBuffer(*buffer);
	buffer = GlobalSoundBufferManager.Get(SFX_GAME_OVER);
	sfxGameOver.SetBuffer(*buffer);

	sfxTetris.OpenFromFile(SFX_TETRIS);
	sfxTetris.SetLoop(true);
}

void GameScreen::InitializeWall()
{
	sf::Image* image;

	image = GlobalImageManager.Get(IMAGE_TEXTURE);
	if(image)
	{
		image->CreateMaskFromColor(sf::Color::White, 0);
		textureTop.SetImage(*image);
		textureTop.SetSubRect(sf::IntRect(0, 0, GAME_WIDTH, 50));
		textureTop.SetBlendMode(sf::Blend::Multiply);
		textureBot.SetImage(*image);
		textureBot.SetSubRect(sf::IntRect(0, 50, GAME_WIDTH, GAME_HEIGHT));
		textureBot.SetBlendMode(sf::Blend::Multiply);
		textureBot.SetPosition(0, 50);
	}

	image = GlobalImageManager.Get(IMAGE_WALL);
	if(image)
	{
		wallTop.SetImage(*image);
		wallTop.SetSubRect(sf::IntRect(0, 0, GAME_WIDTH, 50));
		wallBot.SetImage(*image);
		wallBot.SetSubRect(sf::IntRect(0, 50, GAME_WIDTH, GAME_HEIGHT));
		wallBot.SetPosition(0, 50);
	}
}

void GameScreen::InitializeInfo()
{
	for(uint16 i = 0; i < MaxLevel; ++i)
		delay[i] = (8 - i) * 0.1f;

	level = 1;
	lines = score = land = 0;

	sf::Font* font;
	
	font = GlobalFontManager.Get(TRANSFORMERS);
	if(font)
	{
		txtLevel.SetFont(*font);
		txtLines.SetFont(*font);
		txtScore.SetFont(*font);
		txtGameOver.SetFont(*font);
	}

	font = GlobalFontManager.Get(TRON);
	if(font)
		txtGameOver.SetFont(*font);

	txtGameOver.SetText("GAME OVER");
	txtGameOver.SetColor(sf::Color::Black);
	txtGameOver.SetPosition(175, 250);
	AlignCenter(txtGameOver);

	txtLevel.SetPosition(X_WAIT_PIECE + SIZE_BRICK * 4, Y_WAIT_PIECE + SIZE_BRICK * 4);
	txtLines.SetPosition(X_WAIT_PIECE + SIZE_BRICK * 4, Y_WAIT_PIECE + SIZE_BRICK * 7);
	txtScore.SetPosition(X_WAIT_PIECE + SIZE_BRICK * 4, Y_WAIT_PIECE + SIZE_BRICK * 10);

	txtLevel.SetColor(sf::Color::Black);
	txtLines.SetColor(sf::Color::Black);
	txtScore.SetColor(sf::Color::Black);

	RefreshLevel();
	RefreshLines();
	RefreshScore();
}

void GameScreen::NewGame()
{
	isPlaying = true;

	board.Reset();
	waitPiece.PosWait();
	waitPiece.SetType(sf::Randomizer::Random(0, 6));
	NextPiece();
	board.Push(actPiece);

	level = 1;
	lines = score = land = 0;

	RefreshLevel();
	RefreshLines();
	RefreshScore();

	clock.Reset();
}

Choose GameScreen::Run(sf::RenderWindow& App)
{
	if(sfxTetris.GetStatus() == sf::Music::Stopped)
		sfxTetris.Play();

	if(!isPlaying)
		NewGame();

	sf::Event e;
	while(true)
	{
		while(App.GetEvent(e))
		{
			if(e.Type == sf::Event::Closed)
				return Choose::Closed;

			if(e.Type == sf::Event::KeyPressed)
			{
				if(e.Key.Code == sf::Key::Escape)
				{
					sfxTetris.Pause();
					Choose result = pauseScreen.Run(App);
					if(result == Choose::Closed)
						return Choose::Closed;
					if(result == Choose::Quit)
					{
						sfxTetris.Stop();
						isPlaying = false;
						return Choose::Main;
					}
					sfxTetris.Play();
				}

				Control(e.Key);
			}
		}

		actPiece.DelayDrop(delay[level - 1]);

		if(actPiece.IsStop())
		{
			sfxFill.Play();
			board.Fill();

			if(board.IsFull())
				return GameOver(App);

			lines += board.GetLineDelete();
			score += 4 + 100 * board.GetLineDelete();

			if(board.GetLineDelete() != 0)
				sfxDelete.Play();

			if(land > 50 * level)
			{
				sfxLevelUp.Play();
				NextLevel();
				land = 0;
			}

			RefreshLines();
			RefreshScore();

			land++;
			NextPiece();
			board.Push(actPiece);
		}
		
		App.Clear();

		App.Draw(wallBot);
		App.Draw(textureBot);

		actPiece.Draw(App);
		
		App.Draw(wallTop);
		App.Draw(textureTop);
		
		waitPiece.Draw(App);
		board.Draw(App);

		App.Draw(txtLevel);
		App.Draw(txtScore);
		App.Draw(txtLines);

		App.Display();
	}
}

Choose GameScreen::GameOver(sf::RenderWindow& App)
{
	sfxTetris.Stop();
	sfxGameOver.Play();

	sf::Event e;
	while(true)
	{
		while(App.GetEvent(e))
		{
			if(e.Type == sf::Event::Closed)
				return Choose::Closed;

			if(e.Type == sf::Event::KeyPressed)
			{
				isPlaying = false;
				ScoreScreen::NewScore(score,ID);
				return Choose::HighScores;
			}
		}

		App.Draw(txtGameOver);

		App.Display();
	}
}

void GameScreen::Control(const sf::Event::KeyEvent& Key)
{
	if(actPiece.IsStop())
		return;

	if(Key.Code == sf::Key::Left)
		actPiece.MoveLeft();
	else if(Key.Code == sf::Key::Right)
		actPiece.MoveRight();
	else if(Key.Code == sf::Key::Down)
		actPiece.SoftDrop();
	else if(Key.Code == sf::Key::Z)
	{
		sfxRotate.Play();
		actPiece.RotateLeft();
	}
	else if(Key.Code == sf::Key::X)
	{
		sfxRotate.Play();
		actPiece.RotateRight();
	}
	else if(Key.Code == sf::Key::Space)
		actPiece.HardDrop();
}

void GameScreen::NextLevel()
{
	if(level == MaxLevel)
		return;

	level++;
	RefreshLevel();
}

void GameScreen::NextPiece()
{
	actPiece.SetType(waitPiece.GetType());
	while(actPiece.GetType() == waitPiece.GetType())
		waitPiece.SetType(sf::Randomizer::Random(0, 6));
}

void GameScreen::RefreshLevel()
{
	txtLevel.SetText(Int2Str(level));
	AlignRight(txtLevel);
}

void GameScreen::RefreshLines()
{
	txtLines.SetText(Int2Str(lines));
	AlignRight(txtLines);
}

void GameScreen::RefreshScore()
{
	txtScore.SetText(Int2Str(score));
	AlignRight(txtScore);
}