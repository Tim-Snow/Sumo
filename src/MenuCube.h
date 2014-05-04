#include "CubeObject.h"
/* The start menu, and win states are displayed using a cube with relevant textures positioned in front of the camera*/
#ifndef MENUCUBE_H_
#define MENUCUBE_H_

class MenuCube : public CubeObject{
public:
	MenuCube();
	MenuCube(int);
	MenuCube(float x, float y, float z, int i);

	SDL_Surface * menuTextures[3];
	virtual void buildColourArray();
	virtual void update();
	virtual void draw();
protected:
private:
	int texSelect;
};

#endif // MENUCUBE_H_