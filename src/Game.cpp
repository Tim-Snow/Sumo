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
	gStates = START;
	glewExperimental = GL_TRUE;
	glewInit();

	player = shared_ptr<Player>(new Player(2, 3, 2, 1)); //x offset, height, y/z offset, player number
	objects.push_back(player);
	player2 = shared_ptr<Player>(new Player(8, 3, 2, 2));
	objects.push_back(player2);

	createLevel();

	camera = Camera::getInstance().getCameraM();
	Camera::getInstance().lookAt(Point3(45.0, 0.0, 0.0), Point3(5.0, 5.0, 5.0), Vector3(0.0, 1.0, 0.0));
	Camera::getInstance().setCamera(camera * Matrix4::translation(Vector3(-5.0, -4.5, 7.3)));
	display();
	return 0;
}

void Game::createLevel(){
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			objects.push_back(shared_ptr<LevelCube>(new LevelCube(j, 0, i)));
		}
	}
	objects.push_back(shared_ptr<LevelCube>(new LevelCube(6, 3, 5)));
	objects.push_back(shared_ptr<LevelCube>(new LevelCube(5, 3, 5)));
	objects.push_back(shared_ptr<LevelCube>(new LevelCube(4, 3, 5)));
	objects.push_back(shared_ptr<LevelCube>(new LevelCube(7, 2, 5)));
	objects.push_back(shared_ptr<LevelCube>(new LevelCube(3, 2, 5)));
	objects.push_back(shared_ptr<LevelCube>(new LevelCube(8, 1, 5)));
	objects.push_back(shared_ptr<LevelCube>(new LevelCube(2, 1, 5)));

	objects.push_back(shared_ptr<LevelCube>(new LevelCube(6, 3, 4)));
	objects.push_back(shared_ptr<LevelCube>(new LevelCube(5, 3, 4)));
	objects.push_back(shared_ptr<LevelCube>(new LevelCube(4, 3, 4)));
	objects.push_back(shared_ptr<LevelCube>(new LevelCube(7, 2, 4)));
	objects.push_back(shared_ptr<LevelCube>(new LevelCube(3, 2, 4)));
	objects.push_back(shared_ptr<LevelCube>(new LevelCube(8, 1, 4)));
	objects.push_back(shared_ptr<LevelCube>(new LevelCube(2, 1, 4)));

}

void Game::display(){
	glClearColor(0.35f, 0.8f, 0.9f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);



	for (auto it : objects) {
		it->draw();
	}

	SDL_GL_SwapWindow(window);
}

void Game::update(){
	for (auto it : objects) {
		it->update();
	}
	for (auto it : objects) {
		if ((it != player) && it->collidesWith(*player)) {
			player->landed(); //resets jump variables to allow another jump
			player->noGravity();
		}

		if ((it != player) && it->collidesWithWall(*player)) {
			player->moveBack();
		}

		if ((it != player2) && it->collidesWith(*player2)){
				player2->landed();
				player2->noGravity();
		}
		if ((it != player2) && it->collidesWithWall(*player2)){
			player2->moveBack();
		}
		if ((it = player) && it->collidesWith(*player2) && !it->collidesWithWall(*player2)){
			if (player->getHeight() > player2->getHeight()){
				cout << "p1 win" << endl;
				gStates = WIN1;
			}
			else {
				cout << "p2 win" << endl;
				gStates = WIN2;
			}
		}
	}
}

void Game::loop(){
	while (running){
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT){
				running = false;
			}
			switch (gStates) {
			case START:
				if (event.type = SDL_KEYDOWN){
					switch (event.key.keysym.sym){
					case SDLK_SPACE:
						gStates = PLAY;
						cout << "Start" << endl;
						break;
					default:
						break;
					}
				}
			break;

			case PLAY:
				if (event.type == SDL_KEYUP){
					switch (event.key.keysym.sym){
					case SDLK_LEFT:
						player2->moveX(0);
						break;
					case SDLK_RIGHT:
						player2->moveX(0);
						break;
					case SDLK_UP:
						player2->moveZ(0);
						break;
					case SDLK_DOWN:
						player2->moveZ(0);
						break;
					case SDLK_a:
						player->moveX(0);
						break;
					case SDLK_d:
						player->moveX(0);
						break;
					case SDLK_w:
						player->moveZ(0);
						break;
					case SDLK_s:
						player->moveZ(0);
						break;
					default:
						break;
					}
				}
				if (event.type == SDL_KEYDOWN){
					switch (event.key.keysym.sym){
					case SDLK_ESCAPE:
						running = false;
						break;
					case SDLK_PERIOD:
						player2->jump();
						break;
					case SDLK_LEFT:
						player2->moveX(-0.1);
						break;
					case SDLK_RIGHT:
						player2->moveX(0.1);
						break;
					case SDLK_UP:
						player2->moveZ(0.1);
						break;
					case SDLK_DOWN:
						player2->moveZ(-0.1);
						break;
					case SDLK_SPACE:
						player->jump();
						break;
					case SDLK_a:
						player->moveX(-0.1);
						break;
					case SDLK_d:
						player->moveX(0.1);
						break;
					case SDLK_w:
						player->moveZ(0.1);
						break;
					case SDLK_s:
						player->moveZ(-0.1);
						break;
					case SDLK_p:
						gStates = PAUSE;
						break;
					default:
						break;
					}
				}
				break;
				//Pause state
		case PAUSE:
			if (event.type == SDL_KEYDOWN){
				switch (event.key.keysym.sym){
				case SDLK_p:
					gStates = PLAY;
					break;
				default:
					break;
				}
				break;
			}
			//Player 1 wins
		case WIN1:
			break;
			//Player 2 wins
		case WIN2:
			break;
		default:
			break;
			}
		}
		if (gStates == PLAY){
			update();
			display();
		}
	}
}

void Game::clean(){}