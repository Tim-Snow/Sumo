#include "KeyInput.h"

void KeyInput::updateKeys(SDL_Event &event){
	switch (event.type) {
        case SDL_QUIT:
			SDL_Quit();
			exit(1);
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

void KeyInput::handleKeys(const SDL_Keycode &key, bool keyDown) {
	switch (key) {
	case SDLK_SPACE:
		break;
		case SDLK_ESCAPE:
			if (keyDown)
				SDL_Quit();
				exit(1);
			break;
	}
}