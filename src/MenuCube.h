#include "CubeObject.h"

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