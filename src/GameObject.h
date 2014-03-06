#include <GL/glew.h>
#include <string>
#include <fstream>
#include <iostream>

#include "Camera.h"
#include "BoundingBox.h"
#include "vectormath/scalar/cpp/vectormath_aos.h"

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

using namespace std;
using namespace Vectormath::Aos;

struct Vector3f
{
	float x;
	float y;
	float z;

	Vector3f()
	{
	}

	Vector3f(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
};
struct RGBA
{
	float r;
	float g;
	float b;
	float a;

	RGBA()
	{
	}

	RGBA(float _r, float _g, float _b, float _a)
	{
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}
};

class GameObject{
public:
	GameObject();
	~GameObject();

	virtual void draw();
	virtual void update() = 0;

protected:
	GLuint vertexBuffer, indexBuffer, colourBuffer;
	GLuint vertexShader, fragShader, program;
	GLint position_attrib, tx_uniform, colour_attrib;

	Vector3f * Vertices;
	RGBA * Colours;
	GLushort * Indexes;
	
	string vertShaderStr, fragShaderStr;

	void compileShaders();
	void makeResources();

	int num_triangles;
	int num_vertices;

	shared_ptr<BoundingBox> bbox;
private:
	string ReadFile(const char* path);
};

#endif // GAMEOBJECT_H_