#include "Menu.h"

Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");

	// intialise text
	if (!font_.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font \n";
	}
	text_info_.setFont(font_);
	text_info_.setString("Press Enter to Play");
	text_info_.setCharacterSize(24);
	text_info_.setFillColor(sf::Color::White);
	text_info_.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text_info_.setPosition(window->getSize().x / 2.0f, window->getSize().y / 2.0f);

}

Menu::~Menu()
{

}

// handle user input
void Menu::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		input->setKeyUp(sf::Keyboard::Enter);
		gameState->setCurrentState(GState::LEVEL);
		std::cout << "START GAME PRESSED" << std::endl;
	}
}

// Update game objects
void Menu::update(float dt)
{

}

// Render Menu
void Menu::render()
{
	beginDraw();
	window->draw(text_info_);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Menu::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Menu::endDraw()
{
	window->display();
}