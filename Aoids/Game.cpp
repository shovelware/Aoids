#include "Game.hpp"

Game::Game() : window_(sf::VideoMode(640, 480, 32), "SFML App")
{
}

void Game::run()
{
	sf::Clock frameClock;
	sf::Time tickTime = sf::Time(sf::seconds(1.f / 60.f));
	sf::Time accumulator = sf::Time::Zero;

	//Game loop
	while (window_.isOpen())
	{
		//Get delta time since last frame
		sf::Time frameTime = frameClock.restart();
		accumulator += frameTime;

		//Take inputs
		processEvents();

		//Update to number of physics steps
		while (accumulator >= tickTime)
		{
			update(tickTime);
			accumulator -= tickTime;
		}

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

void Game::update(sf::Time dt)
{
	
}

void Game::render()
{
	window_.clear();
	
	//cout << "render" << endl;

	//Render stuff

	window_.display();
}
