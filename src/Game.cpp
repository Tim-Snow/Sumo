#include "Game.h"
#include <iostream>
using namespace std;

bool Game::init(const char title[], int w, int h){
	SDL_Window * screen;
	SDL_GLContext context;

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3); //Request OpenGL 3.2 context
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
	   cerr << "Unable to initialize SDL" << endl;
	   SDL_Quit();
	   exit(1);
	   return false;
	}

	screen = SDL_CreateWindow(title, 50, 50, w, h, SDL_WINDOW_OPENGL);
	
	if (screen == NULL) {
	   cerr << "Unable to create window" << endl;
	   SDL_Quit();
	   exit(1);
	   return false;
	}

	context = SDL_GL_CreateContext(screen);	
	SDL_GL_SwapWindow(screen);
	running = true;
	return true;

}

void Game::loop(){
	SDL_Event event;
	while(running){
		while(SDL_PollEvent(&event)!=0){
			keys.updateKeys(event);
			update();
			render();

		}
		clean();
	}
	
}

void Game::update(){
}

void Game::render(){
	SDL_GL_SetSwapInterval(1);
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Game::clean(){}