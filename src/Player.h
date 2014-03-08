#include "CubeObject.h"

#ifndef PLAYER_H_
#define PLAYER_H_

class Player : public CubeObject{
public:
	Player();
	Player(float x, float y, float z);

	float xPos, yPos, zPos;
	int maxHeight;
	void setXVel(float f);
	void setYVel(float f);
	bool gravity, jumping;

	void jump();
	void noGrav();
	void grav();

	virtual void buildColourArray();
	virtual void update();
	virtual void draw();
protected:
private:
	bool falling;
};

#endif // PLAYER_H_