#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL.h>
#include <tuple>

using std::tuple;
using std::make_tuple;

class InputManager {
private:
	enum directions { LEFT, RIGHT, UP };
	enum gameKeys { RESET, QUIT };

	bool gameOutput[2];
	bool playerOutput[3];

	void clearInputs();
public:
	InputManager();

	tuple<bool, bool, bool> getPlayerKeys() const;
	tuple<bool, bool> getGameKeys() const;

	void update();
};

#endif
