#include "Player.h"

Player::Player(){
	xVel = 0.0;
	Player(0, 0, 0);
}

Player::Player(float x, float y, float z){
	num_triangles = 12;
	num_vertices = 8;

	Vertices = new Vector3f[num_vertices]; // three points per vertex
	Indexes = new GLushort[num_triangles * 3];
	Colours = new RGBA[num_vertices];

	buildBufferArrays();
	buildColourArray();

	bbox.reset();
	bbox = shared_ptr<BoundingBox>(new BoundingBox(Point3(x, y, z), 1.0, 1.0, 1.0));

	makeResources();
}

void Player::setXVel(float f){
	xVel += f;
}

void Player::setYVel(float f){
	yVel += f;
}

void Player::buildColourArray(){

	Colours[0] = RGBA(1.0f, 0.0f, 0.0f, 1.0f);
	Colours[1] = RGBA(1.0f, 0.0f, 0.0f, 1.0f);
	Colours[2] = RGBA(1.0f, 1.0f, 0.0f, 1.0f);
	Colours[3] = RGBA(1.0f, 1.0f, 0.0f, 1.0f);

	Colours[4] = RGBA(1.0f, 0.0f, 0.0f, 1.0f);
	Colours[5] = RGBA(1.0f, 0.0f, 0.0f, 1.0f);
	Colours[6] = RGBA(1.0f, 1.0f, 0.0f, 1.0f);
	Colours[7] = RGBA(1.0f, 1.0f, 0.0f, 1.0f);
}

void Player::update(){
	bbox.reset();
	bbox = shared_ptr<BoundingBox>(new BoundingBox(Point3(xVel, 1, yVel), 1.0, 1.0, 1.0));
}

void Player::draw(){
	CubeObject::draw();
}