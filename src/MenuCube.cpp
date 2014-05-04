#include "MenuCube.h"

MenuCube::MenuCube(){
	MenuCube(0, 0, 0, 0);
}

MenuCube::MenuCube(float x, float y, float z, int i){
	num_triangles = 12;
	num_vertices = 8;
	texSelect = i;

	Vertices = new Vertex[num_vertices];
	Indexes = new GLushort[num_triangles * 3];
	Colours = new RGBA[num_vertices];

	buildBufferArrays();
	buildColourArray();
	menuTextures[0] = SDL_LoadBMP("res/start.bmp");
	menuTextures[1] = SDL_LoadBMP("res/p1win.bmp");
	menuTextures[2] = SDL_LoadBMP("res/p2win.bmp");
	bbox.reset();
	bbox = shared_ptr<BoundingBox>(new BoundingBox(Point3(x, y, z), 1.0, 1.0, 1.0));
	makeResources();
}

void MenuCube::buildColourArray(){
	Colours[0] = RGBA(1.0f, 1.0f, 1.0f, 1.0f);
	Colours[1] = RGBA(1.0f, 1.0f, 1.0f, 1.0f);
	Colours[2] = RGBA(1.0f, 1.0f, 1.0f, 1.0f);
	Colours[3] = RGBA(1.0f, 1.0f, 1.0f, 1.0f);

	Colours[4] = RGBA(1.0f, 1.0f, 1.0f, 1.0f);
	Colours[5] = RGBA(1.0f, 1.0f, 1.0f, 1.0f);
	Colours[6] = RGBA(1.0f, 1.0f, 1.0f, 1.0f);
	Colours[7] = RGBA(1.0f, 1.0f, 1.0f, 1.0f);
}

void MenuCube::update(){
}

void MenuCube::draw(){
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, menuTextures[texSelect]->w, menuTextures[texSelect]->h, 0, GL_RGB, GL_UNSIGNED_BYTE, menuTextures[texSelect]->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	CubeObject::draw();
}