#include "Window.h"

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
	glewExperimental=true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return 1;
	}
	glGenVertexArrays(1, &VertArrayID);
	glBindVertexArray(VertArrayID);
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

	glClearColor(0,0,0,1);
	glClearDepth(1.0f);
	
	programID = shader.LoadShader("vertShader.vert","fragShader.frag");
	glUseProgram(programID);

	Projection = perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	View       = lookAt(vec3(4,3,3), vec3(0,0,0), vec3(0,1,0));
	Model      = mat4(1.0f);
	MVP        = Projection * View * Model;

	

	return 0;
}

void Window::render(){
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(0,3,GL_FLOAT,	GL_FALSE, 0, (void*)0);
	
	glDrawArrays(GL_TRIANGLES, 0, 12*3);
	glDisableVertexAttribArray(0);

	player.drawPlayer(1);

    SDL_GL_SwapWindow(window);
}

void Window::update(){
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