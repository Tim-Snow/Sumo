#include "CubeObject.h"

#ifndef LEVELCUBE2_H_
#define LEVELCUBE2_H_

class LevelCube2 : public CubeObject{
public:
	LevelCube2();
	LevelCube2(float x, float y, float z);

	virtual void buildColourArray();
	virtual void update();
	virtual void draw();
protected:
private:
};

#endif // LEVELCUBE2_H_