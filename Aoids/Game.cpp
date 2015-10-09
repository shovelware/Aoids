#include "Game.hpp"



Game::Game() : window_(sf::VideoMode(640, 480, 32), "SFML App")
{
}

void Game::run()
{
	//Window info
	sf::Vector2u windowSize = window_.getSize();

	//Fixed Timestep
	sf::Clock frameClock;
	sf::Time tickTime = sf::Time(sf::seconds(1.f / 60.f));
	sf::Time accumulator = sf::Time::Zero;

	//Textures
	sf::Texture texDefault;
	sf::Texture texPlayer;
	sf::Texture texEnemy;
	if (!texDefault.loadFromFile	("X:/AIG/Labs/Aoids/shiptemp.png")) { }
	if (!texPlayer.loadFromFile		("X:/AIG/Labs/Aoids/playerTemp.png")) { }
	if (!texEnemy.loadFromFile		("X:/AIG/Labs/Aoids/enemyTemp.png")) { }

	//Entities
	player_ = Entity(&texPlayer, sf::Vector2f(windowSize.x / 2, windowSize.y / 2), 0);

	//Controls
	//Left Arrow / A : Rotate Left
	buttons[LEFT] = InputAction(Keyboard::Left, Keyboard::A);
	//Right Arrow / D : Rotate Right
	buttons[RIGHT] = InputAction(Keyboard::Right, Keyboard::D);
	//Up Arrow / W : Speed Up
	buttons[UP] = InputAction(Keyboard::Up, Keyboard::W);
	//Down Arrow / S : Slow Down
	buttons[DOWN] = InputAction(Keyboard::Down, Keyboard::S);
	//Space : Activate
	buttons[ACTION] = InputAction(Keyboard::Space);

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

		if (evt.type == sf::Event::KeyPressed && evt.key.code == Key::Escape)
		{
			window_.close();
		}
	}

	//Update all keys
	for (InputMap::iterator mStart = buttons.begin(), mIter = mStart, mEnd = buttons.end(); mIter != mEnd; ++mIter)
	{
		mIter->second.update();
	}

	//Check all keys, take actions
	if (*buttons[LEFT]) { player_.rotate(-0.1); }
	if (*buttons[RIGHT]) { player_.rotate(0.1); }
	if (*buttons[UP]) { ; }
	if (*buttons[DOWN]) { ; }
	if (*buttons[ACTION]) { ; }

}

void Game::update(sf::Time dt)
{
	player_.update(dt);
}

void Game::render()
{
	window_.clear();
	
	window_.draw(player_);
	//cout << "render" << endl;

	//Render stuff

	window_.display();
}
