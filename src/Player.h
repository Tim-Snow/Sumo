#include "CubeObject.h"

#ifndef PLAYER_H_
#define PLAYER_H_
/* The most complex cube object, this object is different as it has logic to be moved with controls, jump, and change the game state (by jumping on opponents head and winning
*/
class Player : public CubeObject{
public:
	Player();
	Player(float x, float y, float z, int i);

	int getHeight();
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
	int pNum;
	Point3 position, newPosition;
	Vector3 velocity;
	bool falling, gravity, jumping;
	float oldHeight, maxHeight;

	void applyGravity();
	void move();
};

#endif // PLAYER_H_