#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include <vector>
#include <memory>

#include "Player.h"
#include "CubeObject.h"
#include "GameObject.h"
#include "LevelCube.h"
#include "LevelCube2.h"
#include "MenuCube.h"
#include "Camera.h"

using namespace std;

#ifndef GAME_H_
#define GAME_H_

enum State {START, PLAY, PAUSE, WIN1, WIN2};

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
	shared_ptr<MenuCube> menu;
	shared_ptr<MenuCube> p1win;
	shared_ptr<MenuCube> p2win;
	State gStates;

	void display();
	void update();
	void createLevel();

	Matrix4 camera;
	bool running;
};

#endif // GAME_H_