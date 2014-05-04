#include "Player.h"

Player::Player(){
	Player(0, 0, 0, 1);
}

Player::Player(float x, float y, float z, int i){
	num_triangles = 12;
	num_vertices = 8;
	pNum = i;

	jumping = falling = false;
	gravity = true;
	position = Point3(x, y, z);
	velocity = Vector3(0.0, 0.0, 0.0);
	newPosition = position + velocity;

	Vertices = new Vertex[num_vertices];
	Indexes = new GLushort[num_triangles * 3];
	Colours = new RGBA[num_vertices];

	buildBufferArrays();
	buildColourArray();

	bbox.reset();
	bbox = shared_ptr<BoundingBox>(new BoundingBox(position, 1.0, 1.0, 1.0));
	makeResources();
}

int Player::getHeight(){
	return position.getY();
}

void Player::buildColourArray(){
	if (pNum == 1){
		Colours[0] = RGBA(0.0f, 0.4f, 0.6f, 1.0f);
		Colours[1] = RGBA(0.0f, 0.4f, 0.6f, 1.0f);
		Colours[2] = RGBA(0.0f, 0.4f, 0.6f, 1.0f);
		Colours[3] = RGBA(0.0f, 0.4f, 0.6f, 1.0f);

		Colours[4] = RGBA(0.0f, 0.4f, 0.6f, 1.0f);
		Colours[5] = RGBA(0.0f, 0.4f, 0.6f, 1.0f);
		Colours[6] = RGBA(0.0f, 0.4f, 0.6f, 1.0f);
		Colours[7] = RGBA(0.0f, 0.4f, 0.6f, 1.0f);
	}
	else {
		Colours[0] = RGBA(0.0f, 0.6f, 0.4f, 1.0f);
		Colours[1] = RGBA(0.0f, 0.6f, 0.4f, 1.0f);
		Colours[2] = RGBA(0.0f, 0.6f, 0.4f, 1.0f);
		Colours[3] = RGBA(0.0f, 0.6f, 0.4f, 1.0f);

		Colours[4] = RGBA(0.0f, 0.6f, 0.4f, 1.0f);
		Colours[5] = RGBA(0.0f, 0.6f, 0.4f, 1.0f);
		Colours[6] = RGBA(0.0f, 0.6f, 0.4f, 1.0f);
		Colours[7] = RGBA(0.0f, 0.6f, 0.4f, 1.0f);
	}
}

void Player::jump(){
	if (!jumping){
		jumping = true;
		oldHeight = position.getY();
		maxHeight = oldHeight + 2.0;
	}
}

void Player::landed(){
	falling = false;
	jumping = false;
}

void Player::move(){
	applyGravity();
	position.setX(newPosition.getX());
	position.setY(newPosition.getY());
	position.setZ(newPosition.getZ());

	if (jumping && !falling){
		if (position.getY() < maxHeight){
			velocity.setY(0.3);
		} else {
			gravity = true;
			falling = true;
		}
	}
	newPosition = position + velocity;
}

void Player::moveBack(){
	newPosition = position;
}

void Player::noGravity(){
	gravity = false;
}

void Player::applyGravity(){
	if (gravity){
		velocity.setY(-0.1);
	}
	else {
		velocity.setY(0);
	}
}

void Player::moveX(double d){
	velocity.setX(d);
}

void Player::moveZ(double d){
	velocity.setZ(d);
}

void Player::update(){
	bbox.reset();

	move();
	bbox = shared_ptr<BoundingBox>(new BoundingBox(newPosition, 1.0, 1.0, 1.0));
	gravity = true;
}

void Player::draw(){
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[2]->w, image[2]->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image[2]->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	CubeObject::draw();
}