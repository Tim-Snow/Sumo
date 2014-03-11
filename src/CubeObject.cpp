#include "CubeObject.h"

CubeObject::CubeObject(){
	CubeObject(0, 0, 0);
}

CubeObject::CubeObject(float x, float y, float z){
	num_triangles = 12;
	num_vertices = 8;

	Vertices = new Vertex[num_vertices];
	Indexes = new GLushort[num_triangles * 3];
	Colours = new RGBA[num_vertices];

	buildColourArray();
	buildBufferArrays();

	bbox.reset();
	bbox = shared_ptr<BoundingBox>(new BoundingBox(Point3(x, y, z), 1.0, 1.0, 1.0));

	makeResources();
}

void CubeObject::buildColourArray(){

	Colours[0] = RGBA(0.0f, 0.0f, 0.0f, 1.0f);
	Colours[1] = RGBA(0.0f, 0.0f, 0.0f, 1.0f);
	Colours[2] = RGBA(1.0f, 1.0f, 1.0f, 1.0f);
	Colours[3] = RGBA(1.0f, 1.0f, 1.0, 1.0f);

	Colours[4] = RGBA(0.0f, 0.0f, 0.0f, 1.0f);
	Colours[5] = RGBA(0.0f, 0.0f, 0.0f, 1.0f);
	Colours[6] = RGBA(1.0f, 1.0f, 1.0f, 1.0f);
	Colours[7] = RGBA(1.0f, 1.0f, 1.0f, 1.0f);
}

void CubeObject::buildBufferArrays(){
	Vertices[0] = Vertex(Vector3f(-0.5f, -0.5f, 0.5f), Vector3f(0.0f, 0.0f, 0.0f));
	Vertices[1] = Vertex(Vector3f(0.5f, -0.5f, 0.5f), Vector3f(1.0f, 0.0f, 0.0f));
	Vertices[2] = Vertex(Vector3f(0.5f, 0.5f, 0.5f), Vector3f(1.0f, 1.0f, 0.0f));
	Vertices[3] = Vertex(Vector3f(-0.5f, 0.5f, 0.5f), Vector3f(0.0f, 1.0f, 0.0f));

	Vertices[4] = Vertex(Vector3f(-0.5f, -0.5f, -0.5f), Vector3f(0.0f, 0.0f, 1.0f));
	Vertices[5] = Vertex(Vector3f(0.5f, -0.5f, -0.5f), Vector3f(1.0f, 0.0f, 1.0f));
	Vertices[6] = Vertex(Vector3f(0.5f, 0.5f, -0.5f), Vector3f(1.0f, 1.0f, 1.0f));
	Vertices[7] = Vertex(Vector3f(-0.5f, 0.5f, -0.5f), Vector3f(0.0f, 1.0f, 1.0f));

	Indexes[0] = 0;	Indexes[1] = 1;	Indexes[2] = 2;
	Indexes[3] = 2;	Indexes[4] = 3;	Indexes[5] = 0;

	Indexes[6] = 3;	Indexes[7] = 2;	Indexes[8] = 6;
	Indexes[9] = 6;	Indexes[10] = 7; Indexes[11] = 3;

	Indexes[12] = 7; Indexes[13] = 6; Indexes[14] = 5;
	Indexes[15] = 5; Indexes[16] = 4; Indexes[17] = 7;

	Indexes[18] = 4; Indexes[19] = 5; Indexes[20] = 1;
	Indexes[21] = 1; Indexes[22] = 0; Indexes[23] = 4;

	Indexes[24] = 4; Indexes[25] = 0; Indexes[26] = 3;
	Indexes[27] = 3; Indexes[28] = 7; Indexes[29] = 4;

	Indexes[30] = 1; Indexes[31] = 5; Indexes[32] = 6;
	Indexes[33] = 6; Indexes[34] = 2; Indexes[35] = 1;
}

void CubeObject::update(){

}

void CubeObject::draw(){
	GameObject::draw();
}