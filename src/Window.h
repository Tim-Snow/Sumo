#include <stdio.h>
#include <GL/glew.h>
#include <SDL.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtx/transform.hpp>

#include "Shader.h"
#include "Player.h"

#include <iostream>

using namespace glm;

class Window {
public:
	SDL_Window * window;
	SDL_GLContext context;
	GLuint VertArrayID, vertexbuffer, programID;
	mat4 Projection, View, Model, MVP;

	Shader shader;
	Player player;

	bool running;

	bool initContext(const char[], int, int);
	bool initOpenGL();

	void render();
	void update();
	void checkInput(SDL_Event&);
	void handleKeys(const SDL_Keycode&, bool);

	void deInit();
private:

};