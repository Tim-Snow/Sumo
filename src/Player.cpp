#include "Player.h"

Player::Player(){
	Player(0, 0, 0);
}

Player::Player(float x, float y, float z){
	num_triangles = 12;
	num_vertices = 8;

	gravity = true;
	position = new Point3(x, y, z);
	velocity = new Vector3(0.0, 0.0, 0.0);
	newPosition = *position + *velocity;

	Vertices = new Vector3f[num_vertices];
	Indexes = new GLushort[num_triangles * 3];
	Colours = new RGBA[num_vertices];

	buildBufferArrays();
	buildColourArray();

	bbox.reset();
	bbox = shared_ptr<BoundingBox>(new BoundingBox(*position, 1.0, 1.0, 1.0));
	makeResources();
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

void Player::jump(){
}

void Player::move(){
	applyGravity();
	position->setX(newPosition.getX());
	position->setY(newPosition.getY());
	position->setZ(newPosition.getZ());

	newPosition = *position + *velocity;
}

void Player::moveBack(){
	newPosition = *position;
}

void Player::noGravity(){
	gravity = false;
}

void Player::applyGravity(){
	if (gravity){
		velocity->setY(-0.1);
	}
	else {
		velocity->setY(0);
	}
}

void Player::moveX(double d){
	velocity->setX(d);
}

void Player::moveZ(double d){
	velocity->setZ(d);
}

void Player::update(){
	bbox.reset();

	move();
	bbox = shared_ptr<BoundingBox>(new BoundingBox(newPosition, 1.0, 1.0, 1.0));
}

void Player::draw(){
	CubeObject::draw();
}