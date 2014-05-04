#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include <vector>
#include <memory>

#include "Player.h"
#include "CubeObject.h"
#include "GameObject.h"
#include "LevelCube.h"
#include "Camera.h"

#define RUN_GRAPHICS_DISPLAY 0x00;

using namespace std;

#ifndef GAME_H_
#define GAME_H_

class Game{
public:
	bool init(int w, int h);
	void loop();
	void clean();

private:
	vector<shared_ptr<GameObject> > objects;

	SDL_Window* window;
	SDL_GLContext context;
	SDL_Event event;
	shared_ptr<Player> player;
	shared_ptr<Player> player2;

	void display();
	void update();
	void createLevel();

	Matrix4 camera;
	bool running;
};

#endif // GAME_H_