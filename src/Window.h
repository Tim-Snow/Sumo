#include <Windows.h>
#include <stdio.h>
#include <GL/glew.h>
#include <SDL.h>

#include <iostream>

class Window {
public:
	SDL_Window * window;
	SDL_GLContext context;
	GLuint VertArrayID;
	GLuint vertexbuffer;
	bool running;

	bool initContext(const char[], int, int);
	bool initOpenGL();
	void render();
	void loop();
	void checkInput(SDL_Event&);
	void handleKeys(const SDL_Keycode&, bool);
	void deInit();
private:
};