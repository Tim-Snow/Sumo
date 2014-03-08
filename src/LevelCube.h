#include "CubeObject.h"

#ifndef LEVELCUBE_H_
#define LEVELCUBE_H_

class LevelCube : public CubeObject{
public:
	LevelCube();
	LevelCube(float x, float y, float z);

	virtual void buildColourArray();
	virtual void update();
	virtual void draw();
protected:
private:
};

#endif // LEVELCUBE_H_