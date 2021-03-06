#include "GameObject.h"
/* This object contains the properties for a basic cube vertexes and colours
*/
#ifndef CUBEOBJECT_H_
#define CUBEOBJECT_H_

class CubeObject : public GameObject{
public:
	CubeObject();
	CubeObject(float x, float y, float z);

	virtual void buildBufferArrays();
	virtual void buildColourArray();

	virtual void update();
	virtual void draw();
private:

protected:

};

#endif // CUBEOBJECT_H_