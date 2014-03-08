#include "Player.h"

Player::Player(){
	Player(0, 0, 0);
}

Player::Player(float x, float y, float z){
	num_triangles = 12;
	num_vertices = 8;
	
	xPos = x;
	yPos = z;
	zPos = y;
	maxHeight = y+1.5;

	jumping = false;
	falling = false;
	gravity = true;

	Vertices = new Vector3f[num_vertices]; // three points per vertex
	Indexes = new GLushort[num_triangles * 3];
	Colours = new RGBA[num_vertices];

	buildBufferArrays();
	buildColourArray();

	bbox.reset();
	bbox = shared_ptr<BoundingBox>(new BoundingBox(Point3(x, y, z), 1.0, 1.0, 1.0));
	makeResources();
}

void Player::jump(){
	if (jumping && !falling){
		if (zPos < maxHeight){
			zPos += 0.1;
			falling = false;
			gravity = false;
		}
		else {
			falling = true;
		}
	}
	if (falling){
		gravity = true;
		jumping = false;
		falling = false;
	}
}

void Player::setXVel(float f){
	xPos += f;
}

void Player::setYVel(float f){
	yPos += f;
}

void Player::buildColourArray(){
	Colours[0] = RGBA(0.0f, 0.0f, 0.0f, 1.0f);
	Colours[1] = RGBA(0.0f, 0.0f, 0.0f, 1.0f);
	Colours[2] = RGBA(1.0f, 1.0f, 0.0f, 1.0f);
	Colours[3] = RGBA(1.0f, 1.0f, 0.0f, 1.0f);

	Colours[4] = RGBA(0.0f, 0.0f, 0.0f, 1.0f);
	Colours[5] = RGBA(0.0f, 0.0f, 0.0f, 1.0f);
	Colours[6] = RGBA(1.0f, 1.0f, 0.0f, 1.0f);
	Colours[7] = RGBA(1.0f, 1.0f, 0.0f, 1.0f);
}

void Player::noGrav(){
	gravity = false;
}

void Player::grav(){
	gravity = true;
}

void Player::update(){
	bbox.reset();
	jump();
	if (gravity){
		zPos -= 0.1;
	}
	bbox = shared_ptr<BoundingBox>(new BoundingBox(Point3(xPos, zPos, yPos), 1.0, 1.0, 1.0));
	gravity = true;
}

void Player::draw(){
	CubeObject::draw();
}