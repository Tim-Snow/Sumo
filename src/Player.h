#include "CubeObject.h"

#ifndef PLAYER_H_
#define PLAYER_H_

class Player : public CubeObject{
public:
	Player();
	Player(float x, float y, float z);

	float xVel, yVel;
	void setXVel(float f);
	void setYVel(float f);

	virtual void buildColourArray();
	virtual void update();
	virtual void draw();
protected:
private:
};

#endif // PLAYER_H_