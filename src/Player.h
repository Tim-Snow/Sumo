#include "CubeObject.h"

#ifndef PLAYER_H_
#define PLAYER_H_

class Player : public CubeObject{
public:
	Player();
	Player(float x, float y, float z);

	void jump();
	void landed();
	void noGravity();

	void moveX(double d);
	void moveZ(double d);
	void moveBack();

	virtual void buildColourArray();
	virtual void update();
	virtual void draw();
protected:
private:
	Point3 position, newPosition;
	Vector3 velocity;
	bool falling, gravity, jumping;
	float oldHeight, maxHeight;

	void applyGravity();
	void move();

	
};

#endif // PLAYER_H_