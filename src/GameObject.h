#include <GL/glew.h>
#include <SDL_image.h>
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

struct Vector2f
{
	float x;
	float y;

	Vector2f()
	{
	}

	Vector2f(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
};
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
struct Vertex{
	Vector3f position;
	Vector2f texture;
	Vertex(){}
	Vertex(Vector3f pos, Vector2f tex){
		position = pos;
		texture = tex;
	}
};

class GameObject{
public:
	GameObject();
	~GameObject();

	bool collidesWith(GameObject & a);
	bool collidesWithWall(GameObject & a);
	virtual void draw();
	virtual void update() = 0;
protected:
	Vertex * Vertices;
	RGBA * Colours;
	GLushort * Indexes;
	GLuint texture;
	SDL_Surface * image[3];

	void compileShaders();
	void makeResources();
	void initTextures();
	void bindTextures(int textureID, char * uniformName);

	int num_triangles, num_vertices;

	shared_ptr<BoundingBox> bbox;
private:
	string ReadFile(const char* path);

	string vertShaderStr, fragShaderStr;

	GLuint vertexBuffer, indexBuffer, colourBuffer;
	GLuint vertexShader, fragShader, program;
	GLint position_attrib, tx_uniform, colour_attrib, texture_attrib;
};

#endif // GAMEOBJECT_H_