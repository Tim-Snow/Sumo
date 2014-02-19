#include "Game.h"

int main(int argc, char* argv[])
{
	//WINDOW PROPERTIES
	const char gameTitle[] = "Sumo Game";
	const int w = 1024;
	const int h = 768;
	//CREATE WINDOW AND INIT OPENGL CONTEXT
	Game * game = new Game();
	if(!game->init(gameTitle, w, h))
		return -1;
	//RUN GAME LOOP
	game->loop();
	delete game;

	return 0;
}
