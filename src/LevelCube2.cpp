#include "LevelCube2.h"

LevelCube2::LevelCube2(){
	LevelCube2(0, 0, 0);
}

LevelCube2::LevelCube2(float x, float y, float z){
	num_triangles = 12;
	num_vertices = 8;

	Vertices = new Vertex[num_vertices];
	Indexes = new GLushort[num_triangles * 3];
	Colours = new RGBA[num_vertices];

	buildBufferArrays();
	buildColourArray();

	bbox.reset();
	bbox = shared_ptr<BoundingBox>(new BoundingBox(Point3(x, y, z), 1.0, 1.0, 1.0));
	makeResources();
}

void LevelCube2::buildColourArray(){
	Colours[0] = RGBA(0.5f, 0.2f, 0.0f, 1.0f);
	Colours[1] = RGBA(0.5f, 0.2f, 0.0f, 1.0f);
	Colours[2] = RGBA(0.3f, 0.8f, 0.3f, 1.0f);
	Colours[3] = RGBA(0.3f, 0.8f, 0.3f, 1.0f);

	Colours[4] = RGBA(0.5f, 0.2f, 0.0f, 1.0f);
	Colours[5] = RGBA(0.5f, 0.2f, 0.0f, 1.0f);
	Colours[6] = RGBA(0.3f, 0.8f, 0.3f, 1.0f);
	Colours[7] = RGBA(0.3f, 0.8f, 0.3f, 1.0f);
}

void LevelCube2::update(){
}

void LevelCube2::draw(){
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[0]->w, image[0]->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image[0]->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	CubeObject::draw();
}