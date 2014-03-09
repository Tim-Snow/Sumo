#include "CubeObject.h"

#ifndef PLAYER_H_
#define PLAYER_H_

class Player : public CubeObject{
public:
	Player();
	Player(float x, float y, float z);

	bool gravity, jumping;
	float oldHeight, maxHeight;

	void jump();
	void landed();
	void applyGravity();
	void noGravity();

	void moveX(double d);
	void moveZ(double d);
	void moveBack();

	virtual void buildColourArray();
	virtual void update();
	virtual void draw();
protected:
private:
	Point3 newPosition;
	Point3 * position;
	Vector3 * velocity;

	void move();
	bool falling;
};

#endif // PLAYER_H_