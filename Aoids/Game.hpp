#ifndef GAME_H
#define GAME_H

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include <SFML/Graphics.hpp>

#include "InputAction.hpp"

#include <map>
using std::map;
enum buttonsName_t { LEFT, RIGHT, UP, DOWN, ACTION };
typedef map<buttonsName_t, InputAction> InputMap;

#include "Entity.hpp"

class Game
{

public:
	Game();
	void run();
	InputMap buttons;
	Entity player_;
private:
	void processEvents();
	void update(sf::Time dt);
	void render();

	sf::RenderWindow window_;
	
};
#endif