#ifndef KEYINPUT_H_
#define KEYINPUT_H_

#include <SDL.h>

class KeyInput{
public:
	void updateKeys(SDL_Event&);
	void handleKeys(const SDL_Keycode&, bool);
private:
};
#endif