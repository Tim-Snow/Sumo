#ifndef GAME_H_
#define GAME_H_

#include <glew.h>
#include <SDL.h>
#include "KeyInput.h"

class Game {
	KeyInput keys;
public:	
	bool init(const char[], int, int);
	void loop();
	void update();
	void render();
	void clean();
private:
	bool running;
};
#endif