#include "Game.hpp"

Game::Game() : window_(sf::VideoMode(640, 480, 32), "SFML App")
{

}

void Game::run()
{
	while (window_.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event evt;
	while (window_.pollEvent(evt))
	{
		if (evt.type == sf::Event::Closed)
			window_.close();
	}
}

void Game::update()
{
}

void Game::render()
{
	window_.clear();

	window_.display();
}
