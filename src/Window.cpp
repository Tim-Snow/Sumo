#include "Window.h"
using namespace std;

bool Window::initContext(const char NAME[], int WIDTH, int HEIGHT){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		cout << "SDL_Init Error: " << SDL_GetError() << endl;
		return 1;
	}
	if((window = SDL_CreateWindow(NAME, 50, 50, WIDTH, HEIGHT, SDL_WINDOW_OPENGL))==nullptr){
		cout << "SDL Error Creating Window: " << SDL_GetError() << endl;
		return 1;	
	}
	if((context = SDL_GL_CreateContext(window))==nullptr){
		cout << "SDL Error Creating OpenGL Context: " << SDL_GetError() << endl;
		return 1;	
	}
	running = true;
	return 0;
}

bool Window::initOpenGL(){
	glewExperimental=true; // Needed in core profile
	
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return 1;
	}

	glGenVertexArrays(1, &VertArrayID);
	glBindVertexArray(VertArrayID);

	static const GLfloat g_vertex_buffer_data[] = {
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f,  1.0f, 0.0f,
	};
	
	glClearColor(0,1,1,1);
	glClearDepth(1.0f);

	glViewport(0, 0, 640, 480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 640, 480, 0, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	return 0;
}

void Window::render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(0,3,GL_FLOAT,	GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);

    SDL_GL_SwapWindow(window);
}

void Window::checkInput(SDL_Event &event){
	switch (event.type) {
        case SDL_QUIT:
				running = false;
			break;
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			if (event.key.repeat == 0) {
				handleKeys(event.key.keysym.sym, event.type == SDL_KEYDOWN);
			}
			break;
		default:
			break;
	}
}

void Window::handleKeys(const SDL_Keycode &key, bool keyDown) {
	switch (key) {
	case SDLK_SPACE:
		break;
		case SDLK_ESCAPE:
			if (keyDown)
				running = false;
			break;
	}
}

void Window::deInit(){
	SDL_DestroyWindow(window);
	SDL_Quit();
}