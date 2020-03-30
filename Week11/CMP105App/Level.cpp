#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");
	audio->addMusic("sfx/hyrulefield.ogg", "hyrule");

	audio->addSound("sfx/SMB_jump-small.ogg", "jump");
	audio->addSound("sfx/SMB_1-up.ogg", "up");
	audio->addSound("sfx/getover.ogg", "getover");
	audio->addSound("sfx/TP_Secret.ogg", "secret");

	// initialise managers
	tile_manager_.creatingTileMap(2);
	tile_manager_.setWindow(hwnd);
	player_manager_.setInput(in);
	player_manager_.setAudioManager(audio);

	// intialise text
	if (!font_.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font \n";
	}
	text_info_.setFont(font_);
	text_info_.setString("Press 'P' to continue");
	text_info_.setCharacterSize(24);
	text_info_.setFillColor(sf::Color::White);
	text_info_.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text_info_.setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (gameState->getCurrentState() == GState::LEVEL)
	{
		player_manager_.handleInput(dt);

		if (input->isKeyDown(sf::Keyboard::P))
		{
			input->setKeyUp(sf::Keyboard::P);
			gameState->setCurrentState(GState::PAUSE);
			audio->stopAllMusic();
			std::cout << "GAME PAUSED" << std::endl;
		}

		// Play Sound Effects
		if (input->isKeyDown(sf::Keyboard::Num1))
		{
			input->setKeyUp(sf::Keyboard::Num1);
			audio->playSoundbyName("up");
		}

		if (input->isKeyDown(sf::Keyboard::Num2))
		{
			input->setKeyUp(sf::Keyboard::Num2);
			audio->playSoundbyName("getover");
		}

		// Control Background music
		if (input->isKeyDown(sf::Keyboard::BackSpace))
		{
			input->setKeyUp(sf::Keyboard::BackSpace);
			audio->stopAllMusic();
		}
		if (input->isKeyDown(sf::Keyboard::Num4))
		{
			input->setKeyUp(sf::Keyboard::Num4);
			audio->playMusicbyName("hyrule");
		}
	}
	else if (gameState->getCurrentState() == GState::PAUSE)
	{
		if (input->isKeyDown(sf::Keyboard::P))
		{
			input->setKeyUp(sf::Keyboard::P);
			gameState->setCurrentState(GState::LEVEL);
			std::cout << "PLAY" << std::endl;
		}
	}
		
	
}

// Update game objects
void Level::update(float dt)
{
	// Update managers
	player_manager_.update(dt);
	tile_manager_.checkCollision(*player_manager_.getPlayer());

	// Controlling audio playback
	if (audio->getMusic()->getStatus() == sf::SoundSource::Stopped && gameState->getCurrentState() != GState::PAUSE)
	{
		audio->playMusicbyName("cantina");
	}

}

// Render level
void Level::render()
{
	beginDraw();
	tile_manager_.render();
	player_manager_.render(window);
	if (gameState->getCurrentState() == GState::PAUSE)
		window->draw(text_info_);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}