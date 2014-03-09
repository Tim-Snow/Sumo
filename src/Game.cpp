#include "Game.h"

bool Game::init(int w, int h){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		cout << "SDL_Init Error: " << SDL_GetError() << endl;
		return 1;
	}

	if ((window = SDL_CreateWindow("Sumo Game", 50, 50, w, h, SDL_WINDOW_OPENGL)) == nullptr){
		cout << "Window Error: " << SDL_GetError() << endl;
		return 1;
	}

	if ((context = SDL_GL_CreateContext(window)) == nullptr){
		cout << "GL Context Error: " << SDL_GetError() << endl;
		return 1;
	}

	running = true;

	glewExperimental = GL_TRUE;
	glewInit();

	player = shared_ptr<Player>(new Player(0, 3, 0)); //x offset, height, y/z offset
	objects.push_back(player);

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			objects.push_back(shared_ptr<LevelCube>(new LevelCube(i, 0, j)));
		}
	}

	camera = Camera::getInstance().getCameraM();
	Camera::getInstance().lookAt(Point3(0.0, 10.0, -10.0), Point3(0.0, -10.0, 10.0), Vector3(0.0, 1.0, 0.0));
	Camera::getInstance().setCamera(camera * Matrix4::translation(Vector3(-4.5, -3.5, 6.0)));
	display();

	return 0;
}

void Game::cameraLoop(){
}

void Game::display(){
	glClearColor(0.35f, 0.8f, 0.9f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	for (auto it : objects) {
		it->update();
		player->applyGravity();
		if ((it != player) && it->collidesWith(*player)) {
			player->noGravity();
			cout << "Player is colliding with another object" << endl;
		}
	}



	
	for (auto it : objects) {
		it->draw();
	}

	SDL_GL_SwapWindow(window);
}

void Game::loop(){
	while (running){
		if (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				running = false;
			}
			if (event.type == SDL_KEYUP){
				switch (event.key.keysym.sym){
				case SDLK_LEFT:
					player->moveX(0);
					break;
				case SDLK_RIGHT:
					player->moveX(0);
					break;
				case SDLK_UP:
					player->moveZ(0);
					break;
				case SDLK_DOWN:
					player->moveZ(0);
					break;
				default:
					break;
				}
			}
			
			if (event.type == SDL_KEYDOWN){
				camera = Camera::getInstance().getCameraM();
				switch (event.key.keysym.sym){
				case SDLK_ESCAPE:
					running = false;
					break;
				case SDLK_LEFT:
					player->moveX(-0.1);
					break;
				case SDLK_RIGHT:
					player->moveX(0.1);
					break;
				case SDLK_UP:
					player->moveZ(0.1);
					break;
				case SDLK_DOWN:
					player->moveZ(-0.1);
					break;
				case SDLK_SPACE:

					break;
				default:
					break;
				}
			}
		}
		display();
	}
}

void Game::clean(){}