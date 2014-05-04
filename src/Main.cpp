#include "Game.h"

int main(int argc, char **argv){
	const int WIDTH = 1024;
	const int HEIGHT = 768;

	Game * game = new Game();

	game->init(WIDTH, HEIGHT);
	game->loop();

	game->clean();
	delete game;

	return 0;
}