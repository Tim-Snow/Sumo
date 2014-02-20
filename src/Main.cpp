#include "Window.h"

int main(int argc, char **argv){

	const char GAMETITLE[] = "Sumo Game";
	const int WIDTH = 1024;
	const int HEIGHT = 768;

	Window * window = new Window();

	window->initContext(GAMETITLE, WIDTH, HEIGHT);
	window->initOpenGL();

	SDL_Event event;
	while(window->running){
		while(SDL_PollEvent(&event)!=0){
			window->checkInput(event);
			window->render();
			window->update();
			SDL_Delay(10);
		}
	}

	window->deInit();

	return 0;
}
