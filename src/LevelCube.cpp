#include "LevelCube.h"

LevelCube::LevelCube(){
	LevelCube(0, 0, 0);
}

LevelCube::LevelCube(float x, float y, float z){
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

void LevelCube::buildColourArray(){
	Colours[0] = RGBA(0.2f, 0.1f, 0.0f, 1.0f);
	Colours[1] = RGBA(0.2f, 0.1f, 0.0f, 1.0f);
	Colours[2] = RGBA(0.0f, 0.7f, 0.3f, 1.0f);
	Colours[3] = RGBA(0.0f, 0.7f, 0.3f, 1.0f);

	Colours[4] = RGBA(0.2f, 0.1f, 0.0f, 1.0f);
	Colours[5] = RGBA(0.2f, 0.1f, 0.0f, 1.0f);
	Colours[6] = RGBA(0.0f, 0.7f, 0.3f, 1.0f);
	Colours[7] = RGBA(0.0f, 0.7f, 0.3f, 1.0f);
}

void LevelCube::update(){
}

void LevelCube::draw(){
	CubeObject::draw();
}