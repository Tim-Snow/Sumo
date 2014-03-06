#include "Game.h"

int main(int argc, char **argv){
	const int WIDTH = 1024;
	const int HEIGHT = 768;

	Game game;

	if (game.init(WIDTH, HEIGHT) != 0){
		return 0;
	}

	game.loop();

	game.clean();

	return 0;
}